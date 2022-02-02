#include "Obstacle.hpp"


Obstacle::Obstacle(){

}

Obstacle::~Obstacle(){}


void Obstacle::addObstacle(int p_w, int p_h, int p_x, int p_y){

    SDL_Rect wall;
    wall.w = p_w;
    wall.h = p_h;
    wall.x = p_x;
    wall.y = p_y;

    obstacles.push_back(wall);

}

std::vector<SDL_Rect> Obstacle::getObstacle(){
    return obstacles;
}

int Obstacle::getSize(){
    return obstacles.size();
}


void Obstacle::draw(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 110, 67, 14, 255);
    for(SDL_Rect& w : obstacles){
        SDL_RenderFillRect(renderer, &w);
    }

}










