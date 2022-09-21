def outer_function(msg):
    message = msg

    def inner_function():
        print(message)
    return inner_function

hi_func = outer_function("hi")

hello_func = outer_function("hello")

print(my_func.__name__)
my_func()
# closure is where an inner function can remember variables within scope despite the outer function being excecuted.


