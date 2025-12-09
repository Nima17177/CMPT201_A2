#include "sprite.h"

sprite sprite_createPlayer(int playerLives)
{
 	sprite player;
	player.yPos = 0;
	player.xPos = 0;
	player.yVel = 1;
	player.xVel = 0;
	player.life = playerLives;
 	player.tile = ' ';
	player.symbol = '*';
	return player;
}

sprite sprite_createEnemy(int i)
{
	sprite enemy;
	enemy.yPos = 0;
	enemy.xPos = 0;
	enemy.yVel = 1;
	enemy.xVel = 0;
	enemy.life = 0;
	enemy.tile = ' ';
	enemy.symbol = (char)(i+64); // Convert to upper case alphabet
	return enemy;
}

void sprite_reset(WINDOW *w, sprite *player, int enemyCount, sprite *enemies)
{
	mvwaddch(w, player->yPos, player->xPos, ' ');
	player->yPos = 24;
	player->xPos = 40;
	mvwaddch(w, player->yPos, player->xPos, player->symbol);
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i].life != 2) // If enemy is alive.
 		{
 			mvwaddch(w, enemies[i].yPos, enemies[i].xPos, ' ');
			enemies[i].yPos = 8;
			enemies[i].xPos = 37 + (i * 1.5);
			if (enemies[i].life == 1)
			{
				enemies[i].symbol = (enemies[i].symbol)-32; 
				mvwaddch(w, enemies[i].yPos, enemies[i].xPos, enemies[i].symbol);
				enemies[i].life = 0; // Unfreeze enemies.
			}
		}
	}
	wrefresh(w);
}

void sprite_move(WINDOW *w, sprite *s)
{
	mvwaddch(w, s->yPos, s->xPos, s->tile);
	s->yPos = s->yPos + s->yVel;
	s->xPos = s->xPos + s->xVel;
	s->tile = mvwinch(w, s->yPos, s->xPos);
	mvwaddch(w, s->yPos, s->xPos, s->symbol);
	wrefresh(w);
}

void sprite_changeVel(sprite *s)
{
	int randNum = rand() % 2;
	if (s->yVel == 0)
	{
		s->xVel = 0;
		if (randNum == 0)
		{
			s->yVel = 1;
  		}
		else
 		{
			s->yVel = -1;
		}
	}
	else if (s->xVel == 0)
	{
		s->yVel = 0;
		if (randNum == 0)
		{
			s->xVel = 1;
		}
		else
		{
			s->xVel = -1;
		}
	}
}
