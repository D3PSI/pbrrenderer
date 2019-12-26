/**
 * @file PBR_UTIL.cpp
 * @brief Defines utility components and functions
 * @author D3PSI
 */
#ifndef PBR_UTIL_CPP
#define PBR_UTIL_CPP

#include "PBR_UTIL.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace pbr {

    namespace util {

        unsigned char* loadSTBI(
            const char* _path, 
            int*        _x, 
            int*        _y, 
            int*        _comp, 
            int         _req_comp) {
            return reinterpret_cast< unsigned char* >(stbi_load(
                _path,
                _x,
                _y,
                _comp,
                _req_comp));
        }

        pbr::util::flags::PBR_STATUS freeSTBI(unsigned char* _pixels) {
            stbi_image_free(_pixels);
            return pbr::util::flags::PBR_OK;
        }

    }

}


#endif      // PBR_UTIL_CPP