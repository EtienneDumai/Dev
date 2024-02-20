import machine
import time
import math

# Set the pin for the RPM sensor
rpmPin = machine.Pin(4, machine.Pin.IN, machine.Pin.PULL_UP)
rpmTemp=0

#focntion qui detecte que le siganl a un intervalle trop petit et qui lance une autre fonction pour ne plus laisser passer le signal
def rpmDetect(pin):
    global rpmTemp
    if time.ticks_diff(time.ticks_us(),rpmTemp) > 1000000: # 1s
        rpmTemp = time.ticks_us()
        print("rpmDetect")
        rpmLimiter()
    else:
        rpmTemp = time.ticks_us()