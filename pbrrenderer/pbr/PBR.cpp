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


namespace pbr {

    uint32_t WIDTH = 1280;
    uint32_t HEIGHT = 720;
    const char* TITLE = "Physically-Based Rendering Example by D3PSI";

    const char* LOADING_SCREEN_IMAGE = "res/images/lion.png";
    const char* APPLICATION_ICON = "res/images/lion_cropped.png";
    pbr::util::PBR_DISPLAY_MODE DISPLAY_MODE = pbr::util::PBR_WINDOWED;

    pbr::util::PBRKeyboardInputCallbackFun keyInputCB;

    pbr::util::PBR_STATUS pbrInit() {
        pbr::core::init();
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrExecute() {
        return pbr::core::execute();
    }

    pbr::util::PBR_STATUS pbrClean() {
        pbr::core::clean();
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrSize(uint32_t _width, uint32_t _height) {
        WIDTH = _width;
        HEIGHT = _height;
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrTitle(const char* _title) {
        TITLE = _title;
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrLoadingScreenImage(const char* _image) {
        LOADING_SCREEN_IMAGE = _image;
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrApplicationIcon(const char* _icon) {
        APPLICATION_ICON = _icon;
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrDisplayMode(pbr::util::PBR_DISPLAY_MODE _mode) {
        pbr::DISPLAY_MODE = _mode;
        return pbr::util::PBR_OK;
    }

    pbr::util::PBR_STATUS pbrKeyboardInputCallback(pbr::util::PBRKeyboardInputCallbackFun _cbfun) {
        keyInputCB = _cbfun;
        return pbr::util::PBR_OK;
    }

    uint32_t pbrGetCurrentWidth() {
        return pbr::core::width;
    }

    uint32_t pbrGetCurrentHeight() {
        return pbr::core::height;
    }

}

#endif      // PBR_CPP