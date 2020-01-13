/**
 * @file PBRShader.cpp
 * @brief Defines a wrapper for shaders
 * @author D3PSI
 */
#ifndef PBR_SHADER_CPP
#define PBR_SHADER_CPP

#include "PBRShader.hpp"


std::string pbr::core::PBRShader::SHADER_BASE_DIR = "shaders/";

pbr::core::PBRShader::PBRShader(std::string _shaderSet) {
    this->shaderSet = _shaderSet;
    int succ;
    char infoLog[1024];
    std::vector< std::string > contents;
    for(const auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(
        (pbr::core::PBRShader::SHADER_BASE_DIR + _shaderSet)), {})) {
        std::string path = std::string(entry.path().c_str());
        std::string ext = path.substr(path.find_last_of("."));
        if(ext == ".comp")
            shaderPaths[pbr::util::flags::PBR_COMPUTE_SHADER] = path;
        if(ext == ".vert")
            shaderPaths[pbr::util::flags::PBR_VERTEX_SHADER] = path;
        if(ext == ".frag")
            shaderPaths[pbr::util::flags::PBR_FRAGMENT_SHADER] = path;
        if(ext == ".geom")
            shaderPaths[pbr::util::flags::PBR_GEOMETRY_SHADER] = path;
        if(ext == ".tes")
            shaderPaths[pbr::util::flags::PBR_TESSELATION_EVALUATION_SHADER] = path;
        if(ext == ".tcs")
            shaderPaths[pbr::util::flags::PBR_TESSELETION_CONTROL_SHADER] = path;
    }
    for(const auto& shader : shaderPaths) {
        shadersRaw[shader.first] = pbr::util::io::read(shader.second);
        if(shader.first == pbr::util::flags::PBR_COMPUTE_SHADER)
            shaders[shader.first] = glCreateShader(GL_COMPUTE_SHADER);
        if(shader.first == pbr::util::flags::PBR_VERTEX_SHADER)
            shaders[shader.first] = glCreateShader(GL_VERTEX_SHADER);
        if(shader.first == pbr::util::flags::PBR_FRAGMENT_SHADER)
            shaders[shader.first] = glCreateShader(GL_FRAGMENT_SHADER);
        if(shader.first == pbr::util::flags::PBR_GEOMETRY_SHADER)
            shaders[shader.first] = glCreateShader(GL_GEOMETRY_SHADER);
        shaderSources[shader.first] = shadersRaw[shader.first].c_str();
        glShaderSource(shaders[shader.first], 1, &shaderSources[shader.first], nullptr);
        glCompileShader(shaders[shader.first]);
        glGetShaderiv(shaders[shader.first], GL_COMPILE_STATUS, &succ);
        if(!succ) {
            glGetShaderInfoLog(shaders[shader.first], 1024, nullptr, infoLog);
            std::cerr << "Error compiling shader at " << shaderPaths[shader.first] << ":\n" << infoLog << std::endl;
        }
    }
    ID = glCreateProgram();
    for(const auto& shader : shaderPaths) {
        glAttachShader(this->ID, shaders[shader.first]);
    }
    glLinkProgram(this->ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &succ);
    if(!succ) {
        glGetProgramInfoLog(this->ID, 1024, nullptr, infoLog);
        std::cerr << "Error linking shader program " << shaderSet <<":\n" << infoLog << std::endl;
    }
    for(const auto& shader : shaderPaths) {
        glDeleteShader(shaders[shader.first]);
    }
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::bind() {
    glUseProgram(this->ID);
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::upload(glm::mat4 _mat, const std::string _name) {
    glUniformMatrix4fv(
        glGetUniformLocation(this->ID, _name.c_str()), 
        1, 
        GL_FALSE, 
        glm::value_ptr(_mat));
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::upload(glm::vec3 _vec, const std::string _name) {
    glUniform3fv(glGetUniformLocation(this->ID, _name.c_str()), 1, glm::value_ptr(_vec));
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::upload(float _val, const std::string _name) {
    glUniform1f(glGetUniformLocation(ID, _name.c_str()), _val);
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::upload(int32_t _val, const std::string _name) {
    glUniform1i(glGetUniformLocation(ID, _name.c_str()), _val);
    return pbr::util::flags::PBR_OK;
}

pbr::util::flags::PBR_STATUS pbr::core::PBRShader::upload(bool _val, const std::string _name) {
    return this->upload(static_cast< int32_t >(_val), _name);
}

pbr::core::PBRShader::~PBRShader() {
    
}

#endif      // PBR_SHADER_CPP