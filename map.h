#include <stdbool.h>

// Draws the easy map. 
void createMapEasy();

// Draws the hard map. 
void createMapHard(); 

// Returns if coordinates are a wall.
bool isWall(int y, int x); 

// If coordinates are a portal, updates pointer to new telerport location. If not, update pointers to -1. 
void isPortal(int *y, int *x);

// Returns if coordinates are a power up; also removed power up from map. 
bool isPower(int y, int x); 
