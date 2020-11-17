#include "sta_mode.h"

void app_main() {
    t_pars_tree **commands = create_arr_commands();
    char *t = mx_strnew(20);

    xTaskCreate()
    task_uart_event_handler(&commands);
//    uart_console_start(commands);
}