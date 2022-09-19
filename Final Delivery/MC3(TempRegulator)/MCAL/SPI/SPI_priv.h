#ifndef SPI_PRIV_H
#define SPI_PRIV_H

#define SPI_SLAVE_MODE    0
#define SPI_MASTER_MODE   1

#define SPI_CLK_IDLE_LOW    0
#define SPI_CLK_IDLE_HIGH   1


#define SPI_PHASE_SETUP_LEADING      0
#define SPI_PHASE_SETUP_TRILLING     1


#define SPI_DOR_LSB_FIRST   0b0010000
#define SPI_DOR_MSB_FIRST   0b0000000

#define SPI_FREQ_DIV_2      0
#define SPI_FREQ_DIV_4      1
#define SPI_FREQ_DIV_8      2
#define SPI_FREQ_DIV_16     3
#define SPI_FREQ_DIV_32     4
#define SPI_FREQ_DIV_64     5
#define SPI_FREQ_DIV_128    6

#define SPDR    *((volatile uint8 * ) 0x2F)  
#define SPCR    *((volatile uint8 * ) 0x2D)
#define SPSR    *((volatile uint8 * ) 0x2E)

#endif