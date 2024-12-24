#include "GameTile.h"
#define MAP_SIZE 10

typedef struct gameMap {
    GameTile *tiles[MAP_SIZE][MAP_SIZE];
    int size;
} GameMap;

void GameMap_Init(GameMap *gameMap);
void GameMap_Destroy(GameMap *gameMap);