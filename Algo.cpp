#include <SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <tuple>
#include"Header.h"
//`````````````````````````````````````````````````````````````````````````````````````` Main ```````````````````````````````````````````````````````````````````
int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("2D Line Drawing Algorithms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) 
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) 
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(0)));

    ClearBackBuffer(renderer, Black);

    DrawBresenhamLine(renderer, 100, 100, 499, 400, White);
    DrawMarker(renderer, 100, 100, Yellow);
    DrawMarker(renderer, 499, 400, Yellow);
    SDL_RenderPresent(renderer);
    HandleInput(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}