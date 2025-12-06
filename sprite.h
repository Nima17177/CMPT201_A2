#include "stdbool.h"
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
        bool frozen;
        char pixel; // Pixel that is under the sprite. Redraw it after the sprite moves.
        char symbol;
} sprite;

sprite createPlayer(WINDOW *w);
sprite createEnemy(WINDOW *w, int c);
sprite moveSprite(WINDOW *w, sprite s);
sprite changeVel(sprite e);