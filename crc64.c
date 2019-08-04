#include "crc64.h"
char* crc64(const char *string, int fmt) {
    if (fmt != CRC64_DEC_STR && fmt != CRC64_HEX_STR){
        fmt = CRC64_DEC_STR;
    }

    char* buff ;
    int offset = 0;
    uint8_t byte = 0;
    uint64_t crc = 0;
    int len = strlen(string);

    for (offset = 0; offset < len; offset++) {
        byte = string[offset];
        crc = crc64_tab[(uint8_t)((crc ^ byte) & 0xff)] ^ ((crc >> 8) & ~(0xffULL << 56));
    }

    buff = (char*)malloc(sizeof(char)*20);
    sprintf(buff, crc64_fmt[fmt], crc);

    return buff;
}
