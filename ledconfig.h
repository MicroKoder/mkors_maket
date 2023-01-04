#ifndef _LEDCONFIG_
#define _LEDCONFIG_

#include <arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <ArduinoModbus.h>

#define VD_NUM 43

typedef enum{
  PORT_NONE,
  PORT_DIGITAL,
  PORT_I2C_1,
  PORT_I2C_2
} port_t;

typedef struct{
  port_t port1;
  uint8_t pin1;
  port_t port2;
  uint8_t pin2;
  int nCoil1;
  int nCoil2;
} vd_t;

vd_t GetVDConfig(int nLed);
void VDInit(Adafruit_PWMServoDriver *pwm1, Adafruit_PWMServoDriver *pwm2, ModbusRTUServerClass *modbus);
void LedDriverTask();
#endif