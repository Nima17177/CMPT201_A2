#include <ncurses.h>
#include "map.h"

#define MAP_X 80
#define MAP_Y 30

void createMapEasy(WINDOW *w)
{
    wborder(w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    // Title
    mvprintw(2, (MAP_X / 2) - 5, "PAC-MAN");
    
    // Maze layout for easy mode
         mvprintw(7, 20, "+-----------------------------------------+");
         mvprintw(8, 20, "|     |    |    |         |    |    |     |");
         mvprintw(9, 20, "|     |   ---   |   ---   |   ---   |     |");
        mvprintw(10, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(11, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(12, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(13, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(14, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(15, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(16, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(17, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(18, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(19, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(20, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(21, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(22, 20, "|-|       |-|       |-|       |-|       |-|");
        mvprintw(23, 20, "|   |---|     |---|     |---|     |---|   |");
        mvprintw(24, 20, "|     |   ---   |         |   ---   |     |");
        mvprintw(25, 20, "|     |    |    |         |    |    |     |");
        mvprintw(26, 20, "+-----------------------------------------+");

        wrefresh(w);
    refresh();
}