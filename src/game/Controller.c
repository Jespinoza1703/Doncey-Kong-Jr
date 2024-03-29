//
// Created by Jesica on 18/09/19.
//

#include "Controller.h"
#include "../entities/Crocodile.h"
#include "../entities/Fruit.h"


//Load images and create rendering textures from them
void loadGraphics(Controller *controller) {
    SDL_Surface *surface = NULL;

    /*
     * In case images can't be found with the specified path
     */
    surface = IMG_Load("../images/junior/jrStanding.png");
    if (surface == NULL) {
        printf("Cannot find jrStanding.png\n\n");
        SDL_Quit();
        exit(1);
    }

    /*
     * Monkey
     */
    controller->monkeyFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/junior/jrWalkLeft.png");
    if (surface == NULL) {
        printf("Cannot find jrWalkLeft.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/junior/jrWalkLeft2.png");
    if (surface == NULL) {
        printf("Cannot find jrWalkLeft2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/junior/jrWalkLeft3.png");
    if (surface == NULL) {
        printf("Cannot find jrWalkLeft3.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/junior/jumping.png");
    if (surface == NULL) {
        printf("Cannot find jumping.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[4] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/fruits/banana.png");
    if (surface == NULL) {
        printf("Cannot find banana.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->monkeyFrames[5] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    /*
     * Fruits
     */
    surface = IMG_Load("../images/fruits/banana.png");
    if (surface == NULL) {
        printf("Cannot find banana.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->banana_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/fruits/mango.png");
    if (surface == NULL) {
        printf("Cannot find mango.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->mango_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/fruits/apple.png");
    if (surface == NULL) {
        printf("Cannot find apple.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->apple_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    /*
     * Blue Crocodile
     */
    surface = IMG_Load("../images/blueCroco.png");
    if (surface == NULL) {
        printf("Cannot find blueCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->blueCrocoFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/blueCroco1.png");
    if (surface == NULL) {
        printf("Cannot find blueCroco1.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->blueCrocoFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/blueCroco2.png");
    if (surface == NULL) {
        printf("Cannot find blueCroco2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->blueCrocoFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/blueCroco3.png");
    if (surface == NULL) {
        printf("Cannot find blueCroco4.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->blueCrocoFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    /*
     * Red Crocodile
     */
    surface = IMG_Load("../images/redCroco.png");
    if (surface == NULL) {
        printf("Cannot find redCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->redCrocoFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/redCroco1.png");
    if (surface == NULL) {
        printf("Cannot find redCroco1.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->redCrocoFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/redCroco2.png");
    if (surface == NULL) {
        printf("Cannot find redCroco2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->redCrocoFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/redCroco3.png");
    if (surface == NULL) {
        printf("Cannot find redCroco3.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->redCrocoFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    /*
     * Ledge
     */
    surface = IMG_Load("../images/ledge.png");
    if (surface == NULL) {
        printf("Cannot find ledge.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ledge_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    /*
     * Donkey kong
     */
    surface = IMG_Load("../images/donkey.png");
    if (surface == NULL) {
        printf("Cannot find donkey.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->donkeyK_img = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    /*
     * Hearts (Lives)
     */
    surface = IMG_Load("../images/lives/hearts0.png");
    if (surface == NULL) {
        printf("Cannot find hearts0.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->livesFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/lives/hearts1.png");
    if (surface == NULL) {
        printf("Cannot find hearts1.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->livesFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/lives/hearts2.png");
    if (surface == NULL) {
        printf("Cannot find hearts2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->livesFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/lives/hearts3.png");
    if (surface == NULL) {
        printf("Cannot find hearts3.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->livesFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../images/ropes/rope1.png");
    if (surface == NULL) {
        printf("Cannot find rope1.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[0] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope2.png");
    if (surface == NULL) {
        printf("Cannot find rope2.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[1] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope3.png");
    if (surface == NULL) {
        printf("Cannot find rope3.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[2] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope4.png");
    if (surface == NULL) {
        printf("Cannot find rope4.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[3] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope5.png");
    if (surface == NULL) {
        printf("Cannot find rope5.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[4] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope6.png");
    if (surface == NULL) {
        printf("Cannot find rope6.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[5] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope7.png");
    if (surface == NULL) {
        printf("Cannot find rope7.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[6] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../images/ropes/rope8.png");
    if (surface == NULL) {
        printf("Cannot find rope8.png\n\n");
        SDL_Quit();
        exit(1);
    }
    controller->ropeFrames[7] = SDL_CreateTextureFromSurface(controller->renderer, surface);
    SDL_FreeSurface(surface);

}

void renderLedges(Controller *controller, Ledge **ledges){
    for(int i = 0; i < LEDGEAMOUNT; i++)
    {
        SDL_Rect ledgeRect = {ledges[i]->x, ledges[i]->y,
                              ledges[i]->width, ledges[i]->height};
        SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &ledgeRect);
    }
}

void renderRopes(Controller *controller, Rope **ropes){

    for(int i = 0; i < ROPEAMOUNT; i++)
    {
        SDL_Rect ropeRect = {ropes[i]->x, ropes[i]->y,
                             ropes[i]->width, ropes[i]->height};
        SDL_RenderCopy(controller->renderer, controller->ropeFrames[i], NULL, &ropeRect);
    }
}


void renderCrocos(Controller *controller, LinkedList *crocos) {

    for (int i = 0; i < getSize(crocos); i++) {
        Crocodile *croco = (Crocodile *)getNode(crocos, i)->value;

        SDL_Rect crocoRect = {
                croco->x, croco->y,
                croco->width, croco->height
        };

        if(croco->isRed){
            SDL_RenderCopy(controller->renderer, controller->redCrocoFrames[croco->animFrame], NULL, &crocoRect);
        }else{
            SDL_RenderCopy(controller->renderer, controller->blueCrocoFrames[croco->animFrame], NULL, &crocoRect);
        }
    }
}

void renderFruits(Controller *controller, LinkedList *fruits) {

    for (int i = 0; i < getSize(fruits); i++) {
        Fruit *fruit = (Crocodile *)getNode(fruits, i)->value;

        SDL_Rect fruitRect = {
                fruit->x, fruit->y,
                fruit->width, fruit->height
        };

        if(fruit->type == 2){
            SDL_RenderCopy(controller->renderer, controller->apple_img, NULL, &fruitRect);
        }

        if(fruit->type == 3){
            SDL_RenderCopy(controller->renderer, controller->banana_img, NULL, &fruitRect);
        }

        if(fruit->type == 4){
            SDL_RenderCopy(controller->renderer, controller->mango_img, NULL, &fruitRect);
        }
    }
}


void renderLives(Controller *controller, Monkey *monkey){

    SDL_Rect livesRect = {800, 10, 150, 46};
    SDL_RenderCopy(controller->renderer, controller->livesFrames[monkey->lives],
                   NULL, &livesRect);

}

void renderDonkey(Controller *controller){

    SDL_Rect donkeyKRect = {10, 110, 141, 85};
    SDL_RenderCopy(controller->renderer, controller->donkeyK_img, NULL, &donkeyKRect);
}

//Free all memory
void closeWindow(SDL_Window *window, Controller *controller) {

    for(int i; i < MONKEYFRAMES; i++){
        SDL_DestroyTexture(controller->monkeyFrames[i]);
    }
    for(int i; i < BLUECROCOFRAMES; i++){
        SDL_DestroyTexture(controller->blueCrocoFrames[i]);
    }
    for(int i; i < REDCROCOFRAMES; i++){
        SDL_DestroyTexture(controller->redCrocoFrames[i]);
    }
    for(int i; i < LIVESFRAMES; i++){
        SDL_DestroyTexture(controller->redCrocoFrames[i]);
    }
    for(int i; i < ROPEAMOUNT; i++){
        SDL_DestroyTexture(controller->redCrocoFrames[i]);
    }

    SDL_DestroyTexture(controller->banana_img);
    SDL_DestroyTexture(controller->mango_img);
    SDL_DestroyTexture(controller->apple_img);
    SDL_DestroyTexture(controller->ledge_img);

    // Destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(controller->renderer);
}
