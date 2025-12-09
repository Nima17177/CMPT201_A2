// CMPT 201, A2, Group 1
// Nathan Alex Sequeira (3141620)
// Nima Houshyar (1741854)

#include "map.h"

#define PORTAL '@'
#define POWER '$'

void map_createEasy(WINDOW *w)
{
	  mvwprintw(w, 7, 18, "+-----------------------------------------+");
	 mvwprintw(w, 8, 18, "|%c    |    |    |         |    |    |    %c|", PORTAL, PORTAL);
	  mvwprintw(w, 9, 18, "|     |   ---   |   ---   |   ---   |     |");
	 mvwprintw(w, 10, 18, "|                                         |");
	 mvwprintw(w, 11, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 12, 18, "|                                         |");
	 mvwprintw(w, 13, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 14, 18, "|                                         |");
	 mvwprintw(w, 15, 18, "|-|       |-|       |-|       |-|       |-|");
	mvwprintw(w, 16, 18, "|%c                                       %c|", POWER, POWER);
	 mvwprintw(w, 17, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 18, 18, "|                                         |");
	 mvwprintw(w, 19, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 20, 18, "|                                         |");
	 mvwprintw(w, 21, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 22, 18, "|                                         |");
	 mvwprintw(w, 23, 18, "|     |   ---   |         |   ---   |     |");
	mvwprintw(w, 24, 18, "|%c    |    |    |         |    |    |    %c|", PORTAL, PORTAL);
	 mvwprintw(w, 25, 18, "+-----------------------------------------+");
	wrefresh(w); 
}

void map_createHard(WINDOW *w)
{
	  mvwprintw(w, 7, 18, "+-----------------------------------------+");
	 mvwprintw(w, 8, 18, "|%c    |    |                   |    |    %c|", PORTAL, PORTAL);
	  mvwprintw(w, 9, 18, "|     |   ---   |   ---   |   ---   |     |");
	 mvwprintw(w, 10, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 11, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 12, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 13, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 14, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 15, 18, "|-|       |-|       |-|       |-|       |-|");
	mvwprintw(w, 16, 18, "|%c  |---|     |---|     |---|     |---|  %c|", POWER, POWER);
	 mvwprintw(w, 17, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 18, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 19, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 20, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 21, 18, "|-|       |-|       |-|       |-|       |-|");
	 mvwprintw(w, 22, 18, "|   |---|     |---|     |---|     |---|   |");
	 mvwprintw(w, 23, 18, "|     |   ---   |         |   ---   |     |");
	mvwprintw(w, 24, 18, "|%c    |    |    |         |    |    |    %c|", PORTAL, PORTAL);
	 mvwprintw(w, 25, 18, "+-----------------------------------------+");
	wrefresh(w);
}

void map_createUi(WINDOW *w, int lives, int enemies)
{
	// Title
	char *t1 = "M  A  C";
	char *t2 = "P  A  N";
	char *dash = "  -  ";
	int len = strlen(t1) + strlen(t2) + strlen(dash);
	int startx = (MAX_X - len) / 2;
	wattron(w, COLOR_PAIR(3));
	mvwprintw(w, 2, startx, "%s", t1);
	wattroff(w, COLOR_PAIR(3));
	mvwprintw(w, 2, startx + strlen(t1), "%s", dash);
	wattron(w, COLOR_PAIR(1));
	mvwprintw(w, 2, startx + strlen(t1) + strlen(dash), "%s", t2);
	wattroff(w, COLOR_PAIR(1));
	//Instructions
	char *toWin = "To win you must freeze the enemey and eat them";
	int len1 = strlen(toWin);
	int startx2 = (MAX_X - len1) / 2;
	wattron(w, COLOR_PAIR(5));
	mvwprintw(w, 4, startx2, "%s", toWin);
	wattroff(w, COLOR_PAIR(5));
	wattron(w, COLOR_PAIR(2));
	mvwprintw(w, 6, 17, " <P> to Pause/Resume");
	mvwprintw(w, 6, 49, " <Q> to Quit");
	mvwprintw(w, 26, 27, "Use <arrows> to move player");
	mvwprintw(w, 27, 24, "Press <space> to activate portal ( %c )", PORTAL);
	mvwprintw(w, 28, 3, "When over a powerup ( %c ), press <1> or <2> to freeze half of the enemies", POWER);
	mvwprintw(w, 20, 62, "<1> Freezes odd"); 
	mvwprintw(w, 21, 62, "<2> Freezes even"); 
	wattroff(w, COLOR_PAIR(2));
	wattron(w, COLOR_PAIR(6));
	mvwprintw(w, 1, 8, "Lives: %d  ", lives);
	mvwprintw(w, 1, 62, "Enemies: %d  ", enemies);
	mvwprintw(w, 10, 62, "Powerup Cooldown:"); 
	wattroff(w, COLOR_PAIR(6));
	mvwprintw(w, 11, 70, "0"); 
	wrefresh(w);
}

bool map_isWall(WINDOW *w, int y, int x)
{
	if (mvwinch(w, y, x) == '|') return true;
	if (mvwinch(w, y, x) == '-') return true;
	if (mvwinch(w, y, x) == '+') return true;
	return false;
}

