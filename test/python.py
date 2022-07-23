

#if statmeent
counter = 0
while (counter < 1):
    print(f"counter: {counter}")
    counter += 1

for i in range(0,1,1):
    print(f"counter: {i}")

nums = [n for n in range(3)]
nums += [4]
for n in nums:
    print(n)

print("\n", end = "")

nums[len(nums):] = [5]
for n in nums:
    print(n)
print("")
presidents = [
    ("president 1", 1789),
    ("president 2", 1797)
]

for i, a in presidents:
    print(f"{i} is in offce at year {a} ")

print("")

pizzas = {
    "cheese" : 9,
    "pepperoni" : 10,
    "vegetables" : 11,
    "buffalo chicken" : 12
}

for i in pizzas:
    print(i)
print("")

for item, price in pizzas.items():
    print(f"The item: {item}\nCosts: ${price} ")
    print("")

print(square(5))
#if __name__ == "__main__":
#    main()

def square(x):
    return x ** 2