#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "inttypes.h"

constexpr uint16_t ROM_0_SIZE = 0x4000;
constexpr uint16_t ROM_1_SIZE = 0x4000;

constexpr uint16_t VRAM_SIZE = 0x2000;
constexpr uint16_t EXT_RAM_SIZE = 0x2000;
constexpr uint16_t WRAM_0_SIZE = 0x1000;
constexpr uint16_t WRAM_1_SIZE = 0x1000;

constexpr uint16_t ECHO_RAM_SIZE = 0x1E00;
constexpr uint16_t OAM_SIZE = 0x00A0;

constexpr uint16_t NOT_USABLE_SIZE = 0x0060;
constexpr uint16_t IO_REG_SIZE = 0x0080;
constexpr uint16_t HRAM_SIZE = 0x007F;

constexpr uint16_t INT_EN_REG = 0xFFFF;

typedef struct mmap {
    public:
        mmap();
        uint8_t readByte(uint16_t addr) const;
        void writeByte(uint16_t addr, uint8_t val);

    private:
        uint8_t rom_0[ROM_0_SIZE];
        uint8_t rom_1[ROM_1_SIZE];
        uint8_t vram[VRAM_SIZE];
        uint8_t extram[EXT_RAM_SIZE];
        uint8_t wram_0[WRAM_0_SIZE];
        uint8_t wram_1[WRAM_1_SIZE];
        uint8_t echoram[ECHO_RAM_SIZE];
        uint8_t oam[OAM_SIZE];
        uint8_t notusable[NOT_USABLE_SIZE];
        uint8_t ioreg[IO_REG_SIZE];
        uint8_t hram[HRAM_SIZE];
        uint8_t intr_en;
};

#endif // MEMORY_MAP_H
