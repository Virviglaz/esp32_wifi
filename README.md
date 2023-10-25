# esp32_wifi
ESP32 Wifi C helper file

Description: This source file helps your project to connect to wifi access point.
User provides a list of access points to connect and the most powerfull AP will be used when available.

## Example of used
### List of APs
~~~cpp
wifi_credentials_t wifi_aps[] = {
	{ "Example_ap1",	"passwd123",	WIFI_AP_AUTH_WPA2_PSK },
	{ "Example_ap2",	"passwd123",	WIFI_AP_AUTH_WPA2_PSK },
	{ "Example_ap3",	"passwd123",	WIFI_AP_AUTH_WPA3_PSK },
};
~~~

### Initiate connection (non-blocking call)
~~~cpp
wifi_start(wifi_aps, 3);
~~~

### Connect socket
User may periodically check when wifi becomes available.
~~~cpp
int sock;
if (wifi_is_connected())
	int err = connect_to_server(&sock, "192.168.0.1", 80);
~~~