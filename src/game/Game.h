#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <time.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 768
#define SPEED 6
#define GRAVITY  0.32f
#define ledgeAmount 15

typedef struct
{
    float x, y;
    int width, height;
    float dx, dy;
    int dead;
    int onLedge;

    int animFrame, facingLeft, slowingDown;

} Monkey;


typedef struct
{
    double x, y, w, h;

} Ledge;


typedef struct
{
    //Players
    Monkey monkey;

    //Ledges
    Ledge ledges[ledgeAmount];

    //Images
    SDL_Texture *monkeyFrames[10];
    SDL_Texture *background_img;
    SDL_Texture *blueCroco_img;
    SDL_Texture *redCroco_img;
    SDL_Texture *banana_img;
    SDL_Texture *mango_img;
    SDL_Texture *apple_img;
    SDL_Texture *ledge_img;
    SDL_Texture *donkeyK_img;

    int time;

    //Renderer
    SDL_Renderer *renderer;

    int end;

} Controller;

void initializeGame();
void createWindow(SDL_Window *window, Controller *controller);
void initScene(Controller *controller);
void loadGraphics(Controller *controller);
int eventManager(SDL_Window *window, Controller *controller);
void render(Controller *controller);
void move(Controller *controller);
void collisionDetect(Controller *controller);
void endGame(SDL_Window *window, Controller *controller, int win);
void closeWindow(SDL_Window *window, Controller *controller);