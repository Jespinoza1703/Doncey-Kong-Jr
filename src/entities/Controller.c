//
// Created by atlas on 22/09/19.
//

#include "Controller.h"

void initScene(Controller *controller, int screenWidth, int lives){

    controller->monkey.x = 320-40;
    controller->monkey.y = 240-40;
    controller->monkey.width = 80;
    controller->monkey.height = 50;
    controller->monkey.lives = lives;
    controller->monkey.dx = 0;
    controller->monkey.dy = 0;
    controller->monkey.onLedge = 0;
    controller->monkey.animFrame = 0;
    controller->monkey.facingLeft = 1;
    controller->monkey.slowingDown = 0;

    controller->time = 0;

    //init ledges
    for(int i = 0; i < ledgeAmount; i++)
    {
        controller->ledges[i].h = 25;
    }
    controller->ledges[ledgeAmount-1].x = 10;
    controller->ledges[ledgeAmount-1].y = 195;
    controller->ledges[ledgeAmount-1].w = screenWidth*0.6;

    controller->ledges[ledgeAmount-2].x = 615;
    controller->ledges[ledgeAmount-2].y = 225;
    controller->ledges[ledgeAmount-2].w = screenWidth*0.25;

    controller->ledges[ledgeAmount-3].x = 250;
    controller->ledges[ledgeAmount-3].y = 100;
    controller->ledges[ledgeAmount-3].w = screenWidth*0.08;

    controller->ledges[ledgeAmount-4].x = 200;
    controller->ledges[ledgeAmount-4].y = 330;
    controller->ledges[ledgeAmount-4].w = screenWidth*0.11;

    controller->ledges[ledgeAmount-5].x = 200;
    controller->ledges[ledgeAmount-5].y = 470;
    controller->ledges[ledgeAmount-5].w = screenWidth*0.17;

    controller->ledges[ledgeAmount-6].x = 840;
    controller->ledges[ledgeAmount-6].y = 400;
    controller->ledges[ledgeAmount-6].w = screenWidth*0.2;
}



void collisionDetect(Controller *controller)
{
    Monkey *monkey = &controller->monkey;
    //Check for collision with any ledges (brick blocks)
    for(int i = 0; i < ledgeAmount; i++)
    {
        float ledgeX = controller->ledges[i].x, ledgeY = controller->ledges[i].y;
        float ledgeWidth = controller->ledges[i].w, ledgeHeight = controller->ledges[i].h;

        if(monkey->x+monkey->width/2 > ledgeX && monkey->x+monkey->width/2 < ledgeX+ledgeWidth)
        {
            //are we bumping our head?
            if(monkey->y < ledgeY+ledgeHeight && monkey->y > ledgeY && controller->monkey.dy < 0)
            {
                //correct y
                controller->monkey.y = ledgeY+ledgeHeight;
                monkey->y = ledgeY+ledgeHeight;

                //bumped our head, stop any jump velocity
                controller->monkey.dy = 0;
                controller->monkey.onLedge = 1;
            }
        }

        if(monkey->x+monkey->width > ledgeX && monkey->x<ledgeX+ledgeWidth)
        {
            //are we landing on the ledge
            if(monkey->y+monkey->height > ledgeY && monkey->y < ledgeY && controller->monkey.dy > 0)
            {
                //correct y
                controller->monkey.y = ledgeY-monkey->height;
                monkey->y = ledgeY-monkey->height;

                //landed on this ledge, stop any jump velocity
                controller->monkey.dy = 0;
                controller->monkey.onLedge = 1;
            }
        }

        if(monkey->y+monkey->height > ledgeY && monkey->y<ledgeY+ledgeHeight)
        {
            //rubbing against right edge
            if(monkey->x < ledgeX+ledgeWidth && monkey->x+monkey->width > ledgeX+ledgeWidth && controller->monkey.dx < 0)
            {
                //correct x
                controller->monkey.x = ledgeX+ledgeWidth;
                monkey->x = ledgeX+ledgeWidth;

                controller->monkey.dx = 0;
            }
                //rubbing against left edge
            else if(monkey->x+monkey->width > ledgeX && monkey->x < ledgeX && controller->monkey.dx > 0)
            {
                //correct x
                controller->monkey.x = ledgeX-monkey->width;
                monkey->x = ledgeX-monkey->width;

                controller->monkey.dx = 0;
            }
        }
    }
}


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


}


//Free all memory
void closeWindow(SDL_Window *window, Controller *controller) {
    SDL_DestroyTexture(controller->monkeyFrames[0]);
    SDL_DestroyTexture(controller->monkeyFrames[1]);
    SDL_DestroyTexture(controller->monkeyFrames[2]);
    SDL_DestroyTexture(controller->monkeyFrames[3]);
    SDL_DestroyTexture(controller->monkeyFrames[4]);
    SDL_DestroyTexture(controller->blueCrocoFrames[0]);
    SDL_DestroyTexture(controller->blueCrocoFrames[1]);
    SDL_DestroyTexture(controller->blueCrocoFrames[2]);
    SDL_DestroyTexture(controller->blueCrocoFrames[3]);
    SDL_DestroyTexture(controller->blueCrocoFrames[4]);
    SDL_DestroyTexture(controller->redCrocoFrames[0]);
    SDL_DestroyTexture(controller->redCrocoFrames[1]);
    SDL_DestroyTexture(controller->redCrocoFrames[2]);
    SDL_DestroyTexture(controller->redCrocoFrames[3]);
    SDL_DestroyTexture(controller->redCrocoFrames[4]);
    SDL_DestroyTexture(controller->livesFrames[0]);
    SDL_DestroyTexture(controller->livesFrames[1]);
    SDL_DestroyTexture(controller->livesFrames[2]);
    SDL_DestroyTexture(controller->livesFrames[3]);
    SDL_DestroyTexture(controller->banana_img);
    SDL_DestroyTexture(controller->mango_img);
    SDL_DestroyTexture(controller->apple_img);
    SDL_DestroyTexture(controller->ledge_img);

    // Destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(controller->renderer);
}
