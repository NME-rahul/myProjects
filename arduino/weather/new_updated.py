import serial
import time
arduino = serial.Serial(port='COM3', baudrate=9600, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

while(1):
    print( arduino.readline())
    time.sleep(0.5)
