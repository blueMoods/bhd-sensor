#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "rgb.h"

void app_main(void)
{
    grb_init();
    grb_color_t color = GRB_NONE;
    while (1){
        grb_color_set(0, color);
        color = (color + 1) % GRB_COLOR_MAX;
        grb_color_set(1, color);
        vTaskDelay(1 * 1000 / portTICK_PERIOD_MS);
    }
    return;
}