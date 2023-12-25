
from time import sleep
from gpiozero import AngularServo
myGPIO=13
 
myCorrection=0.5
maxPW=2.5/1000
minPW=0.5/1000
 
servo = AngularServo(myGPIO,min_pulse_width=minPW,max_pulse_width=maxPW,min_angle=0, max_angle=180)
 
while True:
    servo.angle = 0
    sleep(1)
    servo.angle = 45
    sleep(1)
    servo.angle = 90
    sleep(1)
    servo.angle = 135
    sleep(1)
    servo.angle = 180
    sleep(1)
    servo.angle = 135
    sleep(1)
    servo.angle = 90
    sleep(1)
    servo.angle = 45
    sleep(1)
    