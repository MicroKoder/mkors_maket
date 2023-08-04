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
typedef enum{
	VD1,VD2,VD3,VD4,VD5,VD6,VD7,VD8,VD9,VD10,
	VD11,VD12,VD13,VD14,VD15,VD16,VD17,VD18,VD19,VD20,
	VD21,VD22,VD23,VD24,VD25,VD26,VD27,VD28,VD29,VD30,
	VD31,VD32,VD33,VD34,VD35,VD36,VD37,VD38,VD39,VD40,
	VD41, VD_B1,VD_B2
} vd_names;
vd_t GetVDConfig(int nLed);
void VDInit(Adafruit_PWMServoDriver *pwm1, Adafruit_PWMServoDriver *pwm2, ModbusRTUServerClass *modbus);
void LedDriverTask();
#endif
