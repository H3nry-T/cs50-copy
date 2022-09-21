def outer_function():
    message = "Hi!"

    def inner_function():
        print(message)
    return inner_function

my_func = outer_function()

print(my_func.__name__)
my_func()
# closure is where an inner function can remember 
