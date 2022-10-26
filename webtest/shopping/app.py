from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


#default route, show all the books from the db return_template("default")
@app.route("/")
def index():
    
    return render_template("books.html")

#cart route: post, get methods, check if cart in session object


    # Ensure cart exists


# check for post method: do something.
    # POST

# else GET method, store books in db and render the cart.html page.
    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)