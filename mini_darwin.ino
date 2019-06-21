#include <DynamixelSDK.h>

void setup()
{
    Serial.begin(1000000);
    while (!Serial)
        ;

    dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
    dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);
    dynamixel::GroupSyncWrite groupSyncWrite(portHandler, packetHandler, 30, 4);

    int dxl_comm_result = COMM_TX_FAIL;
    bool dxl_addparam_result = false;
    uint8_t dxl_error = 0;
    uint8_t param_goal_position[4];

    portHandler->openPort();
    portHandler->setBaudRate(1000000);

    for (int i = 1; i < 18; i++)
    {
        dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, i, 24, 1, &dxl_error);
    }

    double stand[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -26.37, 26.37, 29.3, -29.3, 13.18, -13.18, 0, 0, 0};

    for (int i = 0; i < 17; i++)
    {
        param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (stand[i] * 3.41)));
        param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (stand[i] * 3.41)));
        param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (stand[i] * 3.41)));
        param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (stand[i] * 3.41)));

        dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
    }
    dxl_comm_result = groupSyncWrite.txPacket();
    if (dxl_comm_result != COMM_SUCCESS)
        packetHandler->getTxRxResult(dxl_comm_result);
    groupSyncWrite.clearParam();

    while (true)
    {
        char inByte = ' ';
        if (Serial.available())
        {                                // only send data back if data has been sent
            char inByte = Serial.read(); // read the incoming data
            if (char(inByte) == '1')
            {
                double pu1[17] = {68.85, -68.85, -90.53, 90.53, 3.81, -3.81, 0, 0, -102.54, 102.54, 106.93, -106.93, 38.09, -38.09, 0, 0, 0};
                double pu2[17] = {68.85, -68.85, -90.53, 90.53, 3.81, -3.81, 0, 0, -102.54, 102.54, 106.93, -106.93, 38.09, -38.09, 0, 0, 0};
                double pu3[17] = {79.69, -79.69, -93.16, 93.16, 3.81, -3.81, 0, 0, -100.78, 100.78, 126.56, -126.56, 71.78, -71.78, 0, 0, 0};
                double pu4[17] = {67.38, -67.38, -85.25, 85.25, -5.86, 5.86, 0, 0, -13.48, 13.48, 0, 0, 55.96, -55.96, 0, 0, 0};
                double pu5[17] = {89.36, -89.36, -16.99, 16.99, -113.67, 113.67, 0, 0, -13.48, 13.48, 0, 0, 65.04, -65.04, 0, 0, 0};
                double pu6[17] = {67.38, -67.38, -85.25, 85.25, -5.86, 5.86, 0, 0, -13.48, 13.48, 0, 0, 55.96, -55.96, 0, 0, 0};
                double pu7[17] = {65.04, -65.04, -93.16, 93.16, 3.81, -3.81, 0, 0, -100.78, 100.78, 126.56, -126.56, 71.78, -71.78, 0, 0, 0};
                double pu8[17] = {48.34, -48.34, -90.53, 90.53, 3.81, -3.81, 0, 0, -102.54, 102.54, 106.93, -106.93, 38.09, -38.09, 0, 0, 0};
                double pu9[17] = {48.34, -48.34, -90.53, 90.53, 3.81, -3.81, 0, 0, -102.54, 102.54, 106.93, -106.93, 38.09, -38.09, 0, 0, 0};
                double pu10[17] = {48, -48, -91, 91, 4, -4, 0, 0, -50, 50, 50, -50, 13, -13, 0, 0, 0};
                double pu11[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -26.37, 26.37, 29.3, -29.3, 13.18, -13.18, 0, 0, 0};

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu1[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu1[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu1[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu1[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu2[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu2[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu2[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu2[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu3[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu3[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu3[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu3[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu4[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu4[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu4[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu4[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu5[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu6[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu7[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu7[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu7[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu7[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu8[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu8[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu8[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu8[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu9[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu9[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu9[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu9[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu10[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu10[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu10[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu10[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();

                delay(1000);

                for (int i = 0; i < 17; i++)
                {
                    param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (pu11[i] * 3.41)));
                    param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (pu11[i] * 3.41)));
                    param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (pu11[i] * 3.41)));
                    param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (pu11[i] * 3.41)));

                    dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                }
                dxl_comm_result = groupSyncWrite.txPacket();
                if (dxl_comm_result != COMM_SUCCESS)
                    packetHandler->getTxRxResult(dxl_comm_result);
                groupSyncWrite.clearParam();
            }

            else if (char(inByte) == '2')
            {
                double ad1[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -32.23, 20.51, 29.3, -29.3, 10.25, -21.97, 2.93, 11.72, 0};
                double ad2[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -32.23, 20.51, 29.3, -29.3, 10.25, -21.97, 2.93, 11.72, 0};
                double ad3[17] = {8.79, 8.79, -73.24, 73.24, 0, 0, -2.93, 2.93, -26.37, 41.02, 29.3, -58.59, 16.11, -30.76, 2.93, 8.79, 0};
                double ad4[17] = {29.3, 14.65, -73.24, 73.24, 0, 0, 0, 0, -20.51, 32.23, 29.3, -29.3, 21.97, -10.25, 0, 0, 0};
                double ad5[17] = {-0.29, -0.29, -73.54, 72.95, -0.29, -0.29, -0.29, -0.29, -20.8, 31.93, 29, -29.59, 21.68, -10.55, -12.01, -3.22, 0};
                double ad6[17] = {-0.29, -0.29, -73.54, 72.95, -0.29, -0.29, -0.29, -0.29, -20.8, 31.93, 29, -29.59, 21.68, -10.55, -12.01, -3.22, 0};
                double ad7[17] = {-9.08, -9.08, -73.54, 72.95, -0.29, -0.29, -3.22, 2.64, -41.31, 26.07, 58.3, -29.59, 30.47, -16.41, -9.08, -3.22, 0};
                double ad8[17] = {-14.65, -29.3, -73.24, 73.24, 0, 0, 0, 0, -32.23, 20.51, 29.3, -29.3, 10.25, -21.97, 0, 0, 0};
                double ad9[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -32.23, 20.51, 29.3, -29.3, 10.25, -21.97, 2.93, 11.72, 0};
                double ad10[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -32.23, 20.51, 29.3, -29.3, 10.25, -21.97, 2.93, 11.72, 0};
                double ad11[17] = {8.79, 8.79, -73.24, 73.24, 0, 0, -2.93, 2.93, -26.37, 41.02, 29.3, -58.59, 16.11, -30.76, 2.93, 8.79, 0};
                double ad12[17] = {0, 0, -73.24, 73.24, 0, 0, 0, 0, -26.37, 26.37, 29.3, -29.3, 13.18, -13.18, 0, 0, 0};

                while (true)
                {
                    char ch = Serial.read();
                    if (char(ch) == '1')
                    {
                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad9[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad9[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad9[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad9[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad10[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad10[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad10[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad10[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad11[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad11[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad11[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad11[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad12[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad12[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad12[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad12[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        break;
                    }

                    else
                    {
                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad1[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad1[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad1[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad1[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad2[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad2[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad2[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad2[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad3[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad3[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad3[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad3[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad4[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad4[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad4[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad4[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad5[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad5[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad5[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad5[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad6[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad6[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad6[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad6[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad7[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad7[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad7[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad7[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);

                        for (int i = 0; i < 17; i++)
                        {
                            param_goal_position[0] = DXL_LOBYTE(DXL_LOWORD(512 + (ad8[i] * 3.41)));
                            param_goal_position[1] = DXL_HIBYTE(DXL_LOWORD(512 + (ad8[i] * 3.41)));
                            param_goal_position[2] = DXL_LOBYTE(DXL_HIWORD(512 + (ad8[i] * 3.41)));
                            param_goal_position[3] = DXL_HIBYTE(DXL_HIWORD(512 + (ad8[i] * 3.41)));

                            dxl_addparam_result = groupSyncWrite.addParam((i + 1), param_goal_position);
                        }
                        dxl_comm_result = groupSyncWrite.txPacket();
                        if (dxl_comm_result != COMM_SUCCESS)
                            packetHandler->getTxRxResult(dxl_comm_result);
                        groupSyncWrite.clearParam();

                        delay(100);
                    }
                }
            }
            Serial.println(inByte);
            delay(100); // delay for 1/10 of a second
        }
    }
}
void loop()
{
}
