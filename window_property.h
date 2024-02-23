#ifndef WINDOW_PROPERTY_H
#define WINDOW_PROPERTY_H
#include <SDL.h>

struct WindowProperty {
    const char* title;
    const int coordinateX;
    const int coordinateY;
    const int width;
    const int height;
    const Uint32 flags;
};

#endif // WINDOW_PROPERTY_H