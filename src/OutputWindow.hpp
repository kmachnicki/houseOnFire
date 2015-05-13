#pragma once

#include <ncurses.h>
#include <mutex>

struct Window
{
    Window() = default;
    Window(WINDOW* w)
            : w_(w)
    {
    }
    ~Window()
    {
        delwin(w_);
    }

    WINDOW* w_ = nullptr;
};

struct Coords
{
    Coords(unsigned x, unsigned y)
        : x(x), y(y) {}
    unsigned x = 0;
    unsigned y = 0;
};

class OutputWindow
{
public:
    OutputWindow();
    virtual ~OutputWindow();

    void refreshFirefighters();
    void refreshArsonists();
    void refreshHouse();

private:
    std::mutex m_screenLock;
    Coords m_screen;
    Window m_firefightersWindow;
    Window m_arsonistsWindow;
    Window m_houseWindow;
};
