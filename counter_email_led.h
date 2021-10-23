#include "stats.h"
/*function declared to set emailAlertCallCount when max is greater than threshold*/
extern void emailAlerter();

/*function defined to set ledAlertCallCount when max is greater than threshold*/
extern void ledAlerter();

/* function pointer*/
typedef void (*alerter_funcptr)();

/*function declared to check whether max is greater than threshold and also sends email and glows led*/
extern void check_and_alert(float Threshold, alerter_funcptr alerters[], struct Stats computedStats);

/*global variable declared which is set when max is greater than threshold which inturn send an email*/
extern int emailAlertCallCount;

/*global variable declared which is set when max is greater than threshold which inturn glows the led*/
extern int ledAlertCallCount;