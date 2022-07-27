import re
import cs50
import sys
while True:
    input = cs50.get_string("pls type in a string: ")
    if input.isdigit():
        print("this seems to be a number")
        continue
    else:
        break

formatted_input = input.strip().lower()

if re.search("^(hello)$", formatted_input):
    print("it matches!")
