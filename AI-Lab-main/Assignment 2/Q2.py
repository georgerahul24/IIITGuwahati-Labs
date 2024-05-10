# Q2 a
print("The reverse of the string is ", input("Enter the string: ")[::-1])

# Q2 b

str = input("Enter the string: ")
count = 0

for letter in str.lower():
    if letter in "aeiou":
        count += 1

print("The number of vowels in the string is ", count)

# Q2 c

print("The given string is ",
      "not a palindrome" if (str1 := input("Enter the string: ")) != str1[::-1] else "a palindrome")
