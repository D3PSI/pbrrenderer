/**
 * @file PBR_UTIL_IO.hpp
 * @brief Contains declarations of I/O utility
 * @author D3PSI
 */
#ifndef PBR_UTIL_IO_HPP
#define PBR_UTIL_IO_HPP

#include <string>
#include <fstream>
#include <sstream>


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace explicitly for I/O-utility
         */
        namespace io {

            /**
             * Reads a file from disk
             * @param _path The path to the file on disk
             * @return Returns std::string as the read buffer
             */
            std::string read(std::string _path);

        }

    }

}

#endif      // PBR_UTIL_IO_HPP