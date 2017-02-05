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

    void InitOpenGl() const;
    void GetWindowSize(int& width, int& height) const;
    void SwapWindow() const;

    void PollEvents(bool& running) const;

private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;

    SDL_Window* m_window;

    void Init(const std::string& title, bool isFullscreen);
    uint32_t ToggleFullscreen(bool isFullscreen) const;
    void SetOpenGlAttrib() const;
};

}
