#include <iostream>
#include "SDL.h"

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Quit();
        return 1;
    }
    std::cout << "Hello, butts!" << std::endl;
    SDL_Quit();
    return 0;
}
