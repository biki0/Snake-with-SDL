#include <iostream>

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

#include "Game.hpp"

Game game;

void main_loop(void){

    //game.run();
}

int main(int argc, char *argv[]){
    /*
    #ifdef __EMSCRIPTEN__
            emscripten_set_main_loop(main_loop, 0, 1);
    #endif

    #ifndef __EMSCRIPTEN__
            main_loop;
    #endif
    */
    
    game.run();
    
    return 0;
}
