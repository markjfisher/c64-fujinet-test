#include <conio.h>
#include <stdio.h>
#include "fujinet-fuji.h"

#include "main.h"

NetConfig nc;
SSIDInfo info;

int main() {
	bool got_ssid = false;
	uint8_t r = 0;
	uint8_t i = 0;

	message();

	// test_wifi_status();
	// got_ssid = test_get_ssid();
	// if (got_ssid) test_set_ssid(&nc);

	// r = test_scan_for_networks();
	// for (i = 0; i < r; i++) {
	// 	test_get_scan_result(i);
	// }

	// test_fuji_mount_host_slot(2);
	// test_fuji_mount_host_slot(7);

	test_fuji_mount_host_slot(0);
#include <ascii_charmap.h>
	test_fuji_open_directory(0, "/c64/", "t*");
#include <cbm_petscii_charmap.h>

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


bool test_get_ssid() {
	bool is_success = false;
	is_success = fuji_get_ssid(&nc);
	if (!is_success) {
		printf("failed to get ssid\n");
	} else {
		printf("ssid info:\n");
		printf("  ssid: %s\n", nc.ssid);
		printf("  pass: %s\n", nc.password);
	}
	return is_success;
}

void test_wifi_status() {
	uint8_t wifi_status = 0;
	bool is_success = false;

	if (!fuji_get_wifi_status(&wifi_status)) {
		printf("failed to get wifi_status\n");
	} else {
		printf("wifi_status: %d\n", wifi_status);
	}
}

void test_set_ssid() {
	// nc already set
	bool is_success = false;

	printf("Setting ssid...\n");
	is_success = fuji_set_ssid(&nc);
	if (is_success) {
		printf("wrote ssid successfully\n");
	} else {
		printf("failed to set ssid\n");
	}
}

void test_fuji_mount_host_slot(uint8_t hs) {
	bool is_success = false;

	printf("mounting host slot %d\n", hs);
	is_success = fuji_mount_host_slot(hs);
	if (is_success) {
		printf("success\n");
	} else {
		printf("failed\n");
	}
}

void test_fuji_open_directory(uint8_t hs, char *path, char *filter) {
	bool is_success = false;

	printf("opening %s on hs %d\n", path, hs);
	if (filter != NULL) {
		printf("filter set: %s\n", filter);
	}

	is_success = fuji_open_directory2(hs, path, filter);
	if (is_success) {
		printf("success\n");
	} else {
		printf("failed\n");
	}
}

void message() {
	printf("Testing fujinet-lib\n");
}