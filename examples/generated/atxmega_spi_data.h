// Generated with PeakRD-halcpp : https://github.com/Risto97/PeakRDL-halcpp


#ifndef __ATXMEGA_SPI_HAL_DATA_H_
#define __ATXMEGA_SPI_HAL_DATA_H_

#include <stdint.h>
#include <array>
#include <string>
#include <sstream>
#include <iomanip>
#include "include/arch_io.h"

/**
 * @note  C-style bitfields are used in this file to express field widths.
 *        Their in-memory layout (bit ordering, padding between fields) is
 *        implementation-defined and may vary across compilers and platforms.
 *
 *        DO NOT cast or memcpy these structs directly to/from raw register bytes.
 *        Always use the generated pack() and unpack() methods, which encode
 *        bit positions explicitly via shifts and masks, independently of the
 *        struct memory layout.
 */


namespace atxmega_spi_data_nm
{


    struct Ctrl_t {
        uint8_t PRESCALER : 2; // RW 
        uint8_t MODE : 2; // RW 
        uint8_t MASTER : 1; // RW 
        uint8_t DORD : 1; // RW 
        uint8_t ENABLE : 1; // RW 
        uint8_t CLK2X : 1; // RW 
        static Ctrl_t unpack(uint32_t raw) {
            Ctrl_t result{};
            result.PRESCALER = uint8_t((raw >> 0) & 0x3);
            result.MODE = uint8_t((raw >> 2) & 0x3);
            result.MASTER = uint8_t((raw >> 4) & 0x1);
            result.DORD = uint8_t((raw >> 5) & 0x1);
            result.ENABLE = uint8_t((raw >> 6) & 0x1);
            result.CLK2X = uint8_t((raw >> 7) & 0x1);
            return result;
        }
        uint32_t pack() const {
            return 0
                | (uint32_t(PRESCALER) << 0)
                | (uint32_t(MODE) << 2)
                | (uint32_t(MASTER) << 4)
                | (uint32_t(DORD) << 5)
                | (uint32_t(ENABLE) << 6)
                | (uint32_t(CLK2X) << 7);
        }

        std::string to_string(const std::string& indent = "") const {
            std::ostringstream s;
            s << indent << "PRESCALER=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(PRESCALER) << "\n";
            s << indent << "MODE=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(MODE) << "\n";
            s << indent << "MASTER=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(MASTER) << "\n";
            s << indent << "DORD=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(DORD) << "\n";
            s << indent << "ENABLE=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(ENABLE) << "\n";
            s << indent << "CLK2X=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(CLK2X) << "\n";
            return s.str();
        }
    };

    struct Intctrl_t {
        uint8_t INTLVL : 2; // RW 
        static Intctrl_t unpack(uint32_t raw) {
            Intctrl_t result{};
            result.INTLVL = uint8_t((raw >> 0) & 0x3);
            return result;
        }
        uint32_t pack() const {
            return 0
                | (uint32_t(INTLVL) << 0);
        }

        std::string to_string(const std::string& indent = "") const {
            std::ostringstream s;
            s << indent << "INTLVL=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(INTLVL) << "\n";
            return s.str();
        }
    };

    struct Status_t {
        uint8_t WRCOL : 1; // RO 
        uint8_t IF : 1; // RO 
        static Status_t unpack(uint32_t raw) {
            Status_t result{};
            result.WRCOL = uint8_t((raw >> 6) & 0x1);
            result.IF = uint8_t((raw >> 7) & 0x1);
            return result;
        }

        std::string to_string(const std::string& indent = "") const {
            std::ostringstream s;
            s << indent << "WRCOL=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(WRCOL) << "\n";
            s << indent << "IF=0x" << std::hex << std::setfill('0')
              << std::setw(1) << static_cast<uint32_t>(IF) << "\n";
            return s.str();
        }
    };

    struct Data_t {
        uint8_t WDATA : 8; // WO
        uint8_t RDATA : 8; // RO 
        static Data_t unpack(uint32_t raw) {
            Data_t result{};
            result.RDATA = uint8_t((raw >> 0) & 0xff);
            return result;
        }
        uint32_t pack() const {
            return 0
                | (uint32_t(WDATA) << 0);
        }

        std::string to_string(const std::string& indent = "") const {
            std::ostringstream s;
            s << indent << "WDATA=0x" << std::hex << std::setfill('0')
              << std::setw(2) << static_cast<uint32_t>(WDATA) << "\n";
            s << indent << "RDATA=0x" << std::hex << std::setfill('0')
              << std::setw(2) << static_cast<uint32_t>(RDATA) << "\n";
            return s.str();
        }
    };



} // namespace atxmega_spi_data_nm

struct ATXMEGA_SPI_HAL_DATA {

    atxmega_spi_data_nm::Ctrl_t CTRL;
    atxmega_spi_data_nm::Intctrl_t INTCTRL;
    atxmega_spi_data_nm::Status_t STATUS;
    atxmega_spi_data_nm::Data_t DATA;

    static ATXMEGA_SPI_HAL_DATA read_all(uint32_t base) {
        ATXMEGA_SPI_HAL_DATA result{};
        result.CTRL = atxmega_spi_data_nm::Ctrl_t::unpack(ArchIoNode::read32(base + 0x0));
        result.INTCTRL = atxmega_spi_data_nm::Intctrl_t::unpack(ArchIoNode::read32(base + 0x1));
        result.STATUS = atxmega_spi_data_nm::Status_t::unpack(ArchIoNode::read32(base + 0x2));
        result.DATA = atxmega_spi_data_nm::Data_t::unpack(ArchIoNode::read32(base + 0x3));
        return result;
    }

    void write_all(uint32_t base) const {
        ArchIoNode::write32(base + 0x0, CTRL.pack());
        ArchIoNode::write32(base + 0x1, INTCTRL.pack());
        ArchIoNode::write32(base + 0x3, DATA.pack());
    }

    std::string to_string(const std::string& indent = "") const {
        std::string s;
        s += indent + "CTRL:\n";
        s += CTRL.to_string(indent + "  ");
        s += indent + "INTCTRL:\n";
        s += INTCTRL.to_string(indent + "  ");
        s += indent + "STATUS:\n";
        s += STATUS.to_string(indent + "  ");
        s += indent + "DATA:\n";
        s += DATA.to_string(indent + "  ");
        return s;
    }
};

#endif // !__ATXMEGA_SPI_HAL_DATA_H_