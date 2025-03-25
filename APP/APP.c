#include "APP.h"



void APP_Init()
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1 );
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2 );
    __HAL_TIM_MOE_ENABLE(&htim3);
    
    Servo_Init(&ServoPitch, 1, 180, 0, 0.1, TIM_CHANNEL_1, &htim3, 0);
    Servo_Init(&ServoYaw, 1, 180, 0, 0.1, TIM_CHANNEL_2, &htim3, 0);

    printf("Init Success\r\n");
}

void APP_Run()
{
    
    //printf("%d,%d\r\n",ServoA.Current_Angle,ServoA.Target_Angle);
}