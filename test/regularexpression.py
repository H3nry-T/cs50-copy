import re

while True:
    input = str(input("type in a string: "))
    if input.isdigit() == True:
        print("pls type everything as a string")
    else:
        break
    
formatted_input = input.strip().lower()

if re.search("^(hello)$", formatted_input):
    print("it matches!")
