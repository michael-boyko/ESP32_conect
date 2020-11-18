#include "sta_mode.h"

#include "nvs_flash.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"

void app_main() {
    t_pars_tree **commands = create_arr_commands();

    uart_start();
    uart_console_start(commands);

}