Notes
=====

0) Install a few things
  - g++
  - libXext-devel (libxext-dev on ubuntu)
  - libglew-dev (on ubuntu; not sure of fedora)
  - cmake
  - mercurial (hg)

1) Build SDL2 using autoconf, not cmake, to get sdl2-config.cmake >:|

  ```bash
  hg clone https://hg.libsdl.org/SDL SDL
  cd SDL
  mkdir build
  cd build
  # (if on OSX)
  # sed -ie '/if.*MAC.*1060/,/endif.*MAC.*1060/ d' ../include/SDL_platform.h
  # CC=../build-scripts/gcc-fat.sh ../configure
  ../configure 
  make
  sudo make install
  ```

2) Build the project

  ```bash
  git clone https://github.com/d--/butts
  cd butts
  mkdir build
  cd build
  cmake ..
  make
  ```

3) Run `./butts`
