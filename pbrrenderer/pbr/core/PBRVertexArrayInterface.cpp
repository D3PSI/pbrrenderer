/**
 * @file PBRVertexArrayInterface.cpp
 * @brief Defines a wrapper for VAOs
 * @author D3PSI
 */
#ifndef PBR_VERTEX_ARRAY_INTERFACE_CPP
#define PBR_VERTEX_ARRAY_INTERFACE_CPP

#include "PBRVertexArrayInterface.hpp"


template< typename T >
pbr::core::PBRVertexArrayInterface< T >::PBRVertexArrayInterface(const std::vector< T >& _vData, 
    const std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > _vaos,
    const pbr::util::flags::PBR_FLAG_BITS _flags,
    const std::vector< uint32_t >& _iData) : flags(_flags) {
    this->size = _vData.size() / _vaos.size();
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(this->VAO);
    if(_iData.size() != 0) {
        if(!(_flags & pbr::util::flags::PBR_BUFFER_INDEX_BUFFER_FLAG_BIT)) 
            pbr::util::io::raise("Required index buffer flag bit not set!");
        glGenBuffers(1, &this->EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER, 
            sizeof(_iData[0]) * _iData.size(),
            _iData.data(),
            GL_STATIC_DRAW);
    }
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(_vData[0]) * _vData.size(),
        _vData.data(),
        GL_STATIC_DRAW);
    for(pbr::util::initializers::PBRVertexAttributeArrayInitializer vao : _vaos) {
        glVertexAttribPointer(
            vao._index,
            vao._size,
            vao._type,
            vao._normalized,
            vao._stride,
            vao._offset);
        glEnableVertexAttribArray(vao._index);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

template< typename T >
pbr::util::flags::PBR_STATUS pbr::core::PBRVertexArrayInterface< T >::draw() {
    glBindVertexArray(this->VAO);
    if(this->flags & pbr::util::flags::PBR_BUFFER_INDEX_BUFFER_FLAG_BIT) 
        glDrawElements(GL_TRIANGLES, this->size, GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_TRIANGLES, 0, this->size);
    return pbr::util::flags::PBR_OK;
} 

template< typename T >
pbr::core::PBRVertexArrayInterface< T >::~PBRVertexArrayInterface() {

}

template class pbr::core::PBRVertexArrayInterface< float >;

#endif      // PBR_VERTEX_ARRAY_INTERFACE_CPP