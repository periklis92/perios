#include <string.h>

void* memcpy(const void* restrict src, void* restrict dst, size_t size){
    unsigned char* dst_cpy = (unsigned char*) dst;
    const unsigned char* src_cpy = (const unsigned char*) src;
    for (size_t i=0; i < size; i++)
        dst_cpy[i] = src_cpy [i];
    return dst;
}