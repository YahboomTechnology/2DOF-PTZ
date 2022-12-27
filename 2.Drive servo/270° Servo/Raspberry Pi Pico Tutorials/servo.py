from machine import Pin, PWM
import utime

servo = PWM(Pin(7))
servo.freq(50)

# Numerical remapping
def my_map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

# Control steering gear，value=[0, 270]
def servo_control(value):
    if value > 270 or value < 0:
        print('Please enter a limited speed value of 0-270 ')
        return
    duty = my_map(value, 0, 270, 500000, 2500000)
    servo.duty_ns(duty)

# PWM steering gear swings back and forth before 0 and 270 degrees.
while True:
    servo_control(0)
    utime.sleep(1)
    servo_control(90)
    utime.sleep(1)
    servo_control(270)
    utime.sleep(1)
