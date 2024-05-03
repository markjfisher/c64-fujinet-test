#include <conio.h>
#include <stdio.h>
#include "fujinet-fuji.h"

#include "main.h"

NetConfig nc;

int main() {
	message();
	test_wifi_status();
	test_get_ssid();
	test_scan_for_networks();
	return 0;
}


void test_scan_for_networks() {
	uint8_t wifi_count = 0;
	bool is_success = false;

	is_success = fuji_scan_for_networks(&wifi_count);
	if (!is_success) {
		printf("failed scan_for_networks\n");
	} else {
		printf("wifi_count = %d\n", wifi_count);
	}
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

	is_success = fuji_get_wifi_status(&wifi_status);
	if (!is_success) {
		printf("failed to get wifi_status\n");
	} else {
		printf("wifi_status = %d\n", wifi_status);
	}
}

void message() {
	printf("Testing fujinet-lib\n");
}