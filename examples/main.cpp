#include <iostream>

#include "generated/atxmega_spi_hal.h"

int main() {

    ATXMEGA_SPI_HAL<0> hal;

    hal.DATA.WDATA = 0xff;
    std::cout << "hal.DATA.RDATA = " << (uint32_t) hal.DATA.RDATA << "\n";

    return 0;
}

