/**
 * @file PBR_CORE.cpp
 * @brief Defines the core components of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_CPP
#define PBR_CORE_CPP

#include "PBR_CORE.hpp"
#include "../util/flags/PBR_UTIL_FLAGS.hpp"
#include "PBRCameraBase.hpp"


namespace pbr {

    namespace core {

        uint32_t width = pbr::WIDTH;
        uint32_t height = pbr::HEIGHT;

        pbr::core::PBRCameraBase* camera = nullptr;

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        unsigned int VBO;
        unsigned int vs;
        unsigned int fs;

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
                throw std::runtime_error("Failed to gather function pointers for OpenGL through GLAD");
            glViewport(0, 0, pbr::WIDTH, pbr::HEIGHT);
            pbr::ui::loadingScreen->quit();
            glfwShowWindow(pbr::ui::window);
            glfwFocusWindow(pbr::ui::window);
            delete pbr::ui::loadingScreen;
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS loop() {
            while(!glfwWindowShouldClose(pbr::ui::window)) {
                keyInput();
                render();
                glfwSwapBuffers(pbr::ui::window);
                glfwPollEvents();
            }
            glfwTerminate();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS clean() {
            return pbr::util::flags::PBR_OK;
        } 

        pbr::util::flags::PBR_STATUS keyInput() {
            if(glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_1) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_2) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_3) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
                glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE)
                glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            if(pbr::keyInputCB != nullptr)
                keyInputCB(pbr::ui::window);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setup() {
            pbr::core::setupShaders();
            pbr::core::setupBuffers();
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupShaders() {
            /*vs = glCreateShader(GL_VERTEX_SHADER);
            fs = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(vs, 1, &vssource, nullptr);
            glCompileShader(vs);
            glShaderSource(fs, 1, &fssource, nullptr);
            glCompileShader(fs);*/
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupBuffers() {
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            return pbr::util::flags::PBR_OK;
        }

        void framebufferResizeCB(GLFWwindow* _window, int _width, int _height) {
            pbr::core::width = _width;
            pbr::core::height = _height;
            glViewport(0, 0, _width, _height);
        }

        void mouseMoveCB(GLFWwindow* _window, double _xPos, double _yPos) {
        }
        
        void mouseScrollCB(GLFWwindow* _window, double _xOff, double _yOff) {
        }

    }

}

#endif      // PBR_CORE_CPP