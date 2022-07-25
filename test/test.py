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

productdigits = []
for i in range(len(digitarray)):
    j = 0
    while j < len(str(digitarray[i])):
        productdigit = str(digitarray[i])[j]
        productdigits.append(productdigit)
        j += 1

print("")
for i in range(len(productdigits)):
    print(productdigits[i], end = " ")
