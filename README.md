Notes
=====

0) Assuming Ubuntu, install a few things
  - g++
  - libglew-dev
  - libsdl2-dev
  - cmake

1) If on OSX, build SDL2 using autoconf, not cmake, to get sdl2-config.cmake >:|

  ```bash
  hg clone https://hg.libsdl.org/SDL SDL
  cd SDL
  mkdir build
  cd build
  sed -ie '/if.*MAC.*1060/,/endif.*MAC.*1060/ d' ../include/SDL_platform.h
  CC=../build-scripts/gcc-fat.sh ../configure
  make
  sudo make install
  ```
2) If on Windows... good luck.  Read the CMakeLists.txt file :)

3) Build the project

  ```bash
  git clone https://github.com/d--/sdl_starter
  cd sdl_starter
  mkdir build
  cd build
  cmake ..
  make
  ```

