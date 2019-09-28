
#include "Game.h"
#include "../entities/Crocodile.h"
#include "../entities/Fruit.h"

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
        if(monkey->onRope) moveUp(monkey);
    }

    //Rope climbing
    if(state[SDL_SCANCODE_DOWN])
    {
        if(monkey->onRope) moveDown(monkey);
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
    if(monkey->gravity) monkey->y += GRAVITY;

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
    if(getSize(fruits) > 0) renderFruits(controller, fruits);

    //draw a rectangle at monkey's position
    SDL_Rect monkeyRect = {monkey->x, monkey->y,
                     monkey->width, monkey->height};
    //Flips monkey images if facing right
    SDL_RenderCopyEx(controller->renderer, controller->monkeyFrames[monkey->animFrame],
                     NULL, &monkeyRect, 0, NULL, (monkey->facingLeft == 0));



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
        animateCroco(crocos);
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
    monkey->gravity = 1;
}

//init ledges
void initLedges(){

    ledges = (Ledge**) malloc(sizeof(Ledge*) * LEDGEAMOUNT);
    ledges[LEDGEAMOUNT-1] = newLedge(10, 195, SCREEN_WIDTH*0.5, 25);
    ledges[LEDGEAMOUNT-2] = newLedge(590, 160, SCREEN_WIDTH*0.25, 25);
    ledges[LEDGEAMOUNT-3] = newLedge(250, 100, SCREEN_WIDTH*0.08, 25);
    ledges[LEDGEAMOUNT-4] = newLedge(200, 330, SCREEN_WIDTH*0.11, 25);
    ledges[LEDGEAMOUNT-5] = newLedge(200, 470, SCREEN_WIDTH*0.17, 25);
    ledges[LEDGEAMOUNT-6] = newLedge(840, 400, SCREEN_WIDTH*0.2, 25);

}

//init ropes
void initRopes(){

    ropes = (Rope**) malloc(sizeof(Rope*) * ROPEAMOUNT);

    ropes[0] = newRope(0, 210, 24, 217);
    ropes[1] = newRope(150, 210, 26, 179);
    ropes[2] = newRope(300, 210, 19, 232);
    ropes[3] = newRope(450, 210, 24, 135);
    ropes[4] = newRope(600, 180, 20, 272);
    ropes[5] = newRope(750, 180, 20, 279);
    ropes[6] = newRope(900, 140, 18, 500);
    ropes[7] = newRope(1050, 210, 19, 263);
}

void initCroco(int rope, int isRed){

    Crocodile *croco = (Crocodile*) malloc(sizeof(Crocodile));
    croco->isRed = isRed;
    croco->width = 60;
    croco->height = 40;
    croco->x = 100;
    croco->y = 150;
    croco->dx = 0;
    croco->dy = 0;
    if(isRed == 1) croco->rope = ropes[getRope(rope)];
    if(isRed == 0) croco->rope = ropes[getRope(rand() % 8)];
    croco->facingDown = 0;
    croco->facingUp = 0;
    croco->animFrame = 0;
    Node *node = newNode(croco);
    insertNode(crocos, node);
}

void initFruit(int rope, int type, int pos){

    Fruit *fruit = (Fruit*) malloc(sizeof(Fruit));
    fruit->type = type;
    fruit->width = 45;
    fruit->height = 45;
    fruit->rope = ropes[getRope(rope)];
    fruit->y = 0;
    fruit->relativePos = pos + fruit->rope->y;
    fruit->x = fruit->rope->x;
    Node *node = newNode(fruit);
    insertNode(fruits, node);
}

void initializeGame(SDL_Window *window, Controller *controller, int lives){

    loadGraphics(controller);
    initMonkey(lives);
    initLedges();
    initRopes();
    crocos = newList();
    fruits = newList();
    initCroco(5, 0);
    initFruit(4, 2, 50);

    controller->time = 0;

    //Event loop
    while(controller->end != 1)
    {
        eventManager(window, controller);

        //Render
        render(controller);
        animate(controller);

        //collisions
        ledgeCollision(monkey, ledges);
        if(crocoCollision(monkey, crocos)) {
            freeMemory();
            initializeGame(window, controller, monkey->lives);
            break;
        }
        if(ropeCollision(monkey, ropes)){
            monkey->onRope = 1;
            monkey->gravity = 0;
        }else
            monkey->gravity = 1;
        if(getSize(fruits) > 0) fruitCollision(monkey, fruits);

        if(controller->time % 500 == 0) monkey->isColliding = 0;

        for (int i = 0; i < getSize(crocos); i++) {

            Crocodile *croco = (Crocodile *)getNode(crocos, i)->value;
            if(croco->y < SCREEN_HEIGHT)
                crocoMove(croco);
            else
                deleteNode(crocos, getNode(crocos, i));
        }
        for (int i = 0; i < getSize(fruits); i++) {

            Fruit *fruit = (Fruit *)getNode(fruits, i)->value;
            setFruit(fruit);
        }


        SDL_Delay(5);
    }

    closeWindow(window, &controller);
    freeMemory();
}


int getRope(int rope){
    int result = -1;
    for(int i = 0; i < ROPEAMOUNT; i++){
        if(result != rope){
            result++;
        }
        else return result;
    }
    return result;
}



void endGame(SDL_Window *window, Controller *controller, int win){

    if(win == 1){
        freeMemory();
        initializeGame(window, controller, 3);
    }
    else{
        if(controller->time % 50 == 0){
            freeMemory();
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