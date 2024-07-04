#ifndef BLDC_PINS_H_
#define BLDC_PINS_H_

#include "stm32f4xx_hal.h"

// LCD Pin Definitions
#define LCD_RS_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_1
#define LCD_EN_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_3

#define LCD_D4_GPIO_Port GPIOB
#define LCD_D4_Pin GPIO_PIN_0
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_1
#define LCD_D6_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_10
#define LCD_D7_GPIO_Port GPIOB
#define LCD_D7_Pin GPIO_PIN_11

#endif /* BLDC_PINS_H_ */
