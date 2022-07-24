from cs50 import get_int

while True:
    height = get_int("input a height:")
    if 0 < height < 9:
        break
    else:
        print("input a number between 1 and 8 inclusive")
        continue

for i in range(height):
    for j in range(height + 2 + i):
        if j == 4 or j == 5 or j < height - (i + 1):
            print(" ", end = "")
        else:
            print("#", end = "")
        print("")
