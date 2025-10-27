import numpy as np

print("Input lengths:")
length_input = input()

try:
    length_list = np.fromstring(length_input, dtype=float, sep=' ')
except ValueError:
    print("Error: You entered something that wasn't a number.")

print("Input radix:")
radix = int(input())

print("Input Kraft-McMillan coefficient, if you are trying to find maximum possible lenth for the last l, input 1:")
coefficient = eval(input())

sum = 0
for len in length_list:
    sum += np.power(1 / radix, len)

residual = coefficient - sum
if (coefficient == 1):
    result = np.log(residual) / np.log(1 / radix)
    print(np.ceil(result))
elif (coefficient < 1 and coefficient >= 0):
    print(np.log(residual) / np.log(1 / radix))

