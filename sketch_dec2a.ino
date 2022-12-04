#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "ledconfig.h"
#include <ArduinoModbus.h>
#include <microLED.h>

#include "taskhandler.h"
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x7f, Wire);
ModbusRTUServerClass modbus = ModbusRTUServerClass();

TaskHandler taskHandler = TaskHandler();
unsigned long systick;

static int testValue=0;
void TestTask()
{
   modbus.inputRegisterWrite(0,testValue++);
}

void setup() {
  VDInit(&pwm1, 0, &modbus);

  pwm1.begin();  
  modbus.begin(1,19200);
  modbus.configureHoldingRegisters(0,20);
  modbus.configureInputRegisters(0,20);
  modbus.configureCoils(0,100);  
  
  taskHandler.RegisterTask(&TestTask,1000);
  taskHandler.RegisterTask(&LedDriverTask, 100);
}

void loop(){
  modbus.poll(); 
  taskHandler.Poll();
}
