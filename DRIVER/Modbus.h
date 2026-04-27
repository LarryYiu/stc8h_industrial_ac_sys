#ifndef __MODBUS_H__
#define __MODBUS_H__

#include "Config.h"

#ifndef MODBUS_SLAVE_ADDR
#define MODBUS_SLAVE_ADDR 0x01
#endif

#define MODBUS_FUNC_READ_HOLDING_REG 0x03
#define MODBUS_FUNC_WRITE_SINGLE_REG 0x06
#define MODBUS_FUNC_WRITE_MULTIPLE_REG 0x10

void Modbus_ReadPM25(u8* buff);

#endif  // __MODBUS_H__