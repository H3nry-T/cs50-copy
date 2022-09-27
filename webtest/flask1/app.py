from flask import Flask, request, render_template

app = Flask(__name__)

@app.route("/")

def index():
    name = request.args.get("name")
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name_val=name)

    