from flask import Flask, redirect, render_template, request, session
from flask_session import Session

#configure the flask app
app = Flask(__name__)

#configure the session non permanent
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if

print(__name__)