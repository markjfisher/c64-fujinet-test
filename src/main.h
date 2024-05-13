#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

void message();
void test_wifi_status();
void test_get_ssid();
uint8_t test_scan_for_networks();
void test_get_scan_result(uint8_t i);

#endif // MAIN_H
