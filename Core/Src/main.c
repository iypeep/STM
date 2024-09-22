#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"

int main(void) {
	LED_init();

	while (1) {
		LED_Set(1, 1);
		Delay_ms(100);
		LED_Set(1, 0);
		Delay_ms(100);
	}
}
