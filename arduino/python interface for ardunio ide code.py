import serial
import time
import keyboard

car = serial.Serial("COM3", 9600, timeout=1)  

while True:
    if keyboard.is_pressed("w"):
        car.write(b'W')
    elif keyboard.is_pressed("s"):
        car.write(b'S')
    elif keyboard.is_pressed("d"):
        car.write(b'D')
    elif keyboard.is_pressed("a"):
        car.write(b'A')
    elif keyboard.is_pressed("x"):
        car.write(b'X')
    elif keyboard.is_pressed("c"):
        car.write(b'C')
    elif keyboard.is_pressed("v"):
        car.write(b'V')
    else:
        car.write(b'S')

    time.sleep(0.1)  