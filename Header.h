#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <tuple>

const int WIDTH = 800;
const int HEIGHT = 600;

//`````````````````````````````````````````````````````````````` Defining colors ```````````````````````````````````````````````````````````````
const SDL_Color Black = { 0, 0, 0, 255 };
const SDL_Color White = { 255, 255, 255, 255 };
const SDL_Color Red = { 255, 0, 0, 255 };
const SDL_Color Green = { 0, 255, 0, 255 };
const SDL_Color Blue = { 0, 0, 255, 255 };
const SDL_Color Yellow = { 255, 255, 0, 255 };

const int MARKER_SIZE = 2;

std::vector<std::tuple<int, int, int, int, SDL_Color>> lines;

//``````````````````````````````````````````````````````` Clear the back buffer to a specific color `````````````````````````````````````````````
void ClearBackBuffer(SDL_Renderer* renderer, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

//````````````````````````````````````````````````````````````````` Draw a single pixel ``````````````````````````````````````````````````````````
void DrawPixel(SDL_Renderer* renderer, int x, int y, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

//`````````````````````````````````````````````````````````````````` Draw a square marker``````````````````````````````````````````````````````````
void DrawMarker(SDL_Renderer* renderer, int x, int y, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int i = -MARKER_SIZE; i <= MARKER_SIZE; ++i)
    {
        for (int j = -MARKER_SIZE; j <= MARKER_SIZE; ++j)
        {
            DrawPixel(renderer, x + i, y + j, color);
        }
    }
}

//````````````````````````````````````````````````````````````````` Bresenham's line algorithm ````````````````````````````````````````````````````
void DrawBresenhamLine(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, const SDL_Color& color) {
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        DrawPixel(renderer, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy; x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx; y0 += sy;
        }
    }
}

//```````````````````````````````````````````````````````````````````` Midpoint line algorithm ```````````````````````````````````````````````````````
void DrawMidpointLine(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, const SDL_Color& color)
{
    if (std::abs(x1 - x0) < std::abs(y1 - y0))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        if (y0 > y1)
        {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        for (int x = x0; x <= x1; ++x)
        {
            int y = y0 + (y1 - y0) * (x - x0) / (x1 - x0);
            DrawPixel(renderer, x, y, color);
        }
    }
    else
    {
        int dx = x1 - x0;
        int dy = y1 - y0;
        int d = 2 * dy - dx;
        int y = y0;

        for (int x = x0; x <= x1; ++x)
        {
            DrawPixel(renderer, x, y, color);
            if (d > 0)
            {
                y++;
                d -= 2 * dx;
            }
            d += 2 * dy;
        }
    }
}

//````````````````````````````````````````````````````````````````````` Parametric line algorithm ``````````````````````````````````````````````````````
void DrawParametricLine(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, const SDL_Color& color) {
    float dx = x1 - x0;
    float dy = y1 - y0;
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; ++i)
    {
        DrawPixel(renderer, std::round(x), std::round(y), color);
        x += xIncrement;
        y += yIncrement;
    }
}

//`````````````````````````````````````````````````````````````````````````` Draw a random line `````````````````````````````````````````````````````````
void DrawRandomLine(SDL_Renderer* renderer, SDL_Color color)
{
    int x0 = std::rand() % WIDTH;
    int y0 = std::rand() % HEIGHT;
    int x1 = std::rand() % WIDTH;
    int y1 = std::rand() % HEIGHT;

    lines.push_back(std::make_tuple(x0, y0, x1, y1, color));

    DrawBresenhamLine(renderer, x0, y0, x1, y1, color);
    DrawMarker(renderer, x0, y0, Yellow);
    DrawMarker(renderer, x1, y1, Yellow);
}

//````````````````````````````````````````````````````````````````````` Draw all lines stored in the vector ````````````````````````````````````````````````
void DrawStoredLines(SDL_Renderer* renderer)
{
    for (const auto& line : lines)
    {
        int x0 = std::get<0>(line);
        int y0 = std::get<1>(line);
        int x1 = std::get<2>(line);
        int y1 = std::get<3>(line);
        SDL_Color color = std::get<4>(line);

        DrawBresenhamLine(renderer, x0, y0, x1, y1, color);
    }
}

//```````````````````````````````````````````````````````````````````````````` Draw a sky of stars ``````````````````````````````````````````````````````````
void DrawSkyOfStars(SDL_Renderer* renderer)
{
    ClearBackBuffer(renderer, Black);
    for (int i = 0; i < 1000; ++i)
    {
        int x = std::rand() % WIDTH;
        int y = std::rand() % HEIGHT;
        DrawPixel(renderer, x, y, White);
    }
}

//```````````````````````````````````````````````````````````````````````````` Handle keyboard input ````````````````````````````````````````````````````````
void HandleInput(SDL_Renderer* renderer)
{
    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_1:
                    DrawRandomLine(renderer, Red);
                    break;
                case SDLK_2:
                    DrawRandomLine(renderer, Green);
                    break;
                case SDLK_3:
                    DrawRandomLine(renderer, Blue);
                    break;
                case SDLK_4:
                    ClearBackBuffer(renderer, Black);
                    DrawSkyOfStars(renderer);
                    lines.clear();
                    break;
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
}