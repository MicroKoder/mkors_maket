#include "ledconfig.h"

const vd_t vd_config[VD_NUM]=
{
	//VD1 -- фонари, начало
	{
		.port1 = PORT_I2C_1,
		.pin1 = 0,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 0
	},
	//VD2
	{
		.port1 = PORT_I2C_1,
		.pin1 = 1,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 1
	},
	//VD3
	{
		.port1 = PORT_I2C_1,
		.pin1 = 2,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 2
	},
	//VD4
	{
		.port1 = PORT_I2C_1,
		.pin1 = 3,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 3
	},
	//VD5
	{
		.port1 = PORT_I2C_1,
		.pin1 = 4,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 4
	},
	//VD6 -- последний фонарь тут
	{
		.port1 = PORT_I2C_1,
		.pin1 = 5,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 5
	},
	//VD7
	{
		.port1 = PORT_I2C_1,
		.pin1 = 7,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 7
	},
	//VD8
	{
		.port1 = PORT_I2C_1,
		.pin1 = 6,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 6
	},
	//VD9
	{
		.port1 = PORT_I2C_1,
		.pin1 = 8,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 9
	},
	//VD10
	{
		.port1 = PORT_I2C_1,
		.pin1 = 9,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 10
	},
	//VD11
	{
		.port1 = PORT_I2C_1,
		.pin1 = 10,
		.port2 = PORT_I2C_1,
		.pin2 = 11,
		.nCoil1 = 10,
		.nCoil2 = 11
	},
	//VD12
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 17,
		.port2 = PORT_DIGITAL,
		.pin2 = 16,
		.nCoil1 = 12,
		.nCoil2 = 13
	},
	//VD13 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 22,//18,
		.port2 = PORT_DIGITAL,
		.pin2 = 23,//19,
		.nCoil1 = 14,
		.nCoil2 = 15
	},
	//VD14 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 19,//22,
		.port2 = PORT_DIGITAL,
		.pin2 = 18,//23,
		.nCoil1 = 16,
		.nCoil2 = 17
	},
	//VD15 1/10
	{
		/*.port1 = PORT_DIGITAL,
		.pin1 = 24,
		.port2 = PORT_DIGITAL,
		.pin2 = 25,
		.nCoil1 = 18,
		.nCoil2 = 19*/
    	.port1 = PORT_I2C_2,
		.pin1 = 8,
		.port2 = PORT_I2C_2,
		.pin2 = 9,

		.nCoil1 = 68,
		.nCoil2 = 69
	},
	//VD16 - где она ?????
	{
		.port1 = PORT_I2C_1,
		.pin1 = 15,
		.port2 = PORT_I2C_1,
		.pin2 = 14,

		.nCoil1 = 20,
		.nCoil2 = 21
	},
	//VD17  1/11  - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 29,
		.port2 = PORT_DIGITAL,
		.pin2 = 28,
		.nCoil1 = 22,
		.nCoil2 = 23
	},
	//VD18  2/1  - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 31,
		.port2 = PORT_DIGITAL,
		.pin2 = 30,
		.nCoil1 = 24,
		.nCoil2 = 25
	},
	//VD19  2/5 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 33,
		.port2 = PORT_DIGITAL,
		.pin2 = 32,
		.nCoil1 = 26,
		.nCoil2 = 27
	},
	//VD20  2/6 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 34,
		.port2 = PORT_DIGITAL,
		.pin2 = 35,
		.nCoil1 = 28,
		.nCoil2 = 29
	},
	//VD21  2/4 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 37,
		.port2 = PORT_DIGITAL,
		.pin2 = 36,
		.nCoil1 = 30,
		.nCoil2 = 31
	},
	//VD22  2/8 - ОТЛАЖЕНО (регулятор газа)
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 38,
		.port2 = PORT_DIGITAL,
		.pin2 = 39,
		.nCoil1 = 32,
		.nCoil2 = 33
	},
	//VD23  2/3 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 41,
		.port2 = PORT_DIGITAL,
		.pin2 = 40,
		.nCoil1 = 34,
		.nCoil2 = 35
	},
	//VD24  2/2 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 42,
		.port2 = PORT_DIGITAL,
		.pin2 = 43,
		.nCoil1 = 36,
		.nCoil2 = 37
	},
	//VD25 2/9 - ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 47,
		.port2 = PORT_DIGITAL,
		.pin2 = 46,
		.nCoil1 = 38,
		.nCoil2 = 39
	},
	//VD26  ОТЛАЖЕНО  - зд 5/1
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 49,
		.port2 = PORT_DIGITAL,
		.pin2 = 48,
		.nCoil1 = 40,
		.nCoil2 = 41
	},
	//VD27 3/1  ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 51,
		.port2 = PORT_DIGITAL,
		.pin2 = 50,
		.nCoil1 = 42,
		.nCoil2 = 43
	},
	//VD28 ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 53,
		.port2 = PORT_DIGITAL,
		.pin2 = 52,
		.nCoil1 = 44,
		.nCoil2 = 45
	},
	//VD29 ОТЛАЖЕНО зд 3/7
	{
		/*.port1 = PORT_DIGITAL,
		.pin1 = A0,
		.port2 = PORT_DIGITAL,
		.pin2 = A1,*/
    .port1 = PORT_I2C_1,
		.pin1 = 13,
		.port2 = PORT_I2C_1,
		.pin2 = 12,
		.nCoil1 = 46,
		.nCoil2 = 47
	},
	//VD30  3/4 ОТЛАЖЕНО
	{
		.port1 = PORT_I2C_2,// PORT_DIGITAL,
		.pin1 = 0,//A2,
		.port2 = PORT_I2C_2,// PORT_DIGITAL,
		.pin2 = 1,//A3,
		.nCoil1 = 48,
		.nCoil2 = 49
	},
	//VD31  ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A4,
		.port2 = PORT_DIGITAL,
		.pin2 = A5,
		.nCoil1 = 50,
		.nCoil2 = 51
	},
	//VD32 ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A7,
		.port2 = PORT_DIGITAL,
		.pin2 = A6,
		.nCoil1 = 52,
		.nCoil2 = 53
	},
	//VD33 ОТЛАЖЕНО
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A9,
		.port2 = PORT_DIGITAL,
		.pin2 = A8,
		.nCoil1 = 54,
		.nCoil2 = 55
	},
	//VD34 ОТЛАЖЕНО   4/1
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A11,
		.port2 = PORT_DIGITAL,
		.pin2 = A10,
		.nCoil1 = 56,
		.nCoil2 = 57
	},
	//VD35  6/1  наливная
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A13,
		.port2 = PORT_DIGITAL,
		.pin2 = A12,
		.nCoil1 = 58,
		.nCoil2 = 59
	},
	//VD36  
	{
		.port1 =PORT_NONE,// PORT_I2C_2,
		.pin1 = 0,
		.port2 = PORT_NONE,//PORT_I2C_2,
		.pin2 = 1,
		.nCoil1 = 60,
		.nCoil2 = 61
	},
	//VD37
	{
		.port1 = PORT_I2C_2,
		.pin1 = 2,
		.port2 = PORT_I2C_2,
		.pin2 = 3,
		.nCoil1 = 62,
		.nCoil2 = 63
	},
	//VD38
	{
		.port1 = PORT_I2C_2,
		.pin1 = 4,
		.port2 = PORT_I2C_2,
		.pin2 = 5,
		.nCoil1 = 64,
		.nCoil2 = 65
	},
	//VD39
	{
		.port1 = PORT_I2C_2,
		.pin1 = 6,
		.port2 = PORT_I2C_2,
		.pin2 = 7,
		.nCoil1 = 66,
		.nCoil2 = 67
	},
	//VD40  1/9 - ОТЛАЖЕНО
	{
	/*	.port1 = PORT_I2C_2,
		.pin1 = 8,
		.port2 = PORT_I2C_2,
		.pin2 = 9,

		.nCoil1 = 68,
		.nCoil2 = 69*/
    .port1 = PORT_DIGITAL,
		.pin1 = 24,
		.port2 = PORT_DIGITAL,
		.pin2 = 25,
		.nCoil1 = 18,
		.nCoil2 = 19
	},
	//VD41
	{
		.port1 = PORT_I2C_2,
		.pin1 = 11,
		.port2 = PORT_I2C_2,
		.pin2 = 10,
		.nCoil1 = 70,
		.nCoil2 = 71
	},
  //B1
  {
		.port1 = PORT_I2C_2,
		.pin1 = 14,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 74
	},
  //B2
  {
		.port1 = PORT_I2C_2,
		.pin1 = 15,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 75		
	}
};

