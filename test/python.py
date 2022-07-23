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

presidents = [
    ("president 1", 1789),
    ("president 2", 1797)
]

for 