/*
  cnc_boosterpack_map.h - driver code for STM32F4xx processor (on Blackpill board)

  Part of GrblHAL

  Copyright (c) 2020 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#define BOARD_NAME "CNC BoosterPack"

// Define step pulse output pins.
#define STEP_PORT       GPIOA
#define X_STEP_PIN      0
#define Y_STEP_PIN      1
#define Z_STEP_PIN      2
#define X_STEP_BIT      (1<<X_STEP_PIN)
#define Y_STEP_BIT      (1<<Y_STEP_PIN)
#define Z_STEP_BIT      (1<<Z_STEP_PIN)
#if N_AXIS > 3
#define A_STEP_PIN      3
#define A_STEP_BIT      (1<<A_STEP_PIN)
#define STEP_MASK       (X_STEP_BIT|Y_STEP_BIT|Z_STEP_BIT|A_STEP_BIT) // All step bits
#else
#define STEP_MASK       (X_STEP_BIT|Y_STEP_BIT|Z_STEP_BIT) // All step bits
#endif
#define STEP_OUTMODE GPIO_MAP

// Define step direction output pins.
#define DIRECTION_PORT      GPIOA
#define X_DIRECTION_PIN     4
#define Y_DIRECTION_PIN     5
#define Z_DIRECTION_PIN     6
#define X_DIRECTION_BIT     (1<<X_DIRECTION_PIN)
#define Y_DIRECTION_BIT     (1<<Y_DIRECTION_PIN)
#define Z_DIRECTION_BIT     (1<<Z_DIRECTION_PIN)
#if N_AXIS > 3
#define A_DIRECTION_PIN     7
#define A_DIRECTION_BIT     (1<<A_DIRECTION_PIN)
#define DIRECTION_MASK      (X_DIRECTION_BIT|Y_DIRECTION_BIT|Z_DIRECTION_BIT|A_DIRECTION_BIT) // All direction bits
#else
#define DIRECTION_MASK      (X_DIRECTION_BIT|Y_DIRECTION_BIT|Z_DIRECTION_BIT) // All direction bits
#endif
#define DIRECTION_OUTMODE   GPIO_MAP

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_PORT   GPIOA
#define STEPPERS_DISABLE_PIN    15
#define STEPPERS_DISABLE_BIT    (1<<STEPPERS_DISABLE_PIN)
#define STEPPERS_DISABLE_MASK   STEPPERS_DISABLE_BIT

// Define homing/hard limit switch input pins.
#define LIMIT_PORT       GPIOB
#define X_LIMIT_PIN      12
#define Y_LIMIT_PIN      13
#define Z_LIMIT_PIN      14
#define X_LIMIT_BIT      (1<<X_LIMIT_PIN)
#define Y_LIMIT_BIT      (1<<Y_LIMIT_PIN)
#define Z_LIMIT_BIT      (1<<Z_LIMIT_PIN)
#if N_AXIS > 3
#define A_LIMIT_PIN      15
#define A_LIMIT_BIT      (1<<A_LIMIT_PIN)
#define LIMIT_MASK       (X_LIMIT_BIT|Y_LIMIT_BIT|Z_LIMIT_BIT|A_LIMIT_BIT) // All limit bits
#else
#define LIMIT_MASK       (X_LIMIT_BIT|Y_LIMIT_BIT|Z_LIMIT_BIT) // All limit bits
#endif
#define LIMIT_INMODE GPIO_SHIFT12

  // Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOB
#define SPINDLE_ENABLE_PIN          1
#define SPINDLE_ENABLE_BIT          (1<<SPINDLE_ENABLE_PIN)
#define SPINDLE_DIRECTION_PORT      GPIOB
#define SPINDLE_DIRECTION_PIN       0
#define SPINDLE_DIRECTION_BIT       (1<<SPINDLE_DIRECTION_PIN)

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT            GPIOA
#define SPINDLE_PWM_PIN             8
#define SPINDLE_PWM_BIT             (1<<SPINDLE_PWM_PIN)

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOC
#define COOLANT_FLOOD_PIN           15
#define COOLANT_FLOOD_BIT           (1<<COOLANT_FLOOD_PIN)
#define COOLANT_MIST_PORT           GPIOC
#define COOLANT_MIST_PIN            14
#define COOLANT_MIST_BIT            (1<<COOLANT_MIST_PIN)

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT                GPIOB
#define CONTROL_RESET_PIN           6
#define CONTROL_FEED_HOLD_PIN       7
#define CONTROL_CYCLE_START_PIN     8
#define CONTROL_SAFETY_DOOR_PIN     9
#define CONTROL_INMODE GPIO_SHIFT6

#define CONTROL_RESET_BIT           (1<<CONTROL_RESET_PIN)
#define CONTROL_FEED_HOLD_BIT       (1<<CONTROL_FEED_HOLD_PIN)
#define CONTROL_CYCLE_START_BIT     (1<<CONTROL_CYCLE_START_PIN)
#define CONTROL_SAFETY_DOOR_BIT     (1<<CONTROL_SAFETY_DOOR_PIN)
#define CONTROL_MASK                (CONTROL_RESET_BIT|CONTROL_FEED_HOLD_BIT|CONTROL_CYCLE_START_BIT|CONTROL_SAFETY_DOOR_BIT)

// Define probe switch input pin.
#define PROBE_PORT                  GPIOA
#define PROBE_PIN                   7
#define PROBE_BIT                   (1<<PROBE_PIN)

#if KEYPAD_ENABLE
#define KEYPAD_PORT                 GPIOB
#define KEYPAD_STROBE_PIN           15
#define KEYPAD_STROBE_BIT           (1<<KEYPAD_STROBE_PIN)
#endif

#if SDCARD_ENABLE
#define SD_CS_PORT  GPIOA
#define SD_CS_PIN   3
#define SD_CS_BIT   (1<<SD_CS_PIN)
// The following defines are not used but defined for reference
// Port init and remap is done by HAL_SPI_MspInit() in stm32f1xx_hal_msp.c
#define SD_IO_PORT  GPIOB
#define SD_SCK_PIN  3
#define SD_SCK_BIT  (1<<SD_SCK_PIN)
#define SD_MISO_PIN 4
#define SD_MISO_BIT (1<<SD_MISO_PIN)
#define SD_MOSI_PIN 5
#define SD_MOSI_BIT (1<<SD_MOSI_PIN)
#endif

/* EOF */
