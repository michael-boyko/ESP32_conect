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

struct buttons  {
    char enter[5];
    uint8_t backspace[3];
    uint8_t left[3];
    uint8_t right[3];
};

static struct buttons buttons = {
        "\n\r>", // Enter
        {0x08, ' ', 0x08,},  // Backspace
        {0x08, '[', 'D',},  // Left button
        {27, '[', 'C',},  // Right button
};

static uint8_t insert_one_space[3] = { 27, '[', '@',}; // insert one space

void uart_console_start(t_pars_tree **commands);
//void task_uart_event_handler(t_pars_tree ***registered_commands);
void error_output(char *argv);

#endif