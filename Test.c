#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

/* struct representing each part of the player*/
typedef struct
{
        int x;
        int y;
        char symbol;
} Character;


/* Create a player and set starting position at (10, 25)*/
Character createCharacter(char symbol)
{
        Character p;
        p.x = 10;
        p.y = 25;
        p.symbol = symbol;
        return p;
}

/* Draw a player on the screen */
void drawCharacter(Character p)
{
        mvaddch(p.y, p.x, p.symbol);
        refresh();
}

/* Function that takes care of the player moving right*/
/* Moving consists of undrawing the player at current
   position (undrawing meaning setting those positions
   to a space) and redrawing the player at the next
   position.
*/

Character moveRight(Character p)
{
        mvaddch(p.y, p.x, ' ');
        mvaddch(p.y, p.x+1, p.symbol);
        p.x = p.x+1;
        refresh();
        return p;
}

Character moveUp(Character p)
{
        mvaddch(p.y, p.x, ' ');
        mvaddch(p.y-1, p.x, p.symbol);
        p.y = p.y-1;
        refresh();
        return p;
}

int main(){

        WINDOW *w;
        Character p;
        int ch;
        //initialize ncurses
        initscr();

        //add no echo so that entered keys are not printed to the screen
        noecho();

        //height, width, start_y, start_x
        w = newwin(30,30, 1, 1);

        //any window creation or  box plot must be followed by a refresh for changes
        //to take effect
        refresh();

        /*
       use wborder to specify:
       left, right, top, bottom borders
       top left, top right, bottom left, bottom right corners
    */

        wborder(w,'|','|','-','-','+','+','+','+');
        wrefresh(w);
        char h='|';

        /* These are placed here since the above border is not recognized
           by mvinch. This is done so the check in the while loop for
           the border will work
        */

        mvprintw(25,30,"%c",h);
        mvprintw(26,30,"%c",h);
        mvprintw(27,30,"%c",h);

        p=createCharacter('P');

        drawCharacter(p);

        keypad(stdscr, TRUE);
        ch=getch();
        refresh();

        /* Direction checking:
           KEY_UP
           KEY_DOWN
           KEY_LEFT
        */
        Character e = createCharacter('E');
        drawCharacter(e);
        time_t lastmove = time(NULL);
        nodelay(stdscr, TRUE);
        while (1){
                ch = getch();
                if (ch != ERR)
                {
                        if (ch == KEY_RIGHT){
                                //check to see if the player can advance
                                //i.e. is there an empty space
                                if (mvinch(p.y, p.x+1) == ' ')
                                        p = moveRight(p);
                        }

                }
                if (time(NULL) - lastmove >= 0.5)
                {
                        e = moveUp(e);
                        lastmove = time(NULL);
                }
                else if (ch == 'q'){
                        break;
                }
                 refresh();
                 napms(20);
        //       sleep(3);
        }

        //follow with a getch (get a single keystroke from the user)
    //otherwise you will not see any change on the screen
        getch();
        endwin();

        return 0;
}