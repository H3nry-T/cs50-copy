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
# these functions are also used as higher-order functions

def my_map(func, arg_list):
    results = []
    for i in arg_list:
        results.append(func(i))
    return results


squared_list = my_map(square, [1, 2, 3, 4, 5])

print(squared_list)

# as you can see, I am able to pass in a function INSIDE another function.
#  make sure there are no parenthesis

def html_tag(tag):
    def wrap_text(msg):
        print("<{0}> {1} </{0}>".format(tag, msg))
    return wrap_text

h1_tag = html_tag("h1")

h1_tag("test headline")
h1_tag("another headline!")
