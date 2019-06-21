
import serial
from time import sleep
roboser = serial.Serial('/dev/ttyACM1', 1000000) # Establish the connection on a specific port
con='1'
control=5
while 1:
    control=input("enter 1 for pushup and 2 for Walk:")
    if int(control)==1:
        con=str(1)
    elif int(control) == 2:
        con=str(2)
        roboser.write(bytes(con))
        iss = input("enter 1 to stop:")
        if int(iss) == 1:
            con=str(1)
            print iss
    print control

    roboser.write(bytes(con)) # Convert the decimal number to ASCII then send it to the Arduino 
    #sleep(1)
    sleep(.1) # Delay for one tenth of a second
