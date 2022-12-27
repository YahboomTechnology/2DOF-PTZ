/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         ServoControlColor.c
* @author       
* @version      V1.0
* @date        
* @brief        Steering gear rotation(0-270到270-0)
* @details
* @par History  
*
*/
#include <Servo.h>  //Rudder library files included in Arduino IDE

#define ON  1       //Enable LED
#define OFF 0       //Disable LED

Servo myservo;      //Define the steering gear object myservo

//Define pin
int LED_R = 11;     //LED_R Digital 11 port connected to arduino
int LED_G = 10;     //LED_G Digital 10 port connected to arduino
int LED_B = 9;      //LED_B Digital 9 port connected to arduino

//Define the servo pin
int ServoPin = 3;

/**
* Function       setup
* @author        
* @date          
* @brief         Initialize configuration
* @param[in]     void
* @retval        void
* @par History   No
*/
//Initialize Settings
void setup()
{
  //Initialize the IO port of RGB tri color LED as the output mode
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  //Set the steering gear control pin to 3
  myservo.attach(ServoPin);

  //Initialize the steering gear position forward
  int ServoPos = 0;
  myservo.write(ServoPos);
}

/**
* Function       servo_control_color
* @author        
* @date          
* @brief         The steering gear rotates from 0-270, then from 270 to 0, cycle
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
    //Steering gear 0 rotates to 270, delaying 20ms each time
    myservo.write(int(pos/1.5));
    //Rotate to the corresponding angle to judge the calling of related functions
    //corlor_light(pos);
    delay(20);
  }

  for (pos = 270; pos > 0; pos--)
  {
    //Steering gear 270 rotates to 0, delaying 20ms each time
    myservo.write(int(pos/1.5));
    //Rotate to the corresponding angle to judge the calling of related functions
    //corlor_light(pos);
    delay(20);
  }
}

/**
* Function       corlor_light
* @author       
* @date         
* @brief         Light the corresponding color according to the rotation angle
* @param[in]     Rotating position of pos steering gear
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
* Function        color_led
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
  if (v_iRed == ON)
  {
    digitalWrite(LED_R, HIGH);
  }
  else
  {
    digitalWrite(LED_R, LOW);
  }
  //Green LED
  if (v_iGreen == ON)
  {
    digitalWrite(LED_G, HIGH);
  }
  else
  {
    digitalWrite(LED_G, LOW);
  }
  //Blue LED
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
* @author        
* @date          
* @brief         First delay 0.5, then call the steering gear control colorful lamp code
* @param[in]     void
* @retval        void
* @par History   No
*/
void loop()
{
  delay(500);
  //Call the steering gear control code
  servo_control_color();
}
