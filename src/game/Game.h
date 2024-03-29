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
#include "../client/Cliente.h"
#include "../entities/Donkey.h"

//Players
Monkey *monkey;

//Donkey
Donkey *donkey;

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
void initDonkey();
void initLedges();
void initRopes();
void initCroco(int rope, int isRed, int speed);
void initFruit(int rope, int type, int pos);
void initializeGame(SDL_Window *window, Controller *controller, int lives, int crocoSpeed);
int getRope(int rope);
void endGame(SDL_Window *window, Controller *controller, int win);
void update();
void freeMemory();

