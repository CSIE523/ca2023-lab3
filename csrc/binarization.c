#include <stdint.h>
#include <stdio.h>
    
uint16_t count_leading_zeros_16(uint16_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);

    x -= ((x >> 1) & 0x5555);
    x = ((x >> 2) & 0x3333) + (x & 0x3333);
    x = ((x >> 4) + x) & 0x0f0f;
    x += (x >> 8);

    return (16 - (x & 0x1f)); // change 0x3f to 0x1f
}

static int binarization(uint16_t *arr, uint16_t threshold, int i){

    uint16_t sub = threshold - *(arr+i);
    uint16_t clz = count_leading_zeros_16(sub);

    return (clz) ? 0 : 255;
}

int main(){
    // pixel test
    // 8-bit color depth for black and white photo

    uint16_t picture[5] = {0,80,127,150,231};
    uint16_t threshold = 127;
    uint16_t *pixel = picture;

    *((volatile uint16_t *) (2)) = binarization(pixel, threshold, 0);
    *((volatile uint16_t *) (4)) = binarization(pixel, threshold, 1);
    *((volatile uint16_t *) (6)) = binarization(pixel, threshold, 2);
    *((volatile uint16_t *) (8)) = binarization(pixel, threshold, 3);
    *((volatile uint16_t *) (10)) = binarization(pixel, threshold, 4);
    
    return 0;
}