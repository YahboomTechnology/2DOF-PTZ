/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         ServoControlColor.c
* @author      
* @version      V1.0
* @date         
* @brief        Control servo
* @details
* @par History  
*
*/
#include <wiringPi.h>
#include <softPwm.h>

#define ON  1   //Enable LED
#define OFF 0   //Disable LED

//Define pin
int LED_R = 3;  //LED_R wiringPi port 3connected to Raspberry Pi
int LED_G = 2;  //LED_G wiringPi port 2 connected to Raspberry Pi
int LED_B = 5;  //LED_B wiringPi port 5 connected to Raspberry Pi

//Define servo pin
int ServoPin = 4;

//Function declaration
void corlor_light(int);
void corlor_led(int, int, int);

/**
* Function       servo_pulse
* @author        
* @date          
* @brief         Define a pulse function to generate PWM value in analog mode
*                The time base pulse is 20ms, and the high level part of the pulse is 0.5-2.5ms
*                Control 0-270°
* @param[in1]    myangle:Specified angle of servo rotation
* @param[out]    void
* @retval        void
* @par History   No
*/
void servo_pulse(int myangle)
{
  int PulseWidth;                    //Define pulse width variable
  PulseWidth = (myangle * 8) + 500; //Convert angle to 500-2480 pulse width
  digitalWrite(ServoPin, HIGH);      //Set the level of steering gear interface high
  delayMicroseconds(PulseWidth);     //Microseconds of delay pulse width value
  digitalWrite(ServoPin, LOW);       //Set the level of steering gear interface low
  delay(20 - PulseWidth / 1000);     //Remaining time in delay period
  return;
}

/**
* Function       servo_control_color
* @author        
* @date          
* @brief         The steering gear rotates from 0°-270°, then from 270° to 0°
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   No
*/
void servo_control_color()
{
  //Define the turning position of the servo
  int pos = 0;
  for (pos = 0; pos < 270; pos++)
  {
    //Steering gear 0° rotates to 270°, delaying 20ms each time
    servo_pulse(pos);
    //Rotate to the corresponding angle to judge the calling of related functions
    //corlor_light(pos);
    delay(20);
  }

  for (pos = 270; pos > 0; pos--)
  {
    //Steering gear 270° rotates to 0°, delaying 20ms each time
    servo_pulse(pos);
    //Rotate to the corresponding angle to judge the calling of related functions
    //corlor_light(pos);
    delay(20);
  }
  return;
}

/**
* Function       corlor_light
* @author        
* @date          
* @brief         Light the corresponding color according to the rotation angle
* @param[in]     Rotating position of pos servo
* @param[out]    void
* @retval        void
* @par History   No
*/
void corlor_light(int pos)
{
  if (pos > 230)
  {
    corlor_led(ON, OFF, OFF);
  }
  else if (pos > 190)
  {
    corlor_led(OFF, ON, OFF);
  }
  else if (pos > 150)
  {
    corlor_led(OFF, OFF, ON);
  }
  else if (pos > 115)
  {
    corlor_led(OFF, ON, ON);
  }
  else if (pos > 75)
  {
    corlor_led(ON, ON, OFF);
  }
  else if (pos > 40)
  {
    corlor_led(ON, OFF, ON);
  }
  else if (pos > 0)
  {
    corlor_led(ON, ON, ON);
  }
  else
  {
    corlor_led(OFF, OFF, OFF);
  }
}

/**
* Function        corlor_led
* @author         
* @date           
* @brief          Seven different colors are formed by different combinations of R, G and B colors
* @param[in1]     Red switch
* @param[in2]     Green switch
* @param[in3]     Blue switch
* @retval         void
* @par History    No
*/
void corlor_led(int v_iRed, int v_iGreen, int v_iBlue)
{
  //Red LED
  v_iRed == ON ? digitalWrite(LED_R, HIGH): digitalWrite(LED_R, LOW);
 
  //Green LED
  v_iGreen == ON ? digitalWrite(LED_G, HIGH) : digitalWrite(LED_G, LOW);
  
  //Blue LED
  v_iBlue == ON ? digitalWrite(LED_B, HIGH) : digitalWrite(LED_B, LOW);
}

/**
* Function       main
* @author        
* @date          
* @brief         First delay 0.5, then call the steering gear control program
* @param[in]     void
* @retval        void
* @par History   No
*/
void main()
{
  //wiringPi initialization
  wiringPiSetup();
  
  //Steering gear is set to output mode
  pinMode(ServoPin, OUTPUT);
  
  //Initialize the servo position
  int ServoPos = 0;
  servo_pulse(ServoPos);
  
  while(1)
  {
   //delay 0.5s
   delay(500);
   //Call the servo control program
   servo_control_color();
  }
  return;
}


