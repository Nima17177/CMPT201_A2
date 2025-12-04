#include "map.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define MAXY 30
#define MAXX 80

void readFile(FILE *f)
{
        float yf, xf, sf;
        int yi, xi, si;
        while (fscanf(f, "%f, %f, %f\n", &yf, &xf, &sf) == 3)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                si = sf * MAXX;
                mvhline(yi, xi, ACS_HLINE, si);
        }
        fgetc(f); // Consume line between coordinate sets.
        while (fscanf(f, "%f, %f, %f\n", &yf, &xf, &sf) == 3)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                si = sf * MAXY;
                mvvline(yi, xi, ACS_VLINE, si);
        }
        fgetc(f);
        while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                mvaddch(yi, xi, ACS_ULCORNER);
        }
        fgetc(f);
        while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                mvaddch(yi, xi, ACS_LLCORNER);
        }
        fgetc(f);
        while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                mvaddch(yi, xi, ACS_LRCORNER);
        }
        fgetc(f);
        while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
        {
                yi = yf * MAXY;
                xi = xf * MAXX;
                mvaddch(yi, xi, ACS_URCORNER);
        }
        fgetc(f);
}

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
        FILE *f = fopen("splashpage.txt", "r");
                // MAC
                attron(COLOR_PAIR(3));
                readFile(f);
                // PAN
                attron(COLOR_PAIR(1));
                readFile(f);
        fclose(f);
        attron(COLOR_PAIR(6));
        // -
        mvaddch((int)(0.2*MAXY), (int)(0.475*MAXX), ACS_ULCORNER);
        mvaddch((int)(0.234*MAXY), (int)(0.475*MAXX), ACS_LLCORNER);
        mvhline((int)(0.234*MAXY), (int)(0.4875*MAXX), ACS_HLINE, (int)(0.0375*MAXX));
        mvaddch((int)(0.234*MAXY), (int)(0.525*MAXX), ACS_LRCORNER);
        mvaddch((int)(0.2*MAXY), (int)(0.525*MAXX), ACS_URCORNER);
        mvhline((int)(0.2*MAXY), (int)(0.4875*MAXX), ACS_HLINE, (int)(0.0375*MAXX));
        attron(COLOR_PAIR(5));
        char *message[] = {"(not Pac-Man)", "Nathan Alex Sequeira (3141620)", "Nima Houshyar (xxxxxxx)", "Controls", "Use <arrows> to move player", "Press <space> to activate portal", "After collecting a powerup, press <1> or <2> to freeze half of the enemies", "Press <E> to start easy", "Press <H> to start hard"};
        int y, x;
        attron(COLOR_PAIR(5));
        y = 0.367 * MAXY;
        x = (MAXX/2) - (strlen(message[0])/2);
        mvprintw(y, x, "%s", message[0]);
        y = 0.467 * MAXY;
        x = (MAXX/2) - (strlen(message[1])/2);
        mvprintw(y, x, "%s", message[1]);
        y = 0.5 * MAXY;
        x = (MAXX/2) - (strlen(message[2])/2);
        mvprintw(y, x, "%s", message[2]);
        attron(COLOR_PAIR(2));
        y = 0.634 * MAXY;
        x = (MAXX/2) - (strlen(message[3])/2);
        mvprintw(y, x, "%s", message[3]);
        y = 0.67 * MAXY;
        x = (MAXX/2) - (strlen(message[4])/2);
        mvprintw(y, x, "%s", message[4]);
        y = 0.7 * MAXY;
        x = (MAXX/2) - (strlen(message[5])/2);
        mvprintw(y, x, "%s", message[5]);
        y = 0.734 * MAXY;
        x = (MAXX/2) - (strlen(message[6])/2);
        mvprintw(y, x, "%s", message[6]);
        attron(COLOR_PAIR(7));
        y = 0.867 * MAXY;
        x = (MAXX/2) - (strlen(message[7])/2);
        mvprintw(y, x, "%s", message[7]);
        y = 0.9 * MAXY;
        x = (MAXX/2) - (strlen(message[8])/2);
        mvprintw(y, x, "%s", message[8]);
        wrefresh(w);
        refresh();
}

int main(void)
{
        WINDOW *w;
        initscr(); // Initialize window
        noecho(); // Entered keys are not printed on the screen.
        //curs_set(FALSE); // Don't display a cursor
        w = newwin(MAXY, MAXX, 1, 1); // Window size
        box(w, 0, 0); // Default border to window.
        wrefresh(w);
        refresh();
        //splashPage(w);
        /*while (1)
        {
                char c = getch();
                if (c == 'e')
                {
                        createLevelEasy(w);
                        break;
                }
                else if (c == 'h')
                {
                        createLevelHard(w);
                        break;
                }
        }*/
        createMapEasy(w);
        getch();
        endwin();
        return 0;
}