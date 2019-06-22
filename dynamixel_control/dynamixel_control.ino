#include <DynamixelSDK.h>
#include "dynamixel_lib.h"
#include "motion_sets.h"

void setup()
{
  Serial.begin(1000000);
  while (!Serial);

  dynamixel_lib dyn;
  
  dyn.openPort();
  dyn.baud(1000000);

  for (int i = 1; i < 18; i++)
  {
    dyn.enable_torque(i);
  }

while(true){
  char inByte = ' ';
  if (Serial.available())
  {
    char inByte = Serial.read();
    if (char(inByte) == '1')
    {
      dyn.syncwrite_ang(pu1);
      delay(1000);
      dyn.syncwrite_ang(pu2);
      delay(1000);
      dyn.syncwrite_ang(pu3);
      delay(1000);
      dyn.syncwrite_ang(pu4);
      delay(1000);
      dyn.syncwrite_ang(pu5);
      delay(1000);
      dyn.syncwrite_ang(pu6);
      delay(1000);
      dyn.syncwrite_ang(pu5);
      delay(1000);
      dyn.syncwrite_ang(pu6);
      delay(1000);
      dyn.syncwrite_ang(pu5);
      delay(1000);
      dyn.syncwrite_ang(pu6);
      delay(1000);
      dyn.syncwrite_ang(pu7);
      delay(1000);
      dyn.syncwrite_ang(pu8);
      delay(1000);
      dyn.syncwrite_ang(pu9);
      delay(1000);
      dyn.syncwrite_ang(pu10);
      delay(1000);
      dyn.syncwrite_ang(pu11);
      delay(1000);
    }
    else if (char(inByte) == '2')
    {
      while (true)
      {
        char ch = Serial.read();
        if (char(ch) == '1')
        {
          dyn.syncwrite_ang(ad9);
          delay(100);
          dyn.syncwrite_ang(ad10);
          delay(100);
          dyn.syncwrite_ang(ad11);
          delay(100);
          dyn.syncwrite_ang(ad12);
          break;
        }
        else
        {
          dyn.syncwrite_ang(ad1);
          delay(100);
          dyn.syncwrite_ang(ad2);
          delay(100);
          dyn.syncwrite_ang(ad3);
          delay(100);
          dyn.syncwrite_ang(ad4);
          delay(100);
          dyn.syncwrite_ang(ad5);
          delay(100);
          dyn.syncwrite_ang(ad6);
          delay(100);
          dyn.syncwrite_ang(ad7);
          delay(100);
          dyn.syncwrite_ang(ad8);
          delay(100);
        }
      }
    }
    else if (char(inByte) == '3')
    {
      while (true)
      {
        char ch = Serial.read();
        if (char(ch) == '1')
        {
          dyn.syncwrite_ang(stand);
          break;
        }
        else
        {
          dyn.syncwrite_ang(right1);
          delay(100);
          dyn.syncwrite_ang(right2);
          delay(100);
          dyn.syncwrite_ang(right3);
          delay(100);
        }
      }
    }
    else if (char(inByte) == '4')
    {
      while (true)
      {
        char ch = Serial.read();
        if (char(ch) == '1')
        {
          dyn.syncwrite_ang(stand);
          break;
        }
        else
        {
          dyn.syncwrite_ang(left1);
          delay(100);
          dyn.syncwrite_ang(left2);
          delay(100);
          dyn.syncwrite_ang(left3);
          delay(100);
        }
      }
    }
    Serial.println(inByte);
    delay(100);
  }
}
}
void loop()
{
}
