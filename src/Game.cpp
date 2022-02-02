#include "Game.hpp"

Game::Game() : snake(30, 30, 800 / 2, 640 / 2), fruit(300, 300, 110, 29, 38){
    initVar();
    initWin();
    initFont();
    initWalls();
}

Game::~Game(){
    SDL_DestroyTexture(gameStartText);
    SDL_DestroyTexture(gameOverText);
    SDL_DestroyTexture(scoreText);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Game::initVar(){
    windowWidth = 800;
    windowHeight = 640;


    isClosed = false;
    gameStart = false;
    gamePause = false;
    gameOver = false;
    gameRestart = false;
    
    obstacleCollision = false;
    bodyCollision = false;
}

void Game::initWin(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if(TTF_Init() == -1){
        std::cout << "Failed to init. Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    if(window == NULL){
        std::cout << "window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::initFont(){
    std::string msg = "0";
    scoreRect.w = 30;
    scoreRect.h = 30;
    scoreRect.x = 40;
    scoreRect.y = 50;
    //fontManage.updateScore(snake.getScore());
    scoreText = fontManage.loadFont(renderer, "assets/PixelSplitter-Bold.ttf", msg);

    std::string sc = std::to_string(snake.getScore());

    fontManage.setScore(renderer, "assets/PixelSplitter-Bold.ttf", msg);

    std::string startMsg = "Press P to Start Game!";
    gameStartText = fontManage.loadFont(renderer, "assets/PixelSplitter-Bold.ttf", startMsg);
    gameStartRect.w = windowWidth / 2 + 350;
    gameStartRect.h = 100;
    gameStartRect.x = windowWidth / 2 - 370;
    gameStartRect.y = windowHeight / 2 - 100;

    std::string pauseMsg = "Press ESC to Unpause!";
    gamePauseText = fontManage.loadFont(renderer, "assets/PixelSplitter-Bold.ttf", pauseMsg);
    gamePauseRect.w = windowWidth / 2 + 350;
    gamePauseRect.h = 100;
    gamePauseRect.x = windowWidth / 2 - 370;
    gamePauseRect.y = windowHeight / 2 - 100;

    std::string gOverMsg = "You Died! Press R to Play Again!";
    gameOverText = fontManage.loadFont(renderer, "assets/PixelSplitter-Bold.ttf", gOverMsg);
    gameOverRect.w = windowWidth / 2 + 350;
    gameOverRect.h = 100;

    //gameOverRect.w = 200;
    //gameOverRect.h = 200;

    gameOverRect.x = windowWidth / 2 - 370;
    gameOverRect.y = windowHeight / 2 - 100;
    
}


void Game::initWalls(){

    obstacles.addObstacle(windowWidth, 30, 0, 0);
    obstacles.addObstacle(30, windowHeight, 0, 0);
    obstacles.addObstacle(windowWidth, 30, 0, windowHeight - 30);
    obstacles.addObstacle(30, windowHeight, windowWidth - 30, 0);

}


void Game::run(void){
    while(!isClosed){
        update();
        render();
    }
}


void Game::update(){
    
    frameStart = SDL_GetTicks();

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isClosed = true;
        }
        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_p){
                gameStart = true;
            }
            if(gameStart && !gamePause){
                if(event.key.keysym.sym == SDLK_r){
                    gameRestart = true;
                    
                }
            }
            if(event.key.keysym.sym == SDLK_ESCAPE){
                gamePause = !gamePause;
            }           
        }
        
        snake.pollEvents(event);
    }

    frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
    }



    if(gameStart && !gameOver && !gamePause){
        snake.move();
        snake.setBodyPosition();

        score = std::to_string(snake.getScore());
        fontManage.scoreUpdate(renderer, score);

        collision.snakeFruitCollision(snake, fruit);        
        bodyCollision = collision.snakeBodyCollision(snake);
        obstacleCollision = collision.snakeObstacleCollision(snake, obstacles);

        if(bodyCollision || obstacleCollision){
            gameOver = true;
        }
         
    }
    if(gameRestart && !gamePause){
        snake.restart();
        fruit.reset();
        gameRestart = false;
        gameOver = false;
        gamePause = false;
    }

}

void Game::render(){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
 
    obstacles.draw(renderer);

    snake.draw(renderer);

    fruit.draw(renderer);
    
    fontManage.scoreDraw(renderer);
    //SDL_RenderCopy(renderer, scoreText, NULL, &scoreRect);
    //SDL_DestroyTexture(scoreText);
    
    if(!gameStart){
        SDL_RenderCopy(renderer, gameStartText, NULL, &gameStartRect);
    }
    
    if(!gameOver && gamePause){
        SDL_RenderCopy(renderer, gamePauseText, NULL, &gamePauseRect);
    }

    if(gameOver){
        SDL_RenderCopy(renderer, gameOverText, NULL, &gameOverRect);
    }
    
    SDL_RenderPresent(renderer);
    

}








