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

    for i in range(len(number)):
        number % 
if __name__ == "__main__":
    main()

