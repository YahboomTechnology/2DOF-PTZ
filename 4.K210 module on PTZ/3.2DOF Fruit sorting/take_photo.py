import sensor, lcd, image, time
from modules import ybkey

lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.run(1)
sensor.skip_frames(10)
print("init ok")

i = 0
KEY = ybkey()

while True:
    img_path = "/sd/image-"+str(i)+".jpg"
    img = sensor.snapshot()
    print("save image")
    state = KEY.is_press()
    lcd.display(img)
    if(state == 1):
        time.sleep_ms(5)#防抖
        state = KEY.is_press()
        if (state == 1):
            img.save(img_path)
            img_read = image.Image(img_path)
            lcd.display(img_read)
            time.sleep_ms(200)
            i = i+1
