/**
 * @file PBRVertexArrayInterface.hpp
 * @brief Declares a wrapper for VAOs
 * @author D3PSI
 */
#ifndef PBR_VERTEX_ARRAY_INTERFACE_HPP
#define PBR_VERTEX_ARRAY_INTERFACE_HPP

#include "../PBR.hpp"
#include "../util/initializers/PBR_UTIL_INITIALIZERS.hpp"

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
             * @param _flags The flags to set options
             * @param _iData The index data as an std::vector
             */
            PBRVertexArrayInterface(const std::vector< T >& _vData, 
                const std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > _vaos,
                const pbr::util::flags::PBR_FLAG_BITS _flags = pbr::util::flags::PBR_CLEAR_FLAG_BITS,
                const std::vector< uint32_t >& _iData = std::vector< uint32_t >());

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

            pbr::util::flags::PBR_FLAG_BITS flags;

            uint32_t VAO;
            uint32_t VBO;
            uint32_t EBO;
            uint32_t size;

        };

    }

}


#endif      // PBR_VERTEX_ARRAY_INTERFACE_HPP