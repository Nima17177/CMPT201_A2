#ifndef MAP_H
#define MAP_H

#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

/// The window's maximum height. 
#define MAX_Y 30
/// The window's maximum width.
#define MAX_X 80
/// The window's origin y coordinate. 
#define ORIGIN_Y 1
/// The window's origin x coordinate. 
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
void map_createUi(WINDOW *w, int lives, int enemies);

/**
 * @brief Checks if the given coordinates are a wall.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed<br>The integers 'y' and 'x' which represent the coordinates that must be checked.
 * @pre None
 * @post None
 * @throws None
 * @returns A bool if the given coordinates have a wall.
 * @see level_updateFrame
 */
bool map_isWall(WINDOW *w, int y, int x);

/**
 * @brief Checks if the given coordinates are a portal.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer pointers 'y' and 'x' which represent the coordinates that must be checked.
 * @pre None
 * @post If the coordinates are a portal, then the pointers are updated to the portal’s destination. If not, then they are set to -1.
 * @throws None
 * @returns None
 * @see level_checkInput
 */
void map_isPortal(WINDOW *w, int *y, int *x);

/**
 * @brief Checks if the given tile has a power up.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The character 'c' which represets the tile that must be checked.
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
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer pointer 'lives' which saves the amount of lives the player currently has.
 * @pre None
 * @post 'lives' is decremented, and the new number is printed onto 'w'.
 * @throws None
 * @returns None
 * @see level_checkCollision
 */
void map_decrementLives(WINDOW *w, int *lives);

/**
 * @brief Decrement the amount of enemies left and update the game status.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer pointer 'enemies' which saves the amount of enemies still alive.
 * @pre None
 * @post 'enemies' is decremented, and the new number is printed onto 'w'.
 * @throws None
 * @returns None
 * @see level_checkCollision
 */
void map_decrementEnemies(WINDOW *w, int *enemies);

/**
 * @brief Prints the time left on powerup cooldown.  
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer 'time' which represents the time left on power ups cooldown.
 * @pre None
 * @post The time is printed onto 'w'.
 * @throws None
 * @returns None
 * @see levels_run
 */
void map_updateTime(WINDOW *w, int time);

/**                                                                                                                                                          * @brief Displays a message that the game has paused. 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post The message is printed onto 'w'.
 * @throws None
 * @returns None
 * @see levels_run
 */
void map_displayPause(WINDOW *w);

/**                                                                                                                                                          * @brief Removes the pause message. 
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.
 * @pre None
 * @post The message has been removed. 
 * @throws None
 * @returns None
 * @see levels_run
 */
void map_removePause(WINDOW *w); 

/**                                                                                                                                                          * @brief Prints out a quit message and waits for the user to confirm quit. 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.
 * @pre None
 * @post The quit message is removed once the user inputs 'y' or 'n'
 * @throws None
 * @returns A character that saves the user input. 
 * @see levels_run
 */
char map_quitGame(WINDOW *w); 

/**
 * @brief Creates a End Screen message based on outcome or input.
 * @param The WINDOW pointer 'w' which is the window onto which everything has been printed.<br>The integer 'x' which represents how the game ended: 1 = lost, 2 = won, 3 = quit.
 * @pre None
 * @post The message is printed.
 * @throws None
 * @returns None
 * @see level_run map_endScreen
 */
void map_gameDone(WINDOW *w, int x);

/**
 * @brief Displays a star falling animation, that also clears the screen. 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed. 
 * @pre None
 * @post The screen is cleared. 
 * @throws None
 * @returns None
 */
void map_starFall(WINDOW *w);

/**
 * @brief Creates an end screen with a message that bounces around the screen like DVD screensaver until the user presses a key. 
 * @param The WINDOW pointer 'w' which is the window onto which everything must be printed.<br>The string 'msg' which is the message to be printed. 
 * @pre 'msg' is a properly initialized string. 
 * @post None
 * @throws None
 * @returns None
 * @see map_gameDone
 */
void map_endScreen(WINDOW *w, char *msg);

#endif
