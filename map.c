#include <ncurses.h>
#include "map.h"

#define MAP_X 80
#define MAP_Y 30

void createMapEasy(WINDOW *w)
{
    wborder(w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    // Title
    mvwprintw(w, 2, (MAP_X / 2) - 5, "PAC-MAN");
    
    // Maze layout for easy mod9                                       49
         mvwprintw(w, 7, 20, "+-----------------------------------------+");
         mvwprintw(w, 8, 20, "|O    |    |    |         |    |    |    O|");
         mvwprintw(w, 9, 20, "|     |   ---   |   ---   |   ---   |     |");
        mvwprintw(w, 10, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 11, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 12, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 13, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 14, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 15, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 16, 20, "|P  |---|     |---|     |---|     |---|  P|");
        mvwprintw(w, 17, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 18, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 19, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 20, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 21, 20, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 22, 20, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 23, 20, "|     |   ---   |         |   ---   |     |");
        mvwprintw(w, 24, 20, "|O    |    |    |         |    |    |    O|");
        mvwprintw(w, 25, 20, "+-----------------------------------------+");

        wrefresh(w);
    refresh();
}

bool isWall(WINDOW *w, int y, int x) {
    if (mvwinch(w, y, x) == '|') return true;
    if (mvwinch(w, y, x) == '-') return true;
    if (mvwinch(w, y, x) == '+') return true;
    return false;
}

void isPortal(WINDOW *w, int *y, int *x) 
{
    if (mvwinch(w, *y, *x) == 'O')
    {
        if (*y == 8 && *x == 21) {
            *y = 24;
            *x = 49;
        } 
        else if (*y == 24 && *x == 49) {
            *y = 8;
            *x = 21;
        }
        else if (*y == 8 && *x == 49) {
            *y = 24;
            *x = 21;
        }
        else if (*y == 24 && *x == 21) {
            *y = 8;
            *x = 49;
        }

    }
    else {
        *y = -1;
        *x = -1;
    }
}

bool isPower(WINDOW *w, int y, int x) 
{
    if (mvwinch(w, y, x) == 'P') 
    {
        mvwaddch(w, y, x, ' ');
        return true;
    }
    return false;
}