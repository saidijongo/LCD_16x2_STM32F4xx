#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "bldc_pins.h"

// #define LCD20xN // For 20xN LCDs
#define LCD16xN // For 16xN LCDs

// For row start addresses
extern const uint8_t ROW_16[];
extern const uint8_t ROW_20[];

#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE_SET 0x04
#define OPT_S 0x01 // Shift entire display to right
#define OPT_INC 0x02 // Cursor increment
#define DISPLAY_ON_OFF_CONTROL 0x08
#define OPT_D 0x04 // Turn on display
#define OPT_C 0x02 // Turn on cursor
#define OPT_B 0x01 // Turn on cursor blink
#define CURSOR_DISPLAY_SHIFT 0x10 // Move and shift cursor
#define OPT_SC 0x08
#define OPT_RL 0x04
#define FUNCTION_SET 0x20
#define OPT_DL 0x10 // Set interface data length
#define OPT_N 0x08 // Set number of display lines
#define OPT_F 0x04 // Set alternate font
#define SETCGRAM_ADDR 0x040
#define SET_DDRAM_ADDR 0x80 // Set DDRAM address

#define DELAY(X) HAL_Delay(X)

#define LCD_NIB 4
#define LCD_BYTE 8
#define LCD_DATA_REG 1
#define LCD_COMMAND_REG 0

typedef enum {
  LCD_4_BIT_MODE,
  LCD_8_BIT_MODE
} Lcd_ModeTypeDef;

typedef struct {
  GPIO_TypeDef* data_port[4];
  uint16_t data_pin[4];
  GPIO_TypeDef* rs_port;
  uint16_t rs_pin;
  GPIO_TypeDef* en_port;
  uint16_t en_pin;
  Lcd_ModeTypeDef mode;
} Lcd_HandleTypeDef;

void Lcd_init(Lcd_HandleTypeDef* lcd);
void Lcd_int(Lcd_HandleTypeDef* lcd, int number);
void Lcd_string(Lcd_HandleTypeDef* lcd, char* string);
void Lcd_cursor(Lcd_HandleTypeDef* lcd, uint8_t row, uint8_t col);
Lcd_HandleTypeDef Lcd_create(GPIO_TypeDef* port[], uint16_t pin[], GPIO_TypeDef* rs_port, uint16_t rs_pin, GPIO_TypeDef* en_port, uint16_t en_pin, Lcd_ModeTypeDef mode);
void Lcd_define_char(Lcd_HandleTypeDef* lcd, uint8_t code, uint8_t bitmap[]);
void Lcd_clear(Lcd_HandleTypeDef* lcd);

#endif /* LCD_H_ */
