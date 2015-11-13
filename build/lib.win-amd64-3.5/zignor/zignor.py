import numpy as np

from . import _zignor


def randn(*dims):
    if dims:
        return np.reshape(_zignor.randn(np.prod(dims), int(np.random.randint(1e8)), int(np.random.randint(1e8))), dims)
    else:
        return None
