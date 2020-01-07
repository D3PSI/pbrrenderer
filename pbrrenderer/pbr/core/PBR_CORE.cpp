/**
 * @file PBR_CORE.cpp
 * @brief Defines the core components of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_CPP
#define PBR_CORE_CPP

#include "PBR_CORE.hpp"
#include "../util/flags/PBR_UTIL_FLAGS.hpp"
#include "../util/PBR_UTIL.hpp"
#include "PBRFPSCamera.hpp"


namespace pbr {

    namespace core {

        uint32_t width = pbr::util::defaults::WIDTH;
        uint32_t height = pbr::util::defaults::HEIGHT;

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float currentFrame = static_cast< float >(glfwGetTime());

        pbr::core::PBRCameraBase* camera = nullptr;

        std::vector< float > vertices = {
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
        };

        unsigned int VBO;
        unsigned int VAO;
        pbr::core::PBRShaderInterface* shaderMain;
        pbr::core::PBRVertexArrayInterface< float >* vaoMain;

        pbr::util::flags::PBR_STATUS init() {
            pbr::ui::initLoadingScreen();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS execute() {
            pbr::ui::initGLFW();
            pbr::ui::initGLFWWindow();
            pbr::core::initOpenGL();
            pbr::core::loop();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS initOpenGL() {
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                pbr::util::io::raise("Failed to gather function pointers for OpenGL through GLAD");
            glViewport(0, 0, pbr::util::defaults::WIDTH, pbr::util::defaults::HEIGHT);
            pbr::ui::loadingScreen->quit();
            glfwShowWindow(pbr::ui::window);
            glfwMakeContextCurrent(pbr::ui::window);
            glfwFocusWindow(pbr::ui::window);
            delete pbr::ui::loadingScreen;
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS loop() {
            pbr::core::setup();
            while(!glfwWindowShouldClose(pbr::ui::window)) {
                currentFrame = static_cast< float >(glfwGetTime());
                pbr::core::deltaTime = currentFrame - pbr::core::lastFrame;
                pbr::core::lastFrame = currentFrame;
                pbr::util::io::keyboardInput();
                pbr::core::render();
                glfwSwapBuffers(pbr::ui::window);
                glfwPollEvents();
            }
            glfwTerminate();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS clean() {
            delete pbr::core::shaderMain;
            delete pbr::core::vaoMain;
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setup() {
            pbr::core::setupShaders();
            pbr::core::setupBuffers();
            pbr::core::camera = new pbr::core::PBRFPSCamera();
            glEnable(GL_DEPTH_TEST);
            //glEnable(GL_CULL_FACE);
            //glCullFace(GL_BACK);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            pbr::core::shaderMain->bind();
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = camera->lookAt();
            glm::mat4 projection = glm::perspective(static_cast< float >(glm::radians(camera->fov())), width / static_cast< float >(height), 0.1f, 100.0f);
            model = glm::rotate(model, static_cast< float >(glfwGetTime() * glm::radians(90.0f)), glm::vec3(0.0, 0.0, 1.0));
            pbr::core::shaderMain->upload(model, "m");
            pbr::core::shaderMain->upload(view, "v");
            pbr::core::shaderMain->upload(projection, "p");
            pbr::core::vaoMain->draw();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupShaders() {
            pbr::core::shaderMain = new pbr::core::PBRShaderInterface("main");
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupBuffers() {
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
            pbr::core::vaoMain = new pbr::core::PBRVertexArrayInterface< float >(vertices, vaos);
            return pbr::util::flags::PBR_OK;
        }

        void framebufferResizeCB(GLFWwindow* _window, int _width, int _height) {
            pbr::core::width = _width;
            pbr::core::height = _height;
            glViewport(0, 0, _width, _height);
        }

        void mouseMoveCB(GLFWwindow* _window, double _xPos, double _yPos) {
            pbr::util::io::mouseMovement(_xPos, _yPos);
        }
        
        void mouseScrollCB(GLFWwindow* _window, double _xOff, double _yOff) {
            pbr::util::io::mouseScroll(_xOff, _yOff);
        }

    }

}

#endif      // PBR_CORE_CPP