#include "stm32f10x.h"

void LED_init() {
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

   GPIO_InitTypeDef GPIO_InitStructure;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}

void LED_Set(uint8_t led_num, uint8_t state) {
   uint16_t led_pin;
   if (led_num == 1) {
      led_pin = GPIO_Pin_1;  // LED1 对应的引脚
   }
   else if (led_num == 2) {
      led_pin = GPIO_Pin_2;  // LED2 对应的引脚
   }
   else {
      return;  // 如果传入的LED编号不对，则不做任何操作
   }

   if (state == 1) {  // 开灯
      GPIO_ResetBits(GPIOA, led_pin);
   }
   else if (state == 0) {  // 关灯
      GPIO_SetBits(GPIOA, led_pin);
   }
}

void LED_Turn(uint8_t led_num) {
   uint16_t led_pin;
   if (led_num == 1) {
      led_pin = GPIO_Pin_1;  // LED1 对应的引脚
   }
   else if (led_num == 2) {
      led_pin = GPIO_Pin_2;  // LED2 对应的引脚
   }
   else {
      return;  // 如果传入的LED编号不对，则不做任何操作
   }
   if (GPIO_ReadOutputDataBit(GPIOA, led_pin) == 0) {
      GPIO_SetBits(GPIOA, led_pin);
   }
   else if (GPIO_ReadOutputDataBit(GPIOA, led_pin) == 1) {
      GPIO_ResetBits(GPIOA, led_pin);
   }
}