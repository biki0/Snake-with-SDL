#include "Snake.hpp"

Snake::Snake(int w, int h, int x, int y) :
            width(w), height(h), xPos(x), yPos(y){

    
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = true;
    startXPos = x;
    startYPos = y;

    speed = 9;

    popIt = true;

    init();
}

Snake::~Snake(){}

void Snake::init(){
    head.w = width;
    head.h = height;
    head.x = xPos;
    head.y = yPos;

    snakeBody.push_back(head);
    bodyLength = 1;

    score = 0;
}


void Snake::setHeadPosition(int x, int y){
    xPos = x;
    yPos = y;
}

int Snake::getHeadXPos(){
    return snakeBody[0].x;
}
int Snake::getHeadYPos(){
    return snakeBody[0].y;
}


void Snake::increaseBody(){

    //head.x = -200;
    //head.y = -200;
    SDL_Rect tail;
    tail.w = 30;
    tail.h = 30;
    tail.x = -200;
    tail.y = -200;

    for(int i=0; i<3; ++i){
        snakeBody.push_back(tail);
        bodyLength++;
    }
    score++;
}

void Snake::setBodyPosition(){

    for(int i = bodyLength - 1; i>0; i--){
        snakeBody.at(i) = snakeBody.at(i-1);
    }
}

int Snake::getLength(){
    return bodyLength;
}

SDL_Rect* Snake::getHead(){
    return &snakeBody[0];
}

std::vector<SDL_Rect> Snake::getBody(){
    return snakeBody;
}

int Snake::getScore(){
    return score;
}

void Snake::move(){

    if(moveUp){
        yPos -= speed;

    }
    else if(moveLeft){
        xPos -= speed;

    }
    else if(moveDown){
        yPos += speed;

    }
    else{
        xPos += speed;
    }

    snakeBody[0].x = xPos;
    snakeBody[0].y = yPos;


}

void Snake::restart(){
    score = 0;
    snakeBody.clear();
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = true;

    xPos = startXPos;
    yPos = startYPos;
    snakeBody.push_back(head);
    bodyLength = 1;
}


void Snake::pollEvents(SDL_Event& event){
    if(event.type == SDL_KEYDOWN ){
        if((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) && !moveRight){
            moveLeft = true;
            moveUp = moveRight = moveDown = false;
        }
        if((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) && !moveLeft){
            moveRight= true;
            moveUp = moveLeft = moveDown = false;
        }
        if((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) && !moveDown){
            moveUp = true;
            moveLeft = moveDown = moveRight = false;
        }
        if((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) && !moveUp){
            moveDown = true;
            moveUp = moveLeft = moveRight = false;
        }
    }

}

void Snake::draw(SDL_Renderer* renderer){


    SDL_SetRenderDrawColor(renderer, 30, 99, 43, 255);
    for(SDL_Rect& r : snakeBody){
        SDL_RenderFillRect(renderer, &r);
        //SDL_RenderDrawRect(renderer, &r);
    }

}


