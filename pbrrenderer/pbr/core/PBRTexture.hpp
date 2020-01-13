/**
 * @file PBRTexture.hpp
 * @brief Contains declarations of a texture object
 * @author D3PSI
 */
#ifndef PBR_TEXTURE_HPP
#define PBR_TEXTURE_HPP

#include "../util/flags/PBR_UTIL_FLAGS.hpp"

#include <string>


namespace pbr {

    namespace core {

        class PBRTexture {
        public:

            /**
             * Constructor with arguments
             * @param _path The path to the texture file on disk
             * @param _flags The options to set
             */
            PBRTexture(std::string _path, pbr::util::flags::PBR_FLAGS _flags = pbr::util::flags::PBR_FLAG_CLEAR_FLAG_BITS);

            /**
             * Binds a texture
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS bind(void);

            /**
             * Default destructor
             */
            ~PBRTexture(void);

        private:

            int32_t w;     // width
            int32_t h;     // height
            int32_t c;     // number of channels

            uint32_t tex;

        };

    }

}

#endif      // PBR_TEXTURE_HPP