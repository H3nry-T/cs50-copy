from cs50 import get_int
from cs50 import get_string

def main():
    while True:
        number = get_int
        if (not number < 0):
            break
        else:
            print("please insert a valid credit card number")
            continue

main() 

