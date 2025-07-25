#include "MemoryMap.h"
#include <cstring>
#include <cstdio>

mmap::mmap() {
    memset(this, 0, sizeof(mmap));
}

uint8_t mmap::readByte(uint16_t addr) const {
    if(addr <= 0x3FFF) return rom_0[addr];
    if(addr <= 0x7FFF) return rom_1[addr - 0x4000];
    if(addr <= 0x9FFF) return vram[addr - 0x8000];
    if(addr <= 0xBFFF) return extram[addr - 0xA000];
    if(addr <= 0xCFFF) return wram_0[addr - 0xC000];
    if(addr <= 0xDFFF) return wram_1[addr - 0xD000];
    if(addr <= 0xFDFF) return echoram[addr - 0xE000];
    if(addr <= 0xFE9F) return oam[addr - 0xFE00];
    if(addr <= 0xFEFF) return notusable[addr - 0xFEA0];
    if(addr <= 0xFF7F) return ioreg[addr - 0xFF00];
    if(addr <= 0xFFFE) return hram[addr - 0xFF80];
    if(addr == 0xFFFF) return intr_en;
}

void mmap::writeByte(uint16_t addr, uint8_t val) {
    if(addr <= 0x3FFF) rom_0[addr] = val;
    if(addr <= 0x7FFF) rom_1[addr - 0x4000] = val;
    if(addr <= 0x9FFF) vram[addr - 0x8000] = val;
    if(addr <= 0xBFFF) extram[addr - 0xA000] = val;
    if(addr <= 0xCFFF) wram_0[addr - 0xC000] = val;
    if(addr <= 0xDFFF) wram_1[addr - 0xD000] = val;
    if(addr <= 0xFDFF) printf("writing to prohibited Echo Ram area!\n");
    if(addr <= 0xFE9F) oam[addr - 0xFE00] = val;
    if(addr <= 0xFEFF) printf("trying to write to un-usable memory\n");
    if(addr <= 0xFF7F) ioreg[addr - 0xFF00] = val;
    if(addr <= 0xFFFE) hram[addr - 0xFF80] = val;
    if(addr == 0xFFFF) intr_en = val;
}
