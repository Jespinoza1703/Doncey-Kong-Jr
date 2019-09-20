//
// Created by jessica on 16/09/19.
//

#include "Game.h"

int eventProcessing(SDL_Window *window, Controller *controller){
    SDL_Event event;
    int finish = 0;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_WINDOWEVENT_CLOSE:{
                if(window){
                    SDL_DestroyWindow(window);
                    window = NULL;
                    finish = 1;
                }
            }
                break;
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        finish = 1;
                        break;
                }
            }
                break;
            case SDL_QUIT:
                finish = 1;
                break;
        }
    }

    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if(keyboardState[SDL_SCANCODE_LEFT]){
        controller->monkey.xPoss -= movingSpeed;
    }
    if(keyboardState[SDL_SCANCODE_RIGHT]){
        controller->monkey.xPoss += movingSpeed;
    }
    if(keyboardState[SDL_SCANCODE_SPACE]){
        controller->monkey.yPoss -= movingSpeed;
    }

    return finish;
}

void start(SDL_Window *window, Controller *controller){

    SDL_Init(SDL_INIT_EVERYTHING);

    controller->monkey.xPoss = 0;
    controller->monkey.yPoss = 630;

    window = SDL_CreateWindow("Doncey Kong Jr",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              0);
    controller->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void gameRendering(Controller *controller){

    SDL_Rect bgRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(controller->renderer, controller->background_img, NULL, &bgRect);
    SDL_Rect monkeyRect = {controller->monkey.xPoss, controller->monkey.yPoss,
                           SCREEN_WIDTH*0.1, SCREEN_HEIGHT*0.1};
    SDL_RenderCopy(controller->renderer, controller->monkey_img, NULL, &monkeyRect);

    SDL_Rect donkeyK = {0, 100, 140, 85};
    SDL_RenderCopy(controller->renderer, controller->donkeyK_img, NULL, &donkeyK);

    // Render ledges
    SDL_Rect ledgeRect0 = {10, 195,
                          SCREEN_WIDTH*0.6, 25};
    controller->ledges[0].rect = ledgeRect0;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[0].rect);

    SDL_Rect ledgeRect1 = {615, 225,
                          SCREEN_WIDTH*0.25, 25};
    controller->ledges[1].rect = ledgeRect1;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[1].rect);

    SDL_Rect ledgeRect2 = {250, 100,
                          SCREEN_WIDTH*0.08, 25};
    controller->ledges[2].rect = ledgeRect2;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[2].rect);

    SDL_Rect ledgeRect3 = {200, 330,
                          SCREEN_WIDTH*0.11, 25};
    controller->ledges[3].rect = ledgeRect3;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[3].rect);

    SDL_Rect ledgeRect4 = {200, 470,
                          SCREEN_WIDTH*0.17, 25};
    controller->ledges[4].rect = ledgeRect4;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[4].rect);

    SDL_Rect ledgeRect5 = {840, 400,
                           SCREEN_WIDTH*0.2, 25};
    controller->ledges[5].rect = ledgeRect5;
    SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &controller->ledges[5].rect);



    SDL_RenderPresent(controller->renderer);
}

/*
 * Loads all the necessary images
 */
void loadSurfaces(Controller *controller){
    SDL_Surface *bgSurface = NULL;
    SDL_Surface *monkeySurface = NULL;
    SDL_Surface *bananaSurface = NULL;
    SDL_Surface *mangoSurface = NULL;
    SDL_Surface *appleSurface = NULL;
    SDL_Surface *blueCrocoSurface = NULL;
    SDL_Surface *redCrocoSurface = NULL;
    SDL_Surface *ledgeSurface = NULL;
    SDL_Surface *donkeyKSurface = NULL;

    bgSurface = IMG_Load("../images/background.png");
    monkeySurface = IMG_Load("../images/dkjr.png");
    bananaSurface = IMG_Load("../images/banana.png");
    mangoSurface = IMG_Load("../images/mango.png");
    appleSurface = IMG_Load("../images/apple.png");
    blueCrocoSurface = IMG_Load("../images/blueCroco.png");
    redCrocoSurface = IMG_Load("../images/redCroco.png");
    ledgeSurface = IMG_Load("../images/ledge.png");
    donkeyKSurface = IMG_Load("../images/donkey.png");

    /*
     * In case images can't be found with the specified path
     */
    if (bgSurface == NULL){
        printf("Cannot find background.png");
        SDL_Quit();
        exit(1);
    }
    if (monkeySurface == NULL){
        printf("Cannot find dkjr.png");
        SDL_Quit();
        exit(1);
    }    if (bananaSurface == NULL){
        printf("Cannot find banana.png");
        SDL_Quit();
        exit(1);
    }
    if (mangoSurface == NULL){
        printf("Cannot find mango.png");
        SDL_Quit();
        exit(1);
    }
    if (appleSurface == NULL){
        printf("Cannot find apple.png");
        SDL_Quit();
        exit(1);
    }
    if (blueCrocoSurface == NULL){
        printf("Cannot find blueCroco.png");
        SDL_Quit();
        exit(1);
    }
    if (redCrocoSurface == NULL){
        printf("Cannot find redCroco.png");
        SDL_Quit();
        exit(1);
    }
    if (ledgeSurface == NULL){
        printf("Cannot find ledge.png");
        SDL_Quit();
        exit(1);
    }
    if (donkeyKSurface == NULL){
        printf("Cannot find donkey.png");
        SDL_Quit();
        exit(1);
    }

    /*
     * Creating textures for images
     */
    controller->monkey_img = SDL_CreateTextureFromSurface(controller->renderer, monkeySurface);
    controller->background_img = SDL_CreateTextureFromSurface(controller->renderer, bgSurface);
    controller->banana_img = SDL_CreateTextureFromSurface(controller->renderer, bananaSurface);
    controller->mango_img = SDL_CreateTextureFromSurface(controller->renderer, mangoSurface);
    controller->apple_img = SDL_CreateTextureFromSurface(controller->renderer, appleSurface);
    controller->blueCroco_img = SDL_CreateTextureFromSurface(controller->renderer, blueCrocoSurface);
    controller->redCroco_img = SDL_CreateTextureFromSurface(controller->renderer, redCrocoSurface);
    controller->ledge_img = SDL_CreateTextureFromSurface(controller->renderer, ledgeSurface);
    controller->donkeyK_img = SDL_CreateTextureFromSurface(controller->renderer, donkeyKSurface);

    SDL_FreeSurface(monkeySurface);
    SDL_FreeSurface(bgSurface);
    SDL_FreeSurface(bananaSurface);
    SDL_FreeSurface(mangoSurface);
    SDL_FreeSurface(appleSurface);
    SDL_FreeSurface(blueCrocoSurface);
    SDL_FreeSurface(redCrocoSurface);
    SDL_FreeSurface(ledgeSurface);
    SDL_FreeSurface(donkeyKSurface);
}


void closeWindow(SDL_Window *window, Controller *controller){
    SDL_DestroyTexture(controller->monkey_img);
    SDL_DestroyTexture(controller->background_img);
    SDL_DestroyTexture(controller->blueCroco_img);
    SDL_DestroyTexture(controller->redCroco_img);
    SDL_DestroyTexture(controller->banana_img);
    SDL_DestroyTexture(controller->mango_img);
    SDL_DestroyTexture(controller->apple_img);
    SDL_DestroyTexture(controller->ledge_img);
    SDL_DestroyTexture(controller->donkeyK_img);
    SDL_DestroyRenderer(controller->renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}