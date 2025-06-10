import sensor, image, time, lcd, gc, cmath
from maix import KPU
from modules import ybserial
from robot_Lib import Robot

ser = ybserial()
bot = Robot(ser)
bot.set_beep(50)
bot.set_car_motion(0, 0, 0)
bot.set_pwm_servo_all(45)

lcd.init()                          # Init lcd display
lcd.clear(lcd.RED)                  # Clear lcd screen.

# sensor.reset(dual_buff=True)      # improve fps
sensor.reset()                      # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565) # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)   # Set frame size to QVGA (320x240)
#sensor.set_vflip(True)              # 翻转摄像头
#sensor.set_hmirror(True)            # 镜像摄像头
sensor.skip_frames(time = 1000)     # Wait for settings take effect.
clock = time.clock()                # Create a clock object to track the FPS.

print("ready load model")

labels = ["apple", "orange"] #类名称，按照label.txt顺序填写
anchor = (2.42, 2.54, 5.14, 4.42, 5.41, 5.25, 6.11, 5.03, 7.19, 5.91 # anchors,使用anchor.txt中第二行的值

kpu = KPU()
# 从sd或flash加载模型
kpu.load_kmodel('/sd/fruit_sort.kmodel')
#kpu.load_kmodel(0x300000, 584744)
kpu.init_yolo2(anchor, anchor_num=(int)(len(anchor)/2), img_w=320, img_h=240, net_w=320 , net_h=240 ,layer_w=10 ,layer_h=8, threshold=0.6, nms_value=0.3, classes=len(labels))

while(True):
    gc.collect()

    clock.tick()
    img = sensor.snapshot()

    kpu.run_with_output(img)
    dect = kpu.regionlayer_yolo2()

    fps = clock.fps()

    if len(dect) > 0:
        for l in dect :
            a = img.draw_rectangle(l[0],l[1],l[2],l[3],color=(0,255,0))

            info = "%s %.3f" % (labels[l[4]], l[5])
            if "apple" in info:
                print("1")
                bot.set_pwm_servo_all(20)
            elif "orange" in info:
                print("3")
                bot.set_pwm_servo_all(70)

            # 等待一段时间
            time.sleep(1)

            # 回到初始角度
            bot.set_pwm_servo_all(45)
            a = img.draw_string(l[0],l[1],info,color=(255,0,0),scale=2.0)
            print(info)
            del info

    a = img.draw_string(0, 0, "%2.1ffps" %(fps),color=(0,60,255),scale=2.0)
    lcd.display(img)
kpu.deinit()