#include "wifi_communications.h"

void wifi_handle_event_cb(System_Event_t *evt)
{
    printf("event %x\n", evt->event_id);
    
    switch (evt->event_id) {
         case EVENT_STAMODE_CONNECTED:
             printf("connect to ssid %s, channel %d\n",
             evt->event_info.connected.ssid,
             evt->event_info.connected.channel);
             break;
         case EVENT_STAMODE_DISCONNECTED:
             printf("disconnect from ssid %s, reason %d\n",
             evt->event_info.disconnected.ssid,
             evt->event_info.disconnected.reason);
             break;
         case EVENT_STAMODE_AUTHMODE_CHANGE:
             printf("mode: %d -> %d\n",
             evt->event_info.auth_change.old_mode,
             evt->event_info.auth_change.new_mode);
             break;
         case EVENT_STAMODE_GOT_IP:
             printf("ip:" IPSTR ",mask:" IPSTR ",gw:" IPSTR,
             IP2STR(&evt->event_info.got_ip.ip),
             IP2STR(&evt->event_info.got_ip.mask),
             IP2STR(&evt->event_info.got_ip.gw));
             printf("\n");
             break;
         case EVENT_SOFTAPMODE_STADISCONNECTED:
             printf("EVENT_SOFTAPMODE_STADISCONNECTED");
             break;
         default:
             break;
 }
} 

void conn_AP_Init(void)
{
	wifi_set_opmode(STATIONAP_MODE);
	struct station_config config;
	memset(&config,0,sizeof(config));  //set value of config from address of &config to width of size to be value '0'
	
	sprintf(config.ssid, AP_SSID);
	sprintf(config.password, AP_PASSWORD);
	
	wifi_station_set_config(&config);         
	
	wifi_set_event_handler_cb(wifi_handle_event_cb);
	wifi_station_connect();
}