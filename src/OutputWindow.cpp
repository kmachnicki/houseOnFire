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
    m_resourcesWindow.window = newwin(m_screen.y / 2, m_screen.x, m_screen.y / 2, 0);

    mvwprintw(m_firefightersWindow.window, 0, 0, "Firefighters");
    mvwprintw(m_arsonistsWindow.window, 0, 0, "Arsonists");
    mvwprintw(m_houseWindow.window, 0, 0, "House");
    mvwprintw(m_resourcesWindow.window, 0, 0, "Resources");

    wrefresh(m_firefightersWindow.window);
    wrefresh(m_arsonistsWindow.window);
    wrefresh(m_houseWindow.window);
    wrefresh(m_resourcesWindow.window);
}

OutputWindow::~OutputWindow()
{
    endwin();
}

void OutputWindow::refreshFirefighters(unsigned id, std::string status)
{
    std::unique_lock<std::mutex> lock(m_screenLock);
    m_firefighters[id] = status;
    std::string message;
    unsigned i = 0;
    for (auto it = m_firefighters.begin(); it != m_firefighters.end(); ++it, ++i)
    {
        message = "ID: " + std::to_string(it->first) + ":  " + it->second;
        move(i + 2, 0);
        wclrtoeol(m_firefightersWindow.window);
        refresh();
        mvwprintw(m_firefightersWindow.window, i + 2, 0, message.c_str());
    }
    wrefresh(m_firefightersWindow.window);
}

void OutputWindow::refreshArsonists(unsigned id, std::string status)
{
    std::unique_lock<std::mutex> lock(m_screenLock);
    m_arsonists[id] = status;
    std::string message;
    unsigned i = 0;
    for (auto it = m_arsonists.begin(); it != m_arsonists.end(); ++it, ++i)
    {
        message = "ID: " + std::to_string(it->first) + ": " + it->second;
        move(i + 2, 0);
        wclrtoeol(m_arsonistsWindow.window);
        refresh();
        mvwprintw(m_arsonistsWindow.window, i + 2, 0, message.c_str());
    }
    wrefresh(m_arsonistsWindow.window);
}

void OutputWindow::refreshResources(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
                                    unsigned numOfMatches, unsigned numOfFuel)
{
    std::unique_lock<std::mutex> lock(m_screenLock);
    std::string message;
    message = "Hatches: " + std::to_string(numOfHatchets) + " Firehoses: " + std::to_string(numOfFirehoses)
            + " Helmets: " + std::to_string(numOfHelmets) + " Matches: " + std::to_string(numOfMatches)
            + " Fuel: " + std::to_string(numOfFuel);
    move(2, 0);
    wclrtoeol(m_resourcesWindow.window);
    refresh();
    mvwprintw(m_resourcesWindow.window, 2, 0, message.c_str());
    wrefresh(m_resourcesWindow.window);
}

void OutputWindow::refreshHouse(unsigned houseFireSize)
{
    std::unique_lock<std::mutex> lock(m_screenLock);
    std::string message;
    message = "Destruction level: " + std::to_string(houseFireSize) + "%";
    move(2, 0);
    wclrtoeol(m_houseWindow.window);
    refresh();
    mvwprintw(m_houseWindow.window, 2, 0, message.c_str());
    wrefresh(m_houseWindow.window);
}
