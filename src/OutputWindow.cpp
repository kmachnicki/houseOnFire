#include "OutputWindow.hpp"

OutputWindow::OutputWindow()
    : m_screen(Coords(0,0))
{
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(FALSE);
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
    refresh();

    getmaxyx(stdscr, m_screen.y, m_screen.x);
    m_firefightersWindow.window = newwin(m_screen.y / 2, (m_screen.x / 3), 0, 0);
    m_arsonistsWindow.window = newwin(m_screen.y / 2, (m_screen.x / 3), 0, (m_screen.x / 3));
    m_houseWindow.window = newwin(m_screen.y / 2, (m_screen.x / 3), 0,
            (m_screen.x / 3) + (m_screen.x / 3));

    mvwprintw(m_firefightersWindow.window, 0, 0, "Firefighters");
    mvwprintw(m_arsonistsWindow.window, 0, 0, "Arsonists");
    mvwprintw(m_houseWindow.window, 0, 0, "House");

    wrefresh(m_firefightersWindow.window);
    wrefresh(m_arsonistsWindow.window);
    wrefresh(m_houseWindow.window);
}

OutputWindow::~OutputWindow()
{
    endwin();
}

void OutputWindow::refreshFirefighters(std::vector<std::thread> firefighters)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
}

void OutputWindow::refreshArsonists(std::vector<std::thread> arsonists)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
}

void OutputWindow::refreshHouse(unsigned houseFireSize)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
}
