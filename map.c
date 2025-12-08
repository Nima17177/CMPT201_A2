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

void map_createUi(WINDOW *w)
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
	wattroff(w, COLOR_PAIR(2));
	map_vines(w);
	wrefresh(w);
}

void map_status(WINDOW *w, int lives, int enemies)
{
	wattron(w, COLOR_PAIR(6));
	mvwprintw(w, 1, 8, "Lives: %d  ", lives);
	mvwprintw(w, 1, 62, "Enemies: %d  ", enemies);
	wattroff(w, COLOR_PAIR(6));
	wrefresh(w);
}

void map_vines(WINDOW *w)
{
	mvwaddch(w, 10, 4, ACS_ULCORNER);
	mvwaddch(w, 11, 4, ACS_URCORNER);
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

void map_gameDone(WINDOW *w, int x)
{
	map_starFall(w);
	if (x == -1)
	{
		map_loseScreen(w);
	}
	else if (x == -2)
	{
		map_winScreen(w);
	}
	else
	{
		map_quitScreen(w);
	}
	wrefresh(w);
}

void map_starFall(WINDOW *w)
{
	int y = 1;
	while (y < MAX_Y - 1)
	{
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

void map_loseScreen(WINDOW *w)
{
	mvwprintw(w, 15, 15, "You Lost");
	mvwprintw(w, 24, 15, "Press any key to continue.");
}

void map_winScreen(WINDOW *w)
{
	mvwprintw(w, 15, 15, "You Won");
	mvwprintw(w, 24, 15, "Press any key to continue.");
}

void map_quitScreen(WINDOW *w)
{
	mvwprintw(w, 15, 15, "  |||||||    ||      ||   ||   ||||||||||||");
	mvwprintw(w, 16, 15, "||       ||  ||      ||   ||        ||");
	mvwprintw(w, 17, 15, "||       ||  ||      ||   ||        ||");
	mvwprintw(w, 18, 15, "||       ||  ||      ||   ||        ||");
	mvwprintw(w, 19, 15, " ||||||||||  ||      ||   ||        ||");
	mvwprintw(w, 20, 15, "         ||   ||    ||    ||        ||");
	mvwprintw(w, 21, 15, "         ||     ||||      ||        ||");
	mvwprintw(w, 24, 15, "Press any key to continue.");
}