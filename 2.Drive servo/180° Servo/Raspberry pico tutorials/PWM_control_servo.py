from machine import Pin, PWM
import utime

servo = PWM(Pin(7))
servo.freq(50)

# Numerical remapping
def my_map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

# Control servo, value=[0, 180]
def servo_control(value):
    if value > 180 or value < 0:
        print('Please enter a limited speed value of 0-180 ')
        return
    duty = my_map(value, 0, 180, 500000, 2500000)
    servo.duty_ns(duty)

# Control servo
while True:
    servo_control(0)
    utime.sleep(1)
    servo_control(180)
    utime.sleep(1)
