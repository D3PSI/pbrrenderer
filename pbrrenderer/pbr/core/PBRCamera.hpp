/**
 * @file PBRCamera.hpp
 * @brief Contains declarations of a base camera class
 * @author D3PSI
 */
#ifndef PBR_CAMERA_HPP
#define PBR_CAMERA_HPP

#include "../PBR.hpp"
#include "../util/defaults/PBR_UTIL_DEFAULTS.hpp"
#include "../util/PBRMakros.hpp"


namespace pbr {

    namespace core {

        class PBRCamera 
        {
        public:

            /**
             * Constructor with arguments
             * @param _pos The starting position of the camera object
             * @param _up The initial up-vector of the camera object, usually (0, 1, 0)
             * @param _yaw The initial yaw-value of the camera object
             * @param _pitch The initial pitch-value of the camera object
             * @param _roll The initial roll-value of the camera object
             */
            PBRCamera(
                glm::vec3   _pos    = ORIGIN,
                glm::vec3   _up     = Y_AXIS,
                float       _yaw    = pbr::util::defaults::YAW,
                float       _pitch  = pbr::util::defaults::PITCH,
                float       _roll   = pbr::util::defaults::ROLL);

            /**
             * Default destructor
             */
            ~PBRCamera(void) = default;

            /**
             * Moves the camera object
             * @param _direction The relative movement direction
             * @param _speed The relative speed to move the camera with
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            virtual pbr::util::flags::PBR_STATUS move(pbr::util::flags::PBR_DIRECTION _direction, float _speed);

            /**
             * Rotates the camera
             * @param _xPos The x-coordinate of the mouse's position
             * @param _yPos The y-coordinate of the mouse's position
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            virtual pbr::util::flags::PBR_STATUS look(double _xPos, double _yPos);

            /**
             * Zooms the camera
             * @param _xOff The x-offset of the mouse's scroll wheel (0 in most cases)
             * @param _yOff The y-offset of the mouse's scroll wheel
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            virtual pbr::util::flags::PBR_STATUS zoom(double _xOff, double _yOff);

            /**
             * Updates the camera orientation vectors
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS updateVectors(void);

            /**
             * Returns a lookAt matrix with the current state values of the camera
             * @return Returns a 4 x 4 matrix as a lookAt matrix
             */
            glm::mat4 lookAt(void);

            /**
             * Queries the current yaw-value
             * @return Returns the current yaw-value
             */
            float yaw(void);

            /**
             * Sets the yaw-value of the camera
             * @param _yaw The new yaw-value of the camera object
             * @return Returns the newly set yaw-value
             */
            float yaw(float _yaw);

            /**
             * Queries the current pitch-value
             * @return Returns the current pitch-value
             */
            float pitch(void);

            /**
             * Sets the pitch-value of the camera
             * @param _pitch The new pitch-value of the camera object
             * @return Returns the newly set pitch-value
             */
            float pitch(float _pitch);

            /**
             * Queries the current roll-value
             * @return Returns the current roll-value
             */
            float roll(void);

            /**
             * Sets the roll-value of the camera
             * @param _roll The new roll-value of the camera object
             * @return Returns the newly set roll-value
             */
            float roll(float _roll);

            /**
             * Queries the current field of view
             * @return Returns the current field of view
             */
            float fov(void);

            protected:

                float yaw_val;
                float pitch_val;
                float roll_val;

                glm::vec3 pos;
                glm::vec3 front;
                glm::vec3 worldUp;
                glm::vec3 right;
                glm::vec3 up;

                float speed;
                float sens;
                float fov_val;

        };

        extern pbr::core::PBRCamera* camera;

    }

}

#endif      // PBR_CAMERA_HPP