from distutils.core import setup, Extension
import numpy as np

_zignor = Extension('_zignor',
                    sources=['zignor/_zignor.c'],
                    include_dirs=[np.get_include()],
                    extra_compile_args=['-O3'])

setup(name='zignor',
      version='0.1.7',
      description='Ziggurat Fast Normal Distribution RNG',
      author='James Lao',
      author_email='james@jlao.net',
      url='https://github.com/jameslao/zignor-python',
      download_url='https://github.com/jameslao/zignor-python/tarball/0.1',
      packages=['zignor'],
      package_dir={'zignor': 'zignor'},
      ext_package='zignor',
      ext_modules=[_zignor])
