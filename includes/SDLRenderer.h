#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

// Custom Headers
#include <Utils.h>
#include <config.h>

// Third Party Headers
#include <SDL2/SDL.h>

// SDL Renderer Class
class SDLRenderer
{
private:
    int width;              // Window Width
    int height;             // Window Height
    SDL_Window *window;     // Renderer Window
    SDL_Renderer *renderer; // The SDL Renderer
    // SDL_Surface *screenSurface; // Renderer Surface

    // Quits the SDL context
    void quit_sdl()
    {
        SDL_Quit();
    }

    // Destroys the Window
    void destroy_window()
    {
        SDL_DestroyWindow(window);
    }

    // Destroys the Renderer
    void destroy_renderer()
    {
        SDL_DestroyRenderer(renderer);
    }

    // Sets up SDL for the Renderer and returns completion status
    bool init_sdl()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            log_message("COULD NOT INITIALIZE SDL!!!");
            print_message("ERROR: ");
            print_message(SDL_GetError());
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
            log_message("COULD NOT CREATE WINDOW!!!");
            print_message("ERROR: ");
            print_message(SDL_GetError());
            quit_sdl();
            return false;
        }
        return true;
    }

    // Sets up the Renderer and returns the completion status
    bool setup_renderer()
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL)
        {
            log_message("COULD NOT CREATE RENDERER!!!");
            print_message("ERROR: ");
            print_message(SDL_GetError());
            destroy_window();
            quit_sdl();
            return false;
        }
        return true;
    }

public:
    // Default Renderer Constructor
    SDLRenderer(int width_ = SCREEN_WIDTH, int height_ = SCREEN_HEIGHT)
    {
        width = width_;
        height = height_;
        window = NULL;
        renderer = NULL;
        // screenSurface = NULL;
    }

    // Setups the SDL Context, Window and Renderer and returns the completion status
    bool setup_sdl_renderer(const char *title)
    {
        // Initialize SDL
        if (!init_sdl())
        {
            return false;
        }
        // Initialize Window
        if (!setup_window(title))
        {
            return false;
        }
        // Initialize Renderer
        if (!setup_renderer())
        {
            return false;
        }
        return true;
    }

    // Returns the window
    SDL_Window *get_window()
    {
        return window;
    }

    // Returns the Renderer
    SDL_Renderer *get_renderer()
    {
        return renderer;
    }

    // Sets Renderer Backgroung Color
    void set_renderer_color(Uint8 r, Uint8 g, Uint8 b)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    }

    // Waits for the the given number of seconds
    void wait_seconds(unsigned int seconds)
    {
        SDL_Delay(1000 * seconds);
    }

    // Waits for the the given number of seconds
    void wait_milliseconds(unsigned int milliseconds)
    {
        SDL_Delay(milliseconds);
    }

    // Frees all the Data
    void free_data()
    {
        destroy_renderer();
        destroy_window();
        quit_sdl();
    }
};

#endif // SDL_RENDERER_H
