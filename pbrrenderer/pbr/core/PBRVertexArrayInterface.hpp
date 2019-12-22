/**
 * @file PBRVertexArrayInterface.hpp
 * @brief Declares a wrapper for VAOs
 * @author D3PSI
 */
#ifndef PBR_VERTEX_ARRAY_INTERFACE_HPP
#define PBR_VERTEX_ARRAY_INTERFACE_HPP

#include "../util/PBR_UTIL.hpp"

#include <vector>


namespace pbr {

    namespace core {
        
        template< typename T >
        class PBRVertexArrayInterface 
        {
        public:

            /**
             * Constructor with vertex data
             * @param _vData The vertex data as an std::vector
             * @param _vaos The vertex array initializer structs
             */
            PBRVertexArrayInterface(std::vector< T > _vData, 
                std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > _vaos);

            /**
             * Draws the vertex buffer object
             * @return Returns 0 or bigger on success, returns a negative number on failure
             */
            pbr::util::flags::PBR_STATUS draw(void);

            /**
             * Default destructor
             */
            ~PBRVertexArrayInterface(void);

        private:

            uint32_t VAO;
            uint32_t VBO;
            uint32_t size;

        };

    }

}


#endif      // PBR_VERTEX_ARRAY_INTERFACE_HPP