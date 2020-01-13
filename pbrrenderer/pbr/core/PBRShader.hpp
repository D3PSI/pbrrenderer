/**
 * @file PBRShader.hpp
 * @brief Declares a wrapper for shaders
 * @author D3PSI
 */
#ifndef PBR_SHADER_HPP
#define PBR_SHADER_HPP

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "../PBR.hpp"
#include "../util/PBR_UTIL.hpp"

#include <string>
#include <vector>
#include <map>


namespace pbr {

    namespace core {

        class PBRShader
        {
        public:

            /**
             * Constructor with arguments
             * @param _shaderSet The shader subdirectory where the shader set 
             * consisting of various different shader types can be found in SHADER_BASE_DIR.
             * The directory must contain filenames according to the following scheme of file endings:
             *      {_shaderSet}/[*].vert for a vertex shader
             *      {_shaderSet}/[*].frag for a fragment shader
             *      {_shaderSet}/[*].geom for a geometry shader
             *      {_shaderSet}/[*].comp for a compute shader
             *      {_shaderSet}/[*].tes for a tesselation evaluation shader
             *      {_shaderSet}/[*].tcs for a tesselation control shader
             * The function will automatically load and compile the shaders it finds
             */
            PBRShader(std::string _shaderSet);

            /**
             * Binds the shader program to use during rendering
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS bind(void);

            /**
             * Sends a 4 x 4 matrix to the shaders
             * @param _mat The 4 x 4 matrix to send to the shaders
             * @param _name The name of the uniform variable
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS upload(glm::mat4 _mat, const std::string _name);

            /**
             * Sends a 3-component vector to the shaders
             * @param _vec The 3-component vector to send to the shaders
             * @param _name The name of the uniform variable
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS upload(glm::vec3 _vec, const std::string _name);

            /**
             * Sends a float to the shaders
             * @param _val The float to send to the shaders
             * @param _name The name of the uniform variable
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS upload(float _val, const std::string _name);

            /**
             * Sends an integer to the shaders
             * @param _val The integer to send to the shaders
             * @param _name The name of the uniform variable
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS upload(int32_t _val, const std::string _name);

            /**
             * Sends a boolean to the shaders
             * @param _val The boolean to send to the shaders
             * @param _name The name of the uniform variable
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS upload(bool _val, const std::string _name);

            /**
             * Default destructor
             */
            ~PBRShader(void);

        private:

            static std::string SHADER_BASE_DIR;
            std::string shaderSet;
            std::map< pbr::util::flags::PBR_SHADER_TYPE, std::string > shaderPaths;
            std::map< pbr::util::flags::PBR_SHADER_TYPE, std::string > shadersRaw;
            std::map< pbr::util::flags::PBR_SHADER_TYPE, uint32_t > shaders;
            std::map< pbr::util::flags::PBR_SHADER_TYPE, const char* > shaderSources;

            uint32_t ID;

        };

    }

}

#endif      // PBR_SHADER_HPP