//
// Created by atlas on 22/09/19.
//

#include "Loader.h"


void loadGraphics(Controller *controller)
{
    //Load images and create rendering textures from them
    SDL_Surface *surface = NULL;

    /*
     * In case images can't be found with the specified path
     */
    surface = IMG_Load("../images/jrStanding.png");
    if (surface == NULL){
        printf("Cannot find jrStanding.png\n\n");
        SDL_Quit();
        exit(1);
    }
    //Assigns images
    controller->monkeyFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/jrWalkLeft.png");
    if (surface == NULL){
        printf("Cannot find jrWalkLeft.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/jrWalkLeft2.png");
    if (surface == NULL){
        printf("Cannot find jrWalkLeft2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/jrWalkLeft3.png");
    if (surface == NULL){
        printf("Cannot find jrWalkLeft3.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/jumping.png");
    if (surface == NULL){
        printf("Cannot find jumping.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[4] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/background.png");
    if (surface == NULL) {
        printf("Cannot find background.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->background_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/banana.png");
    if (surface == NULL) {
        printf("Cannot find banana.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->banana_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/mango.png");
    if (surface == NULL) {
        printf("Cannot find mango.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->mango_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/apple.png");
    if (surface == NULL) {
        printf("Cannot find apple.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->apple_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/blueCroco.png");
    if (surface == NULL) {
        printf("Cannot find blueCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->blueCroco_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/redCroco.png");
    if (surface == NULL) {
        printf("Cannot find redCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->redCroco_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/ledge.png");
    if (surface == NULL) {
        printf("Cannot find ledge.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ledge_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/donkey.png");
    if (surface == NULL) {
        printf("Cannot find donkey.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->donkeyK_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    initScene(controller);
}