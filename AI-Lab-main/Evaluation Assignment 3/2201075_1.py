def f(x):
    return x ** 2 - 4 * x + 4


stepsize = 0.1
a = -10
b = 10
f_previous = f(a)
x = a
numberofsteps = 0
maxnumberofsteps = 300

while a <= x <= b and numberofsteps < maxnumberofsteps:
    numberofsteps += 1
    x += stepsize
    f_x = f(x)
    if (f_x > f_previous):
        print("Optimal minimum value is ", f_previous, " for value of x = ", x - stepsize)
        break

    f_previous = f_x
else:
    print("Optimal minimum value is ", f_previous, " for value of x = ", x)
print("Iterations: ", numberofsteps)
