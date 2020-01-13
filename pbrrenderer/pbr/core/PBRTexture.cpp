/**
 * @file PBRTexture.cpp
 * @brief Contains definitions of a texture object
 * @author D3PSI
 */
#ifndef PBR_TEXTURE_CPP
#define PBR_TEXTURE_CPP

#include "PBRTexture.hpp"
#include "../util/io/PBR_UTIL_IO.hpp"


pbr::core::PBRTexture::PBRTexture(std::string _path, pbr::util::flags::PBR_FLAGS _flags) {
    unsigned char* _pix = pbr::util::io::loadSTBI(
        _path.c_str(), 
        &this->w, 
        &this->h, 
        &this->c, 
        4);
    if(!_pix) pbr::util::io::warn("Failed to load texture: " + _path);
    glGenTextures(1, &this->tex);
    glBindTexture(GL_TEXTURE_2D, this->tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        GL_RGBA, 
        this->w, 
        this->h, 
        0, 
        GL_RGBA, 
        GL_UNSIGNED_BYTE, 
        _pix);
    glGenerateMipmap(GL_TEXTURE_2D);
    pbr::util::io::freeSTBI(_pix);
}

pbr::util::flags::PBR_STATUS pbr::core::PBRTexture::bind() {
    glBindTexture(GL_TEXTURE_2D, this->tex);
    return pbr::util::flags::PBR_OK;
}

pbr::core::PBRTexture::~PBRTexture() {

}

#endif      // PBR_TEXTURE_CPP