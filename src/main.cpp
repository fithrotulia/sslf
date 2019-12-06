#include <avr/io.h>
#include "adc.h"
#include "spi.h"
// #include "stdint.h"

uint16_t sensor[3];
uint16_t smin[3]={1024,1024,1024};
uint16_t smax[3]={0,0,0};
uint16_t sthres[3];
uint8_t sfix=0x00;
bool snilai[3];
char sdec;

void read_sensor();
void kalibrasi();
void sensor_digital();
void decision();

int main()
{
  ADC_Init();
  SPI_Slave_Init();
  while(1)
  {
 //   decision();
  }
}

void read_sensor()
{
  for(int i=0; i<3; i++)
  {
    sensor[i]=ADC_Read(i, 'F');
  }
}

void kalibrasi()
{
  read_sensor();
  for(int i=0; i<3; i++)
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
  for (int i=0; i<3; i++)
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
  sfix=(snilai[2])*4+(snilai[1]*2)+snilai[0];
}

void decision()
{
  sensor_digital();
  switch (sfix)
  {
  case 0b000: sdec='-'; break;
  case 0b010: sdec='I'; break;
  case 0b011: sdec='R'; break;
  case 0b110: sdec='L'; break;
  case 0b111: sdec='+'; break;
  }
}