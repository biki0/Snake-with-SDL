#include "Fruit.hpp"

Fruit::Fruit(int p_x, int p_y, Uint8 p_r, Uint8 p_g, Uint8 p_b) : 
            xPos(p_x), yPos(p_y), r(p_r), g(p_g), b(p_b){
    init();
}

void Fruit::init(){
    fruit.w = 30;
    fruit.h = 30;
    fruit.x = xPos;
    fruit.y = xPos;
}

void Fruit::setRandomPosition(){

    randXPos = (rand() % 700) + 35;
    randYPos = (rand() % 500) + 35;

/*
    if(randXPos > 800 - 35){
        randXPos = (rand() % 800) + 60;
    }
    if(randYPos > 640 - 35){
        randYPos = (rand() % 800) + 60;
    }
*/
    fruit.x = randXPos;
    fruit.y = randYPos;

}

void Fruit::setPosition(int p_x, int p_y){
    fruit.x = p_x;
    fruit.y = p_y;
}

int Fruit::getXPos(){
    return fruit.x;
}

int Fruit::getYPos(){
    return fruit.y;
}

void Fruit::reset(){
    setRandomPosition();
}


SDL_Rect* Fruit::getFruit(){
    return &fruit;
}

void Fruit::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &fruit);
}



