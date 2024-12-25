#pragma once
#include <SFML/Graphics.h>

typedef enum {EAST, NORTH, WEST, SOUTH} DIRECTIONS;

typedef struct {
    sfRenderWindow *window;
    sfView *view;
    sfEvent *event;
    sfTime e;
} ARGS;
