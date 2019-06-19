
import serial
from time import sleep
roboser = serial.Serial('/dev/ttyACM5', 115200) # Establish the connection on a specific port
con='1'
control=5
while 1:
    control=input("enter 1 for pushup and 2 for Walk:")
    if int(control)==1:
        con=str(0)
        tim=.1
    elif int(control) == 2:
        con=str(1)
        tim=20
    print control
    sleep(1)
    roboser.write(bytes(con)) # Convert the decimal number to ASCII then send it to the Arduino 
    yo = str(roboser.readline()) # Read the newest output from the Arduino
    print (yo[2:len(yo)-5])
    sleep(tim) # Delay for one tenth of a second