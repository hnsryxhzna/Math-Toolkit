# Math Toolkit

A collection of small programs for number theory, linear algebra, coding theory, cryptography, and numerical ODE solving, written in C and Python as a learning project.

## Repository layout

```
.
├── src/
│   ├── math_toolkit.c              # CLI entry point (dispatches on a flag)
│   └── module/
│       ├── GCD_calculator.c        # Euclidean algorithm
│       ├── prime_factorization.c
│       ├── vector_multiplication.c
│       ├── ISBN_check.c
│       ├── hamming_code_check.c    # placeholder, not implemented yet
│       └── python/                 # numerical methods & information theory
├── cryptography/                   # standalone C programs
├── computer_vision/                # raylib 3D camera experiment
└── makefile
```

## The `math_toolkit` CLI

### Build

Requires a C compiler (`gcc` by default).

```sh
# builds ./math_toolkit
make
# removes the binary
make clean
```

### Usage

```sh
./math_toolkit <option> [arguments...]
```

| Option | Function | Arguments | Example |
|--------|----------|-----------|---------|
| `-g` | Greatest common divisor | two integers | `./math_toolkit -g 48 18` |
| `-f` | Prime factorization | one integer ≥ 2 | `./math_toolkit -f 360` |
| `-v` | Dot product of two vectors | `x1 … xn , y1 … yn` | `./math_toolkit -v 1 2 3 , 4 5 6` |
| `-i` | ISBN-10 validation | a 10-digit ISBN | `./math_toolkit -i 0306406152` |

Example output:

```
$ ./math_toolkit -g 48 18
The GCD of 48 and 18 is 6

$ ./math_toolkit -f 360
360 = 2 * 2 * 2 * 3 * 3 * 5

$ ./math_toolkit -v 1 2 3 , 4 5 6
32.000000
```

### How each module works

- **GCD (`-g`)**: The Euclidean algorithm. The GCD of two numbers doesn't change if the larger one is replaced by its remainder when divided by the smaller one. Repeat until the remainder is zero; the last non-zero remainder is the GCD.
- **Prime factorization (`-f`)**: Trial division. The program divides out every factor of 2, then tests odd divisors up to √n. Anything left over after that is prime.
- **Vector multiplication (`-v`)**: Computes the dot product Σ xᵢyᵢ. Separate the two vectors with a standalone `,`. Both vectors must have the same length.
- **ISBN check (`-i`)**: Checks the ISBN-10 checksum Σ i·dᵢ ≡ 0 (mod 11). It only accepts digits for now, so ISBNs that end in `X` aren't supported.

## Cryptography

Each file in `cryptography/` is a standalone program with its own `main`:

| File | Description |
|------|-------------|
| `AES128.c` | AES-128 from scratch: key expansion, SubBytes, ShiftRows, MixColumns, AddRoundKey, and their inverses. Encrypts and then decrypts a fixed test block with the FIPS-197 example key. |
| `caesar_cipher.c` | Interactive Caesar cipher. It reads text and a shift, then prints the encrypted and decrypted results. |
| `bit_inverse.c` | Flips every bit of a file: `./bit_inverse <in> <out>`. Running it twice restores the original. |
| `linear_congruential_random_generator.c` | Linear congruential generator xₙ₊₁ = (a·xₙ + b) mod m, with a = 13¹³ and m = 2⁵⁹. |
| `random_number.c` | Prints one value from the C library's `rand()`, seeded with the current time. |

Build any of them on its own:

```sh
gcc -Wall -O2 cryptography/AES128.c -o aes
gcc -Wall -O2 cryptography/bit_inverse.c -o bit_inverse
gcc -Wall -O2 cryptography/linear_congruential_random_generator.c -o lcg -lm
```

## Python modules

Install the dependencies with `pip install numpy scipy`.

### ODE solvers and models

Each solver has the signature `solver(f, t, y0) -> (t, y)`. `f(t, y)` returns dy/dt, `t` is the time grid, and `y` has shape `(len(y0), len(t))`.

| File | Description |
|------|-------------|
| `EulerSolver.py` | Explicit (forward) Euler method |
| `RK4Solver.py` | Classical 4th-order Runge–Kutta |
| `IRK4Solver.py` | Implicit 4th-order Gauss–Legendre Runge–Kutta (2 stages). It solves the stage equations with `scipy.optimize.least_squares`. |
| `Lorenz.py` | Right-hand side of the Lorenz system (σ, ρ, β) |
| `KMK.py` | Kermack–McKendrick SIR epidemic model (β, γ) |

```python
import numpy as np
from RK4Solver import RK4Solver
from Lorenz import lorenz

t = np.linspace(0, 40, 4001)
t_out, y = RK4Solver(lambda t, x: lorenz(t, x, 10, 28, 8/3), t, [1, 1, 1])
```

### Information theory (interactive scripts)

| File | Description |
|------|-------------|
| `arithmetic_encode.py` | Arithmetic coding. Given symbols, their probabilities, and a message, it prints the final `[low, high)` interval. |
| `Kraft_McMillan_solver.py` | Uses the Kraft–McMillan inequality Σ r^(−lᵢ) ≤ 1 to find the largest possible remaining codeword length, or to check a set of lengths. |
| `min_radix_UD_code.py` | Finds the smallest radix r for which the given codeword lengths can form a uniquely decodable code. |

Run them with `python3 src/module/python/<script>.py` and enter the values when prompted.

## Computer vision

`computer_vision/vision.c` uses [raylib](https://www.raylib.com/) to draw a cube in 3D with a free camera, and prints the camera position every frame.

```sh
# macOS with Homebrew: brew install raylib
gcc computer_vision/vision.c -o vision $(pkg-config --cflags --libs raylib)
```

## Roadmap

- Hamming code check (`src/module/hamming_code_check.c`)
- `X` check digit support for ISBN-10
- Add `-v` and `-i` to the CLI usage message
