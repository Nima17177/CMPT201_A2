#ifndef SPRITE_H
#define SPRITE_H

#include <stdbool.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#define PVEL 1
#define EVEL 1

typedef struct
{
        int yPos;
        int xPos;
        int yVel;
        int xVel;
        int life; // 0 = alive, 1 = frozen, 2 = dead
        char tile; // Tile that is under the sprite. Redraw it after the sprite moves.
        char symbol; // Sprite's symbol
} sprite;

sprite createPlayer(WINDOW *w, int playerLives);
sprite createEnemy(WINDOW *w, int c);
void resetSprites(WINDOW *w, sprite *player, int enemyCount, sprite *enemies);
sprite moveSprite(WINDOW *w, sprite s);
sprite changeVel(sprite e);

#endif