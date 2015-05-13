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
    m_firefightersWindow.w_ = newwin(m_screen.y / 2, (m_screen.x / 3), 0, 0);
    m_arsonistsWindow.w_ = newwin(m_screen.y / 2, (m_screen.x / 3), 0, (m_screen.x / 3));
    m_houseWindow.w_ = newwin(m_screen.y / 2, (m_screen.x / 3), 0,
            (m_screen.x / 3) + (m_screen.x / 3));

    mvwprintw(m_firefightersWindow.w_, 0, 0, "Firefighters");
    mvwprintw(m_arsonistsWindow.w_, 0, 0, "Arsonists");
    mvwprintw(m_houseWindow.w_, 0, 0, "House");

    wrefresh(m_firefightersWindow.w_);
    wrefresh(m_arsonistsWindow.w_);
    wrefresh(m_houseWindow.w_);
}

OutputWindow::~OutputWindow()
{
    endwin();
}
