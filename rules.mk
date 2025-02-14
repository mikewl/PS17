# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#

BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
CONSOLE_ENABLE = no        # Console for debug
MOUSEKEY_ENABLE = no      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
NKRO_ENABLE = yes          # USB Nkey Rollover
RGB_MATRIX_DRIVER = WS2812 # Addressable LED strand driver
UNICODE_ENABLE = yes       # Unicode
ENCODER_ENABLE = yes       # For encoder
LTO_ENABLE = yes           # Reduce firmware size
COMBO_ENABLE = no         # Combos
TAP_DANCE_ENABLE = no      # Tap dance


# Removed for per layout options
# RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
# RGB_MATRIX_ENABLE = no    # RGB matrix for individual LED control.