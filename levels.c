#include "levels.h"
#include "sprite.h"
#include "map.h"

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>

void createLevelEasy(WINDOW *w)
{
        createMapEasy(w);
        status(w, 5, 2);
        createSprites(w, 5, 2);
}

void createLevelHard(WINDOW *w)
{
        createMapEasy(w);
        status(w, 3, 8);
        createSprites(w, 3, 8);
}

void createSprites(WINDOW *w, int playerLives, int enemyCount)
{
        sprite player = createPlayer(w, playerLives);
        sprite enemies[enemyCount];
        for (int i = 0; i < enemyCount; i++)
        {
                enemies[i] = createEnemy(w, i+1);
        }
        resetSprites(w, &player, enemyCount, enemies);
        run(w, player, enemyCount, enemies);
}

void run(WINDOW *w, sprite player, int enemyCount, sprite enemies[enemyCount])
{
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        int ch;
        time_t stoppedTime = 0;
        int stoppedEnemy = -1;
        int enemiesLeft = enemyCount;
        int stage = 0;
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
                                if ((ch == '1') && (isPower(w, player.tile) == true) && (stoppedTime == 0))
                                {
                                        for (int i = 0; i < enemyCount; i+=2)
                                        {
                                                if (enemies[i].life == 0)
                                                {
                                                        enemies[i].life = 1;
                                                        enemies[i].symbol = 'e';                                                                                                                                    mvwaddch(w, enemies[i].yPos, enemies[i].xPos, 'e');
                                                }
                                        }
                                        stoppedTime = time(NULL);
                                        stoppedEnemy = 0;
                                }
                                else if ((ch == '2') && (isPower(w, player.tile) == true) && (stoppedTime == 0))
                                {
                                        for (int i = 1; i < enemyCount; i+=2)
                                        {
                                                if (enemies[i].life == 0)
                                                {
                                                        enemies[i].life = 1;
                                                        enemies[i].symbol = 'e';
                                                        mvwaddch(w, enemies[i].yPos, enemies[i].xPos, 'e');
                                                }
                                        }
                                        stoppedTime = time(NULL);
                                        stoppedEnemy = 1;
                                }
                                else if (ch == 32)
                                {
                                        int y, x;
                                        y = player.yPos;
                                        x = player.xPos;
                                        isPortal(w, &y, &x);
                                        if (y != -1)
                                        {
                                                mvwaddch(w, player.yPos, player.xPos, player.tile);
                                                player.yPos = y;
                                                player.xPos = x;
                                                mvwaddch(w, player.yPos, player.xPos, player.symbol);
                                        }
                                }
                        }
                }
                if (stage == 0)
                {
                        if (isWall(w, player.yPos+player.yVel, player.xPos+player.xVel) == false)
                        {
                                player = moveSprite(w, player);
                        }
                        for (int i = 0; i < enemyCount; i++)
                        {
                                if (enemies[i].life == 0)
                                {
                                        int randNum0 = rand() % 5;
                                        if ((randNum0 == 0) || (isWall(w, enemies[i].yPos+enemies[i].yVel, enemies[i].xPos+enemies[i].xVel) == true) || (mvwinch(w, enemies[i].yPos+enemies[i].yVel, enemies[i].xPos+enemies[i].xVel) == enemies[i].symbol))
                                        {
                                                enemies[i] = changeVel(enemies[i]);
                                        }
                                        else
                                        {
                                                enemies[i] = moveSprite(w, enemies[i]);
                                        }
                                }
                        }
                        if (stoppedTime > 0)
                        {
                                if (time(NULL) - stoppedTime >= 15)
                                {
                                        stoppedTime = 0;
                                        for (int i = stoppedEnemy; i < enemyCount; i+=2)
                                        {
                                                if (enemies[i].life == 1)
                                                {
                                                        enemies[i].life = 0;
                                                        enemies[i].symbol = 'E';                                                                                                                                    mvwaddch(w, enemies[i].yPos, enemies[i].xPos, 'E');
                                                }
                                        }
                                }
                        }
                        for (int i = 0; i < enemyCount; i++)
                        {
                                if ((enemies[i].life != 2) && ((enemies[i].tile == player.symbol) || (player.tile == enemies[i].symbol)))
                                {
                                        enemies[i].tile = ' ';
                                        player.tile = ' ';
                                        if (enemies[i].life == 1)
                                        {
                                                enemies[i].life = 2;
                                                decrementEnemies(w, &enemiesLeft);
                                                stoppedTime -= 12;
                                                mvwaddch(w, enemies[i].yPos, enemies[i].xPos, ' ');
                                                if (enemiesLeft == 0)
                                                {
                                                        stage = -2;
                                                }
                                        }
                                        else if (enemies[i].life == 0)
                                        {
                                                resetSprites(w, &player, enemyCount, enemies);
                                                decrementLives(w, &player.life);
                                                if (player.life == 0)
                                                {
                                                        stage = -1;
                                                }
                                                break;
                                        }
                                }
                        }
                }
                napms(150);
        }
        wclear(w);
        endwin();
        w = newwin(30, 80, 1, 1);
        box(w, 0, 0);
        wrefresh(w);
        gameDone(w, -stage);
        nodelay(stdscr, FALSE);
        getch();
}