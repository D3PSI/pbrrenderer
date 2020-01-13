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

        pbr::core::PBRCamera* camera = nullptr;

        pbr::util::flags::PBR_STATUS init() {
            pbr::ui::initLoadingScreen();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS execute() {
            pbr::ui::initGLFW();
            pbr::ui::initGLFWWindow();
            pbr::core::initOpenGL();
            pbr::core::setup();
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
            if(pbr::util::defaults::CLEAN_CB != nullptr)
                pbr::util::defaults::CLEAN_CB();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setup() {
            if(pbr::util::defaults::INIT_CB != nullptr)
                pbr::util::defaults::INIT_CB();
            pbr::core::camera = new pbr::core::PBRFPSCamera();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS render() {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if(pbr::util::defaults::RENDER_CB != nullptr)
                pbr::util::defaults::RENDER_CB();
            return pbr::util::flags::PBR_OK;
        }

        glm::mat4 getViewMatrix() {
            return camera->lookAt();
        }

        glm::mat4 getProjectionMatrix() {
            return glm::perspective(
                static_cast< float >(glm::radians(pbr::core::camera->fov())), 
                pbr::core::width / static_cast< float >(pbr::core::height),
                0.1f, 
                100.0f);
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