vd_t GetVDConfig(int nLed)
{
  return vd_config[nLed];
}
static Adafruit_PWMServoDriver *_pwm1;
static Adafruit_PWMServoDriver *_pwm2;
static ModbusRTUServerClass *_modbus;
void VDInit(Adafruit_PWMServoDriver *pwm1, Adafruit_PWMServoDriver *pwm2, ModbusRTUServerClass *modbus)
{
  _pwm1 = pwm1;
  _pwm2 = pwm2;
  _modbus = modbus;
  for (int i=0; i<VD_NUM; i++)
    {
      if (vd_config[i].port1 == PORT_DIGITAL)
      {       
          pinMode(vd_config[i].pin1, OUTPUT); 
          digitalWrite(vd_config[i].pin1, LOW);        
      }
      if (vd_config[i].port2 == PORT_DIGITAL)
      {       
          pinMode(vd_config[i].pin2, OUTPUT); 
          digitalWrite(vd_config[i].pin2, LOW);        
      }
    }
}
static int counter=0;
void LedDriverTask()
{
  int c1,c2; 
  int duty;
  counter++;  
  for (int i=0; i< VD_NUM; i++)
  {
    vd_t vd = GetVDConfig(i);
    c1 = _modbus->coilRead(vd.nCoil1);
    c2 = _modbus->coilRead(vd.nCoil2);
    
    if (i>=41)
      duty = 3500;
    else if (i>=12 && (c1==0) && (c2 ==0))
    {
      duty = 4095;
      c1= counter%2;
      c2 = (counter+1)%2;    
    }else
    {
      duty = 4095;      
    }

                    
    switch(vd.port1)
    {
      case PORT_DIGITAL:    
          digitalWrite(vd.pin1, c1 ? HIGH : LOW);    

        if (vd.port2 == PORT_DIGITAL)
        {     
            digitalWrite(vd.pin2, c1 ? LOW : HIGH);         
        }

      break;
      case PORT_I2C_1: 

          _pwm1->setPWM(vd.pin1, 0, c1 ? duty:0);       // 
          if (vd.port2 == PORT_I2C_1)
            _pwm1->setPWM(vd.pin2, 0, c1 ? 0:duty);       // 
      break;
      case PORT_I2C_2: 
                
        _pwm2->setPWM(vd.pin1, 0, c1 ? duty:0);       // 
          if (vd.port2 == PORT_I2C_2)
            _pwm2->setPWM(vd.pin2, 0, c1 ? 0:duty);       // 
      break;
      default:break;
    }
  }
}

void DriveVD(int nVD, bool value)
{

}