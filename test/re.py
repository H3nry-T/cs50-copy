import re

while True:
    input = str(input("type in a string: "))
    if input.isalpha() == True:
        break
    else:
        print("pls type everything as a string")

formatted_input = input.strip().lower()

if re.search("^(hello)$", formatted_input):
    print("it matches!")
