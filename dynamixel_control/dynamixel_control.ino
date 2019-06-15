#include <DynamixelSDK.h>
#include "dynamixel_lib.h"
#include "motion_arrays.h"

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;

  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

  int dxl_comm_result = COMM_TX_FAIL;
  uint8_t dxl_error = 0;

  // Open port
  if (portHandler->openPort())
  {
    Serial.print("Succeeded to open the port!\n");
  }
  else
  {
    Serial.print("Failed to open the port!\nPress any key to terminate...\n");
    return;
  }

  // Set port baudrate
  if (portHandler->setBaudRate(1000000))
  {
    Serial.print("Succeeded to change the baudrate!\n");
  }
  else
  {
    Serial.print("Failed to change the baudrate!\nPress any key to terminate...\n");
    return;
  }

  for (int i = 0; i < 17; i++){
    enable_torque(i);
  }

   //pushup:
   syncwrite_ang(stand);
   delay(3000);
   syncwrite_ang(pu1);
   delay(100);
   syncwrite_ang(pu2);
   delay(100);
   syncwrite_ang(pu3);
   delay(100);
   syncwrite_ang(pu4);
   delay(100);
   syncwrite_ang(pu5);
   delay(100);
   syncwrite_ang(pu6);
   delay(100);
   syncwrite_ang(pu7);
   delay(100);
   syncwrite_ang(pu8);
   delay(100);
   syncwrite_ang(pu9);
   delay(100);
   syncwrite_ang(pu10);
}
void loop()
{   
}
