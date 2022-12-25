#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "ledconfig.h"
#include <ArduinoModbus.h>
#include "taskhandler.h" 
#include "Strip.h"

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x7f, Wire);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x00, Wire);
ModbusRTUServerClass modbus = ModbusRTUServerClass();

TaskHandler taskHandler = TaskHandler();
unsigned long systick;

static int testValue=0;
void TestTask()
{
   modbus.inputRegisterWrite(0,testValue++);
}

void setup() {
  VDInit(&pwm1, &pwm2, &modbus);

  pwm1.begin();  
  modbus.begin(1,19200);
  modbus.configureHoldingRegisters(0,20);
  modbus.configureInputRegisters(0,2);
  modbus.configureCoils(0,200);  
  
  taskHandler.RegisterTask(&TestTask,1000);
  taskHandler.RegisterTask(&LedDriverTask, 100);

 //  ---- strip setup ------
  STRIP_setModbusServer(&modbus);
  taskHandler.RegisterTask(&ProcessAllStrips, 200);
}
/*void show1()
{

 mData data = mRGB(0,0,255);
 strip1.begin();
 
 for(int i=0; i<5; i++)
   strip1.send(data);

  strip1.end();

 delay(10);

}*/

void loop(){
  modbus.poll(); 
  taskHandler.Poll();
}
