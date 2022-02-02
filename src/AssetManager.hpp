#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


class AssetManager{

    public:
        AssetManager();

        ~AssetManager();

        SDL_Texture* loadFont(SDL_Renderer* renderer, const char* fPath, std::string &fMessage);

        void setScore(SDL_Renderer* renderer, const char* fPath, std::string &fMessage);

        void scoreUpdate(SDL_Renderer* renderer, std::string &fMessage);
        
        void scoreDraw(SDL_Renderer* renderer);

    private:
        SDL_Texture* scoreTexture;
        SDL_Rect scoreRect;
        std::string score;
        TTF_Font* scoreFont;

};