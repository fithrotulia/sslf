#ifndef SPI_H_
#define SPI_H_

#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3

void SPI_Slave_Init(void);

#endif /*SPI_H_*/