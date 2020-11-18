#include "my_wifi.h"

void scan() {
    wifi_scan_config_t wsc_t = {
            .ssid = NULL,
            .bssid = NULL,
            .scan_type = WIFI_SCAN_TYPE_ACTIVE,
    };
    esp_wifi_scan_start(&wsc_t, 1);

    uint16_t a;
    esp_wifi_scan_get_ap_num(&a);

    printf("--------------%d\n", a);

    wifi_ap_record_t war_t[20];

    esp_wifi_scan_get_ap_records(&a, &war_t);

    for (int i = 0; i < a; ++i) {
        printf("%3s %12x:%02x:%02x:%02x:%02x:%02x%12d%12d\n", war_t[i].ssid, war_t[i].bssid[0], war_t[i].bssid[1], war_t[i].bssid[2]
                , war_t[i].bssid[3], war_t[i].bssid[4], war_t[i].bssid[5], war_t[i].rssi, war_t[i].primary);
    }
}