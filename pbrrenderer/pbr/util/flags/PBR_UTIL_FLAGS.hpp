/**
 * @file PBR_UTIL_FLAGS.hpp
 * @brief Contains declarations of all sorts of different flags and enumerations
 * @author D3PSI
 */
#ifndef PBR_UTIL_FLAGS_HPP
#define PBR_UTIL_FLAGS_HPP


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace explicitly for flags and enums
         */
        namespace flags {

            /**
             * Defines a status code enumeration
             */
            enum PBR_STATUS {
                PBR_OK = 0,
                PBR_FATAL = -1
            };

            /**
             * Defines an exception code enumeration
             */
            enum PBR_EXCEPTION {
                PBR_IO_EXCEPTION
            };

            /**
             * Defines an enumeration for different display modes
             */
            enum PBR_DISPLAY_MODE {
                PBR_FULLSCREEN,
                PBR_WINDOWED,
                PBR_BORDERLESS
            };

            /**
             * Defines an enumeration for different shader types
             */
            enum PBR_SHADER_TYPE {
                PBR_VERTEX_SHADER,
                PBR_FRAGMENT_SHADER,
                PBR_GEOMETRY_SHADER,
                PBR_COMPUTE_SHADER,
                PBR_TESSELATION_EVALUATION_SHADER,
                PBR_TESSELETION_CONTROL_SHADER
            };

            /**
             * Defines an enumeration for different directions
             */
            enum PBR_DIRECTION {
                PBR_FRONT,
                PBR_BACK,
                PBR_LEFT,
                PBR_RIGHT,
                PBR_UP,
                PBR_DOWN
            };

        }

    }

}

#endif      // PBR_UTIL_FLAGS_HPP