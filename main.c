//#define "levels.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void splashPage(WINDOW *w)
{
        box(w, 0, 0);
         mvprintw(2, 2, "  --------------   ----------   --------     --------   ----------   ---------");
         mvprintw(3, 2, " |              | |   ----   | |        |   |   ---  | |   ----   | |         ");
         mvprintw(4, 2, " |   --    --   | |  |    |  | |   -----    |  |   | | |  |    |  | |         ");
         mvprintw(5, 2, " |  |  |  |  |  | |  |    |  | |  |         |   ---  | |  |    |  | |  || |   ");
         mvprintw(6, 2, " |  |  |  |  |  | |   ----   | |  |    ---  |   -----  |   ----   | |  || |   ");
         mvprintw(7, 2, " |  |  |  |  |  | |   ----   | |  |    ---  |  |       |   ----   | |  || |   ");
         mvprintw(8, 2, " |  |  |  |  |  | |  |    |  | |   -----    |  |       |  |    |  | |  || |   ");
         mvprintw(9, 2, " |  |  |  |  |  | |  |    |  | |        |   |  |       |  |    |  |    || |   ");
        mvprintw(10, 2, "  --    --   --    --      --   --------     --         --      --   --       ");
        mvprintw(11, 2, "                                                                              ");
        mvprintw(12, 2, "                                                                              ");
        mvprintw(13, 2, "                                                                              ");
        mvprintw(14, 2, "                                  (not Pac-Man)                               ");
        mvprintw(15, 2, "                                                                              ");
        mvprintw(16, 2, "                         Nathan Alex Sequeira (3141620)                       ");
        mvprintw(17, 2, "                             Nima Houshyar (xxxxxxx)                          ");
        mvprintw(18, 2, "                                                                              ");
        mvprintw(19, 2, "                                                                              ");
        mvprintw(20, 2, "                                                                              ");
        mvprintw(21, 2, "                                                                              ");
        mvprintw(22, 2, "                                Controls                                      ");
        mvprintw(23, 2, "                                                                              ");
        mvprintw(24, 2, "                                                                              ");
        mvprintw(25, 2, "                                                                              ");
        mvprintw(26, 2, "                        Press <1> to start easy.                              ");
        mvprintw(27, 2, "                                                                              ");
        mvprintw(28, 2, "                        Press <2> to start hard.                              ");
        mvprintw(29, 2, "                                                                              ");
        wrefresh(w);
        refresh();
}

int main(void)
{
        WINDOW *w;
        initscr(); // Initialize window
        noecho(); // Entered keys are not printed on the screen.
        curs_set(FALSE); // Don't display a cursor
        w = newwin(30, 80, 1, 1);
        box(w, 0, 0); // Default border to window.
        wrefresh(w);
        refresh();
        splashPage(w);
        // Call level.
        getch();
        endwin();
        return 0;
}