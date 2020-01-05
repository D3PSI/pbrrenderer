/**
 * @file PBR_UTIL_DEFAULTS.hpp
 * @brief Contains definitions of default values
 * @author D3PSI
 */
#ifndef PBR_UTIL_DEFAULTS_CPP
#define PBR_UTIL_DEFAULTS_CPP

#include "PBR_UTIL_DEFAULTS.hpp"


namespace pbr {

    namespace util {

        namespace defaults {

            uint32_t WIDTH = 1280;
            uint32_t HEIGHT = 720;
            const char* TITLE = "Physically-Based Rendering Example by D3PSI";

            const char* LOADING_SCREEN_IMAGE = "res/images/lion.png";
            const char* APPLICATION_ICON = "res/images/lion_cropped.png";
            pbr::util::flags::PBR_DISPLAY_MODE DISPLAY_MODE = pbr::util::flags::PBR_WINDOWED;

            float YAW = 0.0f;
            float PITCH = 0.0f;
            float ROLL = 0.0f;
            float CAMERA_SPEED = 2.5f;
            float FOV = 45.0f;
            float SENSITIVITY = 0.1f;

            bool DEFAULT_KEY_BINDINGS = false;

            pbr::util::PBRKeyboardInputCallbackFun KEY_INPUT_CB = nullptr;

        }

    }

}

#endif      // PBR_UTIL_DEFAULTS_CPP