#include <DynamixelSDK.h>
#include "dynamixel_lib.h"

void setup() {
  Serial.begin(115200);
  while(!Serial);

  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

  int dxl_comm_result = COMM_TX_FAIL;             
  uint8_t dxl_error = 0;                          
  
  // Open port
  if (portHandler->openPort()){
    Serial.print("Succeeded to open the port!\n");
  }
  else{
    Serial.print("Failed to open the port!\nPress any key to terminate...\n");
    return;
  }

  // Set port baudrate
  if (portHandler->setBaudRate(1000000)){
    Serial.print("Succeeded to change the baudrate!\n");
  }
  else{
    Serial.print("Failed to change the baudrate!\nPress any key to terminate...\n");
    return;
  }
  
  //stand
  int angles[16][2] = {{1, 512}, {2, 512}, {3, 439}, {4, 585}, {5, 512}, {6, 512}, {7, 512}, {8, 512}, {9,486}, {10, 538}, {11, 541}, {12, 483}, {13, 498}, {14, 526}, {15, 512}, {16, 512}};
  syncwrite_ang(16, angles);
//  int arms[2][2] = {{11,512}, {12,512}};
//  syncwrite_ang(2, arms);
//  write_ang(1, 512);
//  write_ang(3, 439);
//  write_ang(2, 512);
//  write_ang(11, 512);
}

void loop() {
}
