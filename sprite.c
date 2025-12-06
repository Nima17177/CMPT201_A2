#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>

#ifndef SPRITE_H
        #include "sprite.h"
        #define SPRITE_H
#endif

sprite createPlayer(WINDOW *w)
{
        sprite p;
        p.yPos = 24;
        p.xPos = 41;
        p.yVel = 1;
        p.xVel = 0;
        p.frozen = false;
        p.pixel = ' ';
        p.symbol = 'X';
        mvwaddch(w, p.yPos, p.xPos, p.symbol);
        wrefresh(w);
        return p;
}

sprite createEnemy(WINDOW *w, int c)
{
        sprite e;
        e.yPos = 8;
        e.xPos = 37 + (c*1.5);
        e.yVel = 1;
        e.xVel = 0;
        e.frozen = false;
        e.pixel = ' ';
        e.symbol = 'E';
        mvwaddch(w, e.yPos, e.xPos, e.symbol);
        wrefresh(w);
        return e;
}

sprite moveSprite(WINDOW *w, sprite s)
{
        mvwaddch(w, s.yPos, s.xPos, s.pixel);
        s.yPos = s.yPos + s.yVel;
        s.xPos = s.xPos + s.xVel;
        s.pixel = mvwinch(w, s.yPos, s.xPos);
        mvwaddch(w, s.yPos, s.xPos, s.symbol);
        wrefresh(w);
        return s;
}

sprite changeVel(sprite e)
{
        int randNum = rand() % 2;
        if (e.yVel == 0)
        {
                e.xVel = 0;
                if (randNum == 0)
                {
                        e.yVel = 1;
                }
                else
                {
                        e.yVel = -1;
                }
        }
        else if (e.xVel == 0)
        {
                e.yVel = 0;
                if (randNum == 0)
                {
                        e.xVel = 1;
                }
                else
                {
                        e.xVel = -1;
                }
        }
        return e;
}