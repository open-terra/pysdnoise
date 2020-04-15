from distutils.core import setup, Extension

sdnoise = Extension('sdnoise',
                    include_dirs=['deps/perlin-noise/src'],
                    sources = ['deps/perlin-noise/src/sdnoise1234.c',
                               'deps/perlin-noise/src/srdnoise23.c',
                               'src/sdnoisemodule.c'])

setup (name = 'sdnoise',
       platforms='any',
       version = '0.1.0',
       description = 'A Python wrapper for simplex noise functions with analytical derivatives.',
       author = 'Oliver John Hitchcock',
       author_email = 'ojhitchcock@gmail.com',
       url = 'https://github.com/open-terra/pysdnoise/',
       download_url = 'https://github.com/open-terra/pysdnoise/archive/master.zip',
       keywords = ['simplex', 'noise', 'procedural'],
       ext_modules = [sdnoise])
