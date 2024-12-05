-include $(USER_PATH)/features/layers/rules.mk
-include $(USER_PATH)/features/macros/rules.mk

TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    -include $(USER_PATH)/features/taps/rules.mk
endif

REPEAT_KEY_ENABLE  ?= no
ifeq ($(strip $(REPEAT_KEY_ENABLE )), yes)
    -include $(USER_PATH)/features/repeat_key/rules.mk
endif

COMBO_ENABLE ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
    -include $(USER_PATH)/features/combos/rules.mk
endif

LEADER_ENABLE ?= no
ifeq ($(strip $(LEADER_ENABLE)), yes)
    -include $(USER_PATH)/features/leader/rules.mk
endif

AUDIO_ENABLE ?= no
ifeq ($(strip $(AUDIO_ENABLE)), yes)
     -include $(USER_PATH)/features/audio/rules.mk
endif

OLED_ENABLE ?= no
ifeq ($(strip $(OLED_ENABLE)), yes)
     -include $(USER_PATH)/features/oled/rules.mk
endif

CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    -include $(USER_PATH)/features/caps_word/rules.mk
endif

RGB_MATRIX_ENABLE ?= no
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    -include $(USER_PATH)/features/rgb/rules.mk
endif

POINTING_DEVICE_ENABLE ?= no
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
    -include $(USER_PATH)/features/pointing/rules.mk
endif

FEATURE_ACHORDION_ENABLE ?= no
ifeq ($(strip $(FEATURE_ACHORDION_ENABLE)), yes)
    -include $(USER_PATH)/features/achordion/rules.mk
    OPT_DEFS += -DFEATURE_ACHORDION_ENABLE
endif

FEATURE_CALLUM_ENABLE ?= no
ifeq ($(strip $(FEATURE_CALLUM_ENABLE)), yes)
    -include $(USER_PATH)/features/callum/rules.mk
    OPT_DEFS += -DFEATURE_CALLUM_ENABLE
endif

FEATURE_SENTENCE_CASE_ENABLE ?= no
ifeq ($(strip $(FEATURE_SENTENCE_CASE_ENABLE)), yes)
    -include $(USER_PATH)/features/sentence_case/rules.mk
    OPT_DEFS += -DFEATURE_SENTENCE_CASE_ENABLE
endif

SRC += $(USER_PATH)/features/callbacks.c \
       $(USER_PATH)/features/process_records.c
