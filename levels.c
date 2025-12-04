#include "levels.h"
#include "sprite.h"
#include "map.h"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void createLevelEasy(WINDOW *w)
{
        createMapEasy(w);
        sprite player = createPlayer();
        sprite enemies[2];
        enemies[0] = createEnemy('1');
        enemies[1] = createEnemy('2');
        run(player, 2, enemies);
}

void createLevelHard(WINDOW *w)
{
        createMapHard(w);
        char player = createPlayer();
        char enemies[4];
        enemies[0] = createEnemy('1');
        enemies[1] = createEnemy('2');
        enemies[2] = createEnemy('3');
        enemies[3] = createEnemy('4');
        run(player, 4, enemies);
}

void run(sprite player, int enemyCount sprite enemies[enemyCount])
{
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        int ch;
        time_t stopped = 0;
        int stage = 0;
        int stopped = -1;
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
                                stage = (((stage+1) % 2) // Increment by 1 and then wrap around. Stage is either 1 or 2.
                        }
                        if (stage != 1)
                        {
                                if (ch == KEY_RIGHT)
                                {
                                        player.xVel = PVEL;
                                        player.yVel = 0;
                                }
                                else if (ch == KEY_LEFT)
                                {
                                        player.xVel = -PVEL;
                                        player.yVel = 0;
                                }
                                else if (ch == KEY_UP)
                                {
                                        player.xVel = 0;
                                        player.yVel = -PVEL;
                                }
                                else if (ch == KEY_DOWN)
                                {
                                        player.xVel = 0;
                                        player.yVel = PVEL;
                                }
                                p = moveCharacter(p);
                /*              for (int i = 0; i < 4; i++)
                                {
                                        e[i] = moveCharacter(e[i]);
                                        e[i] = checkEnemyVel(e[i]);
                                }
                                if (stopped > 0)
                                {
                                        if (time(NULL) - stopped > 0)
                                        {
                                                stopped = 0;
                                                 p = moveCharacter(p);
                for (int i = 0; i < 4; i++)
                {
                  //      e[i] = moveCharacter(e[i]);
                //        e[i] = checkEnemyVel(e[i]);
                }*/
        }
}