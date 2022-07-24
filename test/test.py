import cs50
import sys

def nthlastdigit(number, n):
    return number % 10**n

print(nthlastdigit(689, 2))