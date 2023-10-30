import datetime
from serial import Serial

from config import DATA_PATH

ser = Serial()
ser.port = "/dev/tty.usbmodem1201"
ser.baudrate = 115200
ser.timeout = 1

ser.open()

with open(DATA_PATH + datetime.today().strftime("%y%m%d.%H%M%S.") + ".txt", 'w', encoding="utf-8") as file:
    try:
        while True:
            if ser.readable():
                data = str(ser.readline())
                data = data.split("\'")[1].split("\\r")[0]
                file.write(data + "\n")
    except:
        ser.close()