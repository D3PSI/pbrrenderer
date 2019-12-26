/**
 * @file PBRFPSCamera.cpp
 * @brief Contains definitions of a FPS camera class
 * @author D3PSI
 */
#ifndef PBR_FPS_CAMERA_CPP
#define PBR_FPS_CAMERA_CPP

#include "PBRFPSCamera.hpp"

pbr::util::flags::PBR_STATUS pbr::core::PBRFPSCamera::processInput(GLFWwindow* _window) {
    static float deltaTime = 0.0f;
    static float lastFrame = 0.0f;
    float currentFrame = static_cast< float >(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    float camSpeed = 2.5f * deltaTime;
    if(glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
        this->pos += camSpeed * this->front;
    if(glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) 
        this->pos -= camSpeed * this->front;
    if(glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) 
        this->pos -= camSpeed * this->right;
    if(glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) 
        this->pos += camSpeed * this->right;
    if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        inputEnabled = false;
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstMouse = true;
    }
    else if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE) {
        inputEnabled = true;
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRFPSCamera::processMouseMovement(double _xPos, double _yPos) {
    static double lastX = 0.0;
    static double lastY = 0.0;
    if (this->inputEnabled) {
        double xOff;
        double yOff;
        if (this->firstMouse) {
            xOff = 0;
            yOff = 0;
            this->firstMouse = false;
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

pbr::util::flags::PBR_STATUS pbr::core::PBRFPSCamera::processMouseScroll(double _xOff, double _yOff) {
    if(this->inputEnabled) {
        this->fov_val -= _yOff;
        this->fov_val = pbr::util::clamp(this->fov_val, 1.0f, 130.0f);
    }
    return pbr::util::flags::PBR_OK;
}

pbr::core::PBRFPSCamera::~PBRFPSCamera() {

}

#endif      // PBR_FPS_CAMERA_CPP