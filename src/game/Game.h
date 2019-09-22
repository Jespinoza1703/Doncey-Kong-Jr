#include <stdio.h>
#include <time.h>
#include "../entities/Controller.h"

#define SCREEN_WIDTH 980
#define SCREEN_HEIGHT 668
#define SPEED 6
#define GRAVITY  0.32f


int eventManager(SDL_Window *window, Controller *controller);
void render(Controller *controller);
void moveMonkey(Controller *controller);
void initializeGame(SDL_Window *window, Controller *controller, int lives);
void createWindow(SDL_Window *window, Controller *controller);
void endGame(SDL_Window *window, Controller *controller, int win);

