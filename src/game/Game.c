//
// Created by jessica on 16/09/19.
//

#include "Game.h"

int processEvents(SDL_Window *window, Game *game){
    SDL_Event event;
    int done = 0;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_WINDOWEVENT_CLOSE:{
                if(window){
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
            }
                break;
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                }
            }
                break;
            case SDL_QUIT:
                done = 1;
                break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_LEFT]){
        game->monkey.xPoss -= 1*game->sizeMult;
    }
    if(state[SDL_SCANCODE_RIGHT]){
        game->monkey.xPoss += 1*game->sizeMult;
    }
    if(state[SDL_SCANCODE_UP]){
        game->monkey.yPoss -= 1*game->sizeMult;
    }
    if(state[SDL_SCANCODE_DOWN]){
        game->monkey.yPoss += 1*game->sizeMult;
    }
    return done;
}

void initializeGame(SDL_Window *window, Game *game){
    SDL_Init(SDL_INIT_VIDEO);

    game->sizeMult = 3;
    game->xPoss = 248*game->sizeMult;
    game->yPoss = 216*game->sizeMult;
    game->monkey.xPoss = 0;
    game->monkey.yPoss = game->yPoss-(4*(8*game->sizeMult));
    window = SDL_CreateWindow("Doncey Kong Jr",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH,
                              HEIGHT,
                              0);

    game->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void gameRender(Game *game){
    SDL_Rect backRect = {0, 0, game->xPoss, game->yPoss};
    SDL_RenderCopy(game->renderer, game->background_img, NULL, &backRect);

    SDL_Rect monkeyRect = {game->monkey.xPoss, game->monkey.yPoss, 25*game->sizeMult, 16*game->sizeMult};
    SDL_RenderCopy(game->renderer, game->monkey_img, NULL, &monkeyRect);
    SDL_RenderPresent(game->renderer);
}

void loadGraphics(Game *game){
    SDL_Surface *bgSurface = NULL;
    SDL_Surface *monkeySurface = NULL;
    SDL_Surface *bananaSurface = NULL;
    SDL_Surface *mangoSurface = NULL;
    SDL_Surface *appleSurface = NULL;
    SDL_Surface *blueCrocoSurface = NULL;
    SDL_Surface *redCrocoSurface = NULL;

    bgSurface = IMG_Load("../images/background.png");
    monkeySurface = IMG_Load("../images/dkjr.png");
    bananaSurface = IMG_Load("../images/banana.png");
    mangoSurface = IMG_Load("../images/mango.png");
    appleSurface = IMG_Load("../images/apple.png");
    blueCrocoSurface = IMG_Load("../images/blueCroco.png");
    redCrocoSurface = IMG_Load("../images/redCroco.png");

    if (bgSurface == NULL){
        printf("Cannot find background.png\n\n");
        SDL_Quit();
        exit(1);
    }
    if (monkeySurface == NULL){
        printf("Cannot find dkjr.png\n\n");
        SDL_Quit();
        exit(1);
    }    if (bananaSurface == NULL){
        printf("Cannot find banana.png\n\n");
        SDL_Quit();
        exit(1);
    }
    if (mangoSurface == NULL){
        printf("Cannot find mango.png\n\n");
        SDL_Quit();
        exit(1);
    }
    if (appleSurface == NULL){
        printf("Cannot find apple.png\n\n");
        SDL_Quit();
        exit(1);
    }
    if (blueCrocoSurface == NULL){
        printf("Cannot find blueCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }
    if (redCrocoSurface == NULL){
        printf("Cannot find redCroco.png\n\n");
        SDL_Quit();
        exit(1);
    }


    game->monkey_img = SDL_CreateTextureFromSurface(game->renderer, monkeySurface);
    game->background_img = SDL_CreateTextureFromSurface(game->renderer, bgSurface);
    game->banana_img = SDL_CreateTextureFromSurface(game->renderer, bananaSurface);
    game->mango_img = SDL_CreateTextureFromSurface(game->renderer, mangoSurface);
    game->apple_img = SDL_CreateTextureFromSurface(game->renderer, appleSurface);
    game->blueCroco_img = SDL_CreateTextureFromSurface(game->renderer, blueCrocoSurface);
    game->redCroco_img = SDL_CreateTextureFromSurface(game->renderer, redCrocoSurface);

    SDL_FreeSurface(monkeySurface);
    SDL_FreeSurface(bgSurface);
    SDL_FreeSurface(bananaSurface);
    SDL_FreeSurface(mangoSurface);
    SDL_FreeSurface(appleSurface);
    SDL_FreeSurface(blueCrocoSurface);
    SDL_FreeSurface(redCrocoSurface);
}

void closeWindow(SDL_Window *window, Game *game){
    SDL_DestroyTexture(game->monkey_img);
    SDL_DestroyTexture(game->background_img);
    SDL_DestroyTexture(game->blueCroco_img);
    SDL_DestroyTexture(game->redCroco_img);
    SDL_DestroyTexture(game->banana_img);
    SDL_DestroyTexture(game->mango_img);
    SDL_DestroyTexture(game->apple_img);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}