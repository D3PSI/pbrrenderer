/**
 *  Welcome to pbrrenderer by D3PSI
 * 
 *  This project is open-source and licensed under the GNU General Public License v3.0
 *  Please refer to LICENSE.md for further information
 * 
 *  Refer to README.md for installation and compilation instructions
 */
#include "pbr/PBR.hpp"


/**
 * Defines a namespace for the example application
 */
namespace pbrEx {

    std::vector< float > vertices = {
       -1.0f, -1.0f,  1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
        1.0f,  1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
       -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,
       -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        1.0f,  1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
       -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f
    };

    std::vector< uint32_t > indices = {
        0, 1, 2,
        2, 3, 0,
        1, 5, 6,
        6, 2, 1,
        7, 6, 5,
        5, 4, 7,
        4, 0, 3,
        3, 7, 4,
        4, 5, 1,
        1, 0, 4,
        3, 2, 6,
        6, 7, 3
    };

    pbr::core::PBRMesh< float >* cubeMesh;
    pbr::core::PBRShader* cubeShader;

    /**
     * Serves as a callback function for initializing resources
     */
    void init() {
        glEnable(GL_DEPTH_TEST);
        pbrEx::cubeShader = new pbr::core::PBRShader("cubes");
        std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > vaos;
        pbr::util::initializers::PBRVertexAttributeArrayInitializer posVAO = {};
        posVAO._index = 0;
        posVAO._size = 3;
        posVAO._type = GL_FLOAT;
        posVAO._normalized = GL_FALSE;
        posVAO._stride = 6 * sizeof(vertices[0]);
        posVAO._offset = (void*)0;
        vaos.push_back(posVAO);
        pbr::util::initializers::PBRVertexAttributeArrayInitializer colVAO = {};
        colVAO._index = 1;
        colVAO._size = 3;
        colVAO._type = GL_FLOAT;
        colVAO._normalized = GL_FALSE;
        colVAO._stride = 6 * sizeof(vertices[0]);
        colVAO._offset = (void*)(3 * sizeof(vertices[0]));
        vaos.push_back(colVAO);
        pbrEx::cubeMesh = new pbr::core::PBRMesh< float >(
            pbrEx::vertices, 
            vaos,
            std::vector< std::string >(),
            pbr::util::flags::PBR_BUFFER_INDEX_BUFFER_FLAG_BIT,
            indices);
    }

    /**
     * Serves as a callback function for rendering operations
     */
    void render() {
        pbrEx::cubeShader->bind();
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(glm::mat3(pbr::pbrGetViewMatrix()));
        glm::mat4 projection = pbr::pbrGetProjectionMatrix();
        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        pbrEx::cubeShader->upload(model, "m");
        pbrEx::cubeShader->upload(view, "v");
        pbrEx::cubeShader->upload(projection, "p");
        pbrEx::cubeMesh->draw();
    }

    /**
     * Cleans resources on shutdown
     */
    void clean() {
        delete pbrEx::cubeShader;
        delete pbrEx::cubeMesh;
    }

    /**
    * Serves as a keyboard input callback function for the PBR core engine
    * @param _window A pointer to the GLFWwindow
    */
    void keyboardInputCallback(GLFWwindow* _window) {
        if(glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS)
            std::cout << "This is an example on how you can define own key actions.\n";
    }

}

/**
 *  Defines the main entry point for the application
 */
int main() {
    pbr::pbrInit();
    pbr::pbrTitle("PBR by D3PSI");
    pbr::pbrSize(1280, 720);
    pbr::pbrLoadingScreenImage("res/images/lion.png");
    pbr::pbrApplicationIcon("res/images/lion-cropped.png");
    pbr::pbrDisplayMode(pbr::util::flags::PBR_FULLSCREEN);
    pbr::pbrDefaultKeyBindings();
    pbr::pbrKeyboardInputCallback(pbrEx::keyboardInputCallback);
    pbr::pbrInitCallback(pbrEx::init);
    pbr::pbrRenderCallback(pbrEx::render);
    pbr::pbrCleanCallback(pbrEx::clean);
    return pbr::pbr();
}