#include "Game.h"



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


void initScene(Controller *controller){

    controller->monkey.x = 320-40;
    controller->monkey.y = 240-40;
    controller->monkey.width = 80;
    controller->monkey.height = 50;
    controller->monkey.dead = 0;
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
    controller->ledges[ledgeAmount-1].w = SCREEN_WIDTH*0.6;

    controller->ledges[ledgeAmount-2].x = 615;
    controller->ledges[ledgeAmount-2].y = 225;
    controller->ledges[ledgeAmount-2].w = SCREEN_WIDTH*0.25;

    controller->ledges[ledgeAmount-3].x = 250;
    controller->ledges[ledgeAmount-3].y = 100;
    controller->ledges[ledgeAmount-3].w = SCREEN_WIDTH*0.08;

    controller->ledges[ledgeAmount-4].x = 200;
    controller->ledges[ledgeAmount-4].y = 330;
    controller->ledges[ledgeAmount-4].w = SCREEN_WIDTH*0.11;

    controller->ledges[ledgeAmount-5].x = 200;
    controller->ledges[ledgeAmount-5].y = 470;
    controller->ledges[ledgeAmount-5].w = SCREEN_WIDTH*0.17;

    controller->ledges[ledgeAmount-6].x = 840;
    controller->ledges[ledgeAmount-6].y = 400;
    controller->ledges[ledgeAmount-6].w = SCREEN_WIDTH*0.2;
}


void move(Controller *controller)
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

int eventManager(SDL_Window *window, Controller *controller)
{
    SDL_Event event;

    if (controller->monkey.dead == 1){
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
        if(monkey->y <= (SCREEN_HEIGHT)){
            monkey->animFrame = 0;
            monkey->dx *= 0.5f;
            monkey->slowingDown = 1;
            if(fabsf(monkey->dx) < 0.1f){
                monkey->dx = 0;
            }
        }
        else{
            monkey->dead = 1;
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
    SDL_Rect rect = {controller->monkey.x, controller->monkey.y, controller->monkey.width, controller->monkey.height};

    SDL_Rect donkeyKRect = {10, 110, 141, 85};
    SDL_RenderCopy(controller->renderer, controller->donkeyK_img, NULL, &donkeyKRect);

    /*
     * SDL_RenderCopyEx:
     * arg0 renderer
     * arg1 texture
     * arg2, arg3 rect
     * arg4 angle
     * arg5 point (center)
     * arg6 renderFlip
     */
    SDL_RenderCopyEx(controller->renderer, controller->monkeyFrames[controller->monkey.animFrame],
                     NULL, &rect, 0, NULL, (controller->monkey.facingLeft == 0));


    //Show on the screen
    SDL_RenderPresent(controller->renderer);
}




void endGame(SDL_Window *window, Controller *controller, int win){

    if(win == 1){
        closeWindow(window, controller);
    }
    else{
        if(controller->time % 50 == 0) initializeGame(window, controller);
    }

}

//Free all memory
void closeWindow(SDL_Window *window, Controller *controller) {
    SDL_DestroyTexture(controller->monkeyFrames[0]);
    SDL_DestroyTexture(controller->monkeyFrames[1]);
    SDL_DestroyTexture(controller->monkeyFrames[2]);
    SDL_DestroyTexture(controller->monkeyFrames[3]);
    SDL_DestroyTexture(controller->ledge_img);

    // Destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(controller->renderer);
}

void initializeGame(SDL_Window *window, Controller *controller){

    loadGraphics(controller);

    //Event loop
    while(controller->end != 1)
    {
        eventManager(window, controller);

        //Render
        render(controller);
        move(controller);
        collisionDetect(controller);

        SDL_Delay(10);
    }

    closeWindow(window, &controller);
}