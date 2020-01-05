/**
 * @file PBR_UTIL.tpp
 * @brief Contains template implementations of utility components and functions
 * @author D3PSI
 */
#ifndef PBR_UTIL_TPP
#define PBR_UTIL_TPP

#include <iostream>


template< typename T >
T pbr::util::clamp(T _val, T _low, T _high) {
    if(_low >= _high) throw std::runtime_error("Invalid clamp borders");
    return (_val < _low) ? _low : (_high < _val) ? _high : _val;
}

#endif      // PBR_UTIL_TPP