#include <ncurses.h>
#include "map.h"

#define MAP_X 80
#define MAP_Y 30

void createMapEasy(WINDOW *w)
{
    //wborder(w, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

    /*int top_y = MAP_Y /4;
    int buttom_y = MAP_Y *3/4;
    int left_x = MAP_X /4;
    int right_x = MAP_X *3/4;
    \'-'


    mvwaddch(w, top_y, left_x, ACS_ULCORNER); // left top corner
    mvwaddch(w, top_y, right_x, ACS_URCORNER); // right top corner
    mvwaddch(w, buttom_y, left_x, ACS_LLCORNER); // left bottom corner
    mvwaddch(w, buttom_y, right_x, ACS_LRCORNER); // right bottom corner
    */
    char line[45];
        int x = 1;
        int y = 1;
        FILE *f = fopen("EasyMap.txt", "r");
        for (int i = 0; i < 19; i++)
        {
                fgets(line, 44, f);
                mvwprintw(w, y++, x, "%s", line);
                fgetc(f);
        }
        fclose(f);
        wrefresh(w);
    refresh();
}