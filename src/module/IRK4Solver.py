import numpy as np
from scipy.optimize import least_squares

def IRK4Solver(f, t, y0):
    N = len(t)
    d = len(y0)
    y0 = np.array(y0).flatten()
    yout = np.zeros((len(y0), N))
    yout[:, 0] = y0
    tol = np.finfo(float).eps

    # define the RK tableau
    sqrt3 = np.sqrt(3)
    c = np.array([1 / 2 - sqrt3 / 6, 1 / 2 + sqrt3 / 6])
    b = np.array([1 / 2, 1 / 2])
    a = np.array([
        [1 / 4, 1 / 4 - sqrt3 / 6],
        [1 / 4 + sqrt3 / 6, 1 / 4]
    ])

    for i in range(N - 1):
        h = t[i + 1] - t[i]
        tn = t[i]
        yn = yout[:, i]

        # use trust-region-dogleg solve 2‑vector nonlinear system
        # https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.least_squares.html#least-squares
        Y_guess = np.tile(yn, 2)
        def colloc_res(Y_flat):
            Y = Y_flat.reshape(2, d)
            r = np.empty(2 * d)
            for j in (0, 1):
                rhs = sum(a[j, k] * f(tn + c[k] * h, Y[k]) for k in (0,1))
                r[j * d: (j + 1) * d] = Y[j] - (yn + h * rhs)
            return r

        sol = least_squares(colloc_res, Y_guess,
                            method = 'dogbox',
                            ftol = tol, xtol = tol, gtol = tol,
                            verbose = 0)

        Y1, Y2 = sol.x.reshape(2, d)
        K1 = f(tn + c[0] * h, Y1)
        K2 = f(tn + c[1] * h, Y2)
        yout[:, i + 1] = yn + h * (b[0] * K1 + b[1] * K2)

    tout = t
    return tout, yout
