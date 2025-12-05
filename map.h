#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <ncurses.h>

// Draws the easy map. 
void createMapEasy(WINDOW *w);

// Draws the hard map. 
void createMapHard(WINDOW *w); 

// Returns if coordinates are a wall.
bool isWall(WINDOW *w, int y, int x); 

// If coordinates are a portal, updates pointer to new telerport location. If not, update pointers to -1. 
void isPortal(WINDOW *w, int *y, int *x);

// Returns if coordinates are a power up; also removed power up from map. 
bool isPower(WINDOW *w, int y, int x); 

#endif 