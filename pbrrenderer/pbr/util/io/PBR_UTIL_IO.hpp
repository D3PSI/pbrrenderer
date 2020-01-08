/**
 * @file PBR_UTIL_IO.hpp
 * @brief Contains declarations of I/O utility
 * @author D3PSI
 */
#ifndef PBR_UTIL_IO_HPP
#define PBR_UTIL_IO_HPP

#include "../../PBR.hpp"
#include "../defaults/PBR_UTIL_DEFAULTS.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace explicitly for I/O-utility
         */
        namespace io {

            extern bool inputEnabled;
            extern bool firstMouse;

            /**
             * Reads a file from disk
             * @param _path The path to the file on disk
             * @return Returns std::string as the read buffer
             */
            std::string read(std::string _path);

            /**
             * Processes input from the keyboard
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS keyboardInput(void);

            /**
             * Processes mouse movement 
             * @param _xPos The new x-coordinate of the mouse's position
             * @param _yPos The new y-coordinate of the mouse's position
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS mouseMovement(double _xPos, double _yPos);

            /**
             * Processes mouse scrolling
             * @param _xOff The x-offset of the mouse wheel (usually 0)
             * @param _yOff The y-offset of the mouse wheel
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS mouseScroll(double _xOff, double _yOff);

            /**
             * Throws an exception and handles errors
             * @throw Throws an std::runtime_error when called
             * @return Returns 0 or bigger on success, returns a negative number on failure (for completeness ;))
             */
            pbr::util::flags::PBR_STATUS raise(std::string _msg);

            /**
             * Prints a warning to the console
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS warn(std::string _msg);

            /**
             * Defines a wrapper function to load an image using stb_image.h, 
             * because said file can only be included in *one* .cpp-source file
             * @param _path The path to the image on disk
             * @param _x The width of the image
             * @param _y The height of the image
             * @param _comp Something with channels and stuff - just put 0
             * @param _req_comp The amount of channels :
             *      STBI_default    = 0, // only used for desired_channels
             *      STBI_grey       = 1,
             *      STBI_grey_alpha = 2,
             *      STBI_rgb        = 3,
             *      STBI_rgb_alpha  = 4
             * @return Returns a as a unsigned char* reinterpreted pointer to a stbi_uc struct
             */
            unsigned char* loadSTBI(
                const char* _path, 
                int*        _x, 
                int*        _y, 
                int*        _comp, 
                int         _req_comp);

            /**
             * Defines a wrapper function to free a loaded image using stb_image.h, 
             * because said file can only be included in *one* .cpp-source file
             * @param _pixels The array of pixels as an unsigned char pointer
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS freeSTBI(unsigned char* _pixels);

        }

    }

}

#endif      // PBR_UTIL_IO_HPP