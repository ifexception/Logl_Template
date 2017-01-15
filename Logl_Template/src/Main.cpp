#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include "Window.h"

int main(int argc, char* argv[])
{
    sdl::Window window("Learn OpenGL");
    window.InitOpenGl();

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error on glewInit " << std::endl;
        return 4;
    }

    int width, height;
    SDL_GetWindowSize(window.Get(), &width, &height);
    glViewport(0, 0, width, height);

    auto running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window.Get());
    }

    return 0;
}
