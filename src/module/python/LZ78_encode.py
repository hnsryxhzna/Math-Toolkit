import numpy as np

print("Input symbols:")
symbols_input = input()

print("Input probabilities:")
probabilities_input = input()

symbols_list = symbols_input.split()

print("Input string to encode")
encode_string = input()

try:
    probabilities_list = np.fromstring(probabilities_input, dtype=float, sep=' ')
except ValueError:
    print("Error: You entered something that wasn't a number.")


print(f"Your symbols are\n{symbols_list}")
print(f"Your probabilities are\n{probabilities_list}")

if (len(symbols_list) != len(probabilities_list)):
    print("Invalid input")

