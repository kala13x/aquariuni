/*
 * src/aquariuni.c
 *
 *  Copyleft (C)  2015  IliaUni Robotics TeaM
 *
 * Main source file for aquariuni project.
 */


#include "stdinc.h"
#include "dht11.h"
#include "slog.h"
#include "info.h"
#include "lcd.h"

/* Main function */
int main(void)
{
    /* Used variables */
    DHTSensorValues dht;
    char tempstr[128];
    char humstr[128];
    int status, idp = 0;

    /* Greet users */
    greet("AquariUni");

    /* Initialize logger */
    init_slog("aquariuni", "config.cfg", 3);

    /* Set up writing pin */
    status = wiringPiSetup();
    if(status == -1) exit(1);

    /* Initialize modules */
    bzero(tempstr, sizeof(tempstr));
    bzero(humstr, sizeof(humstr));
    init_dht_val(&dht);
    init_lcd(); sleep(1);

    /* Main loop (never ends) */
    while(1)
    {
        /* Read data from Humidity/Temperature sensor */
        status = dht11_read_val(&dht);
        if (status) 
        {
            /* Log in terminal */
            slog(0, SLOG_DEBUG, "Humidity: %d %% Temperature: %d *C", dht.humidity, dht.celsius);

            /* Write data on display */
            sprintf(tempstr, "Temperature: %d", dht.celsius);
            lcd_position (0, 0); lcd_puts(tempstr);
            delay(5);
            sprintf(humstr, "Humidity: %d %%", dht.humidity);
            lcd_position (0, 1); lcd_puts(humstr);
            delay(5);
            idp = 1;
        }
        else 
        {
            slog(0, SLOG_ERROR, "Invalid data from Humidity/Temperature sensor");
            if (!idp) 
            {
                lcd_position(0, 0);
                lcd_puts("Ivalid data");
                delay(5);
            }
        }
        delay(3000);
    }

    return 0;
}