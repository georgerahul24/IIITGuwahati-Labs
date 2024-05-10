# Q5 a


def factorial(num):
    if num <= 1:
        return 1
    else:
        return num * factorial(num - 1)


num = int(input("Enter a number: "))
print("The factorial of ", num, " is ", factorial(num))


# Q5 b
def fibonacci(num):
    # 1 1 2 3 5 8 13
    if (num <= 1):
        return num
    else:
        return fibonacci(num - 1) + fibonacci(num - 2)


num = int(input("Enter the number of terms: "))
print("The ans is ", fibonacci(num))


#Q5 c
def checkPrime(num):
    i = 2
    while i < num:
        if num % i == 0:
            return False
        i += 1
    return True


num = int(input("Enter the number: "))
print("The number is", "prime" if checkPrime(num) else "not prime")
