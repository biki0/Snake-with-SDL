#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>


class Obstacle{

    public:
        Obstacle();
        ~Obstacle();

        void addObstacle(int p_w, int p_h, int p_x, int p_y);

        std::vector<SDL_Rect> getObstacle();

        int getSize();

        void draw(SDL_Renderer* renderer);

    private:
        std::vector<SDL_Rect> obstacles;


};




