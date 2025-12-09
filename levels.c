#include "levels.h"
#include "sprite.h"
#include "map.h"

void display_level(int i, WINDOW *w)
{
	//WINDOW *w = newwin(MAX_Y, MAX_X, ORIGIN_Y, ORIGIN_X);
	box(w, 0, 0);
	wrefresh(w);
	if (i == 0)
	{
		map_createEasy(w);
		map_createUi(w, 5, 2);
		level_createSprites(w, 5, 2);
	}
	else
	{
		map_createHard(w);
		map_createUi(w, 3, 8);
		level_createSprites(w, 3, 8);
	}
}

void level_createSprites(WINDOW *w, int playerLives, int enemyCount)
{
	sprite player = sprite_createPlayer(playerLives);
	sprite enemies[enemyCount];
	for (int i = 0; i < enemyCount; i++)
	{
		enemies[i] = sprite_createEnemy(i+1);
	}
	sprite_reset(w, &player, enemyCount, enemies);
	level_run(w, player, enemyCount, enemies);
}

void level_run(WINDOW *w, sprite player, int enemyCount, sprite enemies[enemyCount])
{
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE); // The program does not stop for the player input.
	int input;
	time_t stoppedTime = 0; // Amount of time since enemies were frozen.
	int stoppedEnemy = -1; // Which enemy was frozen. 0 = odd enemies, 1 = even enemies
	int enemiesLeft = enemyCount;
	int gameStage = 0; // 0 = running, 1 = paused, -3 = quit, -2 = won game, -1 = lost game
	while (gameStage >= 0)
	{
		input = getch();
		if (input != ERR) // If key has been pressed.
		{
			level_checkInput(w, input, &gameStage, &stoppedTime, &stoppedEnemy, &player, enemyCount, enemies);
		}
		if (gameStage == 0)
		{
			level_updateFrame(w, &stoppedTime, stoppedEnemy, &player, enemyCount, enemies);
			level_checkCollision(w, &stoppedTime, &player, enemyCount, enemies, &enemiesLeft);
			if (enemiesLeft == 0)
			{
				gameStage = -2;
			}
			else if (player.life == 0)
			{
				gameStage = -1;
			}
			if (stoppedTime > 0)
			{
				map_updateTime(w, (15-(time(NULL)-stoppedTime))); 
			}
		}
		napms(150);
	}
	map_gameDone(w, gameStage);
	nodelay(stdscr, FALSE); 
	//endwin();
	//delwin(w);
	wclear(w);   
}

void level_checkInput(WINDOW *w, int input, int *gameStage, time_t *stoppedTime, int *stoppedEnemy, sprite *player, int enemyCount, sprite *enemies)
{
	if (input == 'q') // Quit
	{
		*gameStage = -3;
	}
	else if (input == 'p')
	{
		*gameStage = (((*gameStage)+1) % 2); // Increment by 1 and then wrap around.
	}
	if (*gameStage != 1)
	{
		if (input == KEY_RIGHT)
		{
			player->xVel = 1;
			player->yVel = 0;
		}
		else if (input == KEY_LEFT)
		{
			player->xVel = -1;
			player->yVel = 0;
		}
		else if (input == KEY_UP)
		{
			player->xVel = 0;
			player->yVel = -1;
		}
		else if (input == KEY_DOWN)
		{
			player->xVel = 0;
			player->yVel = 1;
		}
		if ((input == '1' || input == '2') && (map_isPower(w, player->tile) == true) && (*stoppedTime == 0))
		{
			*stoppedTime = time(NULL);
			*stoppedEnemy = ((int)(input-'0')) - 1;
			for (int i = *stoppedEnemy; i < enemyCount; i+=2)
			{
				if (enemies[i].life == 0) // Alive & Moving
				{
					enemies[i].life = 1; // Frozen
					enemies[i].symbol = (enemies[i].symbol)+32;
					mvwaddch(w, enemies[i].yPos, enemies[i].xPos, enemies[i].symbol);
				}
			}
		}
		if (input == 32) // Space bar
		{
			int y, x;
			y = player->yPos;
			x = player->xPos;
			map_isPortal(w, &y, &x);
			if (y != -1)
			{
				mvwaddch(w, player->yPos, player->xPos, player->tile);
				player->yPos = y;
				player->xPos = x;
				mvwaddch(w, player->yPos, player->xPos, player->symbol);
			}
		}
	}
}

void level_updateFrame(WINDOW *w, time_t *stoppedTime, int stoppedEnemy, sprite *player, int enemyCount, sprite *enemies)
{
	if (map_isWall(w, ((player->yPos)+(player->yVel)), ((player->xPos)+(player->xVel))) == false)
	{
		sprite_move(w, player);
	}
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i].life == 0) // Alive & Moving
		{
			int randNum0 = rand() % 5;
			char nextTile = mvwinch(w, ((enemies[i].yPos)+(enemies[i].yVel)), ((enemies[i].xPos)+(enemies[i].xVel))); 
			if ((randNum0 == 0) || (map_isWall(w, ((enemies[i].yPos)+(enemies[i].yVel)), ((enemies[i].xPos)+(enemies[i].xVel))) == true) || (nextTile >= 65 && nextTile <= 90) || (nextTile >= 97 && nextTile <= 122)) // If random chance says yes, or going to move into a wall, or going to move into another enemy (alphabet), then change direction.
			{
				sprite_changeVel(&enemies[i]);
			}
			else
			{
				sprite_move(w, &enemies[i]);
			}
		}
	}
	if (*stoppedTime > 0) // There are some frozen enemies
	{
		if ((time(NULL) - *stoppedTime) >= 15) // Cooldown 15 seconds. Unfreeze enemies.
		{
			*stoppedTime = 0;
			map_updateTime(w, 0); 
			for (int i = stoppedEnemy; i < enemyCount; i+=2)
			{
				if (enemies[i].life == 1) // Enemy is Alive & Frozen. Do this check so that we don't unfreeze dead enemies.
				{
					enemies[i].life = 0;
					enemies[i].symbol = (enemies[i].symbol)-32;
					mvwaddch(w, enemies[i].yPos, enemies[i].xPos, enemies[i].symbol);
				}
			}
		}
	}
}

void level_checkCollision(WINDOW *w, time_t *stoppedTime, sprite *player, int enemyCount, sprite *enemies, int *enemiesLeft)
{
	for (int i = 0; i < enemyCount; i++)
	{
		if ((enemies[i].life != 2) && ((enemies[i].tile == player->symbol) || (player->tile == enemies[i].symbol))) // Enemy is not dead, and player and enemy are over the same tile.
		{
			enemies[i].tile = ' ';
			player->tile = ' ';
			if (enemies[i].life == 1) // Enemy is frozen
			{
				map_decrementEnemies(w, enemiesLeft);
				mvwaddch(w, enemies[i].yPos, enemies[i].xPos, ' ');
				// Set enemy to dead
				enemies[i].life = 2;
				enemies[i].symbol = ' ';
				*stoppedTime = *stoppedTime / 2; // Half frozen cooldown
			}
			else if (enemies[i].life == 0) // Enemy is not frozen
			{
				sprite_reset(w, player, enemyCount, enemies);
				map_decrementLives(w, &player->life);
				stoppedTime = 0;
				map_updateTime(w, 0); 
				break;
			}
		}
	}
}
