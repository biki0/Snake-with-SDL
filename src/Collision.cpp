#include "Collision.hpp"

Collision::Collision(){

    soundManager.addSound("eat_sound", "assets/fruit_eat_sound.wav");
    soundManager.addSound("game_over", "assets/game_over.wav");

}


void Collision::windowCollision(Snake& snake){

    if(snake.getHeadXPos() < 0)
        snake.setHeadPosition(800, snake.getHeadYPos());
    if(snake.getHeadYPos() < 0)
        snake.setHeadPosition(snake.getHeadXPos(), 640);
    if(snake.getHeadXPos() > 800){
        snake.setHeadPosition(0, snake.getHeadYPos());
    }
    if(snake.getHeadYPos() > 640){
        snake.setHeadPosition(snake.getHeadXPos(), 0);
    }

}

bool Collision::snakeObstacleCollision(Snake& snake, Obstacle& obstacle){

    /*
    if(snake.getHeadXPos() < 0)
        snake.setHeadPosition(800, snake.getHeadYPos());
    if(snake.getHeadYPos() < 0)
        snake.setHeadPosition(snake.getHeadXPos(), 640);
    if(snake.getHeadXPos() > 800){
        snake.setHeadPosition(0, snake.getHeadYPos());
    }
    if(snake.getHeadYPos() > 640){
        snake.setHeadPosition(snake.getHeadXPos(), 0);
    }
    */

   SDL_bool col;

    for(int i=0; i<obstacle.getSize(); ++i){
        col = SDL_HasIntersection(snake.getHead(), &obstacle.getObstacle()[i]);
        if(col){
            soundManager.playSound("game_over");
            return true;
        }
    }
    
    return false;
}

void Collision::snakeFruitCollision(Snake& snake, Fruit& fruit){

    SDL_bool col = SDL_HasIntersection(snake.getHead(), fruit.getFruit());

    if(col){
        fruit.setRandomPosition();
        snake.increaseBody();

        soundManager.playSound("eat_sound");
    }
    
}

bool Collision::snakeBodyCollision(Snake& snake){

    for(int i=2; i<snake.getLength(); ++i){

        if((snake.getBody()[0].x == snake.getBody()[i].x) &&
            (snake.getBody()[0].y == snake.getBody()[i].y)){
                soundManager.playSound("game_over");
                return true;
            }
    }

    return false;
}

