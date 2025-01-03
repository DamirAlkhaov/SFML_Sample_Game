#pragma once
#include <SFML/Graphics.h>
#include "Bullet.h"
#include "Time.h"

typedef struct {
    sfSprite *playerSprite;
    clock_t lastShot;
    float stamina;
    float health;
    sfBool cooldown;
} Player;

void Player_Init(Player *player);

void Player_Destroy();

void Player_Shoot(ARGS *args, Player *player);

void Player_Collisions(ARGS *args, Player *player, sfSprite *objs[], float push);