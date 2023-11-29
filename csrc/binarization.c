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

    // for(int i=0;i<5;i++){
    *((volatile uint16_t *) (2)) = binarization(pixel, threshold, 0);
    *((volatile uint16_t *) (4)) = binarization(pixel, threshold, 1);
    *((volatile uint16_t *) (6)) = binarization(pixel, threshold, 2);
    *((volatile uint16_t *) (8)) = binarization(pixel, threshold, 3);
    *((volatile uint16_t *) (10)) = binarization(pixel, threshold, 4);
    // }
    

    /*
    for(int i = 0; i < 5; i++){
        uint16_t sub = threshold - *(pixel+i);
        // printf("%d, ",i);
        printf("before = %d\n, ",*(pixel+i));
        // printf("sub1 : %d\n", sub);
        sub = count_leading_zeros_16(sub);
        // printf("clz_sub2 : %d\n", sub);
        *(pixel+i) = (sub) ? 0 : 255;
        // if(sub)
        //     *(pixel+i) = 0;
        // else
        //     *(pixel+i) = 255;
        printf("after = %d\n",*(pixel+i));
        printf("--------------------------------\n");
    }
    */


// verification
    // for(int i = 0; i <= 255; i++){
    //     uint16_t sub = threshold - i;
    //     sub = count_leading_zeros_16(sub);
    //     // printf("clz_sub2 : %d\n", sub);
    //     if(sub)
    //         sub = 0;
    //     else
    //         sub = 255;
    //     printf("%d: after = %d\n", i, sub);
    //     printf("--------------------------------\n");
    // }

    return 0;
}

// #include <stdint.h>
// #include <stdio.h>
    
// int count_leading_zeros_16(uint16_t x)
// {
//     x |= (x >> 1);
//     x |= (x >> 2);
//     x |= (x >> 4);
//     x |= (x >> 8);

//     x -= ((x >> 1) & 0x5555);
//     x = ((x >> 2) & 0x3333) + (x & 0x3333);
//     x = ((x >> 4) + x) & 0x0f0f;
//     x += (x >> 8);

//     // printf("%d\n", x);
//     return (16 - (x & 0x1f)); // change 0x3f to 0x1f
// }

// static int binarization(int *arr, int threshold, int i){

//     uint16_t sub = threshold - *(arr+i);
//     uint16_t clz = count_leading_zeros_16(sub);

//     return (clz) ? 0 : 255;
// }

// int main(){
//     // pixel test
//     // 8-bit color depth for black and white photo

//     int picture[5] = {0,80,127,150,231};
//     int threshold = 127;
//     int *pixel = picture;

//     // for(int i=0;i<5;i++){
//     *((volatile int *) (4)) = binarization(pixel, threshold, 0);
//     *((volatile int *) (8)) = binarization(pixel, threshold, 1);
//     *((volatile int *) (12)) = binarization(pixel, threshold, 2);
//     *((volatile int *) (16)) = binarization(pixel, threshold, 3);
//     *((volatile int *) (20)) = binarization(pixel, threshold, 4);
//     // }
    

//     /*
//     for(int i = 0; i < 5; i++){
//         uint16_t sub = threshold - *(pixel+i);
//         // printf("%d, ",i);
//         printf("before = %d\n, ",*(pixel+i));
//         // printf("sub1 : %d\n", sub);
//         sub = count_leading_zeros_16(sub);
//         // printf("clz_sub2 : %d\n", sub);
//         *(pixel+i) = (sub) ? 0 : 255;
//         // if(sub)
//         //     *(pixel+i) = 0;
//         // else
//         //     *(pixel+i) = 255;
//         printf("after = %d\n",*(pixel+i));
//         printf("--------------------------------\n");
//     }
//     */


// // verification
//     // for(int i = 0; i <= 255; i++){
//     //     uint16_t sub = threshold - i;
//     //     sub = count_leading_zeros_16(sub);
//     //     // printf("clz_sub2 : %d\n", sub);
//     //     if(sub)
//     //         sub = 0;
//     //     else
//     //         sub = 255;
//     //     printf("%d: after = %d\n", i, sub);
//     //     printf("--------------------------------\n");
//     // }

//     return 0;
// }