void map_isPortal(WINDOW *w, int *y, int *x)
{
	if (*y == 8 && *x == 19)
	{
		*y = 24;
		*x = 59;
	}
	else if (*y == 24 && *x == 59)
	{
		*y = 8;
		*x = 19;
	}
	else if (*y == 8 && *x == 59)
	{
		*y = 24;
		*x = 19;
	}
	else if (*y == 24 && *x == 19)
	{
		*y = 8;
		*x = 59;
	}
	else
	{
		*y = -1;
		*x = -1;
	}
}

bool map_isPower(WINDOW *w, char c)
{
	if (c == POWER) return true;
	return false;
}

void map_decrementLives(WINDOW *w, int *lives)
{
	(*lives)--;
	wattron(w, COLOR_PAIR(6));
	mvwprintw(w, 1, 8, "Lives: %d  ", *lives);
	wattroff(w, COLOR_PAIR(6));
	wrefresh(w);
}

void map_decrementEnemies(WINDOW *w, int *enemies)
{
	(*enemies)--;
	wattron(w, COLOR_PAIR(6));
	mvwprintw(w, 1, 62, "Enemies: %d  ", *enemies);
	wattroff(w, COLOR_PAIR(6));
	wrefresh(w);
}

void map_updateTime(WINDOW *w, int time)
{
	mvwprintw(w, 11, 70, "          "); 
	mvwprintw(w, 11, 70, "%d", time);
	box(w, 0, 0); 
	wrefresh(w);	
}

void map_displayPause(WINDOW *w)
{
	wattron(w, COLOR_PAIR(3)); 
	mvwprintw(w, 5, 35, "Game Paused");
        wattroff(w, COLOR_PAIR(3)); 
	wrefresh(w);
}

void map_removePause(WINDOW *w)
{
	mvwprintw(w, 5, 35, "           "); 
}

char map_quitGame(WINDOW *w)
{
	nodelay(stdscr, FALSE); 
	wattron(w, COLOR_PAIR(3));
	mvwprintw(w, 10, 1, "Quit Game?"); 
	mvwprintw(w, 11, 1, "<y> Return menu"); 
        mvwprintw(w, 12, 1, "<n> Continue game"); 
	wattroff(w, COLOR_PAIR(3)); 
	wrefresh(w);
	while (1)
	{
		char ch = getchar();
	        if (ch == 'y' || ch == 'n')
		{
			mvwprintw(w, 10, 1, "          "); 
			mvwprintw(w, 11, 1, "                ");
		        mvwprintw(w, 12, 1, "                 "); 
			wrefresh(w); 
			return ch; 	
		}	
	}
}

void map_gameDone(WINDOW *w, int x)
{
	map_starFall(w);
	mvwhline(w, MAX_Y - 4, 1, ACS_HLINE, MAX_X - 2);
	wattron(w, COLOR_PAIR(6));
	mvwprintw(w, MAX_Y - 2, MAX_X/2 - 12, "Press any key to continue");
	wattroff(w, COLOR_PAIR(6));
	wrefresh(w);
	if (x == -1)
	{
		map_endScreen(w, "YOU LOST");
	}
	else if (x == -2)
	{
		map_endScreen(w, "YOU WON");
	}
	else
	{
		map_endScreen(w, "QUIT");
	}
}

void map_starFall(WINDOW *w)
{
	int y = 1;
	while (y < MAX_Y - 1)
	{
		//getchar(); // If the user mashes buttons during the transition, this will ignore it. 
		for (int x =1; x < MAX_X -1; x++)
		{
			if (y > 1)
			{
				mvwaddch(w, y -1, x, ' ');
			}
			mvwaddch(w, y, x, '*'); 
		}
		wrefresh(w);
		napms(100);
		y++;
	}
	for (int x = 1; x < MAX_X -1; x++)
	{
		mvwaddch(w, y -1, x, ' ');
	}
	wrefresh(w);
}

void map_endScreen(WINDOW *w, char *msg)
{
	int len = strlen(msg);
	int startx = 3;
	int starty = 3;
	box(w, 0, 0);
	//Small box inside the window
	mvwhline(w, MAX_Y - 4, 1, ACS_HLINE, MAX_X - 2);
	wrefresh(w);
	nodelay(stdscr, TRUE); 
	int dy = 1;
	int dx = 1;
	while (1)
	{
		for (int i = 0; i < len; i++)
		{
			mvwaddch(w, starty, startx + i, ' ');
		}
		startx += dx;
		starty += dy;
		mvwprintw(w, starty, startx, "%s", msg);
		wrefresh(w);
		napms(100);
		if (startx == MAX_X - len -1)
		{
			dx = -dx;
		}
		if (starty == MAX_Y -5)
		{
			dy = -dy;
		}
		if (startx == 3)
		{
			dx = -dx;
		}
		if (starty == 1)
		{
			dy = -dy;
		}
		int ch = getch();
		if (ch != ERR)
		{
			break; 
		}	
	}
	nodelay(stdscr, FALSE); 
	wrefresh(w);
}


