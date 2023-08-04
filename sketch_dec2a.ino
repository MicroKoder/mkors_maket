#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "ledconfig.h"
#include <ArduinoModbus.h>
#include "taskhandler.h" 
#include "Strip.h"

#define BAUDRATE 19200
#define HREG_COUNT 30
#define IREG_COUNT 5
#define COIL_COUNT 200
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41, Wire);//отлажен
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x42, Wire);//?
ModbusRTUServerClass modbus = ModbusRTUServerClass();

TaskHandler taskHandler = TaskHandler();
unsigned long systick;

static int testValue=0;

//	------------ Демонстрация ---------------
int btn1, btn2, btn3;
int btn1_prev, btn2_prev, btn3_prev;

int startVD_ZDs = 12;
int endVD_ZDs = 40;

void SetZDClosed(int nVD)
{
	vd_t vd = GetVDConfig(nVD);
	modbus.coilWrite(vd.nCoil1, 0);
	modbus.coilWrite(vd.nCoil2, 1);
}

void SetZDOpened(int nVD)
{
	vd_t vd = GetVDConfig(nVD);
	modbus.coilWrite(vd.nCoil1, 1);
	modbus.coilWrite(vd.nCoil2, 0);
}
/*
уровень демонстрации
0 - все отключено
1 - все задвижки закрыты, резервуары пустые
1 - открыт поток АГЗУ - НГС, открыта свеча НГС
2 - НГС заполнен наполовину
3 - открыт поток НГС - РГС, открыта лини НГС - СВЕЧА
4 - РГС заполнен наполовину
5 - открыт поток РГС - к потребителю, насос в работе
*/
int demoStep=-1;	//
const int maxDemoStep = 5;

//эмуляция аварий
int alarmStep=-1;
const int maxAlarmStep = 9;
void TestTask()
{
   modbus.inputRegisterWrite(0,testValue++);

}

