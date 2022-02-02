#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>

#include "Snake.hpp"
#include "Fruit.hpp"
#include "Obstacle.hpp"

#include "SoundManager.hpp"

class Collision{

    public:
        Collision();

        void windowCollision(Snake& snake);

        bool snakeObstacleCollision(Snake& snake, Obstacle& obstacle);

        void snakeFruitCollision(Snake& snake, Fruit& fruit);

        bool snakeBodyCollision(Snake& snake);

    private:

        SoundManager soundManager;

};