
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>

#include "sprite.h"
#include "map.h"

typedef struct
{
	int yPos;
        int xPos;
        int yVel;
        int xVel;
	bool frozen; 
        char symbol;
} sprite; 

sprite createPlayer()
{
	sprite p;
        p.yPos = 30;
        p.xPos = 30;
        p.yVel = -PVEL;
        p.xVel = 0;
	p.frozen = false; 
        p.symbol = 'P';
        mvaddch(p.yPos, p.xPos, p.symbol);
        refresh();
        return p;
}

sprite createEnemy(char c)
{	
	sprite e;
        e.yPos = (5 * ((int)(c-'0')));
        e.xPos = (3 * ((int)(c-'0')));
        e.yVel = EVEL * (1.5 * ((int)(c-'0'));
        e.xVel = 0;
        e.symbol = c;
	p.frozen = false; 
        mvaddch(e.yPos, e.xPos, e.symbol);
        refresh();
        return e;
}

sprite moveSprite(sprite s)
{
	if ((s.frozen == false) && (((s.yVel != 0) && (isWall((s.yPos+s.yVel), s.xPos) == false)) || ((s.xVel != 0) && (isWall(s.yPos, (s.xPos+s.xVel)) == false))))
        {
                mvaddch(s.yPos, s.xPos, ' ');
                s.yPos = s.yPos + s.yVel;
                s.xPos = s.xPos + s.xVel;
                mvaddch(s.yPos, s.xPos, s.symbol);
                refresh();
        }
        return s; 
}
