#include "my_wifi.h"
#include <string.h>

static void event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base == WIFI_EVENT) {
        printf("-------WIFI___EVENT-------\n");
        switch (event_id) {
            case WIFI_EVENT_STA_START:
                esp_wifi_connect();
                printf("-------start___connection-------\n");
                break;
            case WIFI_EVENT_SCAN_DONE:
                printf("-------WIFI_EVENT_SCAN_DONE-------\n");
                break;
            case WIFI_EVENT_STA_STOP:
                printf("-------WIFI_EVENT_STA_STOP-------\n");
                break;
            case WIFI_EVENT_STA_CONNECTED:
                printf("-------connected-------\n");
                break;
            case WIFI_EVENT_STA_DISCONNECTED:
                printf("-------WIFI_EVENT_STA_DISCONNECTED-------\n");
                break;
        }
    } else if (event_base == IP_EVENT) {
        printf("-------IP___EVENT-------\n");
        ip_event_got_ip_t* ip_info = (ip_event_got_ip_t*) event_data;
        char buf[50];
        bzero(buf, 50);
        esp_ip4addr_ntoa(&(ip_info->ip_info.ip), buf, 50);
        printf("%s\n", buf);
    }
}

void wifi_init() {
    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();

    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();
    esp_wifi_init(&wifi_config);
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();
}
