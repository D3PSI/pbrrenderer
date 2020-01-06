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

        }

    }

}

#endif      // PBR_UTIL_IO_HPP