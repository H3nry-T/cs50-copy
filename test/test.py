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
print(sum(finalsum))

visa = number
amex = number
master = number

while number >= 10:
    number //= 10

#visacheck
if number == 4 and (lengthnumber(number) == 16 or lengthnumber(number) == 13):
    print("VISA")
#amexcheck
if number ==