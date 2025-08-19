import numpy as np

def EulerSolver(f, t, y0):
    N = len(t)
    y0 = np.array(y0).flatten()
    # yout is an 3 x N matrix
    yout = np.zeros((len(y0), N))
    yout[:, 0] = y0

    for i in range(N - 1):
        h = t[i + 1] - t[i]
        yout[:, i+1] = yout[:, i] + h * f(t[i], yout[:, i])

    # tout is a column vector of grid points
    tout = t
    return tout, yout
