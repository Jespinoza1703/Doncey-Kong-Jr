//
// Created by atlas on 22/09/19.
//

#ifndef DONCEY_KONG_JR_CONTROLLER_H
#define DONCEY_KONG_JR_CONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"


#define ledgeAmount 15
#define ropeAmount 8

typedef struct
{
    float x, y;
    int width, height;
    int lives;
    float dx, dy;
    int onLedge;

    int animFrame, facingLeft, slowingDown;

} Monkey;


typedef struct
{
    double x, y, w, h;

} Ledge;

typedef struct
{
    double x, y, w, h;

} Rope;

typedef struct
{
    //Players
    Monkey monkey;

    //Ledges
    Ledge ledges[ledgeAmount];
    Rope ropes[ropeAmount];

    //Images
    SDL_Texture *monkeyFrames[5];
    SDL_Texture *livesFrames[4];
    SDL_Texture *ropeFrames[ropeAmount];
    SDL_Texture *blueCrocoFrames[5];
    SDL_Texture *redCrocoFrames[5];
    SDL_Texture *banana_img;
    SDL_Texture *mango_img;
    SDL_Texture *apple_img;
    SDL_Texture *ledge_img;
    SDL_Texture *donkeyK_img;

    int time;

    //Renderer
    SDL_Renderer *renderer;

    int end;

} Controller;


void initScene(Controller *controller, int screenWidth, int lives);
void loadGraphics(Controller *controller);
void collisionDetect(Controller *controller);
void closeWindow(SDL_Window *window, Controller *controller);


#endif //DONCEY_KONG_JR_CONTROLLER_H
