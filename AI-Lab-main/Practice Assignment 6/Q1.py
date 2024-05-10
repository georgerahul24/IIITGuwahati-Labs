def f(x: int) -> int:
    return 3*x**6+4*x**3+2*x ** 2 + 2 * x + 1


def hillClimb(initial_value: int, low: int, high: int, step_cost: int):
    init = max(low, initial_value)
    prev_val = f(init)
    currentx = init
    val = 0
    for i in range(init + step_cost, high + step_cost, step_cost):
        currentx = i
        val = f(i)
        if prev_val >= val:
            return i - step_cost, prev_val

        prev_val = val
    return currentx, val


print(hillClimb(-1, -1000, 1000, 1))
