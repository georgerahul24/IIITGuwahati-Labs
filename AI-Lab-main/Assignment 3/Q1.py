import csv


def readCsv(filename):
    data = []
    with open(filename) as f:
        reader = csv.reader(f)
        for row in reader:
            data.append(row)
    return data


# b
def read_data(filename):
    listOfDictionaries = []
    data = readCsv("data_q1.txt")
    for row in data:
        listOfDictionaries.append({
            "ID": row[0],
            "name": row[1],
            "age": row[2], })

    return listOfDictionaries


# c
def write_data(filename, listOfDictionaries: list[dict]):
    newData = []
    for dict in listOfDictionaries:
        newData.append([dict["ID"], dict["name"], dict["age"]])
    with open(filename, "w") as f:
        writer = csv.writer(f)
        writer.writerows(newData)


write_data("data_q1.txt", read_data("data_q1.txt"))


# d
def update_age(filename, id, new_age):
    data = readCsv(filename)
    newData = []

    for row in data:
        if row[0] == id:
            row[2] = new_age
        newData.append(row)
    with open(filename, "w") as f:
        writer = csv.writer(f)
        writer.writerows(newData)


update_age("data_q1.txt", '1', 10)
