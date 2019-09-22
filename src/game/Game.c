#include "Game.h"

int eventManager(SDL_Window *window, Controller *controller)
{
    SDL_Event event;

    if (controller->monkey.lives <= 0){
        endGame(window, controller, 0);
    }

    while(SDL_PollEvent(&event))
    {

        switch(event.type)
        {
            case SDL_WINDOWEVENT_CLOSE:
            {
                if(window)
                {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    controller->end = 1;
                }
            }
                break;
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        controller->end = 1;
                        break;
                    case SDLK_UP:
                        if(controller->monkey.onLedge)
                        {
                            controller->monkey.dy = -4;
                            controller->monkey.onLedge = 0;
                        }
                        break;
                }
            }
                break;
            case SDL_QUIT:
                //quit out of the controller
                controller->end = 1;
                break;
        }
    }

    //Jumping
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    Monkey *monkey = &controller->monkey;
    if(state[SDL_SCANCODE_UP])
    {
        monkey->dy -= 0.2f;
        monkey->animFrame = 4;
    }

    //Walking
    if(state[SDL_SCANCODE_LEFT])
    {
        if(monkey->x > 0){
            monkey->dx -= 0.25;
            if(monkey->dx < -SPEED)
            {
                monkey->dx = -SPEED;
            }
            monkey->facingLeft += 1;
            monkey->slowingDown = 0;
        }
        else{
            monkey->x = 0;
        }
    }

    else if(state[SDL_SCANCODE_RIGHT])
    {
        if(monkey->x < (SCREEN_WIDTH - monkey->width)){
            monkey->dx += 0.25;
            if(monkey->dx > SPEED)
            {
                monkey->dx = SPEED;
            }
            monkey->facingLeft = 0;
            monkey->slowingDown = 0;
        }
        else{
            monkey->x = (SCREEN_WIDTH - monkey->width);
        }
    }

    else{
        if(monkey->y < (SCREEN_HEIGHT)){
            monkey->animFrame = 0;
            monkey->dx *= 0.5f;
            monkey->slowingDown = 1;
            if(fabsf(monkey->dx) < 0.1f){
                monkey->dx = 0;
            }
        }
        if(monkey->y >= SCREEN_HEIGHT){
            monkey->lives -= 1;
            initializeGame(window, controller, monkey->lives);
        }

    }

    return controller->end;
}

void render(Controller *controller)
{
    //set the drawing color to black
    SDL_SetRenderDrawColor(controller->renderer, 0, 0, 0, 0);

    //Clear the screen
    SDL_RenderClear(controller->renderer);

    for(int i = 0; i < ledgeAmount; i++)
    {
        SDL_Rect ledgeRect = { controller->ledges[i].x, controller->ledges[i].y,
                               controller->ledges[i].w, controller->ledges[i].h };
        SDL_RenderCopy(controller->renderer, controller->ledge_img, NULL, &ledgeRect);
    }

    //draw a rectangle at monkey's position
    SDL_Rect rect = {controller->monkey.x, controller->monkey.y,
                     controller->monkey.width, controller->monkey.height};

    SDL_Rect donkeyKRect = {10, 110, 141, 85};
    SDL_RenderCopy(controller->renderer, controller->donkeyK_img, NULL, &donkeyKRect);



    /*
     * Flips monkey images if facing right
     */
    SDL_RenderCopyEx(controller->renderer, controller->monkeyFrames[controller->monkey.animFrame],
                     NULL, &rect, 0, NULL, (controller->monkey.facingLeft == 0));


    SDL_Rect livesRect = {800, 10, 150, 46};
    SDL_RenderCopy(controller->renderer, controller->livesFrames[controller->monkey.lives],
            NULL, &livesRect);

    //Show on the screen
    SDL_RenderPresent(controller->renderer);
}


void createWindow(SDL_Window *window, Controller *controller){

    SDL_Init(SDL_INIT_EVERYTHING);
    srandom((int)time(NULL));
    controller->end = 0;

//Create window
    window = SDL_CreateWindow("controller Window",               //Title
                              SDL_WINDOWPOS_UNDEFINED,           //x position
                              SDL_WINDOWPOS_UNDEFINED,           //y position
                              SCREEN_WIDTH,                      //width
                              SCREEN_HEIGHT,                     //height, in pixels
                              0);

    controller->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}


void animateMonkey(Controller *controller)
{
    //add time
    controller->time++;

    //monkey movement
    Monkey *monkey = &controller->monkey;
    monkey->x += monkey->dx;
    monkey->y += monkey->dy;

    if(monkey->dx != 0 && monkey->onLedge && !monkey->slowingDown)
    {
        if(controller->time % 15 == 0)
        {
            if(monkey->animFrame < 4)
            {
                monkey->animFrame++;
            }
            else
            {
                monkey->animFrame = 1;
            }
        }
    }
    monkey->dy += GRAVITY;
}






void initializeGame(SDL_Window *window, Controller *controller, int lives){

    loadGraphics(controller);
    initScene(controller, SCREEN_WIDTH, lives);

    //Event loop
    while(controller->end != 1)
    {
        eventManager(window, controller);

        //Render
        render(controller);
        animateMonkey(controller);
        collisionDetect(controller);

        SDL_Delay(10);
    }

    closeWindow(window, &controller);
}


void endGame(SDL_Window *window, Controller *controller, int win){

    if(win == 1){
        initializeGame(window, controller, 3);
    }
    else{
        if(controller->time % 50 == 0){
            initializeGame(window, controller, 3);
        }
    }

}
