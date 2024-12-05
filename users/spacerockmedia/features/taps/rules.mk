DYNAMIC_TAPPING_TERM_ENABLE ?= yes
TAPPING_TERM_PER_KEY        ?= yes

SRC += $(USER_PATH)/features/taps/taps.c \
       $(USER_PATH)/features/taps/callbacks.c \
       $(USER_PATH)/features/taps/tap_dances.c \
       $(USER_PATH)/features/taps/process_records.c
