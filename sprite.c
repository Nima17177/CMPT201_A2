#include "sprite.h"

#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>

sprite createPlayer(WINDOW *w, int playerLives)
{
        sprite p;
        p.yPos = 0;
        p.xPos = 0;
        p.yVel = 1;
        p.xVel = 0;
        p.life = playerLives;
        p.tile = ' ';
        p.symbol = 'X';
        return p;
}

sprite createEnemy(WINDOW *w, int c)
{
        sprite e;
        e.yPos = 0;
        e.xPos = 0;
        e.yVel = 1;
        e.xVel = 0;
        e.life = 0;
        e.tile = ' ';
        e.symbol = 'E';
        return e;
}

void resetSprites(WINDOW *w, sprite *player, int enemyCount, sprite *enemies)
{
        mvwaddch(w, player->yPos, player->xPos, ' ');
        player->yPos = 24;
        player->xPos = 40;
        mvwaddch(w, player->yPos, player->xPos, player->symbol);
        for (int i = 0; i < enemyCount; i++)
        {
                if (enemies[i].life != 2)
                {
                        mvwaddch(w, enemies[i].yPos, enemies[i].xPos, ' ');
                        enemies[i].yPos = 8;
                        enemies[i].xPos = 37 + (i * 1.5);
                        mvwaddch(w, enemies[i].yPos, enemies[i].xPos, enemies[i].symbol);
                }
        }
        wrefresh(w);
}

sprite moveSprite(WINDOW *w, sprite s)
{
        mvwaddch(w, s.yPos, s.xPos, s.tile);
        s.yPos = s.yPos + s.yVel;
        s.xPos = s.xPos + s.xVel;
        s.tile = mvwinch(w, s.yPos, s.xPos);
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
