# zignor-python
Ziggurat normal random number generator ported to Python

With code and method from Doornik, J.A. (2005), "An Improved Ziggurat Method to Generate Normal Random Samples", mimeo, Nuffield College, University of Oxford.

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
