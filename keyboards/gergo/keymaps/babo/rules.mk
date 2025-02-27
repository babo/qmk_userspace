AUDIO_ENABLE = no           # Audio output on port C6
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug(+400)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
MIDI_ENABLE = no            # MIDI controls
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
OLED_DRIVER_ENABLE = no     # OLED display
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
SPLIT_KEYBOARD = yes        # Use split_common libraries
TAP_DANCE_ENABLE = no       # Enable tapdance
UNICODEMAP_ENABLE = yes     # Unicode

SRC += hungarian.c            # unicode map
