#include <SDL.h>
#include <GL/glew.h>

void render() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Could not init SDL: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    Uint32 flags;
    flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

    SDL_Window *window;
    window = SDL_CreateWindow(
        "Butts",                    // title
        SDL_WINDOWPOS_UNDEFINED,    // x
        SDL_WINDOWPOS_UNDEFINED,    // y
        400,                        // w
        400,                        // 
        flags                       // flags
    );
    
    if (window == NULL) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext gl = SDL_GL_CreateContext(window);
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        SDL_Log("Error: %s\n", glewGetErrorString(err));
    }

    SDL_Event event;

    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        render();
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(gl);
    SDL_Quit();
    return 0;
}
