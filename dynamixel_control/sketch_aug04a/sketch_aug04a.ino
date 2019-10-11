#include <DynamixelSDK.h>
#include "dynamixel_lib.h"

void setup() {
  dynamixel_lib dyn;
  dyn.openPort();
  dyn.baud(1000000);
  dyn.write_ang(1, 300);
}

void loop() {
  // put your main code here, to run repeatedly:

}
