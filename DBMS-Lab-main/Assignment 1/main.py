import csv


def read_csv(filename):
    values = []
    with open(filename, 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        for row in reader:
            new_row = []
            for value in row:
                new_row.append(value.strip())
            values.append(new_row)
    values.pop(0)
    return values


def Q1():
    print("Q1.......")
    print("Faculty Names")
    for rows in read_csv('instructor.txt'):
        print(rows[1])


def Q2():
    print("Q2......")
    print("Departments")
    for rows in read_csv('instructor.txt'):
        print(rows[2])


def Q3():
    print("Q3.......")
    print("Departments")
    dept = set()
    for rows in read_csv('instructor.txt'):
        dept.add(rows[2])
    for dep in dept:
        print(dep)


def Q4():
    print("Q4......")
    print("Faculty Names")
    for row in read_csv('instructor.txt'):
        if row[2] == "Comp. Sci." and int(row[3]) > 70000:
            print(row[1])


def Q5():
    print("Q5......")
    print("Departments")
    for rows in read_csv('department.txt'):
        print(rows[0])


def Q6():
    print("Q6.......")
    rows = read_csv('department.txt')
    maxBudget = -1
    for row in rows:
        maxBudget = max(maxBudget, int(row[2]))

    print("The maximum budget is ", maxBudget)
    print("Department Names")
    for row in rows:
        if int(row[2]) == maxBudget:
            print(row[0])


Q1()
Q2()
Q3()
Q4()
Q5()
Q6()
