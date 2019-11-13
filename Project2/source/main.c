
#include "main.h"

void RTC_get();
void RTC_init();
/*******************************************************************************
 * Definitions
 ******************************************************************************/
//#define BOARD_LED_BLUE_GPIO BLUE_LED_PORT
//#define BOARD_LED_BLUE_GPIO_PIN BLUE_LED_PIN

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
int delay(int x);



rtc_datetime_t date;
rtc_config_t rtcConfig;

/*******************************************************************************
 * Variables
 ******************************************************************************/
unsigned int time[]= {3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};


/*******************************************************************************
 * Code
 ******************************************************************************/
int delay(int time_ms)
{
	volatile uint32_t i = 0;
	for (i = 0; i < 2400*time_ms; ++i)
	{
		__asm("NOP"); /* delay */
	}
	return i;
}


/*!
 * @brief Main function
 */
int main(void)
{
	/* Board pin, clock, debug console init */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	RGB_init();
	RTC_init();
	int time_last_event;
	/* Init output LED GPIO. */
	// GPIO_PinInit(BOARD_LED_BLUE_GPIO,BOARD_LED_BLUE_GPIO_PIN, &led_blue_config);

	unsigned int i = 0;
#ifdef fb_run
	for ( i=0;i<20;i++)
	{
		if ((i)%2==0)
		{
			led_switch(i/6);
			delay(time[i]);
		}
		else
		{
			RGB_OFF();
			delay(time[i]);
		}

	}
#endif

#ifdef fb_debug
	for ( i=0;i<20;i++)
	{
		if ((i)%2==0)
		{
			led_switch(i/6);
			status_print_on(i/6);
			time_last_event=delay(time[i]);
			PRINTF("%d  ",time_last_event);
			RTC_get();

		}
		else
		{	RGB_OFF();
			status_print_0ff();
			time_last_event= delay(time[i]);
			PRINTF("%d  ",time_last_event);
			RTC_get();

		}

	}
#endif

#ifdef pc_run
	int main (void)
	{
	    int i=0;

	for ( i=0;i<20;i++)
	    {
	    	if ((i)%2==0)
	    	{

	    		status_print_on(i/6);

	    		delay(time[i]);
	    	}
	    	else
	    	{

	    		status_print_0ff();

	    		delay(time[i]);
	    	}

	    }

	return 0;
	}
#endif

#ifdef pc_debug
	int main (void)
	{
	    int i=0;
	    int time_last_event;
	for ( i=0;i<20;i++)
	    {
	    	if ((i)%2==0)
	    	{

	    		status_print_on(i/6);
	    		time_last_event=delay(time[i]);
	    		printf("%d",time_last_event);
	    		delay(time[i]);
	    	}
	    	else
	    	{

	    		status_print_0ff();
	    		time_last_event= delay(time[i]);
	    		printf("%d",time_last_event);
	    		delay(time[i]);
	    	}

	    }

	return 0;
	}
#endif
}

void RTC_init()
{
	RTC_GetDefaultConfig(&rtcConfig);
	RTC_Init(RTC, &rtcConfig);


	date.year = 2019U;
	date.month = 10U;
	date.day = 30U;
	date.hour = 14U;
	date.minute = 0;
	date.second = 0;

	RTC_SetDatetime(RTC, &date);
	RTC_StartTimer(RTC);

}


void RTC_get()
{
	RTC_GetDatetime(RTC, &date);
	PRINTF(       "Current datetime: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day, date.hour,
			date.minute, date.second);

}

