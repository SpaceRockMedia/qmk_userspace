
MUSIC_ENABLE ?= no

OLED_DRIVER ?= ssd1306
WPM_ENABLE ?= yes
ifeq ($(strip $(WPM_ENABLE)), yes)
    WPM_SAMPLE_SECONDS = 15
endif

SRC += $(USER_PATH)/features/oled/oled.c

# DEFERRED_EXEC_ENABLE = yes
