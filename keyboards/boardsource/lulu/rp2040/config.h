// Copyright 2022 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP22
#define I2C1_SCL_PIN GP23

// This requires a setting in rules.mk as well
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define COMBO_MUST_PRESS_IN_ORDER
#define COMBO_TERM 30

// Reset when the device re-inits
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_SINGLE_REPORT

#define SPLIT_MODS_ENABLE

// For cosmetic keypresses and stuff on the right
#define SPLIT_TRANSPORT_MIRROR

//#define OLED_FONT_H  "lib/glcdfont.c"
