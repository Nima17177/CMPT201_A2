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
} Player;

typedef struct
{
        int xPos;
        int yPos;
        int xVel;
        int yVel;
        char symbol;
} Enemy;


Player createPlayer()
{
        Player p;
        p.y = 25;
        p.x = 10;
        p.symbol = 'P';
        return p;
}

Enemy createEnemy()
{
        Enemy e;
        e.yPos = 20;
        e.xPos = 10;
        e.yVel = -1;
        e.xVel = 0;
        e.symbol = 'E';
        return e;
}



Player movePlayer(Player p, int yVel, int xVel)
{
        mvaddch(p.y, p.x, ' ');
        p.y = p.y + yVel;
        p.x = p.x + xVel;
        mvaddch(p.y, p.x, p.symbol);
        refresh();
        return p;
}

Enemy moveEnemy(Enemy e)
{
        mvaddch(e.yPos, e.xPos, ' ');
        e.yPos = e.yPos + e.yVel;
        e.xPos = e.xPos + e.xVel;
        mvaddch(e.yPos, e.xPos, e.symbol);
        refresh();
        return e;
}

int main(){

        WINDOW *w;
        int ch;
        Player p;
        Enemy e;
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

        p = createPlayer();
        e = createEnemy();
        mvaddch(p.y, p.x, p.symbol);
        mvaddch(e.yPos, e.xPos, e.symbol);

        keypad(stdscr, TRUE);
        refresh();
        /* Direction checking:
           KEY_RIGHT
           KEY_UP
           KEY_DOWN
           KEY_LEFT
        */

        time_t lastmove = time(NULL);
        nodelay(stdscr, TRUE);

        while (1)
        {
                ch = getch();
                if (ch != ERR) // If key has been pressed.
                {
                        if (ch == KEY_RIGHT)
                        {
                                if (mvinch(p.y, p.x+1) == ' ') // There is an empty spot to the right, so player can move.
                                {
                                        p = movePlayer(p, 0, 1);
                                }
                        }
                        else if (ch == KEY_LEFT)
                        {
                                if (mvinch(p.y, p.x-1) == ' ') // There is an empty spot to the right, so player can move.
                                {
                                        p = movePlayer(p, 0, -1);
                                }
                        }
                        else if (ch == KEY_UP)
                        {
                                if (mvinch(p.y-1, p.x) == ' ') // There is an empty spot to the right, so player can move.
                                {
                                        p = movePlayer(p, -1, 0);
                                }
                        }
                        else if (ch == KEY_DOWN)
                        {
                                if (mvinch(p.y+1, p.x) == ' ') // There is an empty spot to the right, so player can move.
                                {
                                        p = movePlayer(p, 1, 0);
                                }
                        }

                }
                if (time(NULL) - lastmove >= 0.5)
                {
                        e = moveEnemy(e);
                        if (e.yPos == 15 && e.yVel == -1)
                        {
                                e.yVel = 0;
                                e.xVel = 1;
                        }
                        else if (e.xPos == 15 && e.xVel == 1)
                        {
                                e.yVel = 1;
                                e.xVel = 0;
                        }
                        else if (e.yPos == 20 && e.yVel == 1)
                        {
                                e.yVel = 0;
                                e.xVel = -1;
                        }
                        else if (e.xPos == 10 && e.xVel == -1)
                        {
                                e.yVel = -1;
                                e.xVel = 0;
                        }
                        lastmove = time(NULL);
                        move(30, 30);
                        printw("x = %d, y = %d\n", e.xPos, e.yPos);
                        move(e.yPos, e.xPos);
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