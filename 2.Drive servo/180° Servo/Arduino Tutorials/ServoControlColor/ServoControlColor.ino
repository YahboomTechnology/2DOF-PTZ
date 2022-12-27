/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         ServoControlColor.c
* @author       Danny
* @version      V1.0
* @date         2017.07.25
* @brief        Steering engine rotation control colorful searchlight
* @details
* @par History    Initialization configuration
*
*/
#include <Servo.h>  //Arduino IDE own servo library file

#define ON  1       //enable LED
#define OFF 0       //prohibit LED

Servo myservo;      //Define steering gear-myservo

//Define pin
int LED_R = 11;     //LED_R connect interface 11 on the arduino
int LED_G = 10;     //LED_G connect interface 10 on the arduino
int LED_B = 9;      //LED_B connect interface 9 on the arduino

/*Steering engine*/
int ServoPin = 3;

/**
* Function       setup
* @author        Danny
* @date          2017.07.25
* @brief         Initialization configuration
* @param[in]     void
* @retval        void
* @par History   no
*/

void setup()
{
 //Initialize RGB pin as output interface
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  //Set the  Steering engine control pin to 3
  myservo.attach(ServoPin);
  int ServoPos = 90;
  myservo.write(ServoPos);
}

/**
* Function       servo_control_color
* @author        Danny
* @date          2017.07.25
* @brief         The steering engine rotates from 0-180 and from 180-0,
*                the 180 degree is divided into 7 zones to represent the different colors
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void servo_control_color()
{
  //Define the rotating position of the steering engine
  int pos = 0;
  for (pos = 0; pos < 180; pos++)
  {
    //Steering engine  rotates 0 to 180,delay 20ms each time 
    myservo.write(pos);
    //Rotate to the corresponding angle, judge the call correlation function
    corlor_light(pos);
    delay(20);
  }

  for (pos = 180; pos > 0; pos--)
  {
    //Steering engine  rotates 180 to 0,delay 20ms each time 
    myservo.write(pos);
    //Rotate to the corresponding angle, judge the call correlation function
    corlor_light(pos);
    delay(20);
  }
}

/**
* Function       corlor_light
* @author        Danny
* @date          2017.07.25
* @brief         According to the angle of rotation light the light
* @param[in]     pos :the rotating position of the steering engine
* @param[out]    void
* @retval        void
* @par History   no
*/
void corlor_light(int pos)
{
  //When turning at 150-180 degrees, light a color
  if (pos > 150)
  {
    corlor_led(ON, OFF, OFF);
  }
  //When turning at 125-150 degrees, light a color
  else if (pos > 125)
  {
    corlor_led(OFF, ON, OFF);
  }
  //When turning at 100-125 degrees, light a color
  else if (pos > 100)
  {
    corlor_led(OFF, OFF, ON);
  }
  //When turning at 75-100 degrees, light a color
  else if (pos > 75)
  {
    corlor_led(OFF, ON, ON);
  }
  //When turning at 50-75 degrees, light a color
  else if (pos > 50)
  {
    corlor_led(ON, ON, OFF);
  }
  //When turning at 25-50 degrees, light a color
  else if (pos > 25)
  {
    corlor_led(ON, OFF, ON);
  }
  //When turning at 0-25 degrees, light a color
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
* Function        color_led
* @author         Danny
* @date           2017.07.25
* @brief          The different combinations of R, G, B tricolor form 7 different colors
* @param[in1]     Red ON/OFF
* @param[in2]     Green ON/OFF
* @param[in3]     Blue ON/OFF
* @retval         void
* @par History    no
*/

void corlor_led(int v_iRed, int v_iGreen, int v_iBlue)
{
  //LED_R
  if (v_iRed == ON)
  {
    digitalWrite(LED_R, HIGH);
  }
  else
  {
    digitalWrite(LED_R, LOW);
  }
  //LED_G
  if (v_iGreen == ON)
  {
    digitalWrite(LED_G, HIGH);
  }
  else
  {
    digitalWrite(LED_G, LOW);
  }
  //LED_B
  if (v_iBlue == ON)
  {
    digitalWrite(LED_B, HIGH);
  }
  else
  {
    digitalWrite(LED_B, LOW);
  }
}

/**
* Function       loop
* @author        Danny
* @date          2017.07.25
* @brief         First delay 0.5, and then call the steering engine control colorful light program
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  //delay 0.5s
  delay(500);
  //call the steering engine control colorful light program
  servo_control_color();
}



