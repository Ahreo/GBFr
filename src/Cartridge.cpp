#include "Cartridge.h"

Cartridge::Cartridge() {

}

bool Cartridge::CalcChecksum() {
    const uint8_t* start = reinterpret_cast<uint8_t*>(&this->title);
    const uint8_t* end = reinterpret_cast<uint8_t*>(&this->header_checksum);
    uint8_t checksum = 0;
    for(const uint8_t* ptr = start; ptr < end; ++ptr) {
        checksum = checksum - *ptr - 1;
    }

    return (checksum == this->header_checksum);
}

void Cartridge::feed(uint8_t byte) {
    if(state == BOOT::INIT) {
        if(counter == NINTENDO_LOGO_BYTE_LOC) {
            state = BOOT::LOGO;
        }
        counter++;
    }

    if(state == BOOT::LOGO) {

    }

    if(state == BOOT::TITLE) {
        
    }

    if(state == BOOT::LOAD_AND_CHECK_HEADER) {

    }

    if(state == BOOT::LOCK) {

    }
}
