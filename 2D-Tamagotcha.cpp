// 2D-Tamagotcha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* texture = NULL;

void deinitialize(int exitCode) {
    if (texture != NULL) SDL_DestroyTexture(texture);
    if (renderer != NULL) SDL_DestroyRenderer(renderer);
    if (window != NULL) SDL_DestroyWindow(window);
    SDL_Quit();
    exit(exitCode);
}

void initialize() {
    int wdthRectangle = 200;
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Can't be initialize SDL! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }
    window = SDL_CreateWindow("Tamagotchi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_MOUSE_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == NULL) {
        printf("Can't be initialize window! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        printf("Can't be initialize renderer! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }

    surface = SDL_LoadBMP("C:\\Users\\snd00\\Desktop\\sprite\\bite_modify_transparent.bmp");
    if (surface == NULL) {
        printf("Can't load image! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        printf("Can't create texture! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_FreeSurface(surface);
    SDL_SetTextureAlphaMod(texture, 128);
    SDL_SetTextureColorMod(texture, 255, 255, 255);
    SDL_SetWindowOpacity(window, 0.5f);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int frame = 0;
    SDL_Rect spriteRect = { 0, 0, wdthRectangle, 140};
    int count = surface->w / wdthRectangle;
    while(1)
    for (int i{ 1 }; i < count; i++) {
        SDL_RenderClear(renderer);
        spriteRect = { wdthRectangle * i, 140, 200, 140 };
        SDL_RenderCopy(renderer, texture, &spriteRect, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }


    SDL_RenderPresent(renderer);
}

int main(int args, char *argv[]) {
    initialize();
    SDL_Delay(10000);
    deinitialize(0);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
