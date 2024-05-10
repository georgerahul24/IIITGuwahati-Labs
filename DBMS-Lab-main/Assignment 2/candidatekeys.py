import csv
import itertools


def read_csv(filename):
    values = []
    headers = []

    with open(filename, 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        for row in reader:
            new_row = []
            for value in row:
                new_row.append(value.strip())
            values.append(new_row)
    headers.extend(values.pop(0))
    return headers, values


headers, values = read_csv('Keys.txt')
numberOfAttributesForCandidateKeys = 0
candidateKeys = []
numberOfTotalAttributes = len(headers)
flag = False
for numberOfRowsSelected in range(1, len(headers) + 1):
    for combinations in (
            list(itertools.combinations([i for i in range(numberOfTotalAttributes)], numberOfRowsSelected))):
        check = set()

        for column in values:
            string = ""
            for row_number in combinations:
                string += column[row_number]
            check.add(string)
        if (len(check) == len(values)):
            numberOfAttributesForCandidateKeys = numberOfRowsSelected
            candidateKeys += [combinations]
            flag = True
    if flag:
        break
print("Number of attributes in Candidate Keys: ", numberOfAttributesForCandidateKeys)
print("Candidate Keys are: ")
for key in candidateKeys:
    print(list(headers[i] for i in key))
print("Super Keys are: ")
superKeys = []
for numberOfRowsSelected in range(1, len(headers) + 1):
    for combinations in (
            list(itertools.combinations([i for i in range(numberOfTotalAttributes)], numberOfRowsSelected))):
        check = set()

        for column in values:
            string = ""
            for row_number in combinations:
                string += column[row_number]
            check.add(string)
        if len(check) == len(values):
            superKeys += [combinations]

for key in superKeys:
    print(list(headers[i] for i in key))