import serial
import time
import csv
import os

#put LYING_POSITION=Supinr, Prone, LeftSide, RightSide
try:
    os.remove("LYING_POSITION.csv")
except OSError:
    pass

with open('LYING_POSITION.csv', mode='a') as sensor_file:
    sensor_writer = csv.writer(sensor_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    sensor_writer.writerow(["X","Y","Z"])


com = "/dev/cu.usbmodem14301"
baud = 9600

x = serial.Serial(com, baud, timeout = 0.1)

while x.isOpen() == True:
    data = str(x.readline().decode('utf-8')).rstrip()
    if data != '':
         print(data)
         sensor_data = []
         readings = data.split(",")
         with open('LYING_POSITION.csv', mode='a') as sensor_file:
             sensor_writer = csv.writer(sensor_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
             sensor_writer.writerow([readings[0],readings[1],readings[2]])