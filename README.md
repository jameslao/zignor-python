# zignor-python
Ziggurat normal random number generator ported to Python

## Requirement

`NumPy` installation is required. Python 3 compatible.

## Installation

To install, run 

`python setup.py install`

or you can install from PyPI:

`pip install zignor`

If you are running Windows and don't have MSVC compiler installed, a pre-built distribution on Python 3.5 is given in `dist` folder.

## Usage

It will automatically import `NumPy`, so you can just use

```
import zignor
zignor.randn(10)
```
or
```
zignor.randn(3, 5)
```

to generate a matrix of 3 by 5.

## More functions

This module includes two implementations. One is an implementation of the original Ziggurat method (modified from [http://m.seehuhn.de/data/ziggurat/gauss.c](http://m.seehuhn.de/data/ziggurat/gauss.c)). This is the code behind `zignor.randn()` and `zignor.rnor()` method, and it is the faster of the two.

The other implementation is the VIZIGNOR implementation by Doornik, J.A. It improves the original method and uses MW8222 RNG to enable the method to pass some more tests. This method can be called by `zignor.zignor()`.

## References
1. G. Marsaglia and W.W. Tsang: The Ziggurat Method for Generating Random Variables. *Journal of Statistical Software*, vol. 5, no. 8, pp. 1–7, 2000. and .
2. Doornik, J.A. (2005), "An Improved Ziggurat Method to Generate Normal Random Samples", mimeo, Nuffield College, University of Oxford.



