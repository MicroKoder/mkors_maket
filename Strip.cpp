#include "Strip.h"
#include <microLED.h>
#define LED_STRIPE_COUNT 55


const strip_config_t strip[LED_STRIPE_COUNT]={
  // led 1
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },   
  //2
   {
  .coil = 101,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, .g = 0, .b = 255  
  },
  //3
   {
  .coil = 102,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, .g = 0, .b = 255  
  },
  //4
   {
  .coil = 103,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, .g = 0, .b = 255  
  },
  //5  ????
   {
  .coil = 104,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, .g = 0, .b = 255  
  },
  //6  уровень НГС
   {
  .coil = 1,  .count = 10,
  .mode =   LED_LEVEL,
  .r = 0, .g = 0, .b = 255  
  },
  //7  Уровень в РГС
   {
  .coil = 2,  .count = 10,
  .mode =   LED_LEVEL,
  .r = 0, .g = 0, .b = 255  
  },
  //8  НГС до СР
   {
  .coil = 105,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //9  
   {
  .coil = 105,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
  //10 
   {
  .coil = 105,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
   //11 - ???
   {
  .coil = 106,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
   //12 - насос
   {
  .coil = 107,  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 255  //белый
  },  
  //13 - уровнь РГС
   {
  .coil = 108,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //14 - уровнь РГС
   {
  .coil = 109,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },  
  //15 - уровнь РГС
   {
  .coil = 110,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //16 - уровнь РГС
   {
  .coil = 111,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //17 - уровнь РГС
   {
  .coil = 112,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //18 - уровнь РГС
   {
  .coil = 113,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //19 - уровнь РГС
   {
  .coil = 114,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //20 - уровнь РГС
   {
  .coil = 115,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //21 - уровнь РГС
   {
  .coil = 116,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //22 - уровень НГС
   {
  .coil = 120,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //23 - уровень НГС
   {
  .coil = 121,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //24 - уровень НГС
   {
  .coil = 122,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },  
  //25 - уровень НГС
   {
  .coil = 123,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //синий
  },
  //26 - уровень НГС
   {
  .coil = 124,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //ж
  },
  //27 - уровень НГС
   {
  .coil = 125,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //ж
  },
  //28 - уровень НГС
   {
  .coil = 126,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //ж
  },
  //29 - насос
   {
  .coil = 107,  .count = 8,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 255  //б
  },
  //30 - разгерметизация трубы до НГС
   {
  .coil = 130,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //31 - газ НГС
   {
  .coil = 131,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //32 - газ НГС
   {
  .coil = 132,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //33 - газ труба в ргс
   {
  .coil = 133,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //34 - газ труба в ргс
   {
  .coil = 134,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //35 - газ 
   {
  .coil = 135,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //36 - газ 
   {
  .coil = 136,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //37 - газ насос 
   {
  .coil = 137,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //38 - газ насос 
   {
  .coil = 138,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //39 - газ насос 
   {
  .coil = 139,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //40 - газ разлив нефти
   {
  .coil = 140,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //41 - газ разлив нефти 
   {
  .coil = 141,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //42 - газ разлив продуктов
   {
  .coil = 142,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //43 - свеча
   {
  .coil = 143,  .count = 10,
  .mode =   LED_PULSE,
  .r = 255, .g = 255, .b = 0  //ж
  },
  //44 - уровнь в НГС верх синий
   {
  .coil = 125,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //ж
  },
  //45 - уровнь в НГС низ синий
   {
  .coil = 121,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //
  },
  //46 - уровнь в РГС  синий
   {
  .coil = 113,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //
  },
  //47 - уровнь в РГС  синий
   {
  .coil = 108,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //
  },
  //48 и далее - наличие потока агзу - нгс
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //49
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //50
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //51
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //52
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //53
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //54
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  },
  //55
  {
  .coil = 100,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 0, 
  .g = 0, 
  .b = 255  
  }
};
const int portStrip0[] = {48-1, 49-1, 50-1, 51-1, 52-1, 53-1, 54-1, 55-1, 1-1};   
const int portStrip1[] = {22-1, 23-1, 24-1, 25-1, 26-1, 27-1, 28-1};  //уровни в НГС , все static
const int portStrip2[] = {45-1, 6-1, 44-1};
const int portStrip3[] = {8-1};
const int portStrip4[] = {9-1, 10-1};
const int portStrip5[] = {11-1};
const int portStrip6[] = {2-1};
const int portStrip7[] = {5-1};
const int portStrip8[] = {13-1, 14-1, 15-1, 16-1, 17-1,18-1, 19-1, 20-1, 21-1, 43-1};
const int portStrip9[] = {47-1, 7-1, 46-1};
const int portStrip10[] = {3-1, 4-1};
const int portStrip11[] = {12-1};
const int portStrip12[] =  {29-1};
const int portStrip13[] =  {30-1,31-1,32-1,33-1,34-1,35-1,36-1,37-1,38-1,39-1,40-1,41-1,42-1};

typedef microLED<0, 2, -1, LED_WS2812, ORDER_GRB> strip_port0_t;
typedef microLED<0, 3, -1, LED_WS2812, ORDER_GRB> strip_port1_t;
typedef microLED<0, 4, -1, LED_WS2812, ORDER_GRB> strip_port2_t;
typedef microLED<0, 5, -1, LED_WS2812, ORDER_GRB> strip_port3_t;
typedef microLED<0, 6, -1, LED_WS2812, ORDER_GRB> strip_port4_t;
typedef microLED<0, 7, -1, LED_WS2812, ORDER_GRB> strip_port5_t;
typedef microLED<0, 8, -1, LED_WS2812, ORDER_GRB> strip_port6_t;
typedef microLED<0, 9, -1, LED_WS2812, ORDER_GRB> strip_port7_t;
typedef microLED<0, 10, -1, LED_WS2812, ORDER_GRB> strip_port8_t;
typedef microLED<0, 11, -1, LED_WS2812, ORDER_GRB> strip_port9_t;
typedef microLED<0, 12, -1, LED_WS2812, ORDER_GRB> strip_port10_t;
typedef microLED<0, 13, -1, LED_WS2812, ORDER_GRB> strip_port11_t;
typedef microLED<0, 44, -1, LED_WS2812, ORDER_GRB> strip_port12_t;
typedef microLED<0, 45, -1, LED_WS2812, ORDER_GRB> strip_port13_t;

strip_port0_t port0;
strip_port1_t port1;
strip_port2_t port2;
strip_port3_t port3;
strip_port4_t port4;
strip_port5_t port5;
strip_port6_t port6;
strip_port7_t port7;
strip_port8_t port8;
strip_port9_t port9;
strip_port10_t port10;
strip_port11_t port11;
strip_port12_t port12;
strip_port13_t port13;


strip_stat_t strip_stat[55];

int port1_offset = 0;
ModbusRTUServerClass *pModbus;
template  <class T>
void processStrip(T* port,const strip_config_t &conf, strip_stat_t &stat)
{
  int i=0;
  int val = pModbus->coilRead(conf.coil);
  mData data[2] = {mRGB(conf.r, conf.g, conf.b), mRGB(0,0,0)};
  
  mData matrix_inner[16] = { data[1], data[1], data[1], data[1], data[1], data[0], data[0], data[1],data[1],data[0],data[0],data[1],data[1],data[1],data[1],data[1]}; 
  mData matrix_outer[16] = { data[0], data[0], data[0], data[0], data[0], data[1], data[1], data[0],data[0],data[1],data[1],data[0],data[0],data[0],data[0],data[0]}; 
  //clear strip if 0
  if (!val && conf.mode != LED_LEVEL)  
  {
    for (int i = 0; i < conf.count; i++)
          {         
              port->send(data[1]);
          }
    return;
  }
  
  switch(conf.mode)
  {
    case LED_STATIC:       
        for(i=0; i< conf.count; i++)
          port->send(data[0]);

    break;   
   case LED_RUN_FORWARD:  //вперед
          for (int i = 0; i < conf.count; i++)
          {         
              port->send((i+stat.offset) % 3 == 0 ? data[0] : data[1]);
          }           
        stat.offset++;
   break;
  case LED_RUN_BACKWARD:   //обратно

          for (int i = 0; i < conf.count; i++)
          {
            port->send((stat.offset-i) % 3 == 0 ? data[0] : data[1]);         
          }         
        stat.offset--;
  break;
  case LED_RUN_TO_CENTER: //от краев к центру

          for (int i = 0; i < conf.count/2; i++)
          {
            port->send((stat.offset+i) % 3 == 0 ? data[0] : data[1]);         
          }           
          for (int i = conf.count/2; i < conf.count; i++)
          {
            port->send((stat.offset-i) % 3 == 0 ? data[0] : data[1]);                   
          }           

        stat.offset++;
  break;
  case LED_RUN_FROM_CENTER: //от центра к краям
      for (int i = 0; i < conf.count/2; i++)
        {
          port->send((stat.offset+i) % 3 == 0 ? data[0] : data[1]);        
        }           
        for (int i = conf.count/2; i < conf.count; i++)
        {
          port->send((stat.offset-i) % 3 == 0 ? data[0] : data[1]);                
        }           
        stat.offset--;
  break;
  case LED_GAZ:  //для матрицы 4*4
      if (stat.offset>5)
        for (int i = 0; i < conf.count; i++)
          port->send(matrix_inner[i]);
      else
        for (int i = 0; i < conf.count; i++)
          port->send(matrix_outer[i]);

      stat.offset++;
      if (stat.offset>9)      
        stat.offset = 0;                        
  break;
  case LED_PULSE: //пульсация
  break;
  case LED_LEVEL:  //отображение уровня, считывается не дискрет а holding регистр модбас
  break;
    default:
     
      for(i=0; i< conf.count; i++)
        port->send(val ? data[0] : data[1]);
    break;
  }
}

int prevStaticValue=0;
template  <class T>
void processPort(T* port, const int portStrip[], int stripCnt, bool allStatic=false)
{
  int value = 0;
  if (allStatic)
  {
    
    for (int i =0; i<stripCnt; i++)
      value += pModbus->coilRead(strip[portStrip[i]].coil);

      //не обновлять ленту если не было изменений нигде
    if (prevStaticValue == value)
      return;

    //else
    prevStaticValue = value;
  }
  
  
    
  
  port->begin();  
  for (int i =0; i< stripCnt; i++)
    processStrip<T>(port,strip[portStrip[i]], strip_stat[portStrip[i]]);  
  port->end();
}

void ProcessAllStrips()
{
//cli();
    processPort<strip_port0_t>(&port0, portStrip0, sizeof(portStrip0)/sizeof(int))  ;  
    processPort<strip_port1_t>(&port1, portStrip1, sizeof(portStrip1)/sizeof(int), true)  ;  
    processPort<strip_port2_t>(&port2, portStrip2, sizeof(portStrip2)/sizeof(int))  ;  
    processPort<strip_port3_t>(&port3, portStrip3, sizeof(portStrip3)/sizeof(int))  ;  
    processPort<strip_port4_t>(&port4, portStrip4, sizeof(portStrip4)/sizeof(int))  ;  
    processPort<strip_port5_t>(&port5, portStrip5, sizeof(portStrip5)/sizeof(int))  ;  
    processPort<strip_port6_t>(&port6, portStrip6, sizeof(portStrip6)/sizeof(int))  ;  
    processPort<strip_port7_t>(&port7, portStrip7, sizeof(portStrip7)/sizeof(int))  ;  
    processPort<strip_port8_t>(&port8, portStrip8, sizeof(portStrip8)/sizeof(int))  ;  
    processPort<strip_port9_t>(&port9, portStrip9, sizeof(portStrip9)/sizeof(int))  ;  
    processPort<strip_port10_t>(&port10, portStrip10, sizeof(portStrip10)/sizeof(int))  ;  
    processPort<strip_port11_t>(&port11, portStrip11, sizeof(portStrip11)/sizeof(int))  ;  
    processPort<strip_port12_t>(&port12, portStrip12, sizeof(portStrip12)/sizeof(int))  ;  
    processPort<strip_port13_t>(&port13, portStrip13, sizeof(portStrip13)/sizeof(int))  ;  
 // sei();
}
/*void STRIP_processPort1()
{
   port1_offset++;
   
   mData data[2] = {mRGB(0,0,255), mRGB(0,0,0)};
   strip_port_1.begin();
   
  
   for (int i = 0; i < STRIP_PORT_1_COUNT; i++)
   {
       strip_port_1.send((i+port1_offset) % 3 == 0 ? data[0] : data[1]);
   }   
   
   strip_port_1.end();
         
}*/

void STRIP_setModbusServer(ModbusRTUServerClass* mbus)
{
   pModbus = mbus;
}