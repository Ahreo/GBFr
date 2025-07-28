#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <string>
#include <inttypes.h>

enum LICENSEE : uint16_t {
    None = 0x00,
    NintendoRD = 0x01,
    Capcom = 0x08,
    EA = 0x13,
    DEFAULT
};

enum CARTRIDGE_TYPE : uint8_t {
    ROM_ONLY = 0x00,
    MBC1 = 0x01,
    MBC1_RAM = 0x02,
    MBC1_RAM_BATTERY = 0x03,
    MBC2 = 0x05,
    MBC2_BATTERY = 0x06,
    ROM_RAM = 0x08,
    DEFAULT
};

enum ROM_SIZE : uint8_t {
    _32_KiB = 0x00,
    _64_KiB = 0x01,
    _128_KiB = 0x02,
    _256_KiB = 0x03,
    _512_KiB = 0x04,
    _1_MiB = 0x05,
    _2_MiB = 0x06,
    _4_MiB = 0x07,
    _8_MiB = 0x08,
};

enum RAM_SIZE : uint8_t {
    _0 = 0x00, // no RAM
    _8_KiB = 0x02,
    _32_KiB = 0x03,
    _128_KiB = 0x04,
    _64_KiB = 0x05,
};

enum DEST_CODE : uint8_t {
    Japan = 0x00,
    Overseas = 0x01,
};

enum BOOT : uint8_t {
    INIT,
    LOGO,
    TITLE,
    LOAD_AND_CHECK_HEADER,
    LOCK,
};

uint16_t byte_location = 0;
constexpr uint16_t NINTENDO_LOGO_BYTE_LOC = 104;

// __attribute__((packed))
#pragma pack(push, 1)
struct Cartridge {
    public:
        Cartridge();
        bool CalcChecksum();
        void feed(uint8_t byte);

    private:
        uint8_t nintendo_logo[48] = {
            0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
            0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
            0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
        };
        char title[16] = {0};
        uint32_t mfg_code = 0;
        uint8_t cgb_flag = 0;
        uint16_t licensee_code = 0;
        uint8_t sgb_flag = 0;
        uint8_t cartridge_type = 0;
        uint8_t rom_size = 0;
        uint8_t ram_size = 0;
        uint8_t dest_code = 0;
        uint8_t old_licensee_code = 0;
        uint8_t rom_ver_num = 0;
        uint8_t header_checksum = 0;
        uint16_t global_checksum = 0;
        uint8_t state = BOOT::INIT;
};
#pragma pack(pop)

#endif // CARTRIDGE_H
