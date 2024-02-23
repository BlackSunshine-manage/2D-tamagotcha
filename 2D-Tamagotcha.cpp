// 2D-Tamagotcha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SDL.h>
#include "window_property.h"

SDL_Window* window;
SDL_Renderer* renderer;

void deinitialize(int exitCode) {
    if (renderer != NULL) SDL_DestroyRenderer(renderer);
    if (window != NULL) SDL_DestroyWindow(window);
    SDL_Quit();
    exit(exitCode);
}

void initialize() {
    WindowProperty windowPropeties = new WindowProperty();
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Can't be initialize SDL! Error: %s", SDL_GetError());
        system("pause");
        deinitialize(1);
    }
    window = SDL_CreateWindow("Tamagotchi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

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
