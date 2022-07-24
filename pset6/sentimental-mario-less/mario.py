from cs50 import get_int

while True:
    x = get_int("input the pyramid height:\n")
    if x < 1 or x > 8:
        