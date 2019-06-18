#include <DynamixelSDK.h>
#include "motion_arrays.h"

void setup()
{
  Serial.begin(115200);
  while (!Serial);

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
}
void loop()
{
  pushup();
}
