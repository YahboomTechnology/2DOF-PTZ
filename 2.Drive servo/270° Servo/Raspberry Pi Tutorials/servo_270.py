
from time import sleep
from gpiozero import AngularServo
myGPIO=13
 
Servo_min_angle = 0
Servo_max_angle = 270
maxPW=2.5/1000
minPW=0.5/1000
 
servo = AngularServo(myGPIO,min_pulse_width=minPW,max_pulse_width=maxPW,min_angle=Servo_min_angle, max_angle=Servo_max_angle)
 
while True:
    servo.angle = 0
    sleep(3)
    servo.angle = 45
    sleep(3)
    servo.angle = 90
    sleep(3)
    servo.angle = 135
    sleep(3)
    servo.angle = 180
    sleep(3)
    servo.angle = 225
    sleep(3)
    servo.angle = 270
    sleep(3)