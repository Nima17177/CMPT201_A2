#define PVEL 2
#define EVEL 1

typedef struct sprite; 
sprite createPlayer(void);
sprite createEnemy(char c); 
sprite moveSprite(sprite s); 
