#include "crc32.h"

/* 0x1EDC6F41 (Castagnoli) */
static const uint32_t P = 0x82F63B78;

uint32_t crc32(const void *buf, size_t size, uint32_t crc)
{
        const uint8_t *b = buf;
        while (size--) {
                crc ^= *b++;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
                crc = crc >> 1 ^ (crc & 1) * P;
        }
        return crc;
}