void SetAlarms(bool on)
{
   modbus.coilWrite(6,on ? 1: 0);  //желтый
   modbus.coilWrite(7,on ? 0: 1);  //красный
   modbus.coilWrite(9,on ? 1: 0);  //
   modbus.coilWrite(10,on ? 0: 1);  //
}
void ButtonsTask()
{
  int i;
  btn1 =  digitalRead(A1);  //кнопка включения демонстрации
  btn2 =  digitalRead(A2);  //отключение звука
  btn3 =  digitalRead(A3); // кнопка включения аварии

//принудительное отключение звука
  
  if (btn2 >0)
  {
      modbus.coilWrite(74, modbus.coilRead(72));
      modbus.coilWrite(75, modbus.coilRead(73));
  }else
  {
      modbus.coilWrite(74, 0);
      modbus.coilWrite(75, 0);
  }
  
   //фронт кнопки 1
  
  if (btn1==0 && btn1_prev>0)
  {
	demoStep++;
  
  	if (demoStep>maxDemoStep)
  	{
  		demoStep =0;
  	}
  	
  	switch(demoStep)
  	{
  		case 0: //
  			//закрыть все задвижки
  			for (i=startVD_ZDs; i<=endVD_ZDs;i++)
  				SetZDClosed(i);
  			
  			//уровнемеры
  			modbus.holdingRegisterWrite(1,0);
  			modbus.holdingRegisterWrite(2,0);
  			
  			//отключить все потоки
  			for (i=100; i<=166; i++)
  				modbus.coilWrite(i, 0);
  			
  		break;
  		
  		case 1:
  			SetZDOpened(VD13);
  			SetZDOpened(VD14);
  			SetZDOpened(VD15);
  			SetZDOpened(VD40);
  			
  			modbus.coilWrite(150, 1);//поток АГЗУ
  		break;
  		
  		case 2:
  			SetZDOpened(VD26); //свеча
  			//заполнить НГС 
  			modbus.coilWrite(120, 1);
  			modbus.coilWrite(121, 1);
  			modbus.coilWrite(122, 1);
  			modbus.coilWrite(123, 1);
  			modbus.coilWrite(124, 1);
       modbus.coilWrite(125, 1);
  			//уровнемер НГС
  			modbus.holdingRegisterWrite(1,100);
  			//поток на свечу через БПУ
  			modbus.coilWrite(161, 1);
  			modbus.coilWrite(162, 1);
  		break;
  		
  		case 3:
  		//открыть линию в РГС
  			SetZDOpened(VD21);
  			SetZDOpened(VD16);
  			SetZDOpened(VD24);
  			SetZDOpened(VD18);
        SetZDOpened(VD27);//3/1
  			//задвижки уровнемера РГС
  			SetZDOpened(VD28);
  			SetZDOpened(VD29);
  			
  			//поток через регулятор в РГС
  			modbus.coilWrite(151, 1);
  			modbus.coilWrite(152, 1);
  			modbus.coilWrite(153, 1);
  			
  			//задвижки на свечу
       SetZDOpened(VD17);
  			SetZDOpened(VD19);
  			SetZDOpened(VD22);
  			SetZDOpened(VD25);
  			//поток газа на свечу через регулятор
  			modbus.coilWrite(161, 1);
  			modbus.coilWrite(165, 1);
  			modbus.coilWrite(166, 1);
  			
  		break;
  		
  		case 4:
  		//заполнить РГС		
  			modbus.coilWrite(108, 1);
  			modbus.coilWrite(109, 1);
  			modbus.coilWrite(110, 1);
  			modbus.coilWrite(111, 1);
  			modbus.coilWrite(112, 1);
       modbus.coilWrite(113, 1);
       modbus.coilWrite(114, 1);
       modbus.coilWrite(115, 1);
  		//свеча РГС
  			modbus.coilWrite(159, 1);
  		//задвижка свечи 
  			SetZDOpened(VD41);
  			
  		//уровнемер РГС
  			modbus.holdingRegisterWrite(2,100);
  		break;
  		
  		case 5:
  		//насос
  			
  			SetZDOpened(VD30);
  			SetZDOpened(VD31);
  			SetZDOpened(VD32);
  			SetZDOpened(VD33);
  			SetZDOpened(VD34);
  			SetZDOpened(VD35);
  			
  		//открыть поток насоса
  			modbus.coilWrite(164, 1);
  			modbus.coilWrite(154, 1);
  			modbus.coilWrite(103, 1);
  		break;
  		default:
  		break;
  	}
  }
  btn1_prev = btn1;

  if (btn3==0 && btn3_prev>0)
  {
    alarmStep++;
    if (alarmStep>maxAlarmStep)
      alarmStep=0;
      
      for (int i = 10; i <= 22; i++)
         modbus.holdingRegisterWrite(i,0);  //отключить лужи*/

       
      switch(alarmStep)
      {
        case 0:
          SetAlarms(false); //отключить индикаторы аварий
          
          break;
        case 5:
          modbus.holdingRegisterWrite(19,1);
          SetAlarms(true); //индикаторы аварий
          break;
        case 2://НГС
          modbus.holdingRegisterWrite(10,1);
          modbus.holdingRegisterWrite(12,1);
          SetAlarms(true); //индикаторы аварий
          break;
          case 7://НГС
          modbus.holdingRegisterWrite(11,1);
          modbus.holdingRegisterWrite(20,1);
          SetAlarms(true); //индикаторы аварий
          break;
          
          case 4:
          modbus.holdingRegisterWrite(14,1);
          SetAlarms(true); //индикаторы аварий
          break;

          case 1:
          modbus.holdingRegisterWrite(15,1);
          modbus.holdingRegisterWrite(16,1);
          SetAlarms(true); //индикаторы аварий
          break;

          case 6:
          modbus.holdingRegisterWrite(17,1);
          SetAlarms(true); //индикаторы аварий
          break;

          /*case 7:
          modbus.holdingRegisterWrite(21,1);
          break;*/

          case 8:
          modbus.holdingRegisterWrite(18,1);
          SetAlarms(true); //индикаторы аварий
          break;

          case 3:
          modbus.holdingRegisterWrite(13,1);
          SetAlarms(true); //индикаторы аварий
          break;

          case 9:
          for (int i = 10; i <= 22; i++)
             modbus.holdingRegisterWrite(i,1);  //включить все лужи*/
          SetAlarms(true); //индикаторы аварий
          break;
      }
  }//btn 3

  btn3_prev = btn3;
}
void setup() {
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  
  VDInit(&pwm1, &pwm2, &modbus);

  pwm1.begin();  
  pwm2.begin();
  modbus.begin(1,BAUDRATE);
  modbus.configureHoldingRegisters(0,HREG_COUNT);
  modbus.configureInputRegisters(0,IREG_COUNT);
  modbus.configureCoils(0,COIL_COUNT);  
 
//инвертированные индикаторы аварий
  modbus.coilWrite(6,0);  //желтый
  modbus.coilWrite(7,1);  //красный
  modbus.coilWrite(8,0);  //
  modbus.coilWrite(9,1);  //
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
*/
  /*    for (int i = 10; i <= 22; i++)
     modbus.holdingRegisterWrite(i,1);  //отладка*/
//    modbus.coilWrite(154,1);  //test
  taskHandler.RegisterTask(&ButtonsTask,200);
  taskHandler.RegisterTask(&LedDriverTask, 500);

 //  ---- strip setup ------
  STRIP_setModbusServer(&modbus);
  taskHandler.RegisterTask(&ProcessAllStrips, 100);
}


void loop(){
  modbus.poll(); 
  taskHandler.Poll();
}
