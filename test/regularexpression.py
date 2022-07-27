import re
import cs50
import sys

while True:
    input = cs50.get_string("pls type in a string: ")
    print("")

    if input.isdigit():
        print("this seems to be a number\n")
        continue
    elif len(input) <= 0:
        print("pls type something in\n")
        continue
    else:
        break

formatted_input = input.strip().lower()

if re.search("^(hello)$", formatted_input):
    print("it matches!")
else:
    print("it doesn't match")
