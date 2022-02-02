#include "AssetManager.hpp"


AssetManager::AssetManager(){
    scoreTexture = nullptr;
    score = "0";
}

AssetManager::~AssetManager(){
    TTF_CloseFont(scoreFont);
    SDL_DestroyTexture(scoreTexture);
    
}

SDL_Texture* AssetManager::loadFont(SDL_Renderer* renderer, const char* fPath, std::string &fMessage){

    TTF_Font *font = TTF_OpenFont(fPath, 30);
    if(!font){
        std::cout << "Failed to load font. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, fMessage.c_str(), {255,255,255});
    if(!surfaceMessage){
        std::cout << "Failed to load surface. SDL_ERROR: " << SDL_GetError() <<std::endl;
    }

    SDL_Texture* tTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    if(!tTexture){
        std::cout << "Failed to load text texture. SDL_ERROR: " << SDL_GetError() <<std::endl;
    }
    SDL_FreeSurface(surfaceMessage);

    TTF_CloseFont(font);

    return tTexture;

}

void AssetManager::setScore(SDL_Renderer* renderer, const char* fPath, std::string &fMessage){

    score = fMessage;

    scoreFont = TTF_OpenFont(fPath, 30);
    scoreRect.w = 30;
    scoreRect.h = 30;
    scoreRect.x = 50;
    scoreRect.y = 50;

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(scoreFont, score.c_str(), {255,255,255});
    if(scoreSurface == nullptr){
        std::cout << "Failed to load surface. SDL_ERROR: " << SDL_GetError() <<std::endl;
    }

    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    if(scoreTexture == nullptr){
        std::cout << "Failed to load text texture. SDL_ERROR: " << SDL_GetError() <<std::endl;
    }

    
    SDL_FreeSurface(scoreSurface);

}


void AssetManager::scoreUpdate(SDL_Renderer* renderer, std::string &fMessage){

    SDL_DestroyTexture(scoreTexture);

    SDL_Surface* sSurface = TTF_RenderText_Solid(scoreFont, fMessage.c_str(), {255,255,255});

    scoreTexture = SDL_CreateTextureFromSurface(renderer, sSurface);


    SDL_FreeSurface(sSurface);
}


void AssetManager::scoreDraw(SDL_Renderer* renderer){
    
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    
}







