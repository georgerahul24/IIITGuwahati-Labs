# Q4 a
import re

with open("Q4_a.txt") as f:
    print("The number of words in the file is ", len(f.read().split()))

# Q4 b
with open("Q4_b_source.txt") as fs, open("Q4_b_target.txt", "w") as fr:
    fr.write(fs.read())

# Q4 c
pattern = input("Enter the regex pattern: ")
with open("Q4_c.txt") as f:
    content = f.read()
    print(re.findall(f"({pattern})", content))
