def outer_function():
    message = "Hi!"

    def inner_function():
        print(message)
    return inner_function

my_func = outer_function()


