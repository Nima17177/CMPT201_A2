#include <ncurses.h>
#include "map.h"

#define MAP_X 80
#define MAP_Y 30

void createMapEasy(WINDOW *w)
{
    wborder(w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    // Title
    createMapUi(w);
    
    // Maze layout for easy mod9                                       49
         mvwprintw(w, 7, 18, "+-----------------------------------------+");
         mvwprintw(w, 8, 18, "|O    |    |    |         |    |    |    O|");
         mvwprintw(w, 9, 18, "|     |   ---   |   ---   |   ---   |     |");
        mvwprintw(w, 10, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 11, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 12, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 13, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 14, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 15, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 16, 18, "|P  |---|     |---|     |---|     |---|  P|");
        mvwprintw(w, 17, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 18, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 19, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 20, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 21, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 22, 18, "|   |---|     |---|     |---|     |---|   |");
        mvwprintw(w, 23, 18, "|     |   ---   |         |   ---   |     |");
        mvwprintw(w, 24, 18, "|O    |    |    |         |    |    |    O|");
        mvwprintw(w, 25, 18, "+-----------------------------------------+");
        status(w, 3, 5);
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
    //if (mvwinch(w, *y, *x) == 'O')
    //{
        if (*y == 8 && *x == 19) {
            *y = 24;
            *x = 59;
        }
        else if (*y == 24 && *x == 59) {
            *y = 8;
            *x = 19;
        }
        else if (*y == 8 && *x == 59) {
            *y = 24;
            *x = 19;
        }
        else if (*y == 24 && *x == 19) {
            *y = 8;
            *x = 59;
        }

    //}
    else {
        *y = -1;
        *x = -1;
    }
}

bool isPower(WINDOW *w, char c)
{
    if (c == 'P')
    {
        //mvwaddch(w, y, x, ' ');
        //wrefresh(w);
        return true;
    }
    return false;
}

void createMapUi(WINDOW *w)
{   
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, 2, (MAP_X / 2) - 5, "PAC-MAN");
    // "Controls", "Use <arrows> to move player", "Press <space> to activate portal", "After collecting a powerup, press <1> or <2> to freeze half of the enemies"
    //mvwprintw(w, 5,  
    wattroff(w, COLOR_PAIR(4));
    wrefresh(w);
}

void status(WINDOW *w, int lives, int enemies)
{   
    wattron(w, COLOR_PAIR(6));
    mvwprintw(w, 1, 8, "Lives: %d  ", lives);
    mvwprintw(w, 1, 62, "Enemies: %d  ", enemies);
    wattroff(w, COLOR_PAIR(6));
    wrefresh(w);
}


void decrementLives(WINDOW *w, int *lives)
{   
    if (*lives > 0) {
        (*lives)--;
    }
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, 1, MAP_X - 15, "Lives: %d  ", *lives);
    wattroff(w, COLOR_PAIR(4));
    wrefresh(w);
}
void decrementEnemies(WINDOW *w, int *enemies)
{   
    if (*enemies > 0) {
        (*enemies)--;
    }
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, 1, MAP_X / 2 + 10, "Enemies: %d  ", *enemies);
    wattroff(w, COLOR_PAIR(4));
    wrefresh(w);
}