import numpy as np

matrixA = np.random.normal(0, 1, (2, 4))
matrixB = np.random.uniform(0, 1, (4, 3))
print("Matrix A")
print(matrixA)
print("Matrix B")
print(matrixB)
print()

print("Multiply transpose of A and B")

print(np.dot(matrixA.transpose(), matrixB.transpose()))

print()
print("Multiply Inverse of A and B")
print(np.dot(np.linalg.inv(matrixA),np.linalg.inv(matrixB)))

