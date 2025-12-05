#ifndef LEVELS_H
        #include "levels.h"
        #define LEVELS_H
#endif
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
#include <time.h>
#include <unistd.h>
#include <curses.h>

void createLevelEasy(WINDOW *w)
{
        createMapEasy(w);
        sprite player = createPlayer(w);
        sprite enemies[2];
        enemies[0] = createEnemy('1', w);
        enemies[1] = createEnemy('2', w);
        run(player, 2, enemies, w);
}

void createLevelHard(WINDOW *w)
{
        createMapEasy(w);
        sprite player = createPlayer(w);
        sprite enemies[4];
        enemies[0] = createEnemy('1', w);
        enemies[1] = createEnemy('2', w);
        enemies[2] = createEnemy('3', w);
        enemies[3] = createEnemy('4', w);
        run(player, 4, enemies, w);
}

void run(sprite player, int enemyCount, sprite enemies[enemyCount], WINDOW *w)
{
        if (has_colors())
        {
                start_color();
                init_pair(1, COLOR_RED, COLOR_BLACK);
                init_pair(2, COLOR_CYAN, COLOR_BLACK);
                init_pair(3, COLOR_WHITE, COLOR_BLACK);
        }
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        int ch;
        time_t stoppedTime = 0;
        int stage = 0;
        int stoppedEnemy = -1;
        while (stage >= 0)
        {
                ch = getch();
                if (ch != ERR) // If key has been pressed.
                {
                        if (ch == 'q')
                        {
                                break;
                        }
                        else if (ch == 'p')
                        {
                                stage = ((stage+1) % 2); // Increment by 1 and then wrap around.
                        }
                        if (stage != 1)
                        {
                                if (ch == KEY_RIGHT)
                                {
                                        player.xVel = 1;
                                        player.yVel = 0;
                                }
                                else if (ch == KEY_LEFT)
                                {
                                        player.xVel = -1;
                                        player.yVel = 0;
                                }
                                else if (ch == KEY_UP)
                                {
                                        player.xVel = 0;
                                        player.yVel = -1;
                                }
                                else if (ch == KEY_DOWN)
                                {
                                        player.xVel = 0;
                                        player.yVel = 1;
                                }
                        }
                }
                if (stage == 0)
                {       //wattron(w, COLOR_PAIR(2));
                        player = moveSprite(player, w);
                        //wattron(w, COLOR_PAIR(1));
                        for (int i = 0; i < enemyCount; i++)
                        {
                                enemies[i] = moveSprite(enemies[i], w);
                                enemies[i] = checkEnemyVel(enemies[i], w);
                        }
                        //wattron(w, COLOR_PAIR(3));
                        /*if (stopped > 0)
                        {
                                if (time(NULL) - stopped > 0)
                                {
                                stopped = 0;
                                p = movecharacter(p);
                                }
                                for (int i = 0; i < enemyCount; i++)
                                {
                                        enemies[i] = moveCharacter(e[i]);
                                        enemies[i] = checkEnemyVel(e[i]);
                                }
                        }*/
                }
                napms(150);
        }
}