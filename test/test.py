import cs50
import sys


def nthlastdigit(number, n):
    return number % 10**n // 10


while True:
    try:
        x = int(input("pls give number:\n"))
    except:
        print("This has to be a integer")
        continue

print(nthlastdigit(x, 2))