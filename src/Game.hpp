#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_image.h>

#include "Snake.hpp"
#include "Fruit.hpp"
#include "Collision.hpp"
#include "Obstacle.hpp"

#include "AssetManager.hpp"


class Game{

    public:
        Game();
        ~Game();

        
        void run(void);

        void update();
        void render();


    private:
        void initVar();
        void initWin();
        void initWalls();
        
        void initFont();
        void initSound();
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;

        int windowWidth, windowHeight;

        bool isClosed;
        bool gameStart;
        bool gamePause;
        bool gameOver;
        bool gameRestart;   
        
        bool obstacleCollision;
        bool bodyCollision;

        Snake snake;
        Fruit fruit;
        Collision collision;
        Obstacle obstacles;
        
        AssetManager fontManage;
        

        SDL_Texture* scoreText;
        SDL_Rect scoreRect;
        std::string scoreString;

        SDL_Texture* gameStartText;
        SDL_Rect gameStartRect;

        SDL_Texture* gamePauseText;
        SDL_Rect gamePauseRect;

        SDL_Texture* gameOverText;
        SDL_Rect gameOverRect;

        std::string score;

        const int fps = 60;
        Uint32 frameStart;
        const int frameDelay = 1000 / fps;
        int frameTime;
};