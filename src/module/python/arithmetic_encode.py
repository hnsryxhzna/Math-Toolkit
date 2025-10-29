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

probability_dict = dict(zip(symbols_list, probabilities_list))

output_dict = {}
current_low = 0
for key, value in probability_dict.items():
    low = current_low
    high = current_low + value

    output_dict[key] = {
        'low': low,
        'high': high,
        'range': value
    }

    current_low = high

print(f"\nCreated dictionary\n{output_dict}")

low: float = 0
high: float = 0
current_range: float = 1

for sym in encode_string:
    if output_dict[sym] is None:
        print("Error: Your encode string is invalid")

    current_low = low
    low = current_low + current_range * output_dict[sym]['low']
    high = current_low + current_range * output_dict[sym]['high']
    current_range *= output_dict[sym]['range']
    # print(f"low {low} high {high} range {current_range}")

print(f"low is {low}")
print(f"high is {high}")

