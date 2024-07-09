FROM ghcr.io/qmk/qmk_cli

ENV KEYBOARD=bastardkb/charybdis/3x6 \
    KEYMAP=spacerockmedia \
    FIRMWARE=qmk


WORKDIR /qmk_firmware

RUN python3 -m pip install --upgrade milc qmk
RUN mkdir -p /qmk_userspace
RUN git config --global --add safe.directory /${FIRMWARE}_firmware
RUN git config --global --add safe.directory /qmk_userspace
RUN qmk config user.qmk_home=/qmk_firmware
RUN qmk config user.keyboard=$KEYBOARD
RUN qmk config user.keymap=$KEYMAP
RUN qmk config user.overlay_dir=/qmk_userspace

# RUN qmk git-submodule
RUN qmk setup

CMD ["qmk", "compile"]
