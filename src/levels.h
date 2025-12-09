#ifndef LEVELS_H
#define LEVELS_H

#include "sprite.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Creates and runs the level in a new window.
 * @param The integer 'i' which is either 0 or 1 if the level to be created is Easy or Hard.
 * @pre None
 * @post level_createSprites is called to create sprites.
 * @throws None
 * @returns None
 * @see main
 * @see map_createEasy map_createHard level_createSprites
 */
void display_level(int i, WINDOW *w);

/**
 * @brief Creates the sprites for player and enemies.
 * @param The WINDOW pointer 'w' which is the window onto which the sprites must be drawn.<br>The integer 'playerLives' which is the amount of lives the player can have.<br>The integer 'enemyCount' which is the amount of enemies that must be created.
 * @pre None
 * @post The sprites have been created and printed onto the window, and then level_run will be called.
 * @throws None
 * @returns None
 * @see display_level
 * @see sprite_createPlayer sprite_createEnemy sprite_reset level_run
 */
void level_createSprites(WINDOW *w, int playerLives, int enemyCount);

/**
 * @brief Calls functions to run the game, including getting player input, and updating frames and sprites.
 * @param The WINDOW pointer 'w' which is the window onto which everything will be printed.<br>The sprite structure 'player' which contains information about the player sprite.<br>The integer 'enemyCount' which is the amount of enemies.<br>The array of sprite structures 'enemies' which contains information about all of the enemies.
 * @pre Everything has been initialized properly.
 * @post After the game is complete (player won, lost, or quit) the function stack returns back to main
 * @throws None
 * @returns None
 * @see level_createSprites
 * @see level_checkInput level_updateFrame level_checkCollision map_gameDone
 */
void level_run(WINDOW *w, sprite player, int enemyCount, sprite enemies[enemyCount]);

/**
 * @brief Checks the player input and accordingly updates the game.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer 'input' which contains the player's inputed key.<br>The integer pointer 'gameStage' which represents whether the game is running, paused, or completed.<br>The time_t pointer 'stoppedTime' which saved the when the enemy was frozen.<br>The integer 'stoppedEnemy' which represents the index of the frozen enemies (0 = odd enemies, 1 = even enemies).<br>The sprite structure pointer 'player' which contains information about the player sprite.<br>The integer 'enemyCount' which is the amount of enemies.<br>The array of sprite structures 'enemies' which contains information about all of the enemies.
 * @pre Everything has been initialized and updated properly.
 * @post The pointers might be updated depending on the player's input.
 * @throws None
 * @returns None
 * @see level_run
 * @see map.h sprite.h
 */
void level_checkInput(WINDOW *w, int input, int *gameStage, time_t *stoppedTime, int *stoppedEnemy, sprite *player, int enemyCount, sprite *enemies);

/**
 * @brief Updates the frame by moving sprites, and/or unfreezing enemies.
 * @param The WINDOW pointer 'w' which is the window onto which everything will be printed.<br>The time_t pointer 'stoppedTime' which saved the time when the enemy was frozen.<br>The integer 'stoppedEnemy' which represents the index of the frozen enemies (0 = odd enemies, 1 = even enemies).<br>The sprite structure pointer 'player' which contains information about the player sprite.<br>The integer 'enemyCount' which is the amount of enemies.<br>The array of sprite structures 'enemies' which contains information about all of the enemies.
 * @pre Everything has been initialized and updated properly.
 * @post The pointers might be updated if the sprites can move, and accordingly the window will also be updated.
 * @throws None
 * @returns None
 * @see level_run
 * @see map.h sprite.h
 */
void level_updateFrame(WINDOW *w, time_t *stoppedTime, int stoppedEnemy, sprite *player, int enemyCount, sprite *enemies);

/**
 * @brief Checks if the player and enemies are colliding.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The time_t pointer 'stoppedTime' which saved time when the enemy was frozen.<br>The sprite structure pointer 'player' which contains information about the player sprite.<br>The integer 'enemyCount' which is the amount of enemies.<br>The array of sprite structures 'enemies' which contains information about all of the enemies.<br>The integer pointer 'enemiesLeft' which is the number of enemies still alive.
 * @pre Everything has been initialized and updated properly.
 * @post The pointers might be updated depending on if the player is colliding with an enemy, and if that enemy is frozen or not.
 * @throws None
 * @returns None
 * @see level_run
 * @see map.h sprite.h
 */
void level_checkCollision(WINDOW *w, time_t *stoppedTime, sprite *player, int enemyCount, sprite *enemies, int *enemiesLeft);

#endif


