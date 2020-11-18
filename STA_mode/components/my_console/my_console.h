#ifndef MYCONSOLE_H
#define MYCONSOLE_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_err.h"
#include "freertos/queue.h"
#include "../command_api/command_api.h"
#include "../mylib/mylib.h"

#define UART_NUM UART_NUM_1
#define EN_AMP 23

QueueHandle_t uart0_queue;

typedef struct s_flags {
    int count_str_size;
    int position;
} t_flag;

struct buttons {
    char enter[5];
    uint8_t backspace[3];
    uint8_t left[3];
    uint8_t right[3];
};

static uint8_t insert_one_space[3] = { 27, '[', '@',};

static struct buttons buttons = {
        .enter = "\n\r>",
        .backspace = {0x08, ' ', 0x08,},
        .left = {0x08, '[', 'D',},
        .right = {27, '[', 'C',},
};

void uart_console_start(t_pars_tree **commands);
void error_output(char *argv);
void uart_start();
//void esc_commands();

#endif