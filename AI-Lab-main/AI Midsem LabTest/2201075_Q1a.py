while True:
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    o = input("Enter the operator: ")

    if o == "+":
        print(a + b)
    elif o == "-":
        print(a - b)
    elif o == "*":
        print(a * b)
    elif o == "/":
        print(a / b)
    else:
        print("Invalid operator")
