/* Source File for LED Function*/

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "clock_config.h"
#include "pin_mux.h"

void RGB_init()
{
		gpio_pin_config_t led_blue_config = {
	        kGPIO_DigitalOutput, 1,
	    };
		GPIO_PinInit(BOARD_LED_BLUE_GPIO,BOARD_LED_BLUE_GPIO_PIN, &led_blue_config);
	    gpio_pin_config_t led_red_config = {
	        kGPIO_DigitalOutput, 1,
	    };
	    GPIO_PinInit(BOARD_LED_RED_GPIO,BOARD_LED_RED_GPIO_PIN, &led_red_config);
	    gpio_pin_config_t led_green_config = {
	        kGPIO_DigitalOutput, 1,
	    };
	    GPIO_PinInit(BOARD_LED_GREEN_GPIO,BOARD_LED_GREEN_GPIO_PIN, &led_green_config);
}
void led_switch(int n)
 {
	GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
	GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
	GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);

	switch (n)
	{
	// Switch LED BLUE ON and TURN OTHER LEDs OFF
	case 0:
		{
		GPIO_ClearPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
		GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
		GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
		}
		break;
		// Switch LED RED ON and TURN OTHER LEDs OFF
	case 1:
	{

			GPIO_ClearPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
			GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
			GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
	}
			break;
			// Switch LED GREEN ON and TURN OTHER LEDs OFF
	case 2:
	{
			GPIO_ClearPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
			GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
			GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
	}
			break;
	case 3:
		{
		GPIO_ClearPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
		GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
		GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
		}
		break;
	}
 }


void RGB_OFF()
{
	GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
	GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1u << BOARD_LED_GREEN_GPIO_PIN);
	GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1u << BOARD_LED_RED_GPIO_PIN);
}

void status_print_on(int n)
 {
	switch (n)
	{
	// Switch LED BLUE ON and TURN OTHER LEDs OFF
	case 0:
		{
			PRINTF("BLUE LED ON ::");
		}
		break;
		// Switch LED RED ON and TURN OTHER LEDs OFF
	case 1:
	{

		PRINTF("GREEN LED ON::");
	}
			break;
			// Switch LED GREEN ON and TURN OTHER LEDs OFF
	case 2:
	{
		PRINTF("RED LED ON::");
	}
			break;
	case 3:
		{
		PRINTF("BLUE LED ON");
		}
		break;
	}
 }
void status_print_0ff()
{
	PRINTF("OFF STATE::");
}
