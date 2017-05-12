/*
    Copyright João Schimmelpfeng 2017
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Game_Manager.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    SDL_Event e;
    int quit = 0;

    float sizeW = (float)(SCREEN_WIDTH + 0.0f);
    float sizeH = (float)(SCREEN_HEIGHT + 0.0f);

    Game_Manager gameMan(sizeW, sizeH);

    while( !quit )
    {
        //Input
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_KEYDOWN )
            {
                switch( e.key.keysym.sym )
                {
                            case SDLK_ESCAPE:
                            SDL_DestroyWindow( window );
                            SDL_Quit();
                            quit = 1;
                            break;

                            default:
                            break;
                }
            }
        }

        gameMan.Update();
    	gameMan.Render(renderer);
    }
    
    return 0;
}
