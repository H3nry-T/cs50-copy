from cs50 import get_float

def main():
    while True:
        change = get_float("please input your change\n")
        if 0 < change:
            break
        else:
            print("please input a positive number\n")
            continue

    quarters = calculate_quarters(change)
    change = change - quarters * 25

    dimes = calculate_dimes(change)
    change = change - dimes * 10

    nickels = calculate_nickels(change)
    change = change - nickels * 5

    pennies = calculate_pennies(change)
    change = change - pennies * 1

    print(quarters + dimes + nickels + pennies)






def calculate_quarters(change):
    change % 25
def calculate_dimes(change):

def calculate_nickels(change):

def calculate_pennies(change):



if __name__ == "__main__":
    main()