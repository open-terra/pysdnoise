from distutils.core import setup, Extension

sdnoise = Extension('sdnoise',
                    include_dirs=['deps/perlin-noise/src'],
                    sources = ['deps/perlin-noise/src/sdnoise1234.c',
                               'src/sdnoisemodule.c'])

setup (name = 'sdnoise',
       version = '0.1.0',
       description = 'test',
       author = 'Oliver John Hitchcock',
       url = 'https://github.com/c0rp3n',
       ext_modules = [sdnoise])
