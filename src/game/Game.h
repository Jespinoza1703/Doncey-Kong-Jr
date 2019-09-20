#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <time.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 768
#define SPEED 0.8
#define GRAVITY  0.18
#define num 15

typedef struct
{
    float x, y;
    float dx, dy;
    short life;
    int onLedge;

    int animFrame, facingLeft, slowingDown;
} Monkey;


typedef struct
{
    int x, y, w, h;

} Ledge;


typedef struct
{
    //Players
    Monkey monkey;

    //Ledges
    Ledge ledges[num];

    //Images
    SDL_Texture *monkeyFrames[2];
    SDL_Texture *brick;

    int time;

    //Renderer
    SDL_Renderer *renderer;

} Controller;


void loadSurfaces(Controller *controller);
void process(Controller *controller);
void collisionDetect(Controller *controller);
int processEvents(SDL_Window *window, Controller *controller);
void render(SDL_Renderer *renderer, Controller *controller);
