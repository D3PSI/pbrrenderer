/**
 * @file PBR_UTIL.hpp
 * @brief Contains declarations of utility components and functions
 * @author D3PSI
 */
#ifndef PBR_UTIL_HPP
#define PBT_UTIL_HPP

#include "../PBR.hpp"
#include "flags/PBR_UTIL_FLAGS.hpp"


namespace pbr {

    /**
     * Contains utility functionality for the PBR engine
     */
    namespace util {

        /**
         * Clamps a value to variable borders
         * @param _val The value to clamp
         * @param _low The low border
         * @param _high The high border
         * @return Returns the clamped value
         */
        template< typename T >
        T clamp(T _val, T _low, T _high);
    }

}

#include "PBR_UTIL.tpp"

#endif      // PBR_UTIL_HPP