#ifndef SPRITE_H
#define SPRITE_H

#include "sprite.h"

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
void createLevelEasy(WINDOW *w);
void createLevelHard(WINDOW *w);
void createSprites(WINDOW *w, int playerLives, int enemyCount);
void run(WINDOW *w, sprite player, int enemyCount, sprite enemies[enemyCount]);

#endif