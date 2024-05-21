#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

void message();
void test_wifi_status();
bool test_get_ssid();
uint8_t test_scan_for_networks();
void test_get_scan_result(uint8_t i);
void test_set_ssid();
void test_fuji_mount_host_slot(uint8_t hs);
void test_fuji_open_directory(uint8_t hs, char *path, char *filter);

#endif // MAIN_H
