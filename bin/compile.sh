#!/usr/bin/env bash

export FIRMWARE="${1:-qmk}"
export KEYBOARD="${2:-bastardkb/charybdis/3x6}"
export KEYMAP="${3:-spacerockmedia}"

echo "FIRMWARE=${FIRMWARE}"
echo "KEYBOARD=${KEYBOARD}"
echo "KEYMAP=${KEYMAP}"

QMK_HOME="${HOME}/projects/${FIRMWARE}/qmk_firmware"
#qmk config user.qmk_home=/${FIRMWARE}_firmware
qmk config user.qmk_home=$QMK_HOME

echo "Compiling with qmk='${QMK_HOME}' keyboard='${KEYBOARD}' keymap='${KEYMAP}'"
qmk clean
qmk compile -kb $KEYBOARD -km $KEYMAP
