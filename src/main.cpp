#include <avr/io.h>
#include "adc.h"

uint16_t sensor[3];
uint16_t smin[3]={1024,1024,1024};
uint16_t smax[3]={0,0,0};
uint16_t sthres[3];
bool snilai[3];

void read_sensor();
void kalibrasi();
void sensor_digital();

int main()
{
  ADC_Init();
  while(1)
  {

  }
}

void read_sensor()
{
  for(int i=0;i<=3;i++)
  {
    sensor[i]=ADC_Read(i);
  }
}

void kalibrasi()
{
  read_sensor();
  for(int i=0;i<=3;i++)
  {
    if (sensor[i]<smin[i])
    {
      smin[i]=sensor[i];
    }
    if (sensor[i]>smax[i])
    {
      smax[i]=sensor[i];
    }
    sthres[i]=(smin[i]+smax[i])/2;
  }
}

void sensor_digital()
{
  read_sensor();
  for (int i=0;i<=3;i++)
  {
    if (sensor[i]<sthres[i])
    {
      snilai[i]=0;
    }
    else
    {
     snilai[i]=1;
    }
  }
}