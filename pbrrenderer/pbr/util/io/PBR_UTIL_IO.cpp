/**
 * @file PBR_UTIL_IO.cpp
 * @brief Contains definitions of I/O utility
 * @author D3PSI
 */
#ifndef PBR_UTIL_IO_CPP
#define PBR_UTIL_IO_CPP

#include "PBR_UTIL_IO.hpp"
#include "../../core/PBR_CORE.hpp"
#include "../../core/PBRCameraBase.hpp"
#include "../PBR_UTIL.hpp"


namespace pbr {

    namespace util {

        namespace io {

            bool inputEnabled = true;
            bool firstMouse = true;

            std::string read(std::string _path) {
                std::ifstream fileStream;
                std::string buf;
                fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                try {
                    fileStream.open(_path);
                    std::stringstream contentStream;
                    contentStream << fileStream.rdbuf();
                    fileStream.close();
                    buf = contentStream.str().c_str();
                    return buf;
                }
                catch (std::ifstream::failure& _e) {
                    pbr::util::io::raise("Failed to read file from " + _path);
                    return nullptr;
                }
            }

            pbr::util::flags::PBR_STATUS keyboardInput() {
                if(pbr::util::defaults::DEFAULT_KEY_BINDINGS) {
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_W) == GLFW_PRESS)
                        pbr::core::camera->move(pbr::util::flags::PBR_FRONT, pbr::util::defaults::CAMERA_SPEED);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_S) == GLFW_PRESS) 
                        pbr::core::camera->move(pbr::util::flags::PBR_BACK, pbr::util::defaults::CAMERA_SPEED);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_A) == GLFW_PRESS) 
                        pbr::core::camera->move(pbr::util::flags::PBR_LEFT, pbr::util::defaults::CAMERA_SPEED);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_D) == GLFW_PRESS) 
                        pbr::core::camera->move(pbr::util::flags::PBR_RIGHT, pbr::util::defaults::CAMERA_SPEED);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                        glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                        glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_1) == GLFW_PRESS)
                        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_2) == GLFW_PRESS)
                        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_3) == GLFW_PRESS)
                        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
                        pbr::util::io::inputEnabled = false;
                        pbr::util::io::firstMouse = true;
                        glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                    }
                    if(glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE) {
                        pbr::util::io::inputEnabled = true;
                        glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                    }
                }
                if(pbr::util::defaults::KEY_INPUT_CB != nullptr)
                    pbr::util::defaults::KEY_INPUT_CB(pbr::ui::window);
                return pbr::util::flags::PBR_OK;
            }

            pbr::util::flags::PBR_STATUS mouseMovement(double _xPos, double _yPos) {
                return pbr::util::flags::PBR_OK;
            }

            pbr::util::flags::PBR_STATUS mouseScroll(double _xOff, double _yOff) {
                return pbr::util::flags::PBR_OK;
            }

            pbr::util::flags::PBR_STATUS raise(std::string _msg) {
                throw std::runtime_error(_msg);
                return pbr::util::flags::PBR_OK;
            }

        }

    }

}

#endif      // PBR_UTIL_IO_CPP