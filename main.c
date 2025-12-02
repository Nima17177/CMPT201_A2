void readFile(FILE *f)
{
        int y, x, s;
        char buffer;
        while (fscanf(f, "%d, %d, %d\n", &y, &x, &s) == 3)
        {
                mvhline(y, x, ACS_HLINE, s);
        }
        buffer = fgetc(f); // Consume line between coordinate sets.
        while (fscanf(f, "%d, %d, %d\n", &y, &x, &s) == 3)
        {
                mvvline(y, x, ACS_VLINE, s);
        }
        buffer = fgetc(f);
        while (fscanf(f, "%d, %d\n", &y, &x) == 2)
        {
                mvaddch(y, x, ACS_ULCORNER);
        }
        buffer = fgetc(f);
        while (fscanf(f, "%d, %d\n", &y, &x) == 2)
        {
                mvaddch(y, x, ACS_LLCORNER);
        }
        buffer = fgetc(f);
        while (fscanf(f, "%d, %d\n", &y, &x) == 2)
        {
                mvaddch(y, x, ACS_LRCORNER);
        }
        buffer = fgetc(f);
        while (fscanf(f, "%d, %d\n", &y, &x) == 2)
        {
                mvaddch(y, x, ACS_URCORNER);
        }
        buffer = fgetc(f);
}

void splashPage(WINDOW *w)
{
        box(w, 0, 0);
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
        FILE *f = fopen("splashpage.txt", "r");
                // MAC
                attron(COLOR_PAIR(3));
                readFile(f);
                // PAN
                attron(COLOR_PAIR(1));
                readFile(f);
        fclose(f);
        attron(COLOR_PAIR(6));
        // -
        mvaddch(6, 38, ACS_ULCORNER);
        mvaddch(7, 38, ACS_LLCORNER);
        mvhline(7, 39, ACS_HLINE, 3);
        mvaddch(7, 42, ACS_LRCORNER);
        mvaddch(6, 42, ACS_URCORNER);
        mvhline(6, 39, ACS_HLINE, 3);
        attron(COLOR_PAIR(5));
        mvprintw(11, 2, "                            (not Pac-Man)                                     ");
        mvprintw(14, 2, "                     Nathan Alex Sequeira (3141620)                           ");
        mvprintw(15, 2, "                         Nima Houshyar (xxxxxxx)                              ");
        attron(COLOR_PAIR(2));
        mvprintw(19, 2, "                              Controls                                        ");
        mvprintw(20, 2, "                      Use <arrows> to move player                             ");
        mvprintw(21, 2, "                  Press <space> to activate teleporter                        ");
        mvprintw(22, 2, "  After collecting a powerup, press <1> or <2> to freeze half of the enemies  ");
        attron(COLOR_PAIR(7));
        mvprintw(26, 2, "                        Press <E> to start easy.                              ");
        mvprintw(27, 2, "                        Press <H> to start hard.                              ");
        wrefresh(w);
        refresh();
}

int main(void)
{
        WINDOW *w;
        initscr(); // Initialize window
        noecho(); // Entered keys are not printed on the screen.
        curs_set(FALSE); // Don't display a cursor
        w = newwin(30, 80, 1, 1); // Window size
        box(w, 0, 0); // Default border to window.
        wrefresh(w);
        refresh();
        splashPage(w);
        // Call level.
        if (mvinch(2, 68) == ACS_HLINE)
        {
                printf("True");
        }
        else
        {
                printf("False");
        }
        getch();
        endwin();
        return 0;
}