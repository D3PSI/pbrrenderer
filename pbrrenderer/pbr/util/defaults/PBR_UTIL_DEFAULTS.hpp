/**
 * @file PBR_UTIL_DEFAULTS.hpp
 * @brief Contains declarations of default values
 * @author D3PSI
 */
#ifndef PBR_UTIL_DEFAULTS_HPP
#define PBR_UTIL_DEFAULTS_HPP

#include "../flags/PBR_UTIL_FLAGS.hpp"
#include "../PBRCallbackFunctions.hpp"

#include <stdint.h>


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace for (initially) default values. These may get changed as the library is run.
         */
        namespace defaults {

            extern uint32_t WIDTH;
            extern uint32_t HEIGHT;
            extern const char* TITLE;

            extern const char* LOADING_SCREEN_IMAGE;
            extern const char* APPLICATION_ICON;
            extern pbr::util::flags::PBR_DISPLAY_MODE DISPLAY_MODE;

            extern float YAW;
            extern float PITCH;
            extern float ROLL;
            extern float CAMERA_SPEED;
            extern float FOV;
            extern float SENSITIVITY;

            extern bool DEFAULT_KEY_BINDINGS;
            extern pbr::util::PBRKeyboardInputCallbackFun KEY_INPUT_CB;
            extern pbr::util::PBRRenderCallbackFun RENDER_CB;
            extern pbr::util::PBRRenderCallbackFun INIT_CB;
            extern pbr::util::PBRCleanCallbackFun CLEAN_CB;

        }

    }

}

#endif      // PBR_UTIL_DEFAULTS_HPP