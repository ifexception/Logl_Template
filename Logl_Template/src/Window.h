#pragma once

#include <string>
#include <SDL.h>

namespace sdl
{

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

class Window
{
public:
    Window() = delete;
    explicit Window(const std::string& title, bool isFullscreen = false);
    ~Window();

    SDL_Window* Get() const;

    void InitOpenGl() const;

private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;

    SDL_Window* m_window;

    void Init(const std::string& title, bool isFullscreen);
    uint32_t ToggleFullscreen(bool isFullscreen) const;
    void SetGlAttributes() const;
};

}
