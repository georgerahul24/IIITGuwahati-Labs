with open("2201075_Q1b.txt", "r") as f:
    lines = f.readlines()
    print("Number of lines: ", len(lines))

with open("2201075_Q1b.txt", "r") as f:
    print("Number of words: ", len(f.read().split()))

with open("2201075_Q1b.txt", "r") as f:
    print("Number of spaces: ", f.read().count(" "))

with open("2201075_Q1b.txt", "r") as f:
    print("Number of unique words: ", len(set(f.read().split())))

with open("2201075_Q1b.txt", "r") as f:
    words = f.read().split()
    freq = dict()
    for word in set(words):
        freq[word] = 0
    for word in words:
        freq[word] += 1

    print("The Frequencies of the words are: ")
    for key, val in freq.items():
        print("\t\t", key, " : ", val)

with open("2201075_Q1b.txt", "r") as f:
    longest_word = ""
    longest_length = 0
    words = f.read().split()
    sum_of_length_of_words = 0
    for word in words:
        sum_of_length_of_words += len(word)
        if len(word) > longest_length:
            longest_word = word
            longest_length = len(word)

    print("The longest word is: ", longest_word)
    print("The average length of the words are: ", sum_of_length_of_words / len(words))

with open("2201075_Q1b.txt", "r") as f:
    line1 = f.readline()
    line2 = f.readline()
    print("The similarity is: ", 0 if line1 != line2 else 1)
