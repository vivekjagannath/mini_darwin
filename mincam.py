 
# Needed packages: sudo apt install python-serial

# This tutorial is a simple program that allows one to read and parse serial messages from JeVois

serdev = '/dev/ttyACM2' # serial device of JeVois

import serial
from time import sleep
control=0
# roboser = serial.Serial('/dev/ttyACM0', 115200) # Establish the connection on a specific port
with serial.Serial(serdev, 115200, timeout=1) as ser:
    while 1:
        # Read a whole line and strip any trailing line ending character:
        line = ser.readline()
        #print 1,line
        # print "received: {}".format(line)

        # Split the line into tokens:
        tok = line.split()

        # Skip if timeout or malformed line:
        #if len(tok) < 1: continue

        # Skip if not a standardized "Normal 2D" message:
        # See http://jevois.org/doc/UserSerialStyle.html
        #if tok[0] != 'N2': continue

        # From now on, we hence expect: N2 id x y w h
        if len(tok) == 6:

        # Assign some named Python variables to the tokens:
            key, id, x, y, w, h = tok
            xco=(float(x)+1000)*(float(640)/float(2000))
            yco=(float(y)+750)*(float(480)/float(1500))
            wco=(float(w))*(float(640)/float(2000))
            hco=(float(h))*(float(480)/float(1500))
            centre=((xco+(wco/2.0)),yco+(hco/2.0))
            print centre[0],centre[1]
        else:
            id=""

        print id
        
        if id[0:len(id)-3]!="":
            if xco+wco < 320:
                print "move right"
            elif xco+wco>=320:
                print "move left"
        
        elif id=="":
            print "go straight"
        id=""

        #print "Found {} at ({},{}) size {}x{}".format(id, x, y, w, h)
        # print id[0:len(id)-3]
        # if id[0:len(id)-3]=="person":
        #     control=str(1)
        # elif id[0:len(id)-3] == "bottle": 
        #     control=str(0)
        # print control
        # sleep(1)
        # roboser.write(bytes(control)) # Convert the decimal number to ASCII then send it to the Arduino 
        # yo = str(roboser.readline()) # Read the newest output from the Arduino
        # print (yo[2:len(yo)-5])
        # sleep(.1) # Delay for one tenth of a second