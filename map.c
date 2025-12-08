#include <ncurses.h>
#include "map.h"
#include <string.h>

#define MAP_X 80
#define MAP_Y 30

void createMapEasy(WINDOW *w)
{
    wborder(w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    createMapUi(w);
    
    // Maze layout for easy mod9                                       49
         mvwprintw(w, 7, 18, "+-----------------------------------------+");
         mvwprintw(w, 8, 18, "|O    |    |    |         |    |    |    O|");
         mvwprintw(w, 9, 18, "|     |   ---   |   ---   |   ---   |     |");
        mvwprintw(w, 10, 18, "|                                         |");
        mvwprintw(w, 11, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 12, 18, "|                                         |");
        mvwprintw(w, 13, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 14, 18, "|                                         |");
        mvwprintw(w, 15, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 16, 18, "|P                                       P|");
        mvwprintw(w, 17, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 18, 18, "|                                         |");
        mvwprintw(w, 19, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 20, 18, "|                                         |");
        mvwprintw(w, 21, 18, "|-|       |-|       |-|       |-|       |-|");
        mvwprintw(w, 22, 18, "|                                         |");
        mvwprintw(w, 23, 18, "|     |   ---   |         |   ---   |     |");
        mvwprintw(w, 24, 18, "|O    |    |    |         |    |    |    O|");
        mvwprintw(w, 25, 18, "+-----------------------------------------+");
        wrefresh(w);
    refresh();
}

void createMapHard(WINDOW *w)
{
    //        
         mvwprintw(w, 7, 18, "+-----------------------------------------+");
         mvwprintw(w, 8, 18, "|O    |    |                   |    |    O|");
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
}

bool isPower(WINDOW *w, char c)
{
    if (c == 'P') {
        return true;
    }
    return false;
}

void createMapUi(WINDOW *w)
{   
    // Title
    char *t1 = "M  A  C";
    char *t2 = "P  A  N";
    char *dash = "  -  ";
    int len = strlen(t1) + strlen(t2) + strlen(dash);
    int startx = (MAP_X - len) / 2;
    wattron(w, COLOR_PAIR(3));
    mvwprintw(w, 2, startx, "%s", t1);
    wattroff(w, COLOR_PAIR(3));
    mvwprintw(w, 2, startx + strlen(t1), "%s", dash);
    wattron(w, COLOR_PAIR(1));
    mvwprintw(w, 2, startx + strlen(t1) + strlen(dash), "%s", t2);
    wattroff(w, COLOR_PAIR(1));

    //Instructions
    char *toWin = "To win you must freeze the enemey and eat them";
    int len1 = strlen(toWin);
    int startx2 = (MAP_X - len1) / 2;
    wattron(w, COLOR_PAIR(5));
    mvwprintw(w, 4, startx2, "%s", toWin);
    wattroff(w, COLOR_PAIR(5));
    wattron(w, COLOR_PAIR(2));
    mvwprintw(w, 6, 17, " <P> to Pause/Resume");
    mvwprintw(w, 6, 49, " <Q> to Quit");
    mvwprintw(w, 26, 27, "Use <arrows> to move player"); 
    mvwprintw(w, 27, 24, "Press <space> to activate portal");
    mvwprintw(w, 28, 3, "After collecting a powerup, press <1> or <2> to freeze half of the enemies");
    wattroff(w, COLOR_PAIR(2));
    vines(w);

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
    (*lives)--;
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, 1, 8, "Lives: %d  ", *lives);
    wattroff(w, COLOR_PAIR(4));
    wrefresh(w);
}
void decrementEnemies(WINDOW *w, int *enemies)
{   
    (*enemies)--;
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, 1, 62, "Enemies: %d  ", *enemies);
    wattroff(w, COLOR_PAIR(4));
    wrefresh(w);
}

void gameDone(WINDOW *w, int x)
{
        if (x == 2)
        {
                mvwprintw(w, 20, 20, "WINNER");
                starFall(w);
        }
        else if (x == 1)
        {
                mvwprintw(w, 20, 20, "LOSER");

        }
        else
        {
                mvwprintw(w, 20, 20, "QUIT");
                createMapUi(w);
                starFall(w);
                quitScreen(w);
        }
        wrefresh(w);
}
void vines(WINDOW *w)
{
    mvwaddch(w, 10, 4, ACS_ULCORNER);
    mvwaddch(w, 11, 4, ACS_URCORNER); 
}
void quitScreen(WINDOW *w)
{
   mvwprintw(w, 15, 15, "  |||||||    ||      ||   ||	||||||||||||");
   mvwprintw(w, 16, 15, "||       ||  ||      ||   ||  	     ||");
   mvwprintw(w, 17, 15, "||       ||  ||      ||   ||        ||");
   mvwprintw(w, 18, 15, "||       ||  ||      ||   ||        ||");
   mvwprintw(w, 19, 15, " ||||||||||  ||      ||   ||        ||");
   mvwprintw(w, 20, 15, "	      ||   ||    ||    ||        ||");
   mvwprintw(w, 21, 15, "	      ||     ||||      ||        ||");
   wrefresh(w);
}
void starFall(WINDOW *w)
{
    int y = 1;
    while (y < MAP_Y - 1)
    {
        for (int x =1; x < MAP_X -1; x++)
        {   
            if (y > 1)
            {
                mvwaddch(w, y -1, x, ' ');
            }
             mvwaddch(w, y, x, '*');
        }
        wrefresh(w);
        napms(100);
        y++;
    }
    wrefresh(w);
}
