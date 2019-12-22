/**
 * @file PBR_UTIL_INITIALIZERS.hpp
 * @brief Contains declarations of initializer structures
 * @author D3PSI
 */
#ifndef PBR_UTIL_INITIALIZERS_HPP
#define PBR_UTIL_INITIALIZERS_HPP

#include <stdint.h>


namespace pbr {

    namespace util {

        /**
         * Declares a sub namespace explicitly for initialization structures
         */
        namespace initializers {

            /**
             * Declares a struct containing information on how to activate a vertex array
             * @param _index The index of the vertex array
             * @param _size How many values to pass
             * @param _type The type of the values (eg. GL_FLOAT)
             * @param _normalized Are the values normalized (eg. GL_FALSE)
             * @param _stride The offset to the next value
             * @param _offset The starting offset
             */
            typedef struct PBRVertexAttributeArrayInitializer {
                uint32_t        _index;
                uint32_t        _size;
                uint32_t        _type;
                unsigned char   _normalized;
                uint32_t        _stride;
                const void*     _offset;
            } PBRRVertexAttributeArrayInitializer;

        }

    }

}

#endif      // PBR_UTIL_INITIALIZERS_HPP