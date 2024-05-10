# Q1 a
print("Area of the circle is: ", 3.141 * (r := int(input("Enter the radius of the circle: "))) * r)

# Q1 b

print("The given number is ", "odd" if (num := int(input("Enter the number: "))) % 2 != 0 else "even")

# Q1 c

print("The °F is ", (int(input("Enter the °C to convert: ")) * 9 / 5) + 32)
print("The °C is ", (int(input("Enter the °F to convert: ")) - 32) * 5 / 9)
