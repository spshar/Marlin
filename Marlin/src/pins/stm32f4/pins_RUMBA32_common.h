/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

 /**
  * 2017 Victor Perez Marlin for stm32f1 test
  * 2018 Modified by Pablo Crespo for Morpheus Board (https://github.com/pscrespo/Morpheus-STM32)
  * 08.2020 Modified by 3dmaniack for fork of Morpheus Board
  */

#if NOT_TARGET(STM32F4)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 1 || E_STEPPERS > 1
  #error "RUMBA32 boards support one hotend / E-steppers only."
#endif

#define DEFAULT_MACHINE_NAME BOARD_INFO_NAME

//
// Limit Switches
//
#ifndef X_STOP_PIN      
  #ifndef X_MIN_PIN     
    #define X_MIN_PIN      PB2
  #endif                
  #ifndef X_MAX_PIN     
    #define X_MAX_PIN      PB2
  #endif                
#endif                  
#ifndef Y_STOP_PIN      
  #ifndef Y_MIN_PIN     
    #define Y_MIN_PIN      PB10
  #endif                
  #ifndef Y_MAX_PIN     
    #define Y_MAX_PIN      PB10
  #endif                
#endif                  
#ifndef Z_STOP_PIN      
  #ifndef Z_MIN_PIN     
    #define Z_MIN_PIN      PA14
  #endif                
  #ifndef Z_MAX_PIN     
    #define Z_MAX_PIN      PA14
  #endif                
#endif                  
                        

//
// Steppers
//
// X,Y,Z,E0 enable are the same
#define X_STEP_PIN         PB9
#define X_DIR_PIN          PB8
#define X_ENABLE_PIN       PB14

#define Y_STEP_PIN         PB5
#define Y_DIR_PIN          PB4
#define Y_ENABLE_PIN       PB14

#define Z_STEP_PIN         PA8
#define Z_DIR_PIN          PB15
#define Z_ENABLE_PIN       PB14

#define E0_STEP_PIN        PB13
#define E0_DIR_PIN         PB12
#define E0_ENABLE_PIN      PB14

//
// Temperature Sensors
//
#define TEMP_0_PIN         PB1   // Analog Input (HOTEND thermistor)
#define TEMP_BED_PIN       PB0   // Analog Input (BED thermistor)

//
// Heaters / Fans
//
#define HEATER_0_PIN       PA15  // HOTEND MOSFET
#define HEATER_BED_PIN     PB3   // BED MOSFET

#define FAN_PIN            PA10  // PRINT FAN
#define FAN1_PIN           PA9   // HOTEND FAN

#ifndef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN  FAN1_PIN
#endif

//
// EEPROM settings
//
#if NO_EEPROM_SELECTED
  //#define SDCARD_EEPROM_EMULATION
  //#define I2C_EEPROM                            // AT24C32
  #define FLASH_EEPROM_EMULATION
  #define MARLIN_EEPROM_SIZE              0x1000  // 4KB
#endif

/**
 *                   ______                              ______                             
 *               5V |10  9 | GND                     NC |10  9 | GND                        
 *    (LCD_D7) PA2  | 8  7 | PA3  (LCD_D6)        RESET | 8  7 | NC                         
 *    (LCD_D5) PA1  | 6  5   PB7  (LCD_D4)   (MOSI) PA7 | 6  5   PC14 (BTN_EN2)             
 *    (LCD_RS) PA0  | 4  3 | PB6  (LCD_EN)  (SD_SS) PA4 | 4  3 | PC15 (BTN_EN1)             
 *   (BTN_ENC) PC13 | 2  1 | BEEP             (SCK) PA5 | 2  1 | PA6  (MISO)                
 *                   ------                              ------                             
 *                    EXP1                                EXP2                              
 */

#define EXP1_01_PIN                         -1
#define EXP1_02_PIN                         PC13
#define EXP1_03_PIN                         PB6
#define EXP1_04_PIN                         PA0 
#define EXP1_05_PIN                         PB7 
#define EXP1_06_PIN                         PA1 
#define EXP1_07_PIN                         PA3 
#define EXP1_08_PIN                         PA2
#define EXP1_09_PIN                         -1
#define EXP1_10_PIN                         -1

#define EXP2_01_PIN                         PA6
#define EXP2_02_PIN                         PA5 
#define EXP2_03_PIN                         PC15
#define EXP2_04_PIN                         PA4 
#define EXP2_05_PIN                         PC14
#define EXP2_06_PIN                         PA7
#define EXP2_07_PIN                         -1 
#define EXP2_08_PIN                         -1 
#define EXP2_09_PIN                         -1
#define EXP2_10_PIN                         -1

// SDCard
#ifdef SDSUPPORT
  #define SDSS                       EXP2_04_PIN
  #define SD_DETECT_PIN              -1
  #define KILL_PIN                   -1
#endif

//
// LCD / Controller
//
#if HAS_WIRED_LCD
  #define BEEPER_PIN                 EXP1_01_PIN
  #define BTN_ENC                    EXP1_02_PIN

  #if ENABLED(CR10_STOCKDISPLAY)
//TO TEST

//    #define LCD_PINS_RS              EXP1_04_PIN
  
//    #define BTN_EN1                  EXP1_08_PIN
//    #define BTN_EN2                  EXP1_06_PIN
  
//    #define LCD_PINS_ENABLE          EXP1_03_PIN
//    #define LCD_PINS_D4              EXP1_05_PIN

  #elif IS_TFTGLCD_PANEL
//TO TEST

//    #undef BEEPER_PIN
//    #undef BTN_ENC

//    #if ENABLED(TFTGLCD_PANEL_SPI)
//      #define TFTGLCD_CS             EXP2_08_PIN
//    #endif

//    #define SD_DETECT_PIN            EXP2_04_PIN

  #else

    #define LCD_PINS_RS              EXP1_04_PIN

    #define BTN_EN1                  EXP2_03_PIN
    #define BTN_EN2                  EXP2_05_PIN

    #define LCD_PINS_ENABLE          EXP1_03_PIN

    #if ENABLED(FYSETC_MINI_12864)

      #define DOGLCD_CS              EXP1_03_PIN
      #define DOGLCD_A0              EXP1_04_PIN
      #define LCD_BACKLIGHT_PIN           -1
      #define LCD_RESET_PIN          EXP1_05_PIN  // Must be high or open for LCD to operate normally.

      #define LCD_CONTRAST_INIT      240
      #define LCD_CONTRAST_MIN       200
      #define LCD_CONTRAST_MAX       255
      
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN      EXP1_06_PIN  //not verified
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN      EXP1_07_PIN //not verified
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN      EXP1_08_PIN //not verified
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN         EXP1_06_PIN
      #endif

    #else                                         // !FYSETC_MINI_12864

      #define LCD_PINS_D4            EXP1_05_PIN

      #if IS_ULTIPANEL
        #define LCD_PINS_D5            EXP1_06_PIN
        #define LCD_PINS_D6            EXP1_07_PIN
        #define LCD_PINS_D7            EXP1_08_PIN

        #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
          #define BTN_ENC_EN           LCD_PINS_D7  // Detect the presence of the encoder
        #endif
      #endif //!IS_ULTIPANEL

    #endif // !FYSETC_MINI_12864

    // Alter timing for graphical display
    #if ENABLED(U8GLIB_ST7920)
//TO TEST

//      #define BOARD_ST7920_DELAY_1           125
//      #define BOARD_ST7920_DELAY_2           125
//      #define BOARD_ST7920_DELAY_3           125
    #endif

  #endif

#endif // HAS_WIRED_LCD
