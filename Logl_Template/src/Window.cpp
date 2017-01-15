#include "Window.h"
#include <iostream>

sdl::Window::Window(const std::string& title, bool isFullscreen)
    : m_x(SDL_WINDOWPOS_CENTERED),
      m_y(SDL_WINDOWPOS_CENTERED),
      m_w(WIDTH),
      m_h(HEIGHT)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error on SDL_Init " << SDL_GetError() << std::endl;
        return;
    }

    Init(title, isFullscreen);
}

sdl::Window::~Window()
{
    if (m_window != nullptr) {
        SDL_DestroyWindow(m_window);
    }
}

SDL_Window* sdl::Window::Get() const
{
    return m_window;
}

void sdl::Window::InitOpenGl() const
{
    auto context = SDL_GL_CreateContext(m_window);
    if (context == nullptr) {
        std::cerr << "Error on SDL_GL_CreateContext " << SDL_GetError()
                  << std::endl;
        SDL_Quit();
        return;
    }

    SetGlAttributes();
}

void sdl::Window::Init(const std::string& title, bool isFullscreen)
{
    auto flags = ToggleFullscreen(isFullscreen);

    m_window = SDL_CreateWindow(title.c_str(), m_x, m_y, m_w, m_h, flags);
    if (m_window == nullptr) {
        std::cerr << "Error on SDL_CreateWindow " << SDL_GetError()
                  << std::endl;
        SDL_Quit();
        return;
    }
}

uint32_t sdl::Window::ToggleFullscreen(bool isFullscreen) const
{
    auto flags = 0;
    if (isFullscreen) {
        flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
    }
    else {
        flags = SDL_WINDOW_OPENGL;
    }

    return flags;
}

void sdl::Window::SetGlAttributes() const
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}
