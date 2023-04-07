#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "ledconfig.h"
#include <ArduinoModbus.h>
#include "taskhandler.h" 
#include "Strip.h"

#define BAUDRATE 19200
#define HREG_COUNT 30
#define IREG_COUNT 2
#define COIL_COUNT 200
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41, Wire);//отлажен
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x42, Wire);//?
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
  pwm2.begin();
  modbus.begin(1,BAUDRATE);
  modbus.configureHoldingRegisters(0,HREG_COUNT);
  modbus.configureInputRegisters(0,IREG_COUNT);
  modbus.configureCoils(0,COIL_COUNT);  
 

/*  for (int i = 0; i < COIL_COUNT; i++)
     modbus.coilWrite(i,0);
  
  modbus.coilWrite(100,1);  //test
  modbus.coilWrite(101,1);  //test
  modbus.coilWrite(102,1);  //test
  modbus.coilWrite(103,1);  //test
  modbus.coilWrite(104,1);  //test
  modbus.coilWrite(105,1);  //test
  modbus.coilWrite(106,1);  //test
  modbus.coilWrite(107,1);  //test
  modbus.coilWrite(119,1);  //test
  modbus.coilWrite(143,1);  //test

  for (int i = 108; i <= 126; i++)
     modbus.coilWrite(i,1);  //отладка

      for (int i = 10; i <= 22; i++)
     modbus.holdingRegisterWrite(i,1);  //отладка*/
   
  
  taskHandler.RegisterTask(&TestTask,1000);
  taskHandler.RegisterTask(&LedDriverTask, 1000);

 //  ---- strip setup ------
  STRIP_setModbusServer(&modbus);
  taskHandler.RegisterTask(&ProcessAllStrips, 100);
}


void loop(){
  modbus.poll(); 
  taskHandler.Poll();
}
