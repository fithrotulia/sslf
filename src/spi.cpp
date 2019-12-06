#include <avr/io.h>
#include "spi.h"

void SPI_Slave_init()
{
    DDR_SPI = (1<<DD_MISO);
    SPCR = (1<<SPE);
}