/**
 * @file PBRLoadingScreen.cpp
 * @brief Defines a loading screen object using SDL2
 * @author D3PSI
 */
#ifndef PBR_LOADING_SCREEN_CPP
#define PBR_LOADING_SCREEN_CPP

#include "../PBR.hpp"


pbr::ui::PBRLoadingScreen::PBRLoadingScreen(const char* _image) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::string error = SDL_GetError();
        std::runtime_error("SDL2 Error: " + error);
    }
    imageSurface = IMG_Load(_image);
    if(imageSurface == nullptr) {
        std::string error = SDL_GetError();
        std::runtime_error("SDL2 Error: " + error);
    }
    width = imageSurface->w;
    height = imageSurface->h;
    window = SDL_CreateWindow(
        pbr::util::defaults::TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED);
    if(window == nullptr) {
        std::string error = SDL_GetError();
        std::runtime_error("SDL2 Error: " + error);
    }
    background = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_SetWindowIcon(window, imageSurface);
    std::thread t0(&PBRLoadingScreen::loop, this);
    t0.detach();
}

pbr::util::flags::PBR_STATUS pbr::ui::PBRLoadingScreen::loop() {
    SDL_Event e;
    while(!closeVar) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                closeMutex.lock();
                closeVar = true;
                closeMutex.unlock();
            }
        }
        SDL_RenderCopy(
            renderer,
            background,
            nullptr,
            nullptr);
        SDL_RenderPresent(renderer);
    }
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::ui::PBRLoadingScreen::quit() {
    this->closeMutex.lock();
    this->closeVar = true;
    this->closeMutex.unlock();
    this->clean();
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::ui::PBRLoadingScreen::clean() {
    SDL_FreeSurface(imageSurface);
    imageSurface = nullptr;
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
    return pbr::util::flags::PBR_OK;
}

#endif      // PBR_LOADING_SCREEN_CPP