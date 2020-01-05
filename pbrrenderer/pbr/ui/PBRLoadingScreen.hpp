/**
 * @file PBRLoadingScreen.hpp
 * @brief Defines a loading screen object using SDL2
 * @author D3PSI
 */
#ifndef PBR_LOADING_SCREEN_HPP
#define PBR_LOADING_SCREEN_HPP

#include "../PBR.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include <thread>
#include <mutex>


namespace pbr {

    namespace ui {

        class PBRLoadingScreen
        {
        public:

            /**
             * Constructor with filename
             * @param _image The path to the image on disk
             */
            PBRLoadingScreen(const char* _image);

            /**
             * Closes the loading screen
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS quit(void);

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
            pbr::util::flags::PBR_STATUS loop(void);

            /**
             * Cleans all allocated resources of the loading screen
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS clean(void);

        };

    }

}

#endif      // PBR_LOADING_SCREEN_HPP