// Custom Headers
#include <config.h>
#include <SDL2/SDL.h>

// Standard Headers
#include <iostream>

int WinMain(int argc, char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "COULD NOT INITIALIZE SDL!!!" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create Window
    // Window Declaration
    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "COULD NOT CREATE WINDOW!!!" << std::endl;
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    // Create Surface
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0, 0xFF));
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