#ifndef SPRITE_H
        #include "sprite.h"
        #define SPRITE_H
#endif
//#include "map.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void createLevelEasy(WINDOW *w);
void createLevelHard(WINDOW *w);
void run(sprite player, int enemyCount, sprite enemies[enemyCount], WINDOW *w);