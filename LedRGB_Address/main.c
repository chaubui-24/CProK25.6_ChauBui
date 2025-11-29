#include <stdio.h>
#include "led_driver.h"

int main()
{
    if (led_init(10) != 0)
    {
        printf("Khoi tao dai Led that bai!\n");
        return -1;
    }

    const uint32_t* buffer = led_get_buffer();

    /*Ktra Khoi tao ve 0*/
    printf("Buffer sau khi init:\n");
    for (size_t i = 0; i < led_get_pixel_count(); i++)
    {
        printf("Pixel %zu: 0x%08X\n", i, buffer[i]);
    }

    /*Dat mau*/
    led_set_pixel_color(0, 255, 0, 0);    /*red*/
    led_set_pixel_color(4, 255, 255, 255); /*white*/
    led_set_pixel_color(9, 0, 0, 255);  /*blue*/

    buffer = led_get_buffer();
    printf("\nSau khi set mau:\n");
    printf("Pixel 0 (Red):   0x%08X\n", buffer[0]);
    printf("Pixel 4 (White): 0x%08X\n", buffer[4]);
    printf("Pixel 9 (Blue):  0x%08X\n", buffer[9]);

    /*Fill xanh la (0, 255, 0)*/
    led_fill(0, 255, 0);
    buffer = led_get_buffer();
    printf("\nSau khi fill green:\n");
    for (size_t i = 0; i < led_get_pixel_count(); i++)
    {
        printf("Pixel %zu: 0x%08X\n", i, buffer[i]);
    }

    led_shutdown();
    return 0;
}