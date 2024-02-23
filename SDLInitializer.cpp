#include "WindowInitializer.h"
#include <iostream>

class SDLInitializer {
public:
    SDLInitializer(WindowInitializer windowInitializer) {
        SDL_Init(SDL_INIT_VIDEO);
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            printf("Can't be initialize SDL! Error: %s", SDL_GetError());
            system("pause");
            SDL_Quit();
        }
    }
    ~SDLInitializer() {
        SDL_Quit();
    }
};