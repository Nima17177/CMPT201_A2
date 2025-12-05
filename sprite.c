#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>

#ifndef SPRITE_H
        #include "sprite.h"
        #define SPRITE_H
#endif
#ifndef MAP_H
        #include "map.h"
        #define MAP_H
#endif

sprite createPlayer(WINDOW *w)
{
        sprite p;
        p.yPos = 24;
        p.xPos = 41;
        p.yVel = 1;
        p.xVel = 0;
        p.frozen = false;
        p.symbol = 'X';
        mvwaddch(w, p.yPos, p.xPos, p.symbol);
        wrefresh(w);
        return p;
}

sprite createEnemy(char c, WINDOW *w)
{
        sprite e;
        e.yPos = 8;
        e.xPos = 37 + ((int)(c-'0')*1.5);
        e.yVel = 1;
        e.xVel = 0;
        e.symbol = c;
        e.frozen = false;
        mvwaddch(w, e.yPos, e.xPos, e.symbol);
        wrefresh(w);
        return e;
}

sprite moveSprite(sprite s, WINDOW *w)
{
        if ((s.frozen == false) && (isWall(w, s.yPos+s.yVel, s.xPos+s.xVel) == false))
        {
                mvwaddch(w, s.yPos, s.xPos, ' ');
                s.yPos = s.yPos + s.yVel;
                s.xPos = s.xPos + s.xVel;
                mvwaddch(w, s.yPos, s.xPos, s.symbol);
                wrefresh(w);
        }
        return s;
}

sprite checkEnemyVel(sprite e, WINDOW *w)
{
        if (isWall(w, e.yPos+e.yVel, e.xPos+e.xVel) == true)
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
        }
        else
        {
                int randNum0 = rand() % 5;
                if (randNum0 == 0)
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
                }
        }
        return e;
}