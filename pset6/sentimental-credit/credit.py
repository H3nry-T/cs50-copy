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

    print(nthlastdigit(number, 2))

#get the second last digit
    i = 2
    #while i <= 8
    while (i <= len(number) // 2):
        card = nthlastdigit(number, i)
        card = card * 2

        i += 2

def nthlastdigit(number, n):
    return number % 10 ** n // 10 ** (n - 1)

def lengthnumber(number):
    return int(math.log10(number) + 1)
    
if __name__ == "__main__":
    main()

