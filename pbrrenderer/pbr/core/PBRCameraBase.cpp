/**
 * @file PBRCameraBase.cpp
 * @brief Contains definitions of a base camera class
 * @author D3PSI
 */
#ifndef PBR_CAMERA_BASE_CPP
#define PBR_CAMERA_BASE_CPP

#include "PBRCameraBase.hpp"


pbr::core::PBRCameraBase::PBRCameraBase(
    glm::vec3   _pos,
    glm::vec3   _up,
    float       _yaw,
    float       _pitch,
    float       _roll) : pos(_pos),
                         up(_up),
                         worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
                         speed(pbr::util::defaults::CAMERA_SPEED),
                         sens(pbr::util::defaults::SENSITIVITY),
                         fov_val(pbr::util::defaults::FOV),
                         yaw_val(_yaw),
                         pitch_val(_pitch),
                         roll_val(_roll) {
    this->updateVectors();
}

pbr::util::flags::PBR_STATUS pbr::core::PBRCameraBase::move(pbr::util::flags::PBR_DIRECTION _direction, 
    float _speed) {
        static float deltaTime = 0.0f;
        static float lastFrame = 0.0f;
        float currentFrame = static_cast< float >(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        float camSpeed = _speed * deltaTime;
        switch(_direction) {
            case pbr::util::flags::PBR_FRONT:
                this->pos += camSpeed * this->front;
                break;
            case pbr::util::flags::PBR_BACK:
                this->pos -= camSpeed * this->front;
                break;
            case pbr::util::flags::PBR_LEFT:
                this->pos += camSpeed * this->right;
                break;
            case pbr::util::flags::PBR_RIGHT:
                this->pos -= camSpeed * this->right;
                break;
            default:
                pbr::util::io::raise("Invalid movement direction");
                break;
        }
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRCameraBase::look(double _xPos, double _yPos) {
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRCameraBase::updateVectors() {
    glm::vec3 newFront;
    newFront.x = static_cast< float >(glm::cos(glm::radians(this->yaw())) * glm::cos(glm::radians(this->pitch())));
    newFront.y = static_cast< float >(glm::sin(glm::radians(this->pitch())));
    newFront.z = static_cast< float >(glm::sin(glm::radians(this->yaw())) * glm::cos(glm::radians(this->pitch())));
    this->front = glm::normalize(newFront);
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));
    this->up = glm::cross(this->right, this->front);
    return pbr::util::flags::PBR_OK;
}

glm::mat4 pbr::core::PBRCameraBase::lookAt() {
    return glm::lookAt(this->pos, this->pos + this->front, this->up);
}

float pbr::core::PBRCameraBase::yaw() {
    return this->yaw_val;
}

float pbr::core::PBRCameraBase::yaw(float _yaw) {
    this->yaw_val = _yaw;
    return this->yaw_val;
}

float pbr::core::PBRCameraBase::pitch() {
    return this->pitch_val;
}

float pbr::core::PBRCameraBase::pitch(float _pitch) {
    this->pitch_val = _pitch;
    return this->pitch_val;
}

float pbr::core::PBRCameraBase::roll() {
    return this->roll_val;
}

float pbr::core::PBRCameraBase::roll(float _roll) {
    this->roll_val = _roll;
    return this->roll_val;
}

float pbr::core::PBRCameraBase::fov() {
    return this->fov_val;
}

#endif      // PBR_CAMERA_BASE_CPP