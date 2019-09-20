//
// Created by jessica on 16/09/19.
//

#ifndef DONCEY_KONG_JR_GAME_H
#define DONCEY_KONG_JR_GAME_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 768

#define movingSpeed 5

/*
 * Defining structs for entities in the game
 * structs: monkey, fruits, crocodiles
 */

typedef struct{

    int xPoss;
    int yPoss;
    int width;
    int height;

} Monkey;



typedef struct{

    int xPoss;
    int yPoss;
    int width;
    int height;
    int type;
} Fruit;


typedef struct{

    int xPoss;
    int yPoss;
    int width;
    int height;
    int type;

} Crocodile;


typedef struct{

    SDL_Rect rect;

} Ledge;


/*
 * Controller structure
 */
typedef struct{

    int xPoss;
    int yPoss;
    Monkey monkey;

    Ledge ledges[5];
    Ledge trees[4];

    SDL_Renderer *renderer;

    // Image textures
    SDL_Texture *background_img;
    SDL_Texture *monkey_img;
    SDL_Texture *donkeyK_img;
    SDL_Texture *banana_img;
    SDL_Texture *mango_img;
    SDL_Texture *apple_img;
    SDL_Texture *blueCroco_img;
    SDL_Texture *redCroco_img;
    SDL_Texture *ledge_img;

} Controller;


int eventProcessing(SDL_Window *window, Controller *controller);
void start(SDL_Window *window, Controller *controller);
void gameRendering(Controller *controller);
void loadSurfaces(Controller *controller);
void closeWindow(SDL_Window *window, Controller *controller);

#endif //DONCEY_KONG_JR_GAME_H