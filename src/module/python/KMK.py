import numpy as np

def KMK(t, x, beta, gamma):
    S = x[0]
    I = x[1]
    R = x[2]

    dsdt = -1 * beta * S * I
    didt = beta * S * I - gamma * I
    drdt = gamma * I

    return np.array([dsdt, didt, drdt])
