#include "my_console.h"

void clear_command(char *argv) {
    const uint8_t clear[8] = {27, '[', '2', 'J', 27, '[', 'H', '>'};

    if (argv == NULL) {
        uart_write_bytes(UART_NUM, (char *)clear, 8);
    } else {
        error_output(argv);
    }
}

void default_commands(t_pars_tree **commands) {
    t_command_config cc = {
            .command = "clear",
            .name_func = clear_command,
    };

    command_regist(&cc, commands);
}