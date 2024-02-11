#ifndef __WIFI_H__
#define __WIFI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef enum {
	WIFI_AP_AUTH_OPEN = 0,         /**< authenticate mode : open */
	WIFI_AP_AUTH_WEP,              /**< authenticate mode : WEP */
	WIFI_AP_AUTH_WPA_PSK,          /**< authenticate mode : WPA_PSK */
	WIFI_AP_AUTH_WPA2_PSK,         /**< authenticate mode : WPA2_PSK */
	WIFI_AP_AUTH_WPA_WPA2_PSK,     /**< authenticate mode : WPA_WPA2_PSK */
	WIFI_AP_AUTH_WPA2_ENTERPRISE,  /**< authenticate mode : WPA2_ENTERPRISE */
	WIFI_AP_AUTH_WPA3_PSK,         /**< authenticate mode : WPA3_PSK */
	WIFI_AP_AUTH_WPA2_WPA3_PSK,    /**< authenticate mode : WPA2_WPA3_PSK */
	WIFI_AP_AUTH_WAPI_PSK,         /**< authenticate mode : WAPI_PSK */
	WIFI_AP_AUTH_OWE,              /**< authenticate mode : OWE */
	WIFI_AP_AUTH_MAX
} wifi_ap_auth_t;

typedef struct {
	const char *uuid;
	const char *pass;
	wifi_ap_auth_t auth;
} wifi_credentials_t;

/**
 * @brief Connect to most powerfull access point in the list.
 *
 * @param[in]	ap_list		Access points list.
 * @param[in]	size		Number of elements in the list.
 */
void wifi_start(wifi_credentials_t *ap_list, int size);

/**
 * @brief Connect to server.
 *
 * @param[out] socketfd	Pointer to socket file descriptor.
 * @param[in] server_ip	Pointer to server IP address string.
 * @param[in] port	Server port number.
 *
 * @return int		0 on success, error code on error.
 */
int connect_to_server(int *socketfd, const char *server_ip, uint32_t port);

/**
 * @brief Connect to server from list.
 *
 * @param[out] socketfd		Pointer to socket file descriptor.
 * @param[in] server_ip_list	Pointer to server IP address strings list.
 * @param[in] list_size		List size.
 * @param[in] port	Server port number.
 *
 * @return int		0 on success, error code on error.
 */
int connect_to_server_from_list(int *socketfd,
				const char *server_ip_list[],
				int list_size,
				uint32_t port);

/**
 * @brief Check wifi is connected.
 *
 * @return true if connected.
 * @return false if not connected.
 */
bool wifi_is_connected(void);

/**
 * @brief Stop wifi and release resources.
 */
void wifi_stop(void);

/**
 * @brief Get currently used wifi AP uuid name.
 *
 * @return char* Pointer to string.
 */
const char *wifi_get_current_uuid(void);

/**
 * @brief Get wifi adapter mac address.
 *
 * @return Pointer to mac address string.
 */
const uint8_t *wifi_get_mac(void);

/**
 * @brief Get IPv4 address.
 *
 * @return Pointer to IP address string.
 */
const char *wifi_get_ip(void);

/**
 * @brief Set hostname.
 *
 * @param new_name Pointer to string name.
 */
void wifi_set_hostname(const char *new_name);

#ifdef __cplusplus
}
#endif

#endif /* __WIFI_H__ */
