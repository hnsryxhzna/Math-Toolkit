import numpy as np

def RK4Solver(f, t, y0):
    N = len(t)
    y0 = np.array(y0).flatten()
    # yout is an 3 x N matrix
    yout = np.zeros((len(y0), N))
    yout[:, 0] = y0

    for i in range(N - 1):
        h = t[i + 1] - t[i]
        tn = t[i]
        yn = yout[:, i]

        k1 = f(tn, yn)
        k2 = f(tn + h / 2, yn + h / 2 * k1)
        k3 = f(tn + h / 2, yn + h / 2 * k2)
        k4 = f(tn + h, yn + h * k3)

        yout[:, i + 1] = yn + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4)

    tout = t
    return tout, yout
