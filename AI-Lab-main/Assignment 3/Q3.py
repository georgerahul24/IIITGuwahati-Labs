import numpy as np
import pandas as pd

# a
df = pd.read_csv("data_q3.txt", header=None)
npArray = df.to_numpy()

print("Shape of npArray:", npArray.shape)

row_means = np.mean(npArray, axis=1)
std_dev = np.std(npArray, axis=1)

details = pd.DataFrame({"mean": row_means, "std": std_dev})
print(details)

details.to_csv("data_q3a_output.txt", sep=",", index=False)


# b
def calculate_stats(npArray):
    return {
        "median": np.median(npArray),
        "minimum": np.min(npArray),
        "maximum": np.max(npArray)
    }


print("B subpart")
npArray = np.array([1, 23, 4, 3, 2, 5, 5])
print(calculate_stats(npArray))


# c
def multiply_matrix(m1, m2):
    return np.dot(m1, m2)


m1 = np.array([[1, 2], [2, 3]])
m2 = np.array([[2, 3], [2, 4]])
print(m1)
print(m2)
print(multiply_matrix(m1, m2))


# d

def filteroutOdd(nparray):
    return nparray[nparray % 2 == 0]


randomArray = np.random.randint(1, 101, size=10)
print("Original: ", randomArray)

print("Filtered: ", filteroutOdd(randomArray))

# e
randomArray = np.random.randint(1, 101, size=20)
randomArray[0] = 24
print("Original: ", randomArray)
print("Halves: ", np.array_split(randomArray, 2))

# f
ra1 = np.random.randint(1, 101, size=25).reshape(5, 5)
ra2 = np.random.randint(1, 101, size=25).reshape(5, 5)

print(np.vstack((ra1, ra2)))
print(np.hstack((ra1, ra2)))

print("Sorting them")
print(np.sort(ra1, axis=0))
print(np.sort(ra2, axis=1))

print("Arithmetic Operations")
print(np.add(ra1, ra2))
print(np.subtract(ra1, ra2))
print(np.multiply(ra1, ra2))
print(np.divide(ra1, ra2))

# g
print("Doing subpart g")

iris_dataset = pd.read_csv('iris.csv')
print(iris_dataset.head())

iris_dataset = iris_dataset.iloc[:, :-1]

mean = np.mean(iris_dataset, axis=0)
median = np.median(iris_dataset, axis=0)
min = np.min(iris_dataset, axis=0)
max = np.max(iris_dataset, axis=0)

print("Mean:", mean)
print("Median:", median)
print("Min:", min)
print("Max:", max)
