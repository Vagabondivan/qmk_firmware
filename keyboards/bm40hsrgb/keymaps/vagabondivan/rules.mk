# VAGABONDIVAN - Copyright 2020 Ivano Piacenza
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

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
NKRO_ENABLE = yes			# USB Nkey Rollover
BACKLIGHT_ENABLE = no		# Enable keyboard backlight functionality
#RGB_MATRIX_ENABLE = WS2812	# Enable keyboard RGB Matrix
RGBLIGHT_ENABLE = yes		# Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no		# Enable Bluetooth
AUDIO_ENABLE = no			# Audio output
TAP_DANCE_ENABLE = yes		# Enable TAP DANCE


LAYOUTS = planck_mit
LAYOUTS_HAS_RGB = yes
