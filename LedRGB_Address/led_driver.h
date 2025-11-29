#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include <stddef.h>

/*Khoi tao dai LED voi ... pixel*/
int led_init(size_t num_pixels);

/*Giai phong bo nho*/
void led_shutdown();

/*Dat mau cho pixel tai index*/
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

/*Dat toan bo dai thanh 1 mau*/
void led_fill(uint8_t r, uint8_t g, uint8_t b);

/*Tat dai led*/
void led_clear();

/*Tro toi buffer*/
const uint32_t*  led_get_buffer(void);

/*Lay so luong pixel*/
size_t led_get_pixel_count(void);

#endif