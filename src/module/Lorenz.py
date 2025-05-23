import numpy as np

def lorenz(t, x, sigma, rho, beta):
    # x = x[0]
    # y = x[1]
    # z = x[2]

    dxdt = sigma * (x[1] - x[0])
    dydt = x[0] * (rho - x[2]) - x[1]
    dzdt = x[0] * x[1] - beta * x[2]

    return np.array([dxdt, dydt, dzdt])
