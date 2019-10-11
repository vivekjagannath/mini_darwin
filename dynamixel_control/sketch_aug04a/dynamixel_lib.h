class dynamixel_lib
{

    dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler("1");
    dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

    int dxl_comm_result = COMM_TX_FAIL;
    uint8_t dxl_error = 0;

public:
    void openPort()
    {
        portHandler->openPort();
    }

    void baud(int a)
    {
        portHandler->setBaudRate(a);
    }

    int write_ang(int id, int angle)
    {
        /* move one single motor.
        * arguments:
        * id -> motor id.
        * angle -> value to turn the motor by (between 0 - 1023).*/
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

    double syncwrite_ang(double arr[])
    {
        /*move multiple angles to multiple motors.
        * arguments:
        * arr -> 2D array with id and angle along with them. (Ex: {{1,30}, {2,50}})*/
        dynamixel::GroupSyncWrite groupSyncWrite(portHandler, packetHandler, 30, 4);
        bool dxl_addparam_result = false;
        for (int i = 0; i < 17; i++)
        {
            uint8_t bytearray[4] = {DXL_LOBYTE(DXL_LOWORD((512 + (arr[i] * 3.41)))), DXL_HIBYTE(DXL_LOWORD((512 + (arr[i] * 3.41)))), DXL_LOBYTE(DXL_HIWORD((512 + (arr[i] * 3.41)))), DXL_HIBYTE(DXL_HIWORD((512 + (arr[i] * 3.41))))};
            dxl_addparam_result = groupSyncWrite.addParam((i + 1), bytearray);
        }
        dxl_comm_result = groupSyncWrite.txPacket();
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        groupSyncWrite.clearParam();
    }

    int read_ang(int id)
    {
        /*gives the angle by which a motor is turned (value between 0 - 1023).
        * arguments:
        * id -> motor id. */
        uint16_t dxl_present_position = 0;
        dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, id, 37, (uint16_t *)&dxl_present_position, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
        return dxl_present_position;
    }

    int set_id(int curr_id, int new_id)
    {
        /*sets a new id for the motor.
        * arguments:
        * curr_id -> current id of the motor.
        * new_id -> id you want to set for the motor. */
        dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, curr_id, 3, new_id, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
    }

    int enable_torque(int id)
    {
        /*enables torque for specified motor.
        * arguments:
        * id -> motor id. */
        dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, id, 24, 1, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
    }

    int disable_torque(int id)
    {
        /* diasbles torque
        * arguments:
        * id -> motor id. */
        dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, id, 24, 0, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
    }

    void glow_led(int id, uint8_t value)
    {
        /* glow the led inside the motor.
        * arguments:
        * id -> motor id.
        * value -> bit value. (Ex: 0x01) */
        dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, id, 25, value, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
    }

    int moving_speed(int id, int value)
    {
        /*change the moving speed of the motor.
        * arguments:
        * id -> motor id.
        * value -> speed you want to set (between 0-2047). */
        dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, id, 32, value, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
    }

    int present_speed(int id)
    {
        /*get the moving speed of the motor.
        * arguments:
        * id -> motor id. */
        uint16_t dxl_present_speed = 0;
        dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, id, 39, (uint16_t *)&dxl_present_speed, &dxl_error);
        if (dxl_comm_result != COMM_SUCCESS)
        {
            packetHandler->getTxRxResult(dxl_comm_result);
        }
        else if (dxl_error != 0)
        {
            packetHandler->getRxPacketError(dxl_error);
        }
        return dxl_present_speed;
    }
};
