#include "RendererInitializer.h"
#include <SDL.h>
#include <iostream>
#include "window_property.h"

class WindowInitializer {
public:
    SDL_Window* window;
    WindowInitializer(RendererInitializer renderInitializer, WindowProperty properties) {
        window = SDL_CreateWindow(properties.title, 
            properties.coordinateX, 
            properties.coordinateY, 
            properties.width, 
            properties.height,
            properties.flags);
        if (window == NULL) {
            printf("Can't be initialize window! Error: %s", SDL_GetError());
            system("pause");
            this->~WindowInitializer();
        }
    }
    ~WindowInitializer() {
        if (window != NULL) SDL_DestroyWindow(window);
    }
};