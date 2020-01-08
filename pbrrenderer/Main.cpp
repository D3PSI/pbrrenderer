/**
 *  Welcome to pbrrenderer by D3PSI
 * 
 *  This project is open-source and licensed under the GNU General Public License v3.0
 *  Please refer to LICENSE.md for further information
 * 
 *  Refer to README.md for installation and compilation instructions
 */
#include "pbr/PBR.hpp"

/**
 * Serves as a keyboard input callback function for the PBR core engine
 * @param _window A pointer to the GLFWwindow
 */
void keyboardInputCallback(GLFWwindow* _window) {
    if(glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS)
        std::cout << "This is an example on how you can define own key actions.\n";
}

/**
 *  Defines the main entry point for the application
 */
int main() {
    pbr::pbrInit();
    pbr::pbrTitle("PBR by D3PSI");
    pbr::pbrSize(1280, 720);
    pbr::pbrLoadingScreenImage("res/images/lion.png");
    pbr::pbrApplicationIcon("res/images/lion-cropped.png");
    pbr::pbrDisplayMode(pbr::util::flags::PBR_FULLSCREEN);
    pbr::pbrDefaultKeyBindings();
    pbr::pbrKeyboardInputCallback(keyboardInputCallback);
    return pbr::pbrExecute();
}