from cs50 import get_int

while True:
    height = get_int("input a height:")
    if 0 < height < 9:
        break
    else:
        print("input a number between 1 and 8 inclusive")
        continue

