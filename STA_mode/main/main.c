#include "sta_mode.h"

#define WIFI_SSID "ucode public"
#define WIFI_PASS ">#ucodeworld"

void save_ssid_pass_in_nvs(wifi_config_t *wifi_config) {
    wifi_config_t wifi_config;
    char ssid[] = "Redmi";

    memcpy(wifi_config.sta.ssid, ssid, strlen(ssid));
    nvs_handle_t my_handle;
    nvs_open("wifi", NVS_READWRITE, &my_handle);
    nvs_set_str(my_handle, "ucode public", "58745874");
    size_t t = 0;
    nvs_get_str(my_handle, "ucode public", NULL, &t);

    char *l = malloc(t);
    nvs_get_str(my_handle, "ucode public", l, &t);
    memcpy(wifi_config.sta.password, l, strlen(l));
    nvs_commit(my_handle);
}

void app_main() {
    t_pars_tree **commands = create_arr_commands();

    t_command_config cc = {
            .command = "scan",
            .name_func = scan,
    };
    command_regist(&cc, commands);
    uart_start();
    uart_console_start(commands);
    nvs_flash_init();

    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);

    wifi_init();
}