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


    #get every other digit starting from the second last
    digitarray = []
    for i in range(2, len(str(number)) + 1, 2):
        print(f"every other digit is {nthlastdigit(number, i)}")
        digit = nthlastdigit(number, i)
        digit = digit * 2
        digitarray.append(digit)

    for i in range(len(digitarray)):
        print(digitarray[i])
        

def nthlastdigit(number, n):
    return number % 10 ** n // 10 ** (n - 1)

def lengthnumber(number):
    return int(math.log10(number) + 1)

if __name__ == "__main__":
    main()

