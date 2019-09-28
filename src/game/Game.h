#include <stdio.h>
#include <time.h>
#include "Controller.h"
#include "../Util/GlobalVariables.h"
#include "../entities/Monkey.h"
#include "../entities/Rope.h"
#include "../entities/Ledge.h"
#include "../entities/Crocodile.h"
#include "../Util/Collisions.h"
#include "../structures/LinkedList.h"


//Players
Monkey *monkey;

//Ledges/Ropes
Ledge **ledges;
Rope **ropes;
LinkedList *crocos;
LinkedList *fruits;

int eventManager(SDL_Window *window, Controller *controller);
void render(Controller *controller);
void createWindow(SDL_Window *window, Controller *controller);
void animate(Controller *controller);
void initMonkey(int lives);
void initLedges();
void initRopes();
void initCroco(int rope, int isRed);
void initFruit(int rope, int type);
void initializeGame(SDL_Window *window, Controller *controller, int lives);
int getRope(int rope);
void endGame(SDL_Window *window, Controller *controller, int win);
void freeMemory();

