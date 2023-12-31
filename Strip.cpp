#include "Strip.h"
#include <microLED.h>
#define LED_STRIPE_COUNT 54

enum EZoneStat {EZ_OK, EZ_FIRE, EZ_FREEZE, EZ_LEAKAGE10, EZ_LEAKAGE20};

const strip_config_t strip[LED_STRIPE_COUNT]={
  // led 1 труба от АГЗУ в НГС, ОТЛАЖЕНО количество и направление
  {
  .coil = 150,  
  .count = 23,
  .mode =   LED_RUN_BACKWARD,
  .r = 255, 
  .g = 0, 
  .b = 255  
  },   
  //2 - НГС в РГС , участок от НГС после регулятора
   {
  .coil = 151,  .count = 18,//35,  
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 0, .b = 255  
  },
  //3 выход насоса НУ в АСН ОТЛАЖЕНО
   {
  .coil = 154,  .count = 115,
  .mode =   LED_RUN_FROM_CENTER,
  .r = 255, .g = 0, .b = 255  
  },
  //4 от РГС в НУ ОТЛАЖЕНО
   {
  .coil = 103,  .count = 50,
  .mode =   LED_RUN_TO_CENTER,
  .r = 255, .g = 0, .b = 255  
  },
  //5  байпас из НГС в РГС -- ОТЛАЖЕНО
   {
  .coil = 160,  .count = 22,
  .mode =   LED_RUN_TO_CENTER,
  .r = 255, .g = 0, .b = 255  
  },
  //6  уровень НГС    -- УРОВНЕМЕР НГС
   {
  .coil = 1,  .count = 18,
  .mode =   LED_LEVEL_NGS,
  .r = 255, .g = 0, .b = 255  
  },
  //7  Уровень в РГС
   {
  .coil = 2,  .count = 18, //coil 2
  .mode =   LED_LEVEL_NGS,
  .r = 255, .g = 0, .b = 255  
  },
  //8  НГС до СР, от НГС до СР через БПУ, количество ОТЛАЖЕНО
   {
  .coil = 161, //105
    .count = 18,  //70
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //9  от НГС в СР участок до задвижки, ОТЛАЖЕНО КОЛИЧЕСТВО
   {
  .coil = 165,  //105
  .count = 18,  
  .mode =   LED_RUN_BACKWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
  //10 продолжение 9, от задвижки до регулятора линия НГС-СР, ОТЛАЖЕНО
   {
  .coil = 165,  //105
  .count = 10,
  .mode =   LED_RUN_BACKWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
   //11 - байпас на свечу рассеивания, ОТЛАЖЕНО
   {
  .coil = 163,  .count = 13,
  .mode =   LED_RUN_BACKWARD,
  .r = 255, .g = 255, .b = 0  //желтый
  },  
   //12 - насос (ремень)  -- ОТЛАЖЕНО
   {
  .coil = 164,  .count = 13,  //
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 255  //белый
  },  
  //13 - уровнь РГС (ВЕРХ)
   {
  .coil = 115,  .count = 125, //ОТЛАЖЕНО КОЛИЧЕСТВО
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //желтый
  },
  //14 - уровнь РГС
   {
  .coil = 114,  .count = 140, //ОТЛАЖЕНО КОЛИЧЕСТВО
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //желтый
  },  
  //15 - уровнь РГС
   {
  .coil = 113,  .count = 160, //ОТЛАЖЕНО КОЛИЧЕСТВО --- Последнее кольцо на этом порту
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //синий
  },
  //16 - уровнь РГС
   {
  .coil = 112,  .count = 140, //ОТЛАЖЕНО КОЛИЧЕСТВО
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //синий     // ЕСЛИ Красный и Зеленый не 0 ПОМЕНЯТЬ ИХ МЕСТАМИ, только для этого кольца
  },
  //17 - уровнь РГС //ОТЛАЖЕНО - количество
   {
  .coil = 111,  .count = 150,
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //синий  *****
  },
  //18 - уровнь РГС
   {
  .coil = 110,  .count = 160, //ОТЛАЖЕНО
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //синий  *****
  },
  //19 - уровнь РГС
   {
  .coil = 109,  .count = 140, /// ОТЛАЖЕНО
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //синий
  },
  //20 - уровнь РГС //ОТЛАЖЕНО (нижнее кольцо)
   {
  .coil = 108,  .count = 150, 
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //синий
  },
  //21 - уровнь РГС// НЕТУ
   {
  .coil = 116,  .count = 200,
  .mode =   LED_STATIC,
  .r = 255, .g = 0, .b = 255  //синий
  },
  //22 - уровень НГС (ВЕРХ?)
   {
  .coil = 125,  .count = 63,   //73//******ОТЛАЖЕНО    верхнее кольцо
  .mode =   LED_STATIC,
  .r = 255, .g = 220, .b = 0  //
  },
  //23 - уровень НГС
   {
  .coil = 123,  .count = 135, //***** ОТЛАЖЕНО
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 0  //
  },
  //24 - уровень НГС
   {
  .coil = 122,  .count = 145, //*** ОТЛАЖЕНО
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //синий
  },  
  //25 - уровень НГС
   {
  .coil = 121,  .count = 141, //**** ОТЛАЖЕНО
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //синий
  },
  //26 - уровень НГС
   {
  .coil = 120,  .count = 132,   //** ОТЛАЖЕНО 132
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //ж
  },
  //27 - уровень НГС
   {
  .coil = 124,  .count = 131, // верхушка (вторая сверху)
  .mode =   LED_STATIC,
  .r = 255, .g = 220, .b = 0  //
  },
  //28 - уровень НГС // ?? НЕТУ ??
   {
  .coil = 126,  .count = 200,
  .mode =   LED_STATIC,
  .r = 0, .g = 255, .b = 255  //
  },
  //29 - насос - ротор - оТЛАЖЕНО
   {
  .coil = 164,  .count = 8,
  .mode =   LED_RUN_FORWARD,
  .r = 255, .g = 255, .b = 255  //б
  },
  //30 - разгерметизация трубы до НГС   1
   {
  .coil = 10+20,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //31 - газ НГС            2
   {
  .coil = 11,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //32 - газ НГС          3
   {
  .coil = 12,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //33 - газ труба в ргс  4
   {
  .coil = 13,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //34 - газ труба в ргс  5
   {
  .coil = 14,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //35 - газ  6
   {
  .coil = 15,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //36 - газ  7
   {
  .coil = 16+20,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //37 - газ насос  8
   {
  .coil = 17+20,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //38 - газ насос  9
   {
  .coil = 18,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //39 - газ насос  10
   {
  .coil = 19,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //40 - газ разлив нефти 11
   {
  .coil = 20+20,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //41 - газ разлив нефти   12
   {
  .coil = 21,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //42 - газ разлив продуктов   13
   {
  .coil = 22,  .count = 16,
  .mode =   LED_GAZ,
  .r = 255, .g = 255, .b = 255  //б
  },
  //43 - свеча РГС - ОТЛАЖЕНО
   {
  .coil = 159,  .count = 11,
  .mode =   LED_RUN_FROM_CENTER,
  .r = 255, .g = 255, .b = 0  //ж
  },
  //44 - уровнь в НГС верх синий  -- уровнемер НГС  !!!! ИСКЛЮЧЕН !!!!!
   {
  .coil = 125,  .count = 0,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 0  //ж
  },
  //45 - уровнь в НГС верх синий  ---!!!! ИСКЛЮЧЕН !!!!!!!
   {
  .coil = 121,  .count = 20,
  .mode =   LED_STATIC,
  .r = 255, .g = 255, .b = 255  //
  },
  //46 - уровнь в РГС  синий  !!!ИСКЛЮЧЕН !!!
   {
  .coil = 113,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //
  },
  //47 - уровнь в РГС  синий   !!! ИСКЛЮЧЕН !!!!!!
   {
  .coil = 108,  .count = 10,
  .mode =   LED_STATIC,
  .r = 0, .g = 0, .b = 255  //
  },
  //48 маленькие трубы в АГЗУ
  {
  .coil = 150,
  .count = 24,
  .mode =   LED_RUN_FORWARD,
  .r = 255, 
  .g = 0, 
  .b = 255  
  },
  //49 - кусок трубы с регулятором в линии НГС - СВЕЧА, ОТЛАЖЕНО
  {
  .coil = 166,
  .count = 14,
  .mode =   LED_RUN_BACKWARD,
  .r = 255, 
  .g = 255, 
  .b = 0  
  },
  //50 - LED10 свеча, ОТЛАЖЕНО
  {
  .coil = 161,
  .count = 22,
  .mode =   LED_RUN_BACKWARD,
  .r = 255, 
  .g = 255, 
  .b = 0  
  },
  //51  -- -- кусок от РГС до НУ
  {
  .coil = 154,
  .count = 51,
  .mode =   LED_RUN_TO_CENTER,
  .r = 255, 
  .g = 0, 
  .b = 255  
  },
  //52 - НГС в РГС, регулятор
  {
  .coil = 152,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, 
  .g = 0, 
  .b = 255  
  },
  //53 - НГС в РГС, до регулятора
  {
  .coil = 153,
  .count = 10,
  .mode =   LED_RUN_FORWARD,
  .r = 255, 
  .g = 0, 
  .b = 255  
  },
  //54
  {
  .coil = 162,
  .count = 70-18,
  .mode =   LED_RUN_FORWARD,
  .r = 255, 
  .g = 255, 
  .b = 0  
  }/*,
  //55
  {
  .coil = 100,
  .count = 1,
  .mode =   LED_STATIC,
  .r = 0, 
  .g = 0, 
  .b = 255  
  }*/
};
const int portStrip0[] = {48-1,1-1};   
const int portStrip4[] = {22-1,27-1, 23-1, 24-1, 25-1, 26-1};  //уровни в НГС , все static //checked
const int portStrip2[] = {6-1}; //уровнемер НГС
const int portStrip3[] = {8-1,54-1};
const int portStrip1[] = {9-1, 10-1};
const int portStrip5[] = {11-1};
const int portStrip6[] = {2-1, 52-1, 53-1};
const int portStrip7[] = {5-1};
const int portStrip8[] = {13-1, 14-1, 15-1};
const int portStrip9[] = {/*47-1,*/ 7-1/*, 46-1*/}; //уровнемер РГС
const int portStrip10[] = {3-1, 4-1};
const int portStrip11[] = {12-1};
const int portStrip12[] =  {29-1};
const int portStrip13[] =  {30-1,31-1,32-1,33-1,34-1,35-1,36-1,37-1,38-1,39-1,40-1,41-1,42-1};
const int portStrip14[] = {49-1};
const int portStrip15[] = {50-1};

const int portStrip16[] = {16-1, 17-1, 18-1};
const int portStrip17[] = {19-1, 20-1};
const int portStrip18[] = {43-1};
const int portStrip19[] = {51-1}; //порт А0, кусок трубы от РГС до насоса

typedef microLED<0, 2, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port0_t;
typedef microLED<0, 3, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port1_t;
typedef microLED<20, 4, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port2_t; //уровнемер НГС
typedef microLED<0, 5, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port3_t;
typedef microLED<0, 6, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port4_t;
typedef microLED<0, 7, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port5_t;
typedef microLED<0, 8, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port6_t;
typedef microLED<0, 9, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port7_t;
typedef microLED<0, 10, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port8_t;
typedef microLED<20, 11, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port9_t;
typedef microLED<0, 12, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port10_t;
typedef microLED<0, 13, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port11_t;
typedef microLED<0, 44, -1, LED_WS2812, ORDER_GRB,CLI_LOW> strip_port12_t;
typedef microLED<208, 45, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port13_t;
typedef microLED<0, A14, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port14_t;
typedef microLED<0, A15, -1, LED_WS2812, ORDER_GRB, CLI_LOW> strip_port15_t;

//дополнительные порты для уровней РГС
typedef microLED<0,14, -1, LED_WS2812, ORDER_GRB,CLI_AVER> strip_port16_t;
typedef microLED<0,15, -1, LED_WS2812, ORDER_GRB,CLI_AVER> strip_port17_t;

//свеча РГС
typedef microLED<0,26, -1, LED_WS2812, ORDER_GRB,CLI_AVER> strip_port18_t;

typedef microLED<0,A0, -1, LED_WS2812, ORDER_GRB,CLI_AVER> strip_port19_t;
strip_port0_t port0;
strip_port1_t port1;
strip_port2_t port2;
strip_port3_t port3;
strip_port4_t port4;
strip_port5_t port5;
strip_port6_t port6;
strip_port7_t port7;
strip_port8_t port8; //RGS
strip_port9_t port9;
strip_port10_t port10;
strip_port11_t port11;
strip_port12_t port12;
strip_port13_t port13;
strip_port14_t port14;  //A14
strip_port15_t port15;  //A15
strip_port16_t port16;  //RGS
strip_port17_t port17;  //RGS
strip_port18_t port18;  //
strip_port19_t port19;  //A0

strip_stat_t strip_stat[55];

int port1_offset = 0;
ModbusRTUServerClass *pModbus;
template  <class T>
void processStrip(T* port,const strip_config_t &conf, strip_stat_t &stat, bool forceRed)
{
  int i=0;
  int val = pModbus->coilRead(conf.coil);
  mData data[2] = {mRGB(conf.r, conf.g, conf.b), mRGB(0,0,0)};
  if (forceRed)
  {
    switch(conf.coil)
    {
     
      case 108:
      case 109:
      case 112:
      case 113:
      case 114:
      case 115:       
        data[0] = {mRGB(255,0,0)};
        break;
      case 124:
      case 125: //верхний уровень НГС
        data[0] = {mRGB(255,0,0)};
        break;
      default:
        data[0] = {mRGB(0,255,0)};
        break;
    }        
   
  }
  
  //clear strip if 0
  if (!val && conf.mode != LED_LEVEL_NGS && conf.mode != LED_LEVEL_RGS && conf.mode != LED_GAZ)  
  {
    for (int i = 0; i < conf.count; i++)
          {         
              port->send(forceRed? data[0]: data[1]);
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
            port->send((stat.offset+i) % 3 == 0 ? data[0] : data[1]);         
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
     
  break;
  case LED_PULSE: //пульсация
  break;
  case LED_LEVEL_NGS:  //отображение уровня, считывается не дискрет а holding регистр модбас
    //0..100
    //масштабируем в 0..20 (по количеству диодов)
    val = pModbus->holdingRegisterRead(conf.coil);
    val *= conf.count;
    val /=100;

    //до середины
     for (int i = 0; i < conf.count; i++)
     {
       mData lColor = ((i > 7) && (i<12)) ? mRGB(255,255,0) : mRGB(conf.r, conf.g, conf.b);
       if (i<conf.count/2)
        port->set(i, (i< val/2) ? lColor: mRGB(0, 0, 0));
       else
        port->set(i, ((conf.count - i)< val/2) ? lColor: mRGB(0, 0, 0));
     }  
        


    port->show();     
  break;
 
    default:
     
      for(i=0; i< conf.count; i++)
        port->send(val ? data[0] : data[1]);
    break;
  }
}
mData data_buf[1000];

template  <class T>
int loadStrip(T* port, const strip_config_t &conf, strip_stat_t &stat, int nStart)
{
  mData data[2] = {mRGB(conf.r, conf.g, conf.b), mRGB(0,0,0)};
   int s = pModbus->holdingRegisterRead(conf.coil);
      if (s== EZ_OK)
      {
        data[0] = mRGB(0, 0, 0);
      }else if (s >= EZ_LEAKAGE10)
      {
        data[0] = mRGB(255, 255, 0);
      }else if (s == EZ_FREEZE)
      {
        data[0] = mRGB(0, 0, 255);
      }else if (s == EZ_FIRE)
      {
        data[0] = mRGB(255, 0, 0);
      }
      
      mData matrix_inner[16] = { data[1], data[1], data[1], data[1], data[1], data[0], data[0], data[1],data[1],data[0],data[0],data[1],data[1],data[1],data[1],data[1]}; 
      mData matrix_outer[16] = { data[0], data[0], data[0], data[0], data[0], data[1], data[1], data[0],data[0],data[1],data[1],data[0],data[0],data[0],data[0],data[0]}; 
      
      if (stat.offset>5)
        for (int i = 0; i < conf.count; i++)     
         port->set(nStart+i, matrix_inner[i]);	    
         // port->send(matrix_inner[i]);
      else
        for (int i = 0; i < conf.count; i++)
          port->set(nStart+i, matrix_outer[i]);	    
          //port->send(matrix_outer[i]);

      stat.offset++;
      if (stat.offset>9)      
        stat.offset = 0;       

  return conf.count;                 
}
template  <class T>
void processPortBuffered(T* port, const int portStrip[], int stripCnt, bool allStatic=false)
{
  int total=0;
  for (int i =0; i< stripCnt; i++)
    total += loadStrip(port,strip[portStrip[i]], strip_stat[portStrip[i]], total);  

  port->show();
}

int prevStaticValue=0;
template  <class T>
void processPort(T* port, const int portStrip[], int stripCnt, bool allStatic=false)
{
  int value = 0;
  bool forceRed = false;
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
  
  void *pPort = (void*)port;
    
  if (pPort == (void*)&port4)
  {
    forceRed =  pModbus->coilRead(80)>0;
  }

  if ((pPort == (void*)&port8) ||(pPort == (void*)&port16) ||(pPort == (void*)&port17))
  {
    forceRed =  pModbus->coilRead(81)>0;
  }
  
  
  port->begin();  
  for (int i =0; i< stripCnt; i++)
    processStrip<T>(port,strip[portStrip[i]], strip_stat[portStrip[i]], forceRed);  
  port->end();
}
extern ModbusRTUServerClass modbus;
void ProcessAllStrips()
{
//cli();
    processPort<strip_port0_t>(&port0, portStrip0, sizeof(portStrip0)/sizeof(int))  ;  
    processPort<strip_port1_t>(&port1, portStrip1, sizeof(portStrip1)/sizeof(int))  ;  
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
    processPortBuffered<strip_port13_t>(&port13, portStrip13, sizeof(portStrip13)/sizeof(int))  ;  
    processPort<strip_port14_t>(&port14, portStrip14, sizeof(portStrip14)/sizeof(int))  ;  
    processPort<strip_port15_t>(&port15, portStrip15, sizeof(portStrip15)/sizeof(int))  ;  
    processPort<strip_port16_t>(&port16, portStrip16, sizeof(portStrip16)/sizeof(int))  ;  
    processPort<strip_port17_t>(&port17, portStrip17, sizeof(portStrip17)/sizeof(int))  ;  
    processPort<strip_port18_t>(&port18, portStrip18, sizeof(portStrip18)/sizeof(int))  ;  
    processPort<strip_port19_t>(&port19, portStrip19, sizeof(portStrip19)/sizeof(int))  ;  
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
