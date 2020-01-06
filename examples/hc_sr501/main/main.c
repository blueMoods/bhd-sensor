#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "hc_sr501.h"

void hc_sr501_callback(bool up) {
    if(up) {
        printf("HC-SR501: Someone is in range!\n");
    } else {
        printf("HC-SR501: None is in range!\n");
    }
    return;
}

void app_main(void)
{
    hc_sr501_init(hc_sr501_callback);
    return;
}