#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 800
#define HEIGHT 800

void fpsFunc(void* textP){
    sfTime time = sfSeconds(1.f);
    int sum = 0;
    char string[10];
    while (1){
        printf("Thread print\n");
        itoa(sum, string, 10);
        sfText_setString(textP, string);
        sfFloatRect rc = sfText_getLocalBounds(textP);
        printf("%f | %f\n", rc.width/2, rc.height/2);
        sfText_setOrigin(textP, (sfVector2f){rc.width/2, rc.height/2});
        sum++;
        sfSleep(time);
    }
}

void main(){
    sfVideoMode vm = {WIDTH,HEIGHT};
    sfFont *marioFont;
    sfText *text;
    sfView *view = sfView_create();
    sfRenderWindow *myWindow;
    sfColor color = sfBlack;

    marioFont = sfFont_createFromFile("fonts/Mario64.ttf");
    if (!marioFont)
        marioFont = sfFont_createFromFile("C:/coding/sfmlGame/bin/fonts/Mario64.ttf");
        if (!marioFont)
            return;
    text = sfText_create();
    sfText_setFont(text, marioFont);
    sfText_setCharacterSize(text, 100);
    sfText_setString(text, "Hello World");
    sfFloatRect rc = sfText_getLocalBounds(text);
    printf("%f | %f\n", rc.width/2, rc.height/2);
    sfText_setOrigin(text, (sfVector2f){rc.width/2, rc.height/2});
    sfText_setPosition(text, (sfVector2f) {WIDTH/2,HEIGHT/2});
    sfText_setColor(text, sfWhite);
    
    sfEvent event;
    myWindow = sfRenderWindow_create(vm, "Game", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(myWindow, 60);

    clock_t start;
    clock_t end;
    int diff;
    
    
    
    sfThread *thread1;

    thread1 = sfThread_create(&fpsFunc, (void *)text);
    sfThread_launch(thread1);
    
    int angle = 0;

    while (sfRenderWindow_isOpen(myWindow)){
        //start = clock();
        while (sfRenderWindow_pollEvent(myWindow, &event)){
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(myWindow);
            }
            if (event.type == sfEvtResized){
                sfVector2f scrnSize = (sfVector2f){(float)event.size.width, (float)event.size.height};
                sfView_setSize(view, scrnSize);
                scrnSize.x /= 2; scrnSize.y /= 2;
                sfView_setCenter(view, scrnSize);
                
                sfRenderWindow_setView(myWindow, view);
            }
        }
        angle++;
        if (angle >= 360) {
            angle = 0;
        }
        
        //sfText_setRotation(text, angle);

        sfRenderWindow_clear(myWindow, color);

        sfRenderWindow_drawText(myWindow, text, NULL);
        sfRenderWindow_display(myWindow);

        //end = clock();
        //printf("time per frame: %dms\n", end-start);
    }

    
    sfText_destroy(text);
    sfView_destroy(view);
    sfFont_destroy(marioFont);
    sfRenderWindow_destroy(myWindow);
    sfThread_terminate(thread1);
}
