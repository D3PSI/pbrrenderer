# Physically-Based Rendering in OpenGL 3.3 by D3PSI

## pbrrenderer

[![Build Status](https://travis-ci.com/D3PSI/pbrrenderer.svg?branch=master)](https://travis-ci.com/D3PSI/pbrrenderer)
[![C/C++ CI](https://github.com/D3PSI/pbrrenderer/workflows/C/C++%20CI/badge.svg)](https://github.com/D3PSI/pbrrenderer/actions?query=workflow%3A"C%2FC%2B%2B+CI")
[![Build status](https://ci.appveyor.com/api/projects/status/6cp2udvipkuchs42/branch/master?svg=true)](https://ci.appveyor.com/project/D3PSI/pbrrenderer/branch/master)
[![CircleCI](https://circleci.com/gh/D3PSI/pbrrenderer.svg?style=svg)](https://circleci.com/gh/D3PSI/pbrrenderer)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/D3PSI/pbrrenderer/graphs/commit-activity)
[![GitHub issues](https://img.shields.io/github/issues/D3PSI/pbrrenderer.svg)](https://github.com/D3PSI/pbrrenderer/issues/)
[![GitHub issues-closed](https://img.shields.io/github/issues-closed/D3PSI/pbrrenderer.svg)](https://github.com/D3PSI/pbrrenderer/issues?q=is%3Aissue+is%3Aclosed)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](https://github.com/D3PSI/pbrrenderer/compare)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/D3PSI/pbrrenderer.svg)](https://GitHub.com/D3PSI/pbrrenderer/pull/)
[![GitHub pull-requests closed](https://img.shields.io/github/issues-pr-closed/D3PSI/pbrrenderer.svg)](https://GitHub.com/D3PSI/pbrrenderer/pull/)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
[![Awesome Badges](https://img.shields.io/badge/badges-awesome-green.svg)](https://github.com/D3PSI/pbrrenderer)

This repository contains my first ever physically-based rendering application, 
written in C++-17 using the OpenGL core version 3.3 for backwards compatibility.  

## Installation

### Linux

The repository comes with a versatile install script. It offers support for a wide variety of distributions including Debian, Fedora and Arch/Manjaro Linux. Clone the repository and run the installer like so:

    git clone https://github.com/D3PSI/pbrrenderer.git
    cd pbrrenderer/

Start the installation procedure via one of the following commands:

1.:

    ./INSTALL.sh

2.: 

    make install

Then, run the application with `./pbr` in the project root directory.
If you want to recompile and automatically run the software, run either `make run` or `make debug`.

### Windows

Windows is currently not supported. Support will be added in future versions.

### macOS

macOS is currently not supported. Support may be added in future versions.

## Uninstallation

Just simply delete the project folder from disk:

    rm -r pbrrenderer

## Getting started

At the moment, there is no documentation as this project is still early in development.
 Here is the base program being used in the repository for testing:

    /**
    *  Welcome to pbrrenderer by D3PSI
    * 
    *  This project is open-source and licensed under the GNU General Public License v3.0
    *  Please refer to LICENSE.md for further information
    * 
    *  Refer to README.md for installation and compilation instructions
    */
    #include "pbr/PBR.hpp"


    void keyboardInputCallback(GLFWwindow* _window) {
        if(glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS)
            std::cout << "This is an example on how you can define own key actions.\n";
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
        pbr::pbrDisplayMode(pbr::util::flags::PBR_WINDOWED);
        pbr::pbrKeyboardInputCallback(keyboardInputCallback);
        return pbr::pbrExecute();
    }

## Troubleshoot

### Linux

#### Fedora
If you are facing the problem that `libassimp.so.5` isn't found anywhere.

    ./pbr: error while loading shared libraries: libassimp.so.5: cannot open shared object file: No such file or directory

Then just simply make a copy of `libassimp.so.3` or any other version and rename it to `libassimp.so.5` in the specific folder.
    
    sudo cp /usr/lib64/libassimp.so.3 /usr/lib64/libassimp.so.5
    
Like this.

This is also an problem with the boost library for libboost_filesystem.so.1.71.0 libboost_system.so.1.71.0 and should be solved this way:

    sudo cp /usr/lib64/libboost_filesystem.so /usr/lib64/libboost_filesystem.so.1.71.0
    sudo cp /usr/lib64/libboost_system.so /usr/lib64/libboost_system.so.1.71.0

## Contributors

Special thanks to [Pluscrafter](https://github.com/Pluscrafter) for taking part in essential development of this project.

Thanks for the interest in the project!
