// Generated with PeakRD-halcpp : https://github.com/Risto97/PeakRDL-halcpp
#ifndef __ATXMEGA_SPI_HAL_H_
#define __ATXMEGA_SPI_HAL_H_

#include <stdint.h>
#include <string_view>
#include "include/halcpp_base.h"

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wundefined-var-template"
#endif

namespace atxmega_spi_nm
{
    
    template <uint32_t BASE, uint32_t WIDTH, typename PARENT_TYPE>
    class Ctrl : public halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>
    {
    public:
        using TYPE = Ctrl<BASE, WIDTH, PARENT_TYPE>;

        static inline halcpp::FieldRW<0, 1, TYPE> PRESCALER{};
        static inline halcpp::FieldRW<2, 3, TYPE> MODE{};
        static inline halcpp::FieldRW<4, 4, TYPE> MASTER{};
        static inline halcpp::FieldRW<5, 5, TYPE> DORD{};
        static inline halcpp::FieldRW<6, 6, TYPE> ENABLE{};
        static inline halcpp::FieldRW<7, 7, TYPE> CLK2X{};

        using halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>::operator=;
    };
    
    template <uint32_t BASE, uint32_t WIDTH, typename PARENT_TYPE>
    class Intctrl : public halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>
    {
    public:
        using TYPE = Intctrl<BASE, WIDTH, PARENT_TYPE>;

        static inline halcpp::FieldRW<0, 1, TYPE> INTLVL{};

        using halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>::operator=;
    };
    
    template <uint32_t BASE, uint32_t WIDTH, typename PARENT_TYPE>
    class Status : public halcpp::RegRO<BASE, WIDTH, PARENT_TYPE>
    {
    public:
        using TYPE = Status<BASE, WIDTH, PARENT_TYPE>;

        static inline halcpp::FieldRO<6, 6, TYPE> WRCOL{};
        static inline halcpp::FieldRO<7, 7, TYPE> IF{};
    };
    /*
     * The DATA register is used for sending and receiving data.
     * Writing to the register initiates the data transmission, and the byte
     * written to the register will be shifted out on the SPI output line.
     * Reading the register causes the shift register receive buffer to be read,
     * returning the last byte successfully received
     */
    template <uint32_t BASE, uint32_t WIDTH, typename PARENT_TYPE>
    class Data : public halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>
    {
    public:
        using TYPE = Data<BASE, WIDTH, PARENT_TYPE>;

        static inline halcpp::FieldWO<0, 7, TYPE> WDATA{};
        static inline halcpp::FieldRO<0, 7, TYPE> RDATA{};

        using halcpp::RegRW<BASE, WIDTH, PARENT_TYPE>::operator=;
    };



}

/*
 * Register description of Atmel XMEGA AU's SPI controller
 * Transcribed from original manual as an example exercise:
 * http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8331-8-and-16-bit-AVR-Microcontroller-XMEGA-AU_Manual.pdf
 */
template <uint32_t BASE, typename PARENT_TYPE=void>
class ATXMEGA_SPI_HAL : public AddrmapNode<BASE, PARENT_TYPE>
{
public:
    using TYPE = ATXMEGA_SPI_HAL<BASE, PARENT_TYPE>;

    static inline atxmega_spi_nm::Ctrl<0x0, 8, TYPE> CTRL{};
    static inline atxmega_spi_nm::Intctrl<0x1, 2, TYPE> INTCTRL{};
    static inline atxmega_spi_nm::Status<0x2, 8, TYPE> STATUS{};
    static inline atxmega_spi_nm::Data<0x3, 8, TYPE> DATA{};
};

#endif // !__ATXMEGA_SPI_HAL_H_
