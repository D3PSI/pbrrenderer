/**
 * Welcome to PBR by D3PSI
 * 
 * This project is open-source and licensed under the GNU General Public License v3.0
 * Please refer to LICENSE.md for further information
 * 
 * Refer to README.md for installation and compilation instructions
 * @file PBR.hpp
 * @brief Main include file for PBR
 * @author D3PSI
 */
#ifndef PBR_HPP
#define PBR_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SDL.h>
#include <SDL_image.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "core/PBR_CORE.hpp"
#include "core/PBRShaderInterface.hpp"
#include "core/PBRVertexArrayInterface.hpp"
#include "ui/PBR_UI.hpp"
#include "ui/PBRLoadingScreen.hpp"
#include "util/PBR_UTIL.hpp"
#include "util/PBRCallbackFunctions.hpp"
#include "util/PBRMakros.hpp"
#include "util/defaults/PBR_UTIL_DEFAULTS.hpp"
#include "util/flags/PBR_UTIL_FLAGS.hpp"
#include "util/initializers/PBR_UTIL_INITIALIZERS.hpp"
#include "util/io/PBR_UTIL_IO.hpp"


/**
 * Defines a namespace to minimize variable naming conflicts
 */
namespace pbr {

    /**
     * Initializes the PBR core engine
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrInit(void);

    /**
     * Starts the main application
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrExecute(void);

    /**
     * Cleans allocated resources
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrClean(void);

    /**
     * Sets the width and height of the application window
     * @param _width The desired width
     * @param _height The desired height
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrSize(uint32_t _width, uint32_t _height);

    /**
     * Sets the title of the application window
     * @param _title The desired title
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrTitle(const char* _title);

    /**
     * Sets the image of the main loading screen
     * @param _image The path to the image on disk
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrLoadingScreenImage(const char* _image);

    /**
     * Sets the icon of the application
     * @param _icon The path to the icon on disk
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrApplicationIcon(const char* _icon);

    /**
     * Sets the display mode of the application
     * @param _mode The display mode
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrDisplayMode(pbr::util::flags::PBR_DISPLAY_MODE _mode);

    /**
     * Sets the keyboard input callback function
     * @param _cbfun The callback function
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrKeyboardInputCallback(pbr::util::PBRKeyboardInputCallbackFun _cbfun);

    /**
     * Enables default key bindings for a PBR application
     * @param _enable Enable with true or disable with false
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    pbr::util::flags::PBR_STATUS pbrDefaultKeyBindings(bool _enable = true);

    /**
     * Queries the current width of the window
     * @return Returns the current width of the GLFWwindow
     */
    uint32_t pbrGetCurrentWidth(void);

    /**
     * Queries the current height of the window
     * @return Returns the current height of the GLFWwindow
     */
    uint32_t pbrGetCurrentHeight(void);

}

#endif      // PBR_HPP