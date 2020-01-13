/**
 * @file PBRMesh.cpp
 * @brief Defines a renderable mesh object
 * @author D3PSI
 */
#ifndef PBR_MESH_CPP
#define PBR_MESH_CPP

#include "PBRMesh.hpp"


template< typename T >
pbr::core::PBRMesh< T >::PBRMesh(const std::vector< T >& _vData, 
    const std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > _vaos,
    const std::vector< std::string > _texPaths,
    const pbr::util::flags::PBR_FLAGS _flags,
    const std::vector< uint32_t >& _iData) : flags(_flags) {
    uint32_t valsPerVert = 0;
    for(auto vao : _vaos) valsPerVert += vao._size;
    this->size = _vData.size() / valsPerVert;
    if(_flags & pbr::util::flags::PBR_BUFFER_INDEX_BUFFER_FLAG_BIT) this->size = _iData.size();
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
    if(_texPaths.size() != 0) {
        if(!(_flags & pbr::util::flags::PBR_BUFFER_TEXTURE_FLAG_BIT))
            pbr::util::io::raise("Required texture flag bit not set!");
        for(std::string path : _texPaths)    
            this->textures.push_back(new pbr::core::PBRTexture(path));
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
pbr::util::flags::PBR_STATUS pbr::core::PBRMesh< T >::draw() {
    if(this->flags & pbr::util::flags::PBR_BUFFER_TEXTURE_FLAG_BIT)
        for(uint32_t i = 0; i < this->textures.size(); i++) {
            glActiveTexture(GL_TEXTURE0 + i);
            this->textures[i]->bind();
        }
    glBindVertexArray(this->VAO);
    if(this->flags & pbr::util::flags::PBR_BUFFER_INDEX_BUFFER_FLAG_BIT) 
        glDrawElements(GL_TRIANGLES, this->size, GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_TRIANGLES, 0, this->size);
    return pbr::util::flags::PBR_OK;
} 

template< typename T >
pbr::core::PBRMesh< T >::~PBRMesh() {
    for(auto tex : this->textures)
        delete tex;
}

template class pbr::core::PBRMesh< float >;

#endif      // PBR_MESH_CPP