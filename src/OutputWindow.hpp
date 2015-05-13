#pragma once

#include <ncurses.h>
#include <thread>
#include <mutex>
#include <map>
#include <sstream>

class Firefighter;
class Arsonist;

#define Screen OutputWindow::get()

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
    static OutputWindow& get();
    void refreshFirefighters(unsigned id, std::string status);
    void refreshArsonists(unsigned id, std::string status);
    void refreshHouse(unsigned houseFireSize);

private:
    OutputWindow();
    virtual ~OutputWindow();
    OutputWindow(OutputWindow&&) = delete;
    OutputWindow(const OutputWindow&) = delete;
    OutputWindow& operator=(OutputWindow&) = delete;

    static OutputWindow* m_instance;

    std::map<unsigned, std::string> m_firefighters;
    std::map<unsigned, std::string> m_arsonists;
    mutable std::mutex m_screenLock;
    Coords m_screen;
    Window m_firefightersWindow;
    Window m_arsonistsWindow;
    Window m_houseWindow;
};
