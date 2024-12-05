
MUSIC_ENABLE ?= no

OLED_DRIVER ?= ssd1306
WPM_ENABLE ?= no
ifeq ($(strip $(WPM_ENABLE)), yes)
    WPM_SAMPLE_SECONDS = 15
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += $(USER_PATH)/features/oled/oled.c
endif

# DEFERRED_EXEC_ENABLE = yes
