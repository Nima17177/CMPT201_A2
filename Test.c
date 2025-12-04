#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

typedef struct
{
	int yPos;
	int xPos;
	int yVel;
	int xVel;
	char symbol;
} Character; 


Character createPlayer()
{
	Character p;
	p.yPos = 30;
	p.xPos = 30;
	p.yVel = -2; 
	p.xVel = 0; 
	p.symbol = 'P'; 	
	mvaddch(p.yPos, p.xPos, p.symbol);
	refresh(); 
	return p;
}

Character createEnemy(char x)
{
	Character e; 
        e.yPos = (5 * ((int)(x-'0')));
	e.xPos = (3 * ((int)(x-'0')));
	e.yVel = 1; 
	e.xVel = 0;
	e.symbol = x; 	
	mvaddch(e.yPos, e.xPos, e.symbol);
	refresh(); 
	return e;
}



Character moveCharacter(Character c)
{
	if (((c.yVel != 0) && (mvinch(c.yPos+c.yVel, c.xPos) == ' ' )) || ((c.xVel != 0) && (mvinch(c.yPos, c.xPos+c.xVel) == ' ' ))) 
	{
		mvaddch(c.yPos, c.xPos, ' ');
		c.yPos = c.yPos + c.yVel; 
		c.xPos = c.xPos + c.xVel; 
		mvaddch(c.yPos, c.xPos, c.symbol);
		refresh();
	}
	return c;
}

Character checkEnemyVel(Character e)
{
	if (e.yVel == 1 && mvinch(e.yPos+1, e.xPos) != ' ')
	{
		e.yVel = 0; 
		e.xVel = 1; 
	}
	else if (e.xVel == 1 && mvinch(e.yPos, e.xPos+1) != ' ')
	{
		e.yVel = -1; 
		e.xVel = 0; 
	}
	else if (e.yVel == -1 && mvinch(e.yPos-1, e.xPos) != ' ')
	{
		e.yVel = 0; 
		e.xVel = -1;
	}
	else if (e.xVel == -1 && mvinch(e.yPos, e.xPos-1) != ' ')
	{
		e.yVel = 1; 
		e.xVel = 0; 
	}
	return e; 
}


int main(){

	WINDOW *w;
	// initialize ncurses
	initscr();
	//add no echo so that entered keys are not printed to the screen
	noecho();	
	//height, width, start_y, start_x
	w = newwin(50,50, 1, 1);
	//any window creation or  box plot must be followed by a refresh for changes
	//to take effect
	wrefresh(w);
	
	mvprintw(10, 3,"%c",'-');
        mvprintw(9, 10, "%c", '|'); 
	mvprintw(4, 9, "%c", '-'); 
	mvprintw(5, 2, "%c", '|'); 	

	Character p = createPlayer();
	Character e[4];
        e[0] = createEnemy('1');
        e[1] = createEnemy('2'); 
	e[2] = createEnemy('3'); 
	e[3] = createEnemy('4'); 

	/* Direction checking:
	   KEY_RIGHT
	   KEY_UP
	   KEY_DOWN
	   KEY_LEFT
	*/
        keypad(stdscr, TRUE); 
	nodelay(stdscr, TRUE); 
	int ch;	
	time_t stopped = 0; 
	while (1)
	{
		ch = getch(); 
		if (ch != ERR) // If key has been pressed. 
		{
			if (ch == KEY_RIGHT)
			{
				p.xVel = 2; 
				p.yVel = 0; 
			}
			else if (ch == KEY_LEFT)
			{
				p.xVel = -2;
				p.yVel = 0; 
			}
			else if (ch == KEY_UP)
			{
				p.xVel = 0; 
				p.yVel = -1; 
			}
			else if (ch == KEY_DOWN)
			{
				p.xVel = 0;
				p.yVel = 1; 
			}
			else if (ch == 'q')
			{
				break; 
			}
			else if (ch == 'p')
			{
				break; 
			}
			else if (ch == '1')
			{
				e[0].yVel = 0; 
				e[0].xVel = 0;
				e[2].yVel = 0; 
				e[2].xVel = 0; 
			        stopped = time(NULL); 	
			}
			else if (ch == '2')
			{
				e[1].yVel = 0;
				e[1].xVel = 0;
			        e[3].yVel = 0;
				e[3].xVel = 0;	
				stopped = time(NULL); 
			}

		}
		p = moveCharacter(p); 
		for (int i = 0; i < 4; i++)
		{
			e[i] = moveCharacter(e[i]);
			e[i] = checkEnemyVel(e[i]); 
		}
		if (stopped > 0)
		{
			if (time(NULL) - stopped > 0)
			{
				stopped = 0; 
				for (int i = 0; i < 4; i++)
				{
					if (e[i].xVel == 0 && e[i].yVel == 0)
					{
						e[i].xVel = 1; 
					}
				}
			}
		}	
		refresh();
		napms(100); // pause program
	}
	endwin();
	return 0;
}

