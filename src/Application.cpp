// Custom Headers
#include <Utils.h>
#include <SDLRenderer.h>
#include <config.h>

// Standard Headers
#include <iostream>

// Setup SDL Renderer
SDLRenderer sdlRenderer(SCREEN_WIDTH, SCREEN_HEIGHT);

// Main Function
int WinMain(int argc, char *argv[])
{
    // Initialize SDL
    if (!sdlRenderer.init_sdl())
    {
        return -1;
    }

    // Initialize Window
    if (!sdlRenderer.setup_window(WINDOW_TITLE))
    {
        return -1;
    }

    // Initialize Renderer
    if (!sdlRenderer.setup_renderer())
    {
        return -1;
    }
    sdlRenderer.set_renderer_color(255, 0, 255);

    // Load Surfaces to Textures
    // sdlRenderer.setup_screen();

    // Render Loop Start
    for (int i = 0; i < 200; i++)
    {
        // Check for Events
        // Check for Input
        // Setup Data
        sdlRenderer.set_renderer_color(i, 255 - i, i);

        // Render Objects
        SDL_RenderClear(sdlRenderer.get_renderer());
        // Draw Start
        // Draw End
        SDL_RenderPresent(sdlRenderer.get_renderer());
        // Refresh Screen
        sdlRenderer.wait_milliseconds(10);
        // Render Loop End
    }

    // Free Data
    sdlRenderer.destroy_window();
    return 0;
}
