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
    i = 2
    while (i < len(number) // 2):
        card = nthlastdigit(number, i)
        card = card * 2
        
        i += 2

def nthlastdigit(number, n):
    return number % 10**n

if __name__ == "__main__":
    main()

