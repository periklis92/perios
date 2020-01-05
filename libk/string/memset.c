#include <string.h>

void* memset(void* buffer, int value, unsigned long size){
    unsigned char* buffer_cpy = (unsigned char*)buffer;
    unsigned long i;
    for (i=0; i<size; i++){
        buffer_cpy[i] = (unsigned char)value;
    }
    return buffer;
}
