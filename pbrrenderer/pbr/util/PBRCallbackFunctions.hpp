/**
 * @file PBRCallbackFunctions.hpp
 * @brief Defines an enumeration for different callback function types
 * @author D3PSI
 */
#ifndef PBR_CALLBACK_FUNCTIONS_HPP
#define PBR_CALLBACK_FUNCTIONS_HPP

#include <GLFW/glfw3.h>


namespace pbr {

    namespace util {

        /**
         * Defines a callback function for keyboard inputs
         * @param _window The pointer to the GLFWwindow
         */
        typedef void (*PBRKeyboardInputCallbackFun)(GLFWwindow* _window);

        /**
         * Defines a callback function for rendering operations
         */
        typedef void (*PBRRenderCallbackFun)(void);

        /**
         * Defines a callback function for resource loading
         */
        typedef void (*PBRInitCallbackFun)(void);

        /**
         * Defines a callback function for garbage collection
         */
        typedef void (*PBRCleanCallbackFun)(void);

    }

}

#endif      // PBR_CALLBACK_FUNCTIONS_HPP