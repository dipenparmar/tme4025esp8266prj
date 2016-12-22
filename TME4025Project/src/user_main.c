#include <user_main.h>


//added as per: http://bbs.espressif.com/viewtopic.php?t=2492
uint32 ICACHE_FLASH_ATTR user_rf_cal_sector_set(void)
{
    flash_size_map size_map = system_get_flash_size_map();
    uint32 rf_cal_sec = 0;

    switch (size_map) {
        case FLASH_SIZE_4M_MAP_256_256:
            rf_cal_sec = 128 - 8;
            break;

        case FLASH_SIZE_8M_MAP_512_512:
            rf_cal_sec = 256 - 5;
            break;

        case FLASH_SIZE_16M_MAP_512_512:
        case FLASH_SIZE_16M_MAP_1024_1024:
            rf_cal_sec = 512 - 5;
            break;

        case FLASH_SIZE_32M_MAP_512_512:
        case FLASH_SIZE_32M_MAP_1024_1024:
            rf_cal_sec = 1024 - 5;
            break;

        default:
            rf_cal_sec = 0;
            break;
    }

    return rf_cal_sec;
}

void user_init(void)
   {
        printf("SDK version:%s\n", system_get_sdk_version());
        printf("HI JAMES THis is V4");
        
        /*Init*/
        //Configure Interrupts
        initrelaybutton();
        //Configure WIFI
        connecttowifi();
        //Configure Relay
        initrelaycontrol();
        //Configure Mux
        initmuxcontrol();
 
        //Start Tasks
        StartTasks();
        
    }