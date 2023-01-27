#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "ledconfig.h"
#include <ArduinoModbus.h>
#include "taskhandler.h" 
#include "Strip.h"

#define BAUDRATE 9600
#define HREG_COUNT 30
#define IREG_COUNT 2
#define COIL_COUNT 200
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
  modbus.begin(1,BAUDRATE);
  modbus.configureHoldingRegisters(0,HREG_COUNT);
  modbus.configureInputRegisters(0,IREG_COUNT);
  modbus.configureCoils(0,COIL_COUNT);  
 

  for (int i = 0; i < COIL_COUNT; i++)
     modbus.coilWrite(i,0);
  
  taskHandler.RegisterTask(&TestTask,1000);
  taskHandler.RegisterTask(&LedDriverTask, 1000);

 //  ---- strip setup ------
  STRIP_setModbusServer(&modbus);
  taskHandler.RegisterTask(&ProcessAllStrips, 100);
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
