#include <stdio.h>
#include <time.h>
#include "../entities/Controller.h"
#include "../Util/GlobalVariables.h"


//Players
Monkey *monkey;

//Ledges/Ropes
Ledge **ledges;
Rope **ropes;

int eventManager(SDL_Window *window, Controller *controller);
void render(Controller *controller);
void createWindow(SDL_Window *window, Controller *controller);
void animate(Controller *controller);
void initMonkey(int lives);
void initLedges();
void initRopes();
void initializeGame(SDL_Window *window, Controller *controller, int lives);
void endGame(SDL_Window *window, Controller *controller, int win);

