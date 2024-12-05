#!/usr/bin/env bash

export FIRMWARE="${1:-qmk}"
export KEYBOARD="${2:-bastardkb/charybdis/3x6}"
export KEYMAP="${3:-spacerockmedia}"

echo "FIRMWARE=${FIRMWARE}"
echo "KEYBOARD=${KEYBOARD}"
echo "KEYMAP=${KEYMAP}"

# qmk config user.qmk_home=/${FIRMWARE}_firmware
# qmk config user.overlay_dir=/qmk_userspace

QMK_HOME="${HOME}/projects/${FIRMWARE}/qmk_firmware"
cd $QMK_HOME
util/docker_build.sh ${KEYBOARD}:${KEYMAP}
