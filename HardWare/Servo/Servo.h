#ifndef Servo_h
#define Servo_h

#include "stdint.h"
#include "APP.h"

/*0-2.0ms PulseWidth*/
typedef struct 
{
    uint8_t MAX_Angle;
    uint8_t MIN_Angle;
    float Resolution_Angle;
    TIM_HandleTypeDef *htim;
    uint32_t Channel;

    uint8_t ID;
    float Current_Angle;

}Servo_t;

extern Servo_t ServoPitch;
extern Servo_t ServoYaw;

void Servo_Init(Servo_t *Servo , uint8_t id ,uint8_t max ,uint8_t min ,float Res, uint32_t channel , TIM_HandleTypeDef *htim, float InitTarget);
void Servo_Set_Abso_Angle(Servo_t *Servo , float Angle);
void Servo_Set_Relat_Angle(Servo_t *Servo , uint8_t DeltaAngle);



#endif // !Servo_h

