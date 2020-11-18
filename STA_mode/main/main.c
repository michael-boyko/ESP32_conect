#include "sta_mode.h"

static void clear_command(char *argv) {
    static uint8_t clear[8] = {27, '[', '2', 'J', 27, '[', 'H', '>'};

    if (argv == NULL) {
        uart_write_bytes(UART_NUM, (char *)clear, 8);
    } else {
        error_output(argv);
    }
}

void app_main() {
    t_pars_tree **commands = create_arr_commands();
//    t_command_config cc0 = {
//            .command = "clear",
//            .name_func = clear_command,
//    };
//    command_regist(&cc0, commands);

//    task_uart_event_handler(&commands);
    uart_start();
    uart_console_start(commands);

//    uart_pattern_queue_reset(UART_NUM, 20);    xTaskCreate(task_uart_event_handler, "task_uart_event_handler", 14096, (void *)&commands, 10, NULL);
}