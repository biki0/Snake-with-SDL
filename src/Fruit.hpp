#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>


class Fruit{

    public:
        Fruit(int p_x, int p_y, Uint8 p_r, Uint8 p_g, Uint8 p_b);

        void setRandomPosition();

        void setPosition(int p_x, int p_y);

        int getXPos();
        int getYPos();

        void reset();


        SDL_Rect* getFruit();

        void draw(SDL_Renderer* renderer);

    private:
        void init();

        SDL_Rect fruit;
        int xPos, yPos;
        int randXPos, randYPos;

        Uint8 r, g, b;

};
