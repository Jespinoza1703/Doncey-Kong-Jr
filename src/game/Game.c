#include "Game.h"
#include "../entities/Crocodile.h"

int eventManager(SDL_Window *window, Controller *controller)
{
    SDL_Event event;

    if (monkey->lives <= 0){
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
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        controller->end = 1;
                        break;

                    case SDLK_UP:
                        break;
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

    if(state[SDL_SCANCODE_UP])
    {
        !monkey->isJumping;
        if(monkey->onLedge == 1) {
            jump(monkey);
        }
    }

    //Walking
    if(state[SDL_SCANCODE_LEFT])
    {
        moveLeft(monkey);
    }

    else if(state[SDL_SCANCODE_RIGHT])
    {
        moveRight(monkey);
    }

    else {
        monkeyStill(monkey);

        if (monkey->y >= SCREEN_HEIGHT) {
            monkey->lives--;
            freeMemory();
            initializeGame(window, controller, monkey->lives);
        }
    }
    monkey->y += GRAVITY;

    return controller->end;
}

void render(Controller *controller)
{
    //set the drawing color to black
    SDL_SetRenderDrawColor(controller->renderer, 0, 0, 0, 0);
    SDL_RenderClear(controller->renderer);

    renderLedges(controller, ledges);
    renderRopes(controller, ropes);
    renderLives(controller, monkey);
    renderDonkey(controller);
    if(getSize(crocos) > 0) renderCrocos(controller, crocos);

    //draw a rectangle at monkey's position
    SDL_Rect rect = {monkey->x, monkey->y,
                     monkey->width, monkey->height};
    //Flips monkey images if facing right
    SDL_RenderCopyEx(controller->renderer, controller->monkeyFrames[monkey->animFrame],
                     NULL, &rect, 0, NULL, (monkey->facingLeft == 0));




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


void animate(Controller *controller)
{
    //add time
    controller->time++;

    if(controller->time % 15 == 0) {
        animateMonkey(monkey);
    }

    monkey->dy += GRAVITY;
}


void initMonkey(int lives) {

    monkey = (Monkey*) malloc(sizeof(Monkey));
    monkey->x = 320 - 40;
    monkey->y = 240 - 40;
    monkey->width = 80;
    monkey->height = 50;
    monkey->lives = lives;
    monkey->dx = 0;
    monkey->dy = 0;
    monkey->onLedge = 0;
    monkey->animFrame = 0;
    monkey->facingLeft = 1;
    monkey->slowingDown = 0;
    monkey->isJumping = 0;
    monkey->isColliding = 0;
}

//init ledges
void initLedges(){

    ledges = (Ledge**) malloc(sizeof(Ledge*) * LEDGEAMOUNT);
    ledges[LEDGEAMOUNT-1] = newLedge(10, 195, SCREEN_WIDTH*0.6, 25);
    ledges[LEDGEAMOUNT-2] = newLedge(590, 160, SCREEN_WIDTH*0.25, 25);
    ledges[LEDGEAMOUNT-3] = newLedge(250, 100, SCREEN_WIDTH*0.08, 25);
    ledges[LEDGEAMOUNT-4] = newLedge(200, 330, SCREEN_WIDTH*0.11, 25);
    ledges[LEDGEAMOUNT-5] = newLedge(200, 470, SCREEN_WIDTH*0.17, 25);
    ledges[LEDGEAMOUNT-6] = newLedge(840, 400, SCREEN_WIDTH*0.2, 25);

}

//init ropes
void initRopes(){

    ropes = (Rope**) malloc(sizeof(Rope*) * ROPEAMOUNT);

    for(int i = 0; i < ROPEAMOUNT; i++)
    {
        ropes[i] = newRope(150*i, 210, 35, 272);
    }

    ropes[4]->y = 180;
    ropes[5]->y = 180;
    ropes[6]->y = 140;
    ropes[6]->height = 500;
}

void initCroco(int rope, int isRed){

    Crocodile *croco = (Crocodile*) malloc(sizeof(Crocodile));
    croco->isRed = isRed;
    croco->width = 60;
    croco->height = 40;
    croco->x = 100;
    croco->y = 280;
    croco->dx = 0;
    croco->dy = 0;
    croco->facingDown = 0;
    croco->facingUp = 0;
    croco->animFrame = 0;
    croco->onRope = 0;
    Node *node = newNode(croco);
    insertNode(crocos, node);

}

void initializeGame(SDL_Window *window, Controller *controller, int lives){

    loadGraphics(controller);
    initMonkey(lives);
    initLedges();
    initRopes();
    crocos = newList();
    initCroco(1, 0);

    controller->time = 0;

    //Event loop
    while(controller->end != 1)
    {
        eventManager(window, controller);

        //Render
        render(controller);
        animate(controller);
        ledgeCollision(monkey, ledges);
        if(crocoCollision(monkey, crocos)) {
            freeMemory();
            initializeGame(window, controller, monkey->lives);
            break;
        }
        if(controller->time % 100 == 0) monkey->isColliding = 0;

        crocoMove((Crocodile *)getNode(crocos, 0)->value);
        int k = controller->time;
        printf("%d\n", k);

        SDL_Delay(5);
    }

    closeWindow(window, &controller);
    freeMemory();
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

void freeMemory(){

    for(int i = 0; i < ROPEAMOUNT; i++)
        free(ropes[i]);
    for(int i = 0; i < LEDGEAMOUNT; i++)
        free(ledges[i]);
    free(monkey);
    //free(donkey);
    free(ropes);
    free(ledges);
}
