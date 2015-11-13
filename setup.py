from distutils.core import setup, Extension
import numpy as np

_zignor = Extension('_zignor',
                    sources=['zignor/_zignor.c'],
                    include_dirs=[np.get_include()],
                    extra_compile_args=['-O3'])

setup(name='zignor',
      version='0.1',
      description='zignor RNG',
      author='James Lao',
      author_email='james@jlao.net',
      packages=['zignor'],
      package_dir={'zignor': 'zignor'},
      ext_package='zignor',
      ext_modules=[_zignor])
