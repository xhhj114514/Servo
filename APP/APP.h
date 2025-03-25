#ifndef APP_H
#define APP_H

#pragma once

/*Public Libraries*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdint.h"



/*private Libraries*/
#include "printf.h"
#include "Servo.h"


/*Functions*/
void APP_Init(void);
void APP_Run(void);









#endif // APP_H