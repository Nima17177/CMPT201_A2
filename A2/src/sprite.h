// CMPT 201, A2, Group 1
// Nathan Alex Sequeira (3141620)
// Nima Houshyar (1741854)

#ifndef SPRITE_H
#define SPRITE_H

#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct
{
	/// Sprite's y position.
	int yPos;
	/// Sprite's x position.
	int xPos;
	/// Sprite's y velocity.
 	int yVel;
	/// Sprite's x velocity.
	int xVel;
	/// For the player, this is the amount of lives left; <br> For the enemies it is their status: 0 = alive & moving, 1 = alive & frozen, 2 = dead
	int life;
	/// The tile that is under the sprite. Program will redraw it after the sprite moves.
	char tile;
	/// The sprite's symbol.
	char symbol;
} sprite;

/**
 * @brief Creates and initializes the player sprite.
 * @param The integer 'playerLives' which is the amount of lives that the player must have at the start of the level.
 * @pre None
 * @post None
 * @throws None
 * @returns A new sprite structure
 * @see level_createSprites
 */
sprite sprite_createPlayer(int playerLives);

/**
 * @brief Creates and initializes the enemy sprite.
 * @param The integer 'i' which is the enemy's index and symbol. 
 * @pre None
 * @post None
 * @throws None
 * @returns A new sprite structure
 * @see level_createSprites
 */
sprite sprite_createEnemy(int i);

/**
 * @brief Spawns the player and enemy sprites, or resets the positions to their spawn points.
 * @param The WINDOW pointer 'w' which is the window onto which the sprites must be drawn.<br>The sprite structure pointer 'player' which contains information about the player sprite.<br>The integer 'enemyCount' which is the amount of enemies.<br>The array of sprite structures 'enemies' which contains information about all of the enemies.
 * @pre None
 * @post The x and y positions of the sprites will be changed, and they will be redrawn on the window.
 * @throws None
 * @returns None
 * @see level_createSprites level_checkCollision
 */
void sprite_reset(WINDOW *w, sprite *player, int enemyCount, sprite *enemies);

/**
 * @brief Moves the given sprite.
 * @param The WINDOW pointer 'w' which is the window onto which the sprites must be drawn.<br>The sprite structure pointer 's' which contains information about the sprite to be moved.
 * @pre The appropriate checks were done to make sure the sprite can be moved.
 * @post The sprite's xPos, yPos, and tile will be changed, and they will be redrawn on the window.
 * @throws None
 * @returns None
 * @see level_createSprites level_checkCollision
 */
void sprite_move(WINDOW *w, sprite *s);

/**
 * @brief Randomly changes the velocity of the given sprite.
 * @param The sprite structure pointer 's' which contains information about the sprite whose velocity must be changed.
 * @pre The appropriate checks were done to make sure the sprite's velocity should be changed.
 * @post The sprite's xVel and yVel will be changed.
 * @throws None
 * @returns None
 * @see level_updateFrame
 * @note This function can be used on any sprite, but it should only be called on enemies to randomly change their velocity. The player's velocity is changed by player input.
 */
void sprite_changeVel(sprite *s);

#endif



