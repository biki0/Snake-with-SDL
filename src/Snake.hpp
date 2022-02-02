#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>

class Snake{

    public:
        Snake(int w, int h, int x, int y);
        ~Snake();

        void setHeadPosition(int x, int y);
        int getHeadXPos();
        int getHeadYPos();

        void increaseBody();
        void setBodyPosition();
        int getLength();

        SDL_Rect* getHead();
        std::vector<SDL_Rect> getBody();


        int getScore();

        void move();
        

        void restart();

        void pollEvents(SDL_Event& event);
        void draw(SDL_Renderer* renderer);
        

    private:
        void init();

        int width, height;
        int startXPos, startYPos;
        int xPos, yPos;
        int speed;
        bool moveUp, moveLeft, moveDown, moveRight;
        bool popIt;
        int score;

        int pX, pY;

        
        int bodyLength; 

        std::vector<SDL_Rect> snakeBody;
        SDL_Rect head;

};

