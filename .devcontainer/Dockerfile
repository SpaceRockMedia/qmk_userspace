FROM ghcr.io/qmk/qmk_cli

ENV KEYBOARD=bastardkb/charybdis/3x6 \
    KEYMAP=spacerockmedia \
    FIRMWARE=Bastardkb/bastardkb-qmk

RUN wget https://bootstrap.pypa.io/get-pip.py
RUN python3 get-pip.py
RUN python3 -m pip install qmk
RUN rm get-pip.py

RUN python3 -m pip install --upgrade milc

WORKDIR /workspaces/qmk_firmware

RUN git clone -b bkb-master https://github.com/${FIRMWARE}.git /workspaces/qmk_firmware
RUN git config --global --add safe.directory /workspaces/qmk_firmware
RUN python3 -m pip install -r requirements.txt

RUN git config --global --add safe.directory /workspaces/qmk_userspace

RUN qmk config user.qmk_home=/workspaces/qmk_firmware
RUN qmk config user.overlay_dir=/workspaces/qmk_userspace
RUN qmk config user.keyboard=$KEYBOARD
RUN qmk config user.keymap=$KEYMAP

RUN qmk setup -y
RUN qmk git-submodule
