/**
 * Welcome to PBR by D3PSI
 * 
 * This project is open-source and licensed under the GNU General Public License v3.0
 * Please refer to LICENSE.md for further information
 * 
 * Refer to README.md for installation and compilation instructions
 * @file PBR.cpp
 * @brief Main source file for PBR
 * @author D3PSI
 */
#ifndef PBR_CPP
#define PBR_CPP

#include "PBR.hpp"
#include "core/PBRCameraBase.hpp"


namespace pbr {

    pbr::util::flags::PBR_STATUS pbrInit() {
        return pbr::core::init();
    }

    pbr::util::flags::PBR_STATUS pbrExecute() {
        return pbr::core::execute();
    }

    pbr::util::flags::PBR_STATUS pbrClean() {
        pbr::core::clean();
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrSize(uint32_t _width, uint32_t _height) {
        pbr::util::defaults::WIDTH = _width;
        pbr::util::defaults::HEIGHT = _height;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrTitle(const char* _title) {
        pbr::util::defaults::TITLE = _title;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrLoadingScreenImage(const char* _image) {
        pbr::util::defaults::LOADING_SCREEN_IMAGE = _image;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrApplicationIcon(const char* _icon) {
        pbr::util::defaults::APPLICATION_ICON = _icon;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrDisplayMode(pbr::util::flags::PBR_DISPLAY_MODE _mode) {
        pbr::util::defaults::DISPLAY_MODE = _mode;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrKeyboardInputCallback(pbr::util::PBRKeyboardInputCallbackFun _cbfun) {
        pbr::util::defaults::KEY_INPUT_CB = _cbfun;
        return pbr::util::flags::PBR_OK;
    }

    pbr::util::flags::PBR_STATUS pbrDefaultKeyBindings(bool _enable) {
        pbr::util::defaults::DEFAULT_KEY_BINDINGS = _enable;
        return pbr::util::flags::PBR_OK;
    }

    uint32_t pbrGetCurrentWidth() {
        return pbr::core::width;
    }

    uint32_t pbrGetCurrentHeight() {
        return pbr::core::height;
    }

    float pbrGetCurrentYaw() {
        return pbr::core::camera->yaw();
    }
    
    float pbrGetCurrentPitch() {
        return pbr::core::camera->pitch();
    }

    float pbrGetCurrentRoll() {
        return pbr::core::camera->roll();
    }

}

#endif      // PBR_CPP