# first class functions:
# being able to use functions in the same way we use objects generally.

def square(x):
    return x * x

f = square(5)

print(square)
print(f)

# now lets see what happens if f = square

f = square

print(square)
print(f)

# f is now a function.

print(f(5))

# we can now treat f just like any other function. 