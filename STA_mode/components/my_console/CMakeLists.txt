idf_component_register(SRCS "start_console.c" "my_console.h" "error_output.c" "uart_start.c" "default_commands.c"
                       INCLUDE_DIRS "."
                       REQUIRES command_api mylib main
                      )