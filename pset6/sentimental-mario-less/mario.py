from cs50 import get_int

while True:
    height = get_int("input the pyramid height:\n")
    if 0 < height < 9:
        break

for i in range(height):
    for j in range(height):
        if j < height - (i + 1):
            print(" ", end = "")
        else:
            print("#", end = "")
    print("")

