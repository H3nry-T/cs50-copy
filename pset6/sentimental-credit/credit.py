from cs50 import get_int
import math
import sys

def main():
    while True:
        number = get_int("please type in your credit card number:\n")
        if number > 0:
            break
        else:
            print("please insert a valid credit card number")
            continue
    print("")

    #get every other digit starting from the second last
    digitarray = []
    print("every other digit is: ")
    for i in range(2, lengthnumber(number) + 1, 2):
        print(nthlastdigit(number, i), end = " ")
        digit = nthlastdigit(number, i)
        digit = digit * 2
        digitarray.append(digit)

    print("")
    print("times every digit by two:")
    print(digitarray)

    productdigits = []
    for i in range(len(digitarray)):
        for j in range(1, len(str(digitarray[i])) + 1, 1):
            productdigit = nthlastdigit(digitarray[i], j)
            productdigits.append(productdigit)

    print("seperate out all the product digits:")
    print(productdigits)

    print("leftover digits:")
    leftoverdigits = []
    for i in range(1, lengthnumber(number) + 1, 2):
        untouched_digits = nthlastdigit(number, i)
        leftoverdigits.append(untouched_digits)

    print(leftoverdigits)
    finalsum = productdigits + leftoverdigits
    print(finalsum)
    print(sum(finalsum))



    if nthlastdigit(sum(finalsum), 1) == 0:
        visa = number
        amex = number
        master = number

        #visacheck
        if (lengthnumber(number) == 16 or lengthnumber(number) == 13) and str(visa)[0] == '4':
            print("VISA")

        #amexcheck
        elif lengthnumber(number) == 15 and (str(amex)[0:2] == "37" or str(amex)[0:2] == "34"):
            print("AMEX")

        #mastercheck
        elif lengthnumber(number) == 16 and (str(master)[0:2] == "51" or str(master)[0:2] == "52" or str(master)[0:2] == "53" or str(master)[0:2] == "54" or str(master)[0:2] == "55"):
            print("MASTERCARD")

        #anything else
        else:
            print("INVALID")

    else:
        print("INVALID")
        sys.exit()






def nthlastdigit(number, n):
    return number % 10 ** n // 10 ** (n - 1)

def lengthnumber(number):
    return int(math.log10(number) + 1)

if __name__ == "__main__":
    main()

