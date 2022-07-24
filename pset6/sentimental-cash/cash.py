from cs50 import get_float

def main():
    while True:
        change = get_float("please input your change:\n")
        if 0 < change:
            break
        else:
            print("please input a positive number\n")
            continue

    quarters = calculate_quarters(change)
    change = change - quarters * 0.25

    dimes = calculate_dimes(change)
    change = change - dimes * 0.10

    nickels = calculate_nickels(change)
    change = change - nickels * 0.05

    pennies = calculate_pennies(change)
    change = change - pennies * 0.01

    print(quarters + dimes + nickels + pennies)

def calculate_quarters(change):
    quarters = 0
    while (change >= 0.25):
        change -= 0.25
        quarters += 1
    return quarters

def calculate_dimes(change):
    dimes = 0
    while (round(change, 2) >= 0.1):
        change -= 0.1
        dimes += 1
    return dimes

def calculate_nickels(change):
    nickels = 0
    while (round(change, 2) >= 0.05):
        change -= 0.05
        nickels += 1
    return nickels

def calculate_pennies(change):
    pennies = 0
    while (round(change, 2) >= 0.01):
        change -= 0.01
        pennies += 1
    return pennies

if __name__ == "__main__":
    main()