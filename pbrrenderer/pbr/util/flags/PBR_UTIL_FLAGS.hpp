/**
 * @file PBR_UTIL_FLAGS.hpp
 * @brief Contains declarations of all sorts of different flags and enumerations
 * @author D3PSI
 */
#ifndef PBR_UTIL_FLAGS_HPP
#define PBR_UTIL_FLAGS_HPP

#include <stdint.h>


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace explicitly for flags and enums
         */
        namespace flags {

            typedef int32_t PBR_FLAG;

            /**
             * Defines a status code enumeration
             */
            typedef enum PBR_STATUS {
                PBR_OK = 0,
                PBR_FATAL = -1
            } PBR_STATUS;

            /**
             * Defines an exception code enumeration
             */
            typedef enum PBR_EXCEPTION {
                PBR_IO_EXCEPTION
            } PBR_EXCEPTION;

            /**
             * Defines an enumeration for different display modes
             */
            typedef enum PBR_DISPLAY_MODE {
                PBR_FULLSCREEN,
                PBR_WINDOWED,
                PBR_BORDERLESS
            } PBR_DISPLAY_MODE;

            /**
             * Defines an enumeration for different shader types
             */
            typedef enum PBR_SHADER_TYPE {
                PBR_VERTEX_SHADER,
                PBR_FRAGMENT_SHADER,
                PBR_GEOMETRY_SHADER,
                PBR_COMPUTE_SHADER,
                PBR_TESSELATION_EVALUATION_SHADER,
                PBR_TESSELETION_CONTROL_SHADER
            } PBR_SHADER_TYPE;

            /**
             * Defines an enumeration for different directions
             */
            typedef enum PBR_DIRECTION {
                PBR_FRONT,
                PBR_BACK,
                PBR_LEFT,
                PBR_RIGHT,
                PBR_UP,
                PBR_DOWN
            } PBR_DIRECTION;

            /**
             * Defines an enumeration for flag bits
             */
            typedef enum PBR_FLAG_BITS {
                PBR_FLAG_CLEAR_FLAG_BITS = 0x00000000,
                PBR_BUFFER_INDEX_BUFFER_FLAG_BIT = 0x00000001,
                PBR_BUFFER_TEXTURE_FLAG_BIT = 0x00000002,
                PBR_FLAG_MAX_BIT = 0x7fffffff
            } PBR_FLAG_BITS;
            typedef PBR_FLAG PBR_FLAGS;

        }

    }

}

#endif      // PBR_UTIL_FLAGS_HPP