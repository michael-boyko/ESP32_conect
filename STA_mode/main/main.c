#include "sta_mode.h"

#define WIFI_SSID "ucode public"
#define WIFI_PASS ">#ucodeworld"

void app_main() {
    t_pars_tree **commands = create_arr_commands();

    uart_start();
    uart_console_start(commands);
    nvs_flash_init();
    wifi_init();

    wifi_config_t wifi_config = {
            .sta = {
                    .ssid = WIFI_SSID,
//                    .password = WIFI_PASS,
            },
    };
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);
}