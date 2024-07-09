#!/usr/bin/env bash

export FIRMWARE="${1:-qmk}"
export KEYBOARD="${2:-bastardkb/charybdis/3x6}"
export KEYMAP="${3:-spacerockmedia}"

qmk config user.qmk_home=/${FIRMWARE}_firmware

qmk compile -kb $KEYBOARD -km $KEYMAP
