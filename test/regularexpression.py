import re
import cs50
while True:
    input = cs50.get_string("pls type in a string: ")
    if input.isalpha():
        print("this seems to be a number")
        continue
    else:
        break

formatted_input = input.strip().lower()

if re.search("^(hello)$", formatted_input):
    print("it matches!")
