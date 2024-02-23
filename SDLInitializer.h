#pragma once
#include <SDL.h>
#include "SDLInitializer.h"

class SDLInitializer {
public:
    SDLInitializer(WindowInitializer windowInitializer)
    {
        name = p_name;
        std::cout << "Person " << name << " created" << std::endl;
    }
    ~SDLInitializer()
    {
        std::cout << "Person " << name << " deleted" << std::endl;
    }

};

