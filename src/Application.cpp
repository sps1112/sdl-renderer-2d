// Custom Headers
#include <Utils.h>
#include <SDLRenderer.h>
#include <config.h>
#include <FileSystem.h>

// Standard Headers
#include <iostream>

// Setup SDL Renderer
SDLRenderer sdlRenderer(SCREEN_WIDTH, SCREEN_HEIGHT);

// Main Function
int WinMain(int argc, char *argv[])
{
    // Initialize SDL
    if (!sdlRenderer.setup_sdl_renderer(WINDOW_TITLE))
    {
        return -1;
    }

    // Load External Data
    SDL_Surface *bmp = SDL_LoadBMP(FileSystem::get_path("resources/hello.bmp").c_str());
    if (bmp == NULL)
    {
        log_message("ERROR BMP");
        return -1;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(sdlRenderer.get_renderer(), bmp);
    SDL_FreeSurface(bmp);
    if (tex == NULL)
    {
        log_message("ERROR TEX");
        return -1;
    }

    // Variable Declaration
    int bgR = 25;
    int bgG = 25;
    int bgB = 25;
    bool drawTex = false;

    // Render Loop Start
    bool toQuit = false;
    SDL_Event event;
    while (!toQuit)
    {
        // Check for Events
        if (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                toQuit = true;
                break;
            // Check for Input
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    toQuit = true;
                }
                if (event.key.keysym.sym == SDLK_1)
                {
                    bgR = 225;
                    bgG = 25;
                    bgB = 25;
                }
                else if (event.key.keysym.sym == SDLK_2)
                {
                    bgR = 25;
                    bgG = 225;
                    bgB = 25;
                }
                else if (event.key.keysym.sym == SDLK_3)
                {
                    bgR = 25;
                    bgG = 25;
                    bgB = 225;
                }
                else
                {
                    bgR = 25;
                    bgG = 25;
                    bgB = 25;
                }
                if (event.key.keysym.sym == SDLK_5)
                {
                    drawTex = true;
                }
                else
                {
                    drawTex = false;
                }
                break;
            }
        }
        // Setup Data
        sdlRenderer.set_renderer_color(bgR, bgG, bgB);

        // Render Objects
        SDL_RenderClear(sdlRenderer.get_renderer());
        // Draw Start
        if (drawTex)
        {
            SDL_RenderCopy(sdlRenderer.get_renderer(), tex, NULL, NULL);
        }
        // Draw End
        SDL_RenderPresent(sdlRenderer.get_renderer());
        // Refresh Screen
        // Render Loop End
        sdlRenderer.wait_milliseconds(0);
    }
    // Free Data
    SDL_DestroyTexture(tex);
    sdlRenderer.free_data();
    return 0;
}
