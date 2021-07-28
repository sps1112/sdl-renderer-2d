// Custom Headers
#include <Utils.h>
#include <config.h>
#include <SDL2/SDL.h>

// Standard Headers
#include <iostream>

int WinMain(int argc, char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Log("COULD NOT INITIALIZE SDL!!!");
        Print("ERROR: ");
        Print(SDL_GetError());
        return -1;
    }

    // Create Window
    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        Log("COULD NOT CREATE WINDOW!!!");
        Print("ERROR: ");
        Print(SDL_GetError());
        return -1;
    }

    // Create Surface
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);

    /*// Setup Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
   */

    // Free Data
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}