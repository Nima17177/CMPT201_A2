#ifndef SPRITE_H
        #include "sprite.h"
        #define SPRITE_H
#endif
#ifndef MAP_H
        #include "map.h"
        #define MAP_H
#endif
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
void createLevelEasy(WINDOW *w);
void createLevelHard(WINDOW *w);
void createSprites(WINDOW *w, int enemyCount);
void run(WINDOW *w, sprite player, int enemyCount, sprite enemies[enemyCount]);