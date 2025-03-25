#include "Servo.h"
Servo_t ServoPitch;
Servo_t ServoYaw;

void Servo_Init(Servo_t *Servo , uint8_t id ,uint8_t max ,uint8_t min ,float Res, uint32_t channel , TIM_HandleTypeDef *htim, float InitTarget)
{
    Servo->ID = id;
    Servo->Resolution_Angle = Res;
    Servo->MAX_Angle = max;
    Servo->MIN_Angle = min;
    Servo->htim = htim;
    Servo->Channel = channel;
    Servo_Set_Abso_Angle(Servo, InitTarget);
    Servo->Current_Angle = InitTarget;
}


void Servo_Set_Abso_Angle(Servo_t *Servo , float Angle)
{
    volatile uint32_t pwm = (uint32_t)((Angle/Servo->MAX_Angle)*4000+(0.5/20)*40000);

    __HAL_TIM_SET_COMPARE(Servo->htim, Servo->Channel, pwm);

    Servo->Current_Angle = Angle;

}
void Servo_Set_Relat_Angle(Servo_t *Servo , uint8_t DeltaAngle)
{
    volatile uint8_t Angle_INT;
    if(Servo->Current_Angle + DeltaAngle > Servo->MAX_Angle)
    {
        Angle_INT = Servo->MAX_Angle;
    }
    else
    {
        Angle_INT = Servo->Current_Angle + DeltaAngle;
    }
    Servo_Set_Abso_Angle(Servo , Angle_INT);
    Servo->Current_Angle = Angle_INT;
}


