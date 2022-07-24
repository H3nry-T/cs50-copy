from cs50 import get_int
from cs50 import get_string

def main():
    while True:
        number = get_int("please type in your credit card number:\n")
        if number > 0:
            break
        else:
            print("please insert a valid credit card number")
            continue

#get the second last digit
    i = len(number)
    while (i > 0):

        i -= 2

def secondlastdigit(number):
    

if __name__ == "__main__":
    main()

