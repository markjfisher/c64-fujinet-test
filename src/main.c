#include <conio.h>
#include <stdio.h>
#include "fujinet-fuji.h"

#include "main.h"

NetConfig nc;
SSIDInfo info;

int main() {
	uint8_t r = 0;
	uint8_t i = 0;

	message();

	test_wifi_status();
	test_get_ssid();
	r = test_scan_for_networks();
	for (i = 0; i < r; i++) {
		test_get_scan_result(i);
	}

	return 0;
}

void test_get_scan_result(uint8_t i) {
	if (!fuji_get_scan_result(i, &info)) {
		printf("Failed to get scan result for index: %d\n", i);
		return;
	}

	printf("ssid info:\n");
	printf("  ssid: %s\n", info.ssid);
	printf("  rssi: %02x\n", (uint8_t)(info.rssi) & 0xFF);
}

uint8_t test_scan_for_networks() {
	uint8_t wifi_count = 0;
	bool is_success = false;

	is_success = fuji_scan_for_networks(&wifi_count);
	if (!is_success) {
		printf("failed scan_for_networks\n");
		return 0;
	}

	printf("wifi_count = %d\n", wifi_count);
	return wifi_count;
}


void test_get_ssid() {
	bool is_success = false;
	is_success = fuji_get_ssid(&nc);
	if (!is_success) {
		printf("failed to get ssid\n");
	} else {
		printf("ssid info:\n");
		printf("  ssid: %s\n", nc.ssid);
		printf("  pass: %s\n", nc.password);
	}
}

void test_wifi_status() {
	uint8_t wifi_status = 0;
	bool is_success = false;

	if (!fuji_get_wifi_status(&wifi_status)) {
		printf("failed to get wifi_status\n");
	} else {
		printf("wifi_status passed\n");
	}
}

void message() {
	printf("Testing fujinet-lib\n");
}