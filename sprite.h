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
        char symbol;
} sprite;

sprite createPlayer(WINDOW *w);
sprite createEnemy(char c, WINDOW *w);
sprite moveSprite(sprite s, WINDOW *w);
sprite checkEnemyVel(sprite e, WINDOW *w);