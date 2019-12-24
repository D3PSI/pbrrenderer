/**
 * @file PBRFPSCamera.hpp
 * @brief Contains declarations of a FPS camera class
 * @author D3PSI
 */
#ifndef PBR_FPS_CAMERA_HPP
#define PBR_FPS_CAMERA_HPP

#include "PBRCameraBase.hpp"


namespace pbr {

    namespace core {

        class PBRFPSCamera :
        public pbr::core::PBRCameraBase
        {
            using pbr::core::PBRCameraBase::PBRCameraBase;
        public:

            /**
             * Handles keyboard input
             * @param _window A pointer to the GLFWwindow
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS processInput(GLFWwindow* _window);

            /**
             * Handles mouse rotation of the camera
             * @param _xPos The x-position of the mouse pointer
             * @param _yPos The y-position of the mouse pointer
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS processMouseMovement(double _xPos, double _yPos);

            /**
             * Handles scrolling on the mouse wheel
             * @param _xOff The x-offset of the mouse wheel (0 in most cases)
             * @param _yOff The y-offset of the mouse wheel
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS processMouseScroll(double _xOff, double _yOff);

            /**
             * Default destructor
             */
            ~PBRFPSCamera(void);
        
        private:

        };

    }

}

#endif      // PBR_FPS_CAMERA_HPP