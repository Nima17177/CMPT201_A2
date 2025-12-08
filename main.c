#include "levels.h"
#include "map.h"

#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#define SPLASHFILE "splashpage.txt"

/**
 * @brief Reads coordinates for the game title from a file.
 * @param The FILE pointer 'f' which contains the coordinates to read, and the WINDOW pointer 'w' which is the window to draw onto.
 * @pre The correct file has been opened, and the data written in it is in the pattern: "y_ratio, x_ratio, size_ratio(for_lines)/n". The coordinates are in blocks for horizontal lines, vertical lines, upper left corner, lower left corner, lower right corner, and upper right corner in that order. The blocks are separated by "X/n".
 * @post Part of the game title has been printed out.
 * @throws None
 * @returns None
 * @see splashPage
 * @note splashPage will call readFile twice, first to print "MAC" and then to print "PAN"
 */
void readFile(FILE *f, WINDOW *w)
{
	float yf, xf, sf;
	int yi, xi, si;
	while (fscanf(f, "%f, %f, %f\n", &yf, &xf, &sf) == 3)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		si = sf * MAX_X;
		mvhline(yi, xi, ACS_HLINE, si);
	}
	fgetc(f); // Consume line between coordinate sets.
	while (fscanf(f, "%f, %f, %f\n", &yf, &xf, &sf) == 3)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		si = sf * MAX_Y;
		mvvline(yi, xi, ACS_VLINE, si);
	}
	fgetc(f);
	while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		mvaddch(yi, xi, ACS_ULCORNER);
	}
	fgetc(f);
	while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		mvaddch(yi, xi, ACS_LLCORNER);
	}
	fgetc(f);
	while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		mvaddch(yi, xi, ACS_LRCORNER);
	}
	fgetc(f);
	while (fscanf(f, "%f, %f\n", &yf, &xf) == 2)
	{
		yi = yf * MAX_Y;
		xi = xf * MAX_X;
		mvaddch(yi, xi, ACS_URCORNER);
	}
	fgetc(f);
}

/**
 * @brief Draws out the splash page. Contains the game title, instructions for playing the game, and instructions to start/quit a level.
 * @param The WINDOW pointer 'w' which is the window to draw on.
 * @pre 'w' has been initialized properly. Also, the macros 'MAX_Y' and 'MAX_X' have been defined in "map.h"
 * @post The splash page has been drawn onto 'w'
 * @throws None
 * @returns None
 * @see main
 */
void splashPage(WINDOW *w)
{
	if (has_colors())
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
		init_pair(4, COLOR_BLUE, COLOR_BLACK);
		init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6, COLOR_CYAN, COLOR_BLACK);
		init_pair(7, COLOR_WHITE, COLOR_BLACK);
	}
	FILE *f = fopen(SPLASHFILE, "r");
		// MAC
		attron(COLOR_PAIR(3));
		readFile(f, w);
		// PAN
		attron(COLOR_PAIR(1));
		readFile(f, w);
	fclose(f);
	attron(COLOR_PAIR(6));
	// -
	mvaddch((int)(0.2*MAX_Y), (int)(0.475*MAX_X), ACS_ULCORNER);
	mvaddch((int)(0.234*MAX_Y), (int)(0.475*MAX_X), ACS_LLCORNER);
	mvhline((int)(0.234*MAX_Y), (int)(0.4875*MAX_X), ACS_HLINE, (int)(0.0375*MAX_X));
	mvaddch((int)(0.234*MAX_Y), (int)(0.525*MAX_X), ACS_LRCORNER);
	mvaddch((int)(0.2*MAX_Y), (int)(0.525*MAX_X), ACS_URCORNER);
	mvhline((int)(0.2*MAX_Y), (int)(0.4875*MAX_X), ACS_HLINE, (int)(0.0375*MAX_X));
	attron(COLOR_PAIR(5));
	char *message[] = {"(not Pac-Man)", "Nathan Alex Sequeira (3141620)", "Nima Houshyar (xxxxxxx)", "Controls", "Use <arrows> to move player", "Press <space> to activate portal", "When over a powerup, press <1> or <2> to freeze half of the enemies", "Press <P> to pause", "Press <Q> to quit ", "Press <E> to start easy", "Press <H> to start hard"};
	int y, x;
	attron(COLOR_PAIR(5));
	y = 0.367 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[0])/2);
	mvprintw(y, x, "%s", message[0]);
	y = 0.467 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[1])/2);
	mvprintw(y, x, "%s", message[1]);
	y = 0.5 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[2])/2);
	mvprintw(y, x, "%s", message[2]);
	attron(COLOR_PAIR(2));
	y = 0.6 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[3])/2);
	mvprintw(y, x, "%s", message[3]);
	y = 0.634 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[4])/2);
	mvprintw(y, x, "%s", message[4]);
	y = 0.67 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[5])/2);
	mvprintw(y, x, "%s", message[5]);
	y = 0.7 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[6])/2);
	mvprintw(y, x, "%s", message[6]);
	attron(COLOR_PAIR(7));
	y = 0.787 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[7])/2);
	mvprintw(y, x, "%s", message[7]);
	y = 0.8 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[8])/2);
	mvprintw(y, x, "%s", message[8]);
	y = 0.867 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[9])/2);
	mvprintw(y, x, "%s", message[9]);
	y = 0.9 * MAX_Y;
	x = (MAX_X/2) - (strlen(message[10])/2);
	mvprintw(y, x, "%s", message[10]);
	wrefresh(w);
}

/**
 * @brief Main function. Creates the window and calls function to create splash page and levels.
 * @param None
 * @pre "levels", "sprite" and "map" modules exist and have been compiled.
 * @post Runs the game
 * @throws None
 * @returns None
 */
int main(void)
{
	initscr(); // Initialize window.
	noecho(); // Entered keys are not printed on the screen.
	curs_set(FALSE); // Don't display a cursor.
	WINDOW *w = newwin(MAX_Y, MAX_X, ORIGIN_Y, ORIGIN_X);
	box(w, 0, 0);
	refresh();
	splashPage(w);
	while (1)
	{
		char input = getch();
		if (input == 'e' || input == 'h')
		{
			map_starFall(w);
			endwin();
			if (input == 'e')
			{
				display_level(0);
			}
			else
			{
				display_level(1);
			}
			w = newwin(MAX_Y, MAX_X, ORIGIN_Y, ORIGIN_X);
			box(w, 0, 0);
			splashPage(w);
			wrefresh(w);
		}
		else if (input == 'q')
		{
			map_starFall(w);
			break;
		}
	}
	endwin();
	curs_set(TRUE);
	return 0;
}



