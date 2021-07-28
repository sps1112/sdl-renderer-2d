// Custom Headers
#include <Utils.h>
#include <Renderer.h>
#include <config.h>

// Standard Headers
#include <iostream>

// Setup Renderer
Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);

// Main Function
int WinMain(int argc, char *argv[])
{
    // Initialize SDL
    if (!renderer.init_sdl())
    {
        return -1;
    }

    // Setup Window
    if (!renderer.setup_window(WINDOW_TITLE))
    {
        return -1;
    }

    // Create Surface
    renderer.setup_screen();

    // Render Loop
    renderer.wait_seconds(1);

    // Free Data
    renderer.destroy_window();
    return 0;
}
