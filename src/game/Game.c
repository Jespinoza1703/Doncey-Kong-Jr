#include "Game.h"


void init(Controller *controller){

    controller->monkey.x = 320-40;
    controller->monkey.y = 240-40;
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
        controller->ledges[i].w = 256;
        controller->ledges[i].h = 64;
        controller->ledges[i].x = i*256;
        controller->ledges[i].y = 400;
    }
    controller->ledges[ledgeAmount-1].x = 590;
    controller->ledges[ledgeAmount-1].y = 200;

    controller->ledges[ledgeAmount-2].x = 350;
    controller->ledges[ledgeAmount-2].y = 350;

}

void loadGraphics(Controller *controller)
{
    //Load images and create rendering textures from them
    SDL_Surface *surface = NULL;

    //Load images and create rendering textures from them
    surface = IMG_Load("../images/jrStanding.png");
    if (surface == NULL){
        printf("Cannot find jrStanding.png\n\n");
        SDL_Quit();
        exit(1);
    }
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


    init(controller);

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
                monkey->animFrame = 0;
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
        float mw = 25, mh = 16;
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
                            controller->monkey.dy = -2;
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
    if(state[SDL_SCANCODE_UP])
    {
        controller->monkey.dy -= 0.20;
    }

    //Walking
    if(state[SDL_SCANCODE_LEFT])
    {
        controller->monkey.dx -= 0.25;
        if(controller->monkey.dx < -SPEED)
        {
            controller->monkey.dx = -SPEED;
        }
        controller->monkey.facingLeft += 1;
        controller->monkey.slowingDown = 0;
    }

    else if(state[SDL_SCANCODE_RIGHT])
    {
        controller->monkey.dx += 0.25;
        if(controller->monkey.dx > SPEED)
        {
            controller->monkey.dx = SPEED;
        }
        controller->monkey.facingLeft = 0;
        controller->monkey.slowingDown = 0;
    }
    else{
        controller->monkey.animFrame = 0;
        controller->monkey.dx *= 0.08f;
        controller->monkey.slowingDown = 1;
        if(fabsf(controller->monkey.dx) < 0.01f){
            controller->monkey.dx = 0;
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
        SDL_RenderCopy(renderer, controller->ledge, NULL, &ledgeRect);
    }

    //draw a rectangle at monkey's position
    SDL_Rect rect = { controller->monkey.x, controller->monkey.y, 105, 70};
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
                              0                                  //flags
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    controller.renderer = renderer;

    loadGraphics(&controller);

    //Enter loop
    int finish = 0;

    //Event loop
    while(!finish)
    {
        //Check for events
        finish = eventManager(window, &controller);

        process(&controller);
        collisionDetect(&controller);

        //Render display
        render(renderer, &controller);

        SDL_Delay(10);
    }


    //Shutdown controller and unload all memory
    SDL_DestroyTexture(controller.monkeyFrames[0]);
    SDL_DestroyTexture(controller.monkeyFrames[1]);
    SDL_DestroyTexture(controller.monkeyFrames[2]);
    SDL_DestroyTexture(controller.monkeyFrames[3]);
    SDL_DestroyTexture(controller.ledge);

    // Destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();
    return 0;
}
