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
        return 1;
    }

    int width, height;
    window.GetWindowSize(width, height);
    glViewport(0, 0, width, height);

    auto running = true;
    while (running) {
        window.PollEvents(running);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.SwapWindow();
    }

    return 0;
}
