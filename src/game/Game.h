//
// Created by jessica on 16/09/19.
//

#ifndef DONCEY_KONG_JR_GAME_H
#define DONCEY_KONG_JR_GAME_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WIDTH 1080
#define HEIGHT 768

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

    int xPoss;
    int yPoss;
    Monkey monkey;

    int sizeMult;
    SDL_Renderer *renderer;

    SDL_Texture *background_img;
    SDL_Texture *monkey_img;
    SDL_Texture *blueCroco_img;
    SDL_Texture *redCroco_img;
    SDL_Texture *banana_img;
    SDL_Texture *mango_img;
    SDL_Texture *apple_img;

} Game;


int processEvents(SDL_Window *window, Game *game);
void initializeGame(SDL_Window *window, Game *game);
void gameRender(Game *game);
void loadGraphics(Game *game);
void closeWindow(SDL_Window *window, Game *game);

#endif //DONCEY_KONG_JR_GAME_H