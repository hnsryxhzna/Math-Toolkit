import numpy as np

codeword_lengths = [1, 1, 1, 2, 2, 3, 4, 4]
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

