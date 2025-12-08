#ifndef MAP_H
#define MAP_H

#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#define MAX_Y 30
#define MAX_X 80
#define ORIGIN_Y 1
#define ORIGIN_X 1

/**
 * @brief Creates the map for easy mode.
 * @param The WINDOW pointer 'w' which is the window onto which the map must be drawn.
 * @pre None
 * @post The map is drawn onto the window.
 * @throws None
 * @returns None
 * @see display_level
 */
void map_createEasy(WINDOW *w);

/**
 * @brief Creates the map for hard mode.
 * @param The WINDOW pointer 'w' which is the window onto which the map must be drawn.
 * @pre None
 * @post The map is drawn onto the window.
 * @throws None
 * @returns None
 * @see display_level
 */
void map_createHard(WINDOW *w);

/**
 * @brief Creates the game UI.
 * @param The WINDOW pointer 'w' which is the window onto which the game UI must be drawn.
 * @pre None
 * @post The game UI is printed onto the window.
 * @throws None
 * @returns None
 * @see display_level
 */
void map_createUi(WINDOW *w);

/**
 * @brief Prints the game status.
 * @param The WINDOW pointer 'w' which is the window onto which the game status must be drawn.
 * @pre None
 * @post The game status is printed onto the window.
 * @throws None
 * @returns None
 * @see display_level
 */
void map_status(WINDOW *w, int lives, int enemies);

/**
 * @brief
 * @param The WINDOW pointer 'w' which is the window onto which the vines must be drawn.
 * @pre
 * @post
 * @throws None
 * @returns None
 * @see
 */
void map_vines(WINDOW *w);

/**
 * @brief Checks if the given coordinates are a wall.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the integers 'y' and 'x' which represent the coordinates that must be checked.
 * @pre None
 * @post None
 * @throws None
 * @returns A bool if the given coordinates have a wall.
 * @see level_updateFrame
 */
bool map_isWall(WINDOW *w, int y, int x);

/**
 * @brief Checks if the given coordinates are a portal.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the integer pointers 'y' and 'x' which represent the coordinates that must be checked.
 * @pre None
 * @post If the coordinates are a portal, then the pointers are updated to the portal’s destination. If not, then they are set to -1.
 * @throws None
 * @returns None
 * @see level_checkInput
 */
void map_isPortal(WINDOW *w, int *y, int *x);

/**
 * @brief Checks if the given tile has a power up.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the character 'c' which represets the tile that must be checked.
 * @pre None
 * @post None
 * @throws None
 * @returns A bool if the given tile is a portal.
 * @see level_checkInput
 * @note A character is sent instead of coordinates because the player is currently standing over the power up tile.
 */
bool map_isPower(WINDOW *w, char c);

/**
 * @brief Decrement player lives and update the game status.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the integer pointer 'lives' which saves the amount of lives the player currently has.
 * @pre None
 * @post 'lives' is decremented, and the new number is printed onto 'w'.
 * @throws None
 * @returns None
 * @see level_checkCollision
 */
void map_decrementLives(WINDOW *w, int *lives);

/**
 * @brief Decrement the amount of enemies left and update the game status.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the integer pointer 'enemies' which saves the amount of enemies still alive.
 * @pre None
 * @post 'enemies' is decremented, and the new number is printed onto 'w'.
 * @throws None
 * @returns None
 * @see level_checkCollision
 */
void map_decrementEnemies(WINDOW *w, int *enemies);

/**
 * @brief Creates a game over message.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed; and the integer 'x' which represents how the game ended: 1 = lost, 2 = won, 3 = quit.
 * @pre None
 * @post The message is printed
 * @throws None
 * @returns None
 * @see level_run map_looseScreen map_winScreen map_quitScreen
 */
void map_gameDone(WINDOW *w, int x);

/**
 * @brief
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post 
 * @throws None
 * @returns None
 * @see map_gameDone
 */
void map_starFall(WINDOW *w);

/**
 * @brief 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post 
 * @throws None
 * @returns None
 * @see map_gameDone
 */
void map_winScreen(WINDOW *w);

/**
 * @brief 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post 
 * @throws None
 * @returns None
 * @see map_gameDone
 */
void map_looseScreen(WINDOW *w);

/**
 * @brief 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post 
 * @throws None
 * @returns None
 * @see map_gameDone
 */
void map_quitScreen(WINDOW *w);

#endif

