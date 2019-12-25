#!/bin/bash
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 1>&2
   exit 1
else
    echo "Uninstalling pbrrenderer by D3PSI..."
    if rm -r /usr/bin/pbrrenderer; then
        echo "Removing shortcuts..."
        if rm -r /usr/share/applications/PBR\ by\ D3PSI.desktop; then
            echo "Successfully uninstalled project. Thank you for checking by!"
        else
            echo "Failed to remove shortcuts. Either they have never been created or they cannot be found in directory /usr/share/applications"
        fi
    else
        echo "Failed to uninstall pbrrenderer. Either it has never been installed or cannot be found in /usr/bin/pbrrenderer"
    fi
fi