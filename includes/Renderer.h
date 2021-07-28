#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

// Custom Headers
#include <Utils.h>
#include <config.h>

// Third Party Headers
#include <SDL2/SDL.h>

// SDL Renderer Class
class Renderer
{
private:
    int width;                  // Window Width
    int height;                 // Window Height
    SDL_Window *window;         // Renderer Window
    SDL_Surface *screenSurface; // Renderer Surface

public:
    // Default Renderer Constructor
    Renderer(int width_ = SCREEN_WIDTH, int height_ = SCREEN_HEIGHT)
    {
        width = width_;
        height = height_;
        window = NULL;
        screenSurface = NULL;
    }

    // Sets up SDL for the Renderer and returns completion status
    bool init_sdl()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            Log("COULD NOT INITIALIZE SDL!!!");
            Print("ERROR: ");
            Print(SDL_GetError());
            return false;
        }
        return true;
    }

    // Sets up Window for the Renderer and returns completion status
    bool setup_window(const char *title)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  width, height, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            Log("COULD NOT CREATE WINDOW!!!");
            Print("ERROR: ");
            Print(SDL_GetError());
            return false;
        }
        return true;
    }

    // Returns the window
    SDL_Window *get_window()
    {
        return window;
    }

    // Destroys the Window
    void destroy_window()
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Sets up the Screen
    void setup_screen()
    {
        screenSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);
    }

    // Waits for the the given number of seconds
    void wait_seconds(unsigned int seconds)
    {
        SDL_Delay(1000 * seconds);
    }
};

#endif // SDL_RENDERER_H
