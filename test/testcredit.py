import cs50
import sys
import math

def nthlastdigit(number, n):
    return number % 10**n // 10 ** (n - 1)

def lengthnumber(number):
    return int(math.log10(number) + 1)



while True:
    try:
        number = int(input("pls give number:\n"))
        break
    except:
        print("This has to be a integer")
        continue
print("")

digitarray = []
print("every other digit is: ")
for i in range(2, lengthnumber(number) + 1, 2):
    print(nthlastdigit(number, i), end = " ")
    digit = nthlastdigit(number, i)
    digit = digit * 2
    digitarray.append(digit)

print("")
print("times every digit by two:")

for i in range(len(digitarray)):
    print(digitarray[i], end = " ")

#product digits all seperated out
productdigits = []
for i in range(len(digitarray)):
    j = 0
    while j < len(str(digitarray[i])):
        productdigit = str(digitarray[i])[j]
        productdigits.append(int(productdigit))
        j += 1

print("")
print("seperate out all the product digits:")
for i in range(len(productdigits)):
    print(productdigits[i], end = " ")
print("")

print("leftover digits:")
leftoverdigits = []
for i in range(1, lengthnumber(number) + 1, 2):
    untouched_digits = nthlastdigit(number, i)
    print(untouched_digits, end = " ")
    leftoverdigits.append(untouched_digits)
print("")

finalsum = productdigits + leftoverdigits
print("combine both product and leftover digits")

for i in range(len(finalsum)):
    print(finalsum[i], end = " ")
print("")
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
        print("MASTER")

    #anything else
    else:
        print("INVALID")

else:
    print("INVALID")
    sys.exit()