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

print(nthlastdigit(number, 16))

