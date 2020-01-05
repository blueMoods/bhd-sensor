
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "rgb.h"

#define LED_NUM 2
#define GPIO_OUTPUT_IO_G0    26
#define GPIO_OUTPUT_IO_R0    27
#define GPIO_OUTPUT_IO_B0    25

#define GPIO_OUTPUT_IO_G1    12
#define GPIO_OUTPUT_IO_R1    13
#define GPIO_OUTPUT_IO_B1    14
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_B0) | (1ULL<<GPIO_OUTPUT_IO_G0) | (1ULL<<GPIO_OUTPUT_IO_R0) | (1ULL<<GPIO_OUTPUT_IO_B1) | (1ULL<<GPIO_OUTPUT_IO_G1) | (1ULL<<GPIO_OUTPUT_IO_R1))


#define GRB_NUM 3

bool grb_color[GRB_COLOR_MAX][GRB_NUM] = {
    {0, 0, 0},// GRB_NONE
    {1, 0, 0},// GRB_GREEN
    {0, 1, 0},// GRB_RED
    {0, 0, 1},// GRB_BLUE
    {1, 1, 0},// GRB_YELLOW
    {0, 1, 1},// GRB_PURPLE
    {1, 0, 1},// GRB_CYAN
    {1, 1, 1},// GRB_WHITE
};

int led_gpio[LED_NUM][GRB_NUM] = {
    {GPIO_OUTPUT_IO_G0, GPIO_OUTPUT_IO_R0, GPIO_OUTPUT_IO_B0},
    {GPIO_OUTPUT_IO_G1, GPIO_OUTPUT_IO_R1, GPIO_OUTPUT_IO_B1},
};

int grb_color_set(int num, grb_color_t color)
{
    if (num >= LED_NUM){
        return -1;
    }

    for (int i = 0; i < GRB_NUM; i++){
        gpio_set_level(led_gpio[num][i], grb_color[color][i]);
    }
    return 0;
}



void grb_init(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
}

