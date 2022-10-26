from flask import Flask, render_template, redirect
from flask_session import Session

#configure the flask app
app = Flask(__name__)

#configure the session non permanent
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if request.get("name"):
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    

print(__name__)