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

    bool lockCube = true;

    /**
     * Serves as a callback function for initializing resources
     */
    void init() {
        glEnable(GL_DEPTH_TEST);
        pbrEx::cubeShader = new pbr::core::PBRShader("cubes");
        std::vector< pbr::util::initializers::PBRVertexAttributeArrayInitializer > vaos;
        pbr::util::initializers::PBRVertexAttributeArrayInitializer posVA = {};
        posVA._index = 0;
        posVA._size = 3;
        posVA._type = GL_FLOAT;
        posVA._normalized = GL_FALSE;
        posVA._stride = 6 * sizeof(vertices[0]);
        posVA._offset = (void*)0;
        vaos.push_back(posVA);
        pbr::util::initializers::PBRVertexAttributeArrayInitializer colVA = {};
        colVA._index = 1;
        colVA._size = 3;
        colVA._type = GL_FLOAT;
        colVA._normalized = GL_FALSE;
        colVA._stride = 6 * sizeof(vertices[0]);
        colVA._offset = (void*)(3 * sizeof(vertices[0]));
        vaos.push_back(colVA);
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
        glm::mat4 view = glm::mat4(1.0f);
        if(pbrEx::lockCube)
            view = glm::mat4(glm::mat3(pbr::pbrGetViewMatrix()));
        else
            view = pbr::pbrGetViewMatrix();
        glm::mat4 projection = pbr::pbrGetProjectionMatrix();
        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        pbrEx::cubeShader->upload(model, "m");
        pbrEx::cubeShader->upload(view, "v");
        pbrEx::cubeShader->upload(projection, "p");
        glViewport(
            0, 
            0, 
            pbr::pbrGetCurrentWidth() / 2, 
            pbr::pbrGetCurrentHeight() / 2);
        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        pbrEx::cubeMesh->draw();
        glViewport(
            pbr::pbrGetCurrentWidth() / 2, 
            0, 
            pbr::pbrGetCurrentWidth() / 2, 
            pbr::pbrGetCurrentHeight() / 2);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        pbrEx::cubeMesh->draw();
        glViewport(
            0, 
            pbr::pbrGetCurrentHeight() / 2,
            pbr::pbrGetCurrentWidth() / 2, 
            pbr::pbrGetCurrentHeight() / 2);
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        pbrEx::cubeMesh->draw();
        glViewport(
            pbr::pbrGetCurrentWidth() / 2,
            pbr::pbrGetCurrentHeight() / 2,
            pbr::pbrGetCurrentWidth() / 2, 
            pbr::pbrGetCurrentHeight() / 2);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDisable(GL_DEPTH_TEST);
        pbrEx::cubeMesh->draw();
        glViewport(
            0, 
            0, 
            pbr::pbrGetCurrentWidth(), 
            pbr::pbrGetCurrentHeight());
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
        if(glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            static double start = glfwGetTime() - 1.0;      // -1.0 prevents bug for first time switch
            double now = glfwGetTime();
            if(now - start > 0.5) {
                pbrEx::lockCube = !pbrEx::lockCube;
                start = glfwGetTime();
            }
        }
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
    pbr::pbrApplicationIcon("res/images/icon-32.png");
    pbr::pbrDisplayMode(pbr::util::flags::PBR_WINDOWED);
    pbr::pbrDefaultKeyBindings();
    pbr::pbrKeyboardInputCallback(pbrEx::keyboardInputCallback);
    pbr::pbrInitCallback(pbrEx::init);
    pbr::pbrRenderCallback(pbrEx::render);
    pbr::pbrCleanCallback(pbrEx::clean);
    return pbr::pbr();
}