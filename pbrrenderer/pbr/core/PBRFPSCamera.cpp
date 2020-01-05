/**
 * @file PBRFPSCamera.cpp
 * @brief Contains definitions of a FPS camera class
 * @author D3PSI
 */
#ifndef PBR_FPS_CAMERA_CPP
#define PBR_FPS_CAMERA_CPP

#include "PBRFPSCamera.hpp"


pbr::util::flags::PBR_STATUS pbr::core::PBRFPSCamera::look(double _xPos, double _yPos) {
    static double lastX = 0.0;
    static double lastY = 0.0;
    if (pbr::util::io::inputEnabled) {
        double xOff;
        double yOff;
        if (pbr::util::io::firstMouse) {
            xOff = 0;
            yOff = 0;
            pbr::util::io::firstMouse = false;
        }
        else {
            xOff = _xPos - lastX;
            yOff = -(_yPos - lastY);
        }
        lastX = _xPos;
        lastY = _yPos;
        xOff *= sens;
        yOff *= sens;
        this->yaw_val += xOff;
        this->pitch_val += yOff;
        this->pitch_val = pbr::util::clamp(this->pitch_val, -89.0f, 89.0f);
        this->updateVectors();
    }
    return pbr::util::flags::PBR_OK;
}

#endif      // PBR_FPS_CAMERA_CPP