#include "Game.h"


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
    controller->ledges[ledgeAmount-4].w = SCREEN_WIDTH*0.81;

    controller->ledges[ledgeAmount-5].x = 200;
    controller->ledges[ledgeAmount-5].y = 470;
    controller->ledges[ledgeAmount-5].w = SCREEN_WIDTH*0.17;

    controller->ledges[ledgeAmount-6].x = 840;
    controller->ledges[ledgeAmount-6].y = 400;
    controller->ledges[ledgeAmount-6].w = SCREEN_WIDTH*0.2;
}

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
            if(monkey->animFrame < 3)
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
    //Check for collision with any ledges (brick blocks)
    for(int i = 0; i < ledgeAmount; i++)
    {
        float mw = controller->monkey.width, mh = controller->monkey.height;
        float mx = controller->monkey.x, my = controller->monkey.y;
        float bx = controller->ledges[i].x, by = controller->ledges[i].y;
        float bw = controller->ledges[i].w, bh = controller->ledges[i].h;

        if(mx+mw/2 > bx && mx+mw/2 < bx+bw)
        {
            //are we bumping our head?
            if(my < by+bh && my > by && controller->monkey.dy < 0)
            {
                //correct y
                controller->monkey.y = by+bh;
                my = by+bh;

                //bumped our head, stop any jump velocity
                controller->monkey.dy = 0;
                controller->monkey.onLedge = 1;
            }
        }

        if(mx+mw > bx && mx<bx+bw)
        {
            //are we landing on the ledge
            if(my+mh > by && my < by && controller->monkey.dy > 0)
            {
                //correct y
                controller->monkey.y = by-mh;
                my = by-mh;

                //landed on this ledge, stop any jump velocity
                controller->monkey.dy = 0;
                controller->monkey.onLedge = 1;
            }
        }

        if(my+mh > by && my<by+bh)
        {
            //rubbing against right edge
            if(mx < bx+bw && mx+mw > bx+bw && controller->monkey.dx < 0)
            {
                //correct x
                controller->monkey.x = bx+bw;
                mx = bx+bw;

                controller->monkey.dx = 0;
            }
                //rubbing against left edge
            else if(mx+mw > bx && mx < bx && controller->monkey.dx > 0)
            {
                //correct x
                controller->monkey.x = bx-mw;
                mx = bx-mw;

                controller->monkey.dx = 0;
            }
        }
    }
}

int eventManager(SDL_Window *window, Controller *controller)
{
    SDL_Event event;
    int finish = 0;

    if (controller->monkey.dead == 1){
        endGame();
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
                    finish = 1;
                }
            }
                break;
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        finish = 1;
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
                finish = 1;
                break;
        }
    }

    //Jumping
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    Monkey *monkey = &controller->monkey;
    if(state[SDL_SCANCODE_UP])
    {
        monkey->dy -= 0.2f;
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
            endGame();
        }

    }

    return finish;
}

void render(SDL_Renderer *renderer, Controller *controller)
{
    //set the drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    //Clear the screen
    SDL_RenderClear(renderer);


    for(int i = 0; i < ledgeAmount; i++)
    {
        SDL_Rect ledgeRect = { controller->ledges[i].x, controller->ledges[i].y,
                               controller->ledges[i].w, controller->ledges[i].h };
        SDL_RenderCopy(renderer, controller->ledge_img, NULL, &ledgeRect);
    }

    //draw a rectangle at monkey's position
    SDL_Rect rect = { controller->monkey.x, controller->monkey.y, controller->monkey.width, controller->monkey.height};


    /*
     * SDL_RenderCopyEx:
     * arg0 renderer
     * arg1 texture
     * arg2, arg3 rect
     * arg4 angle
     * arg5 point (center)
     * arg6 renderFlip
     */
    SDL_RenderCopyEx(renderer, controller->monkeyFrames[controller->monkey.animFrame],
                     NULL, &rect, 0, NULL, (controller->monkey.facingLeft == 0));



    //Show on the screen
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
    Controller controller;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    srandom((int)time(NULL));

    //Create window
    window = SDL_CreateWindow("controller Window",               //Title
                              SDL_WINDOWPOS_UNDEFINED,           //x position
                              SDL_WINDOWPOS_UNDEFINED,           //y position
                              SCREEN_WIDTH,                      //width
                              SCREEN_HEIGHT,                     //height, in pixels
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    controller.renderer = renderer;

    loadGraphics(&controller);

    //Enter loop
    int finish = 0;

    //Event loop
    while(!finish)
    {
        finish = eventManager(window, &controller);

        move(&controller);
        collisionDetect(&controller);

        //Render
        render(renderer, &controller);

        SDL_Delay(10);
    }

    closeWindow(window, controller);
    return 0;
}


void endGame(){
    SDL_Quit();
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

    // Clean up
    SDL_Quit();
}