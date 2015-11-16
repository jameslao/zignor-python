import numpy as np

from . import _zignor


def rnor(*dims):
    if dims:
        return np.reshape(_zignor.rnor(np.prod(dims), int(np.random.randint(1e8)), int(np.random.randint(1e8))), dims)
    else:
        return None

def rexp(*dims):
    if dims:
        return np.reshape(_zignor.rexp(np.prod(dims), int(np.random.randint(1e8)), int(np.random.randint(1e8))), dims)
    else:
        return None

def randn(*dims):
    return rnor(*dims)
    

def zignor(*dims):
    if dims:
        return np.reshape(_zignor.zignor(np.prod(dims), int(np.random.randint(1e8)), int(np.random.randint(1e8))), dims)
    else:
        return None
