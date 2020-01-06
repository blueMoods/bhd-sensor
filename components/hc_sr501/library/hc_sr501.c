
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "hc_sr501.h"

#define GPIO_INPUT_HC_SR501    12
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_HC_SR501)
#define ESP_INTR_FLAG_DEFAULT 0

static xQueueHandle hc_sr501_evt_queue = NULL;
static hc_sr501_cb_t hc_sr501_cb = NULL;

static void IRAM_ATTR hc_sr501_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(hc_sr501_evt_queue, &gpio_num, NULL);
}

static void hc_sr501_task_handler(void* arg)
{
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(hc_sr501_evt_queue, &io_num, portMAX_DELAY)) {
            if (hc_sr501_cb != NULL) {
                if (gpio_get_level(io_num) == 0) {
                    hc_sr501_cb(false);
                } else {
                    hc_sr501_cb(true);
                }
            }
        }
    }
}

void hc_sr501_init(hc_sr501_cb_t cb)
{
    hc_sr501_cb = cb;

    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_ANYEDGE;
    //set as output mode
    io_conf.mode = GPIO_MODE_INPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //disable pull-up mode
    io_conf.pull_up_en = 1;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    //create a queue to handle gpio event from isr
    hc_sr501_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    //start gpio task
    xTaskCreate(hc_sr501_task_handler, "HC_SR501_T", 2048, NULL, 10, NULL);

    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(GPIO_INPUT_HC_SR501, hc_sr501_isr_handler, (void*) GPIO_INPUT_HC_SR501);
}

