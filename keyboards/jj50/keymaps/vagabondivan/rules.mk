# MCU name
MCU = atmega32a

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = bootloadHID

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite		# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes		# Mouse keys
EXTRAKEY_ENABLE = yes		# Audio control and System control
CONSOLE_ENABLE = no			# Console for debug
COMMAND_ENABLE = no			# Commands for debug and configuration

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no		# Breathing sleep LED during USB suspend

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no			# USB Nkey Rollover
BACKLIGHT_ENABLE = yes		# Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes		# Enable keyboard underlight functionality
#LED_MATRIX_ENABLE = IS31FL3731
#RGB_MATRIX_ENABLE = WS2812	# Enable keyboard RGB Matrix
#WS2812_DRIVER = i2c		# This driver powers the RGB Lighting and RGB Matrix features
BLUETOOTH_ENABLE = no		# Enable Bluetooth
AUDIO_ENABLE = no			# Audio output
AUTO_SHIFT_ENABLE = no		# Enable Auto Shift
LTO_ENABLE = yes			# Enable link time optimization
TAP_DANCE_ENABLE = yes		# Enable Tap Dancing

LAYOUTS = jj50_1x2uC
LAYOUTS = ortho_5x12
