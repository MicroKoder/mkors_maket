#include "ledconfig.h"

const vd_t vd_config[VD_NUM]=
{
	//VD1
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
	//VD6
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
		.pin1 = 6,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 6
	},
	//VD8
	{
		.port1 = PORT_I2C_1,
		.pin1 = 7,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 7
	},
	//VD9
	{
		.port1 = PORT_I2C_1,
		.pin1 = 8,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 8
	},
	//VD10
	{
		.port1 = PORT_I2C_1,
		.pin1 = 9,
		.port2 = PORT_NONE,
		.pin2 = 0,
		.nCoil1 = 9
	},
	//VD11
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 14,
		.port2 = PORT_DIGITAL,
		.pin2 = 15,
		.nCoil1 = 10,
		.nCoil2 = 11
	},
	//VD12
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 16,
		.port2 = PORT_DIGITAL,
		.pin2 = 17,
		.nCoil1 = 12,
		.nCoil2 = 13
	},
	//VD13
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 18,
		.port2 = PORT_DIGITAL,
		.pin2 = 19,
		.nCoil1 = 14,
		.nCoil2 = 15
	},
	//VD14
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 22,
		.port2 = PORT_DIGITAL,
		.pin2 = 23,
		.nCoil1 = 16,
		.nCoil2 = 17
	},
	//VD15
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 24,
		.port2 = PORT_DIGITAL,
		.pin2 = 25,
		.nCoil1 = 18,
		.nCoil2 = 19
	},
	//VD16
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 26,
		.port2 = PORT_DIGITAL,
		.pin2 = 27,
		.nCoil1 = 20,
		.nCoil2 = 21
	},
	//VD17
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 28,
		.port2 = PORT_DIGITAL,
		.pin2 = 29,
		.nCoil1 = 22,
		.nCoil2 = 23
	},
	//VD18
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 30,
		.port2 = PORT_DIGITAL,
		.pin2 = 31,
		.nCoil1 = 24,
		.nCoil2 = 25
	},
	//VD19
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 32,
		.port2 = PORT_DIGITAL,
		.pin2 = 33,
		.nCoil1 = 26,
		.nCoil2 = 27
	},
	//VD20
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 34,
		.port2 = PORT_DIGITAL,
		.pin2 = 35,
		.nCoil1 = 28,
		.nCoil2 = 29
	},
	//VD21
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 36,
		.port2 = PORT_DIGITAL,
		.pin2 = 37,
		.nCoil1 = 30,
		.nCoil2 = 31
	},
	//VD22
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 38,
		.port2 = PORT_DIGITAL,
		.pin2 = 39,
		.nCoil1 = 32,
		.nCoil2 = 33
	},
	//VD23
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 40,
		.port2 = PORT_DIGITAL,
		.pin2 = 41,
		.nCoil1 = 34,
		.nCoil2 = 35
	},
	//VD24
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 42,
		.port2 = PORT_DIGITAL,
		.pin2 = 43,
		.nCoil1 = 36,
		.nCoil2 = 37
	},
	//VD25
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 46,
		.port2 = PORT_DIGITAL,
		.pin2 = 47,
		.nCoil1 = 38,
		.nCoil2 = 39
	},
	//VD26
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 48,
		.port2 = PORT_DIGITAL,
		.pin2 = 49,
		.nCoil1 = 40,
		.nCoil2 = 41
	},
	//VD27
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 50,
		.port2 = PORT_DIGITAL,
		.pin2 = 51,
		.nCoil1 = 42,
		.nCoil2 = 43
	},
	//VD28
	{
		.port1 = PORT_DIGITAL,
		.pin1 = 52,
		.port2 = PORT_DIGITAL,
		.pin2 = 53,
		.nCoil1 = 44,
		.nCoil2 = 45
	},
	//VD29
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A0,
		.port2 = PORT_DIGITAL,
		.pin2 = A1,
		.nCoil1 = 46,
		.nCoil2 = 47
	},
	//VD30
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A2,
		.port2 = PORT_DIGITAL,
		.pin2 = A3,
		.nCoil1 = 48,
		.nCoil2 = 49
	},
	//VD31
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A4,
		.port2 = PORT_DIGITAL,
		.pin2 = A5,
		.nCoil1 = 50,
		.nCoil2 = 51
	},
	//VD32
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A6,
		.port2 = PORT_DIGITAL,
		.pin2 = A7,
		.nCoil1 = 52,
		.nCoil2 = 53
	},
	//VD33
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A8,
		.port2 = PORT_DIGITAL,
		.pin2 = A9,
		.nCoil1 = 54,
		.nCoil2 = 55
	},
	//VD34
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A10,
		.port2 = PORT_DIGITAL,
		.pin2 = A11,
		.nCoil1 = 56,
		.nCoil2 = 57
	},
	//VD35
	{
		.port1 = PORT_DIGITAL,
		.pin1 = A12,
		.port2 = PORT_DIGITAL,
		.pin2 = A13,
		.nCoil1 = 58,
		.nCoil2 = 59
	},
	//VD36
	{
		.port1 = PORT_I2C_2,
		.pin1 = 0,
		.port2 = PORT_I2C_2,
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
	//VD40
	{
		.port1 = PORT_I2C_2,
		.pin1 = 8,
		.port2 = PORT_I2C_2,
		.pin2 = 9,
		.nCoil1 = 68,
		.nCoil2 = 69
	},
	//VD41
	{
		.port1 = PORT_I2C_2,
		.pin1 = 10,
		.port2 = PORT_I2C_2,
		.pin2 = 11,
		.nCoil1 = 70,
		.nCoil2 = 71
	},
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

void LedDriverTask()
{
  int c1,c2; 
  for (int i=0; i< VD_NUM; i++)
  {
    vd_t vd = GetVDConfig(i);
    c1 = _modbus->coilRead(vd.nCoil1);
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

          _pwm1->setPWM(vd.pin1, c1? 4095:0, c1 ? 0: 4095);       // 
          if (vd.port2 == PORT_I2C_1)
            _pwm1->setPWM(vd.pin2, c1? 0:4095, c1 ? 4095:0);       // 
      break;
      case PORT_I2C_2: 
        _pwm2->setPWM(vd.pin1, c1? 4095:0, c1 ? 0: 4095);       // 
          if (vd.port2 == PORT_I2C_1)
            _pwm2->setPWM(vd.pin2, c1? 0:4095, c1 ? 4095:0);       // 
      break;
      default:break;
    }
  }
}

void DriveVD(int nVD, bool value)
{

}