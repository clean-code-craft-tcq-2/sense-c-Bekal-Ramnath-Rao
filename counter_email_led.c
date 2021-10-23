#include "counter_email_led.h"
#include "stdio.h"

/*global variable defined which is set when max is greater than threshold which is used to send an email*/
int emailAlertCallCount = 0;

/*global variable defined which is set when max is greater than threshold which is used to glow led*/
int ledAlertCallCount = 0;

/*function defined to set emailAlertCallCount when max is greater than threshold which in turn sends an email*/
void emailAlerter()
{
	emailAlertCallCount = 1;
}

/*function defined to set ledAlertCallCount when max is greater than threshold which in turn glows led*/
void ledAlerter()
{
	ledAlertCallCount = 1;
}

/*function defined to check whether max is greater than threshold and also sends email and glows led*/
void check_and_alert(float Threshold, alerter_funcptr alerters[], struct Stats computedStats)
{ 
	if(computedStats.max > Threshold)
	{
		(*alerters[0])();
		(*alerters[1])();
	}
}