/**
 * @file SDLLoadingScreen.hpp
 * @brief Defines a loading screen object using SDL2
 * @author D3PSI
 */
#ifndef SDL_LOADING_SCREEN_HPP
#define SDL_LOADING_SCREEN_HPP

#include "../util/PBR_STATUS.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include <thread>
#include <mutex>


class SDLLoadingScreen
{
public:

    /**
     * Constructor with filename
     * @param _image The path to the image on disk
     */
    SDLLoadingScreen(const char* _image);

    /**
     * Closes the loading screen
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS quit(void);

private:

    SDL_Window* window = nullptr;
    SDL_Surface* imageSurface = nullptr;
    SDL_Texture* background = nullptr;
    SDL_Renderer* renderer = nullptr;

    uint32_t width = 0;
    uint32_t height = 0;

    bool closeVar = false;
    std::mutex closeMutex;

    /**
     * Contains the event loop for the loading screen
     * @return Returns 0 or bigger on success, returns a negative number on failure 
     */
    PBR_STATUS loop(void);

    /**
     * Cleans all allocated resources of the loading screen
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS clean(void);

};

#endif      // SDL_LOADING_SCREEN_HPP