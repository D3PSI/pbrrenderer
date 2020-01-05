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
             * Handles mouse rotation of the camera
             * @param _xPos The x-position of the mouse pointer
             * @param _yPos The y-position of the mouse pointer
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS look(double _xPos, double _yPos);

            /**
             * Default destructor
             */
            ~PBRFPSCamera(void) = default;
        
        private:

        };

    }

}

#endif      // PBR_FPS_CAMERA_HPP