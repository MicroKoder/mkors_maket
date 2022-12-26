#ifndef _STRIP_CONTROL_
#define _STRIP_CONTROL_
#include <Arduino.h>
#include <ArduinoModbus.h>
#include <Arduino.h>


//void STRIP_processPort1();
void STRIP_setModbusServer(ModbusRTUServerClass* mbus);

typedef enum
{ 
  LED_STATIC,       //без анимации
  LED_RUN_FORWARD,  //вперед
  LED_RUN_BACKWARD,   //обратно
  LED_RUN_TO_CENTER, //от краев к центру
  LED_RUN_FROM_CENTER, //от центра к краям
  LED_GAZ,  //для матрицы 4*4
  LED_PULSE, //пульсация
  LED_LEVEL   //отображение уровня, считывается не дискрет а holding регистр модбас
} strip_mode_t;

typedef struct
{
  int coil;   //номер управляющего дискрета модбас
  int count;  //количество ламп
  strip_mode_t mode; //режим работы 
  int r; //цвет участка
  int g;
  int b;
} strip_config_t;

typedef struct
{
  int offset=0;
} strip_stat_t;

void ProcessAllStrips();
#endif