#ifndef ESP_TAP_TO_SERIAL_H
#define ESP_TAP_TO_SERIAL_H

//Wifi Configuration
const char* ssid = "Wifi Name";
const char* password = "Wifi Password";

//Change the hostname for your server
const char* hostname="espTapToSerial";

//Change the mac address for your server
uint8_t macAddress[] = {0xC2, 0x18, 0x85, 0x58, 0x02, 0x2E};

//Change the port of your server
#define SERVER_PORT 7497

#endif