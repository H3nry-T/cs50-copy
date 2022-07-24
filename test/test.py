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

for i in range(2, lengthnumber(number), 2):
    print(f"every other digit is {nthlastdigit(number, i)}")


# print(nthlastdigit(x, 2))