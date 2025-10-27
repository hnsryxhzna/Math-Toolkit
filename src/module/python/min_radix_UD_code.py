import numpy as np

print("Input symbols:")
codeword_lengths = input()

try:
    codeword_lengths = np.fromstring(codeword_lengths, dtype=float, sep=' ')
except ValueError:
    print("Error: You entered something that wasn't a number.")

radix = 2
sum = 0

while (1):
    for len in codeword_lengths:
        sum += np.power(1 / radix, len)

    if sum <= 1:
        print(radix)
        break
    else:
        radix += 1
        sum = 0

