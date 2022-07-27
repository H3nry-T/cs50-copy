import re

while True:
    input = str(input("type in a string: "))
    if input.isalpha() == True:
        break
    else:
        print("pls type everything as a string")

input.lower()
if re.search("^(hello)$", input):
    print("it matches!") 
