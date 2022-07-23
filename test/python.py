#if statmeent
counter = 0
while (counter < 1):
    print(f"counter: {counter}")
    counter += 1

for i in range(0,1,1):
    print(f"counter: {i}")

nums = [n for n in range(10)]
nums += [4]
for n in nums:
    print(n)

nums[:-1] = [5]
for n in nums:
    print(n)