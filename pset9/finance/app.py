import os


from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # pull out a portfolio table take out the rows and template it into the html
    portfolio_rows = db.execute("SELECT * FROM portfolio WHERE portfolio_user_id = ?", session["user_id"])

    user_cash_rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    user_cash_balance = round(float(user_cash_rows[0]["cash"]), 2)

    # summing up
    total_starting_cash = 0
    for dict in portfolio_rows:
        total_starting_cash += float(dict["total_value_of_stock"])
    total_starting_cash += user_cash_balance

    # formatting to usd string
    for dict in portfolio_rows:
        dict["price"] = usd(dict["price"])
        dict["total_value_of_stock"] = usd(dict["total_value_of_stock"])

    return render_template("index.html", portfolio_rows = portfolio_rows, user_cash_balance = usd(user_cash_balance), total_starting_cash = usd(total_starting_cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    # check number of shares
    if not request.form.get("shares"):
        return apology("missing shares")

    elif request.method == "POST":
        # validate symbol
        if not request.form.get("symbol"):
            return apology("symbol required")
        try:
            # take all info from json parse
            symbol_given = request.form.get("symbol")
            symbol_parse = lookup(symbol_given)

            stock_name = symbol_parse["name"]
            stock_symbol = symbol_parse["symbol"]
            stock_price = symbol_parse["price"]
            stock_shares = request.form.get("shares")

        except:
            return apology("invalid symbol")

        db.execute('''CREATE TABLE IF NOT EXISTS history (
                history_user_id INTEGER NOT NULL,
                history_id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                symbol TEXT NOT NULL,
                shares INTEGER NOT NULL,
                price INTEGER NOT NULL,
                value_of_stock NUMERIC NOT NULL
            ); ''')

        db.execute('''CREATE TABLE IF NOT EXISTS portfolio (
                portfolio_user_id INTEGER NOT NULL,
                portfolio_id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                symbol TEXT NOT NULL,
                shares INTEGER NOT NULL,
                price INTEGER NOT NULL,
                total_value_of_stock NUMERIC NOT NULL DEFAULT 0
            ); ''')

        # check if user has enough cash to afford stocks
        value_of_stock = symbol_parse["price"] * float(stock_shares)
        users_rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        user_cash = users_rows[0]["cash"]
        if (user_cash - value_of_stock) < 0:
            return apology("Too many shares are bought")

        # update the cash leftover
        cash_left = user_cash - value_of_stock
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_left, session["user_id"])

        # insert info into transaction history
        db.execute("INSERT INTO history (history_user_id, name, symbol, shares, price, value_of_stock) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], stock_name, stock_symbol, stock_shares, stock_price, value_of_stock)

        # insert new stocks into portfolio
        if not db.execute("SELECT symbol FROM portfolio WHERE portfolio_user_id = ? AND symbol = ?", session["user_id"], stock_symbol):
            db.execute("INSERT INTO portfolio (portfolio_user_id, name, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", session["user_id"], stock_name, stock_symbol, stock_shares, stock_price)

        #take value_of_stock, shares from transaction history; adding it up cumulatively
        old_value_row = db.execute("SELECT SUM(value_of_stock) AS sum_value FROM history WHERE history_user_id = ? AND symbol = ?", session["user_id"], stock_symbol)
        old_shares_row = db.execute("SELECT SUM(shares) AS sum_shares FROM history WHERE history_user_id = ? AND symbol = ?", session["user_id"], stock_symbol)

        total_value_of_stock = old_value_row[0]["sum_value"]
        total_shares_of_stock = old_shares_row[0]["sum_shares"]


        # update the portfolio table
        db.execute("UPDATE portfolio SET total_value_of_stock = ?, shares = ? WHERE (portfolio_user_id = ? AND name = ?)", total_value_of_stock, total_shares_of_stock, session["user_id"], stock_name)

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("/history in progress")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html", )

    elif request.method == "POST":
        if not request.form.get("symbol"):
            return apology("symbol required")
        try:
            symbol_given = request.form.get("symbol")
            symbol_parse = lookup(symbol_given)
            stock_name = symbol_parse["name"]
            stock_symbol = symbol_parse["symbol"]
            stock_price = usd(symbol_parse["price"])
            return render_template("quote_info.html", stock_name=stock_name, stock_price=stock_price, stock_symbol=stock_symbol)
        except:
            return apology("invalid symbol")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        username_given = request.form.get("username")
        password_given = request.form.get("password")
        confirm_pass_given = request.form.get("confirmation")

        if not username_given or not password_given:
            return apology("please type in a username")

        array_of_usernames = db.execute("SELECT username FROM users WHERE username = ?", username_given)
        try:
            if not array_of_usernames[0].get(username_given, 0):
                return apology("username exists")
        except:
            if password_given != confirm_pass_given:
                return apology("Confirmed password doesn't match")


        hashed_password = generate_password_hash(password_given)
        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username_given, hashed_password)
        return render_template("login.html")

    elif request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    def list_of_dict_search(symbol, rows):
        for dict in rows:
            if dict["symbol"] == symbol:
                return dict

    portfolio_rows = db.execute("SELECT * FROM portfolio WHERE portfolio_user_id = ?", session["user_id"])

    if request.method == "GET":
        return render_template("sell.html", portfolio_rows = portfolio_rows)

    elif request.method == "POST":
        # get number of shares and stock ticker symbol
        symbol_given = request.form.get("symbol")
        shares_given = request.form.get("shares")

        # search the specific dictionary of the given stock
        dict_of_stock_info = list_of_dict_search(symbol_given, portfolio_rows)

        # up to date info on stock selection
        symbol_parse = lookup(symbol_given)
        current_stock_price = symbol_parse["price"]
        stock_name = dict_of_stock_info["name"]
        value_of_stock_sold = int(shares_given) * current_stock_price

        # check for negative numbers and for too many shares sold
        if int(shares_given) < 0:
            return apology("cannot sell negative shares")
        elif int(shares_given) > dict_of_stock_info["shares"]:
            return apology("too many shares bro")

        # update history table of the user
        db.execute("INSERT INTO history (history_user_id, name, symbol, shares, price, value_of_stock) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], stock_name, symbol_given, -int(shares_given), current_stock_price, -value_of_stock_sold)


        #take value_of_stock, shares from transaction history; adding it up cumulatively
        old_value_row = db.execute("SELECT SUM(value_of_stock) AS sum_value FROM history WHERE history_user_id = ? AND symbol = ?", session["user_id"], symbol_given)
        old_shares_row = db.execute("SELECT SUM(shares) AS sum_shares FROM history WHERE history_user_id = ? AND symbol = ?", session["user_id"], symbol_given)

        total_value_of_stock = old_value_row[0]["sum_value"]
        total_shares_of_stock = old_shares_row[0]["sum_shares"]


        # update the portfolio table take away the money in stock
        db.execute("UPDATE portfolio SET total_value_of_stock = ?, shares = ? WHERE (portfolio_user_id = ? AND name = ?)", total_value_of_stock, total_shares_of_stock, session["user_id"], stock_name)

        # update the user cash balance add the liquid cash
        cash_balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        updated_cash_balance = cash_balance[0]["cash"] + value_of_stock_sold
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash_balance, session["user_id"])

        return redirect("/")
