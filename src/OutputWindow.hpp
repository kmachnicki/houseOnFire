#pragma once

#include <ncurses.h>
#include <thread>
#include <mutex>
#include <vector>

struct Window
{
    Window() = default;
    Window(WINDOW* window)
        : window(window)
    {}
    ~Window()
    {
        delwin(window);
    }

    WINDOW* window = nullptr;
};

struct Coords
{
    Coords(unsigned x, unsigned y)
        : x(x), y(y)
    {}
    unsigned x = 0;
    unsigned y = 0;
};

class OutputWindow
{
public:
    OutputWindow();
    virtual ~OutputWindow();

    void refreshFirefighters(std::vector<std::thread> firefighters);
    void refreshArsonists(std::vector<std::thread> arsonists);
    void refreshHouse(unsigned houseFireSize);

private:
    std::mutex m_screenLock;
    Coords m_screen;
    Window m_firefightersWindow;
    Window m_arsonistsWindow;
    Window m_houseWindow;
};
