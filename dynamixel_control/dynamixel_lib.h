int write_ang(int id, int angle)
{
  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

  int dxl_comm_result = COMM_TX_FAIL;
  uint8_t dxl_error = 0;

  dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, id, 30, angle, &dxl_error);

  if (dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
  }
  else if (dxl_error != 0)
  {
    packetHandler->getRxPacketError(dxl_error);
  }
}

//-------------------------------------------------------------------------------------------

int syncwrite_ang(int m, int arr[][2])
{
  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);
  dynamixel::GroupSyncWrite groupSyncWrite(portHandler, packetHandler, 30, 4);

  int dxl_comm_result = COMM_TX_FAIL;
  bool dxl_addparam_result = false;
  uint8_t dxl_error = 0;

  for (int i = 0; i < m; i++)
  {
    uint8_t bytearray[4] = {DXL_LOBYTE(DXL_LOWORD(arr[i][1])), DXL_HIBYTE(DXL_LOWORD(arr[i][1])), DXL_LOBYTE(DXL_HIWORD(arr[i][1])), DXL_HIBYTE(DXL_HIWORD(arr[i][1]))};
    dxl_addparam_result = groupSyncWrite.addParam(arr[i][0], bytearray);
  }

  dxl_comm_result = groupSyncWrite.txPacket();

  if (dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
  }

  groupSyncWrite.clearParam();
}
