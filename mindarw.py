
import serial
from time import sleep

roboser = serial.Serial('/dev/ttyACM2', 1000000)
con='1'
control=5

while True:
    control=input("enter 1 for pushup, 2 for Walk, 3 for right and 4 for left:")
    if int(control)==1:
        con=str(1)
    elif int(control) == 2:
        con=str(2)
        roboser.write(bytes(con))
        iss = input("enter 1 to stop:")
        if int(iss) == 1:
            con=str(1)
            print iss
    elif int(control) == 3:
        con = str(3)
        roboser.write(bytes(con))
        iss = input("enter 1 to stop:")
        if int(iss) == 1:
            con=str(1)
            print iss
    elif int(control) == 4:
        con = str(4)
        roboser.write(bytes(con))
        iss = input("enter 1 to stop:")
        if int(iss) == 1:
            con=str(1)
            print iss

    print control
    roboser.write(bytes(con))  
    sleep(.1) 
