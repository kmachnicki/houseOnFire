#include "OutputWindow.hpp"
#include "Firefighter.hpp"
#include "Arsonist.hpp"

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

void OutputWindow::refreshFirefighters(unsigned id, std::string status)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
    m_firefighters[id] = status;
    std::stringstream message;
    unsigned i = 0;
    for (auto it = m_firefighters.begin(); it != m_firefighters.end(); ++it, ++i)
    {
        message << "ID: " << it->first << " Status: " << it->second;
        move(i + 2, 0);
        clrtoeol();
        refresh();
        mvwprintw(m_firefightersWindow.window, i + 2, 0, message.str().c_str());
    }
    wrefresh(m_firefightersWindow.window);
}

void OutputWindow::refreshArsonists(unsigned id, std::string status)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
    m_arsonists[id] = status;
    std::stringstream message;
    unsigned i = 0;
    for (auto it = m_arsonists.begin(); it != m_arsonists.end(); ++it, ++i)
    {
        message << "ID: " << it->first << " Status: " << it->second;
        move(i + 2, 0);
        clrtoeol();
        refresh();
        mvwprintw(m_arsonistsWindow.window, i + 2, 0, message.str().c_str());
    }
    wrefresh(m_arsonistsWindow.window);
}

void OutputWindow::refreshHouse(unsigned houseFireSize)
{
    std::lock_guard<std::mutex> lock(m_screenLock);
    std::stringstream status;
    status << "Destruction level: " << houseFireSize << "%";
    move(2, 0);
    clrtoeol();
    refresh();
    mvwprintw(m_houseWindow.window, 2, 0, status.str().c_str());
    wrefresh(m_houseWindow.window);
}
