from cs50 import get_int

def main():
    height = getheight()
    for i in range(height):
        for j in range(i + 1):
            print("#", end = "")
        print("")

def getheight():
    while True:
        n = get_int("please input a number:")
        if n > 0:
            break
    return n

main()