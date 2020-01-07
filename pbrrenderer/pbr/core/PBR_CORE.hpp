/**
 * @file PBR_CORE.hpp
 * @brief Contains the declarations of core functions of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_HPP
#define PBR_CORE_HPP

#include "../PBR.hpp"
#include "../util/PBR_UTIL.hpp"

#include <iostream>


namespace pbr {

    /**
     * Contains core functionality for the PBR engine
     */
    namespace core {

        extern uint32_t width;
        extern uint32_t height;

        extern float deltaTime;
        extern float lastFrame;
        extern float currentFrame;

        /**
         * Initializes the PBR core engine
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS init(void);

        /**
         * Starts the main application
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS execute(void);

        /**
         * Initializes everything OpenGL-related
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS initOpenGL(void);

        /**
         * Contains the main loop
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS loop(void);

        /**
         * Cleans all allocated resources and handles shutdown operations
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS clean(void);

        /**
         * Processes keyboard inputs
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS keyInput(void);

        /**
         * Coordinates one-time setup steps
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS setup(void);

        /**
         * Coordinates main rendering operations
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS render(void);

        /**
         * Initializes shaders
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS setupShaders(void);

        /**
         * Initializes buffers
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::flags::PBR_STATUS setupBuffers(void);

        /**
         * Callback function for window resize events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _width The new width of the GLFWwindow
         * @param _height The new height of the GLFWwindow
         */
        void framebufferResizeCB(GLFWwindow* _window, int _width, int _height);

        /**
         * Callback function for mouse movement events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _xPos The new x-position of the mouse pointer
         * @param _yPos The new y-position of the mouse pointer
         */
        void mouseMoveCB(GLFWwindow* _window, double _xPos, double _yPos);

        /**
         * Callback function for mouse scroll events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _xOff The amount of scroll in the x-direction (usually 0)
         * @param _yOff The amount of scroll in the y-direction
         */        
        void mouseScrollCB(GLFWwindow* _window, double _xOff, double yOff_);

    }

}

#endif      // PBR_CORE_HPP