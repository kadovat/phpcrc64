/* crc64.i */
%module crc64

#define CRC64_DEC_STR 1 
#define CRC64_HEX_STR 2

%{
    extern char* crc64(const char *string, int fmt); 
%}

extern char* crc64(const char *string, int fmt); 

