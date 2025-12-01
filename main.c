//#define "levels.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void splashPage(WINDOW *w)
{
        box(w, 0, 0);
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

        attron(COLOR_PAIR(3));

        // M
        mvaddch(2, 2, ACS_ULCORNER);
        mvvline(3, 2, ACS_VLINE, 7);
        mvaddch(10, 2, ACS_LLCORNER);
        mvhline(10, 3, ACS_HLINE, 2);
        mvaddch(10, 5, ACS_LRCORNER);
        mvvline(5, 5, ACS_VLINE, 5);
        mvaddch(4, 5, ACS_ULCORNER);
        mvhline(4, 6, ACS_HLINE, 2);
        mvaddch(4, 8, ACS_URCORNER);
        mvvline(5, 8, ACS_VLINE, 5);
        mvaddch(10, 8, ACS_LLCORNER);
        mvhline(10, 9, ACS_HLINE, 2);
        mvaddch(10, 11, ACS_LRCORNER);
        mvvline(5, 11, ACS_VLINE, 5);
        mvaddch(4, 11, ACS_ULCORNER);
        mvhline(4, 12, ACS_HLINE, 2);
        mvaddch(4, 14, ACS_URCORNER);
        mvvline(5, 14, ACS_VLINE, 5);
        mvaddch(10, 14, ACS_LLCORNER);
        mvhline(10, 15, ACS_HLINE, 2);
        mvaddch(10, 17, ACS_LRCORNER);
        mvvline(3, 17, ACS_VLINE, 7);
        mvaddch(2, 17, ACS_URCORNER);
        mvhline(2, 3, ACS_HLINE, 14);

        // A
        mvaddch(2, 19, ACS_ULCORNER);
        mvvline(3, 19, ACS_VLINE, 7);
        mvaddch(10, 19, ACS_LLCORNER);
        mvhline(10, 20, ACS_HLINE, 2);
        mvaddch(10, 22, ACS_LRCORNER);
        mvvline(8, 22, ACS_VLINE, 2);
        mvaddch(7, 22, ACS_ULCORNER);
        mvhline(7, 23, ACS_HLINE, 4);
        mvaddch(7, 27, ACS_URCORNER);
        mvvline(8, 27, ACS_VLINE, 2);
        mvaddch(10, 27, ACS_LLCORNER);
        mvhline(10, 28, ACS_HLINE, 2);
        mvaddch(10, 30, ACS_LRCORNER);
        mvvline(3, 30, ACS_VLINE, 7);
        mvaddch(2, 30, ACS_URCORNER);
        mvhline(2, 20, ACS_HLINE, 10);
        mvaddch(3, 22, ACS_ULCORNER);
        mvvline(4, 22, ACS_VLINE, 2);
        mvaddch(6, 22, ACS_LLCORNER);
        mvhline(6, 23, ACS_HLINE, 4);
        mvaddch(6, 27, ACS_LRCORNER);
        mvvline(4, 27, ACS_VLINE, 2);
        mvaddch(3, 27, ACS_URCORNER);
        mvhline(3, 23, ACS_HLINE, 4);

        // C
        mvaddch(2, 32, ACS_ULCORNER);
        mvvline(3, 32, ACS_VLINE, 7);
        mvaddch(10, 32, ACS_LLCORNER);
        mvhline(10, 33, ACS_HLINE, 8);
        mvaddch(10, 41, ACS_LRCORNER);
        mvvline(9, 41, ACS_VLINE, 1);
        mvaddch(8, 41, ACS_URCORNER);
        mvhline(8, 36, ACS_HLINE, 5);
        mvaddch(8, 35, ACS_LLCORNER);
        mvvline(5, 35, ACS_VLINE, 3);
        mvaddch(4, 35, ACS_ULCORNER);
        mvhline(4, 36, ACS_HLINE, 5);
        mvaddch(4, 41, ACS_LRCORNER);
        mvvline(3, 41, ACS_VLINE, 1);
        mvaddch(2, 41, ACS_URCORNER);
        mvhline(2, 33, ACS_HLINE, 8);

        attron(COLOR_PAIR(6));
        // -
        mvaddch(6, 38, ACS_ULCORNER);
        mvaddch(7, 38, ACS_LLCORNER);
        mvhline(7, 39, ACS_HLINE, 2);
        mvaddch(7, 41, ACS_LRCORNER);
        mvaddch(6, 41, ACS_URCORNER);
        mvhline(6, 39, ACS_HLINE, 2);

        attron(COLOR_PAIR(1));

        // P
        mvaddch(2, 43, ACS_ULCORNER);
        mvvline(3, 43, ACS_VLINE, 7);
        mvaddch(10, 43, ACS_LLCORNER);
        mvhline(10, 44, ACS_HLINE, 2);
        mvaddch(10, 46, ACS_LRCORNER);
        mvvline(7, 46, ACS_VLINE, 3);
        mvaddch(6, 46, ACS_ULCORNER);
        mvhline(6, 47, ACS_HLINE, 5);
        mvaddch(6, 52, ACS_LRCORNER);
        mvvline(3, 52, ACS_VLINE, 3);
        mvaddch(2, 52, ACS_URCORNER);
        mvhline(2, 44, ACS_HLINE, 8);
        mvaddch(3, 46, ACS_ULCORNER);
        mvvline(4, 46, ACS_VLINE, 1);
        mvaddch(5, 46, ACS_LLCORNER);
        mvhline(5, 47, ACS_HLINE, 3);
        mvaddch(5, 50, ACS_LRCORNER);
        mvvline(4, 50, ACS_VLINE, 1);
        mvaddch(3, 50, ACS_URCORNER);
        mvhline(3, 47, ACS_HLINE, 3);

        // A
        mvaddch(2, 54, ACS_ULCORNER);
        mvvline(3, 54, ACS_VLINE, 7);
        mvaddch(10, 54, ACS_LLCORNER);
        mvhline(10, 55, ACS_HLINE, 2);
        mvaddch(10, 57, ACS_LRCORNER);
        mvvline(8, 57, ACS_VLINE, 2);
        mvaddch(7, 57, ACS_ULCORNER);
        mvhline(7, 58, ACS_HLINE, 4);
        mvaddch(7, 62, ACS_URCORNER);
        mvvline(8, 62, ACS_VLINE, 2);
        mvaddch(10, 62, ACS_LLCORNER);
        mvhline(10, 63, ACS_HLINE, 2);
        mvaddch(10, 65, ACS_LRCORNER);
        mvvline(3, 65, ACS_VLINE, 7);
        mvaddch(2, 65, ACS_URCORNER);
        mvhline(2, 55, ACS_HLINE, 10);
        mvaddch(3, 57, ACS_ULCORNER);
        mvvline(4, 57, ACS_VLINE, 2);
        mvaddch(6, 57, ACS_LLCORNER);
        mvhline(6, 58, ACS_HLINE, 4);
        mvaddch(6, 62, ACS_LRCORNER);
        mvvline(4, 62, ACS_VLINE, 2);
        mvaddch(3, 62, ACS_URCORNER);
        mvhline(3, 58, ACS_HLINE, 4);

        // N
        mvaddch(2, 67, ACS_ULCORNER);
        mvvline(3, 67, ACS_VLINE, 7);
        mvaddch(10, 67, ACS_LLCORNER);
        mvhline(10, 68, ACS_HLINE, 2);
        mvaddch(10, 70, ACS_LRCORNER);
        mvvline(6, 70, ACS_VLINE, 4);
        mvaddch(5, 70, ACS_ULCORNER);
        mvaddch(5, 71, ACS_URCORNER);
        mvvline(6, 71, ACS_VLINE, 1);
        mvaddch(7, 71, ACS_LLCORNER);
        mvhline(7, 72, ACS_HLINE, 1);
        mvaddch(7, 73, ACS_URCORNER);
        mvvline(8, 73, ACS_VLINE, 1);
        mvaddch(9, 73, ACS_LLCORNER);
        mvhline(9, 74, ACS_HLINE, 1);
        mvaddch(9, 75, ACS_URCORNER);
        mvaddch(10, 75, ACS_LLCORNER);
        mvhline(10, 76, ACS_HLINE, 3);
        mvaddch(10, 79, ACS_LRCORNER);
        mvvline(3, 79, ACS_VLINE, 7);
        mvaddch(2, 79, ACS_URCORNER);
        mvhline(2, 77, ACS_HLINE, 2);
        mvaddch(2, 76, ACS_ULCORNER);
        mvvline(3, 76, ACS_VLINE, 5);
        mvaddch(7, 76, ACS_LRCORNER);
        mvaddch(7, 75, ACS_LLCORNER);
        mvvline(6, 75, ACS_VLINE, 1);
        mvaddch(5, 75, ACS_URCORNER);
        mvhline(5, 74, ACS_HLINE, 1);
        mvaddch(5, 73, ACS_LLCORNER);
        mvvline(4, 73, ACS_VLINE, 1);
        mvaddch(3, 73, ACS_URCORNER);
        mvhline(3, 72, ACS_HLINE, 1);
        mvaddch(3, 71, ACS_LLCORNER);
        mvaddch(2, 71, ACS_URCORNER);
        mvhline(2, 68, ACS_HLINE, 3);

        attron(COLOR_PAIR(5));
        mvprintw(11, 2, "                            (not Pac-Man)                                     ");
        mvprintw(14, 2, "                     Nathan Alex Sequeira (3141620)                           ");
        mvprintw(15, 2, "                         Nima Houshyar (xxxxxxx)                              ");
        attron(COLOR_PAIR(2));
        mvprintw(19, 2, "                              Controls                                        ");
        mvprintw(20, 2, "                      Use <arrows> to move player                             ");
        mvprintw(21, 2, "                  Press <space> to activate teleporter                        ");
        mvprintw(22, 2, "  After collecting a powerup, press <1> or <2> to freeze half of the enemies  ");
        attron(COLOR_PAIR(7));
        mvprintw(26, 2, "                        Press <E> to start easy.                              ");
        mvprintw(27, 2, "                        Press <H> to start hard.                              ");
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