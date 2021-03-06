#ifndef __RELAYCONTROL_H__
#define __RELAYCONTROL_H__

#include <esp_common.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "gpio.h"

#include "button_interrupt.h"

#define RELAY_ON 1
#define RELAY_OFF 0

#define RELAY_PIN 12
#define RELAY_INDICATOR 15
#define RELAY_BUTTON 14

static int relaysstate = 0;

extern void invertrelaystate(void);
extern void setrelaystate(int newstate);
extern int getrelaystate(void);

extern void initrelay(void);

static void initrelaycontrol(void);
static void initrelaybutton(void);
static void initrelayindicator(void);



#endif