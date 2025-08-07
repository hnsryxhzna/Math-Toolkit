import numpy as np

T = np.array([[1, 3],
                [2, 7]])

A = np.array([[5, 3],
              [2, 1]])

# T = np.array([0, 1, 0])

# print(np.dot(np.linalg.inv(T), np.dot(A, T)))

P = np.array([[8/9, -1/9, 4/9],
              [-1/9, 8/9, 4/9],
              [4/9, 4/9, -7/9]])

value, vector = np.linalg.eig(P)

print(value)
print(vector)

# P = np.array([[-9, 7, -10],
#               [3, -2, 3],
#               [1, -1, 1]]) # Your 'Basis' is P

# A_B = np.array([[3, 5, 0],
#                 [-1, -1, 1],
#                 [1, 2, 1]]) # Your 'A' is A_B

# e2 = np.array([0, 1, 0]) # Your 'T' is e2

# # Step 1: Find e2 in B-coordinates
# e2_in_B = np.linalg.solve(P, e2) # Solves P * x = e2 for x. x is e2_in_B

# print(e2_in_B)

# # Step 2: Apply A_B to e2_in_B
# T_e2_in_B = np.dot(A_B, e2_in_B)

# print(T_e2_in_B)

# # Step 3: Convert T_e2_in_B back to standard coordinates
# result = np.dot(P, T_e2_in_B)

# print(result)



B = np.array([[1, 4],
              [-1, -3]])

P = np.array([[-3, 2],
              [-8, 5]])

C = np.array([[1, 1], [5, 6]])
D = np.array([[2, 1], [5, 2]])

# print(np.dot(np.dot(B, A), np.linalg.inv(B)))
# print(np.linalg.solve(A, B))




B = np.array([[10, 17, 20],
              [3, 5, 6],
              [1, 2, 2]])   # corrected row

target = np.array([-3, -1, 0])

# print(np.linalg.solve(B, target))

P = np.array([[5, 1, 0],
              [0, 5, 1],
              [0, 0, 5]])

# print(np.dot(np.dot(B, P), np.linalg.inv(B)))

B = np.array([[0, 1, -3],
              [1, 3, -11],
              [1, 3, -12]])   # corrected row

target = np.array([-6, -25, -26])

# print(np.linalg.solve(B, target))
