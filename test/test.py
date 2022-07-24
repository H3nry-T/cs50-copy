import cs50
import sys


def nthlastdigit(number, n):
    return number % 10**n // 10


while True:
    x = input("pls give number\n")
    if (x.isdigit() == False):
        print("this has to be a number")
    else:
        continue

print(nthlastdigit(689098834729234253424, 2))