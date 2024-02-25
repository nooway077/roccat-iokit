#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iodev.h"
#include "roccat_driver.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please specify an argument\n");
        return -1;
    }
    if (strncmp(argv[1], "--set_brightness_and_color", 26) == 0)
    {
        int brightness = atoi(argv[2]);
        int color_intensity = atoi(argv[3]);
        int red = atoi(argv[4]);
        int green = atoi(argv[5]);
        int blue = atoi(argv[6]);

        if (!(0 <= brightness && brightness < 101))
        {
           printf("Error, brightness is a percentage, can be 0 to 100\n");
           return -1;
        }
        if (!(0 <= color_intensity && color_intensity < 101))
        {
           printf("Error, color intensity is a percentage, can be 0 to 100\n");
           return -1;
        }
        if (!(0 <= red && red < 256))
        {
           printf("Error, red is a color value, can be 0 to 255\n");
           return -1;
        }
        if (!(0 <= green && green < 256))
        {
           printf("Error, green is a color value, can be 0 to 255\n");
           return -1;
        }
        if (!(0 <= blue && blue < 256))
        {
           printf("Error, blue is a color value, can be 0 to 255\n");
           return -1;
        }

        UInt16 vId = getVendorId();
        UInt16 pId = getProductId();

        IOUSBDeviceInterface **dev = getIOUSBDeviceInterface(vId, pId);
        printf("Looking for compatible usb device ...\n");

        if (dev == NULL)
        {
            printf("No compatible device found\n");
            return -1;
        }

        printf("Device found\n");
        
        set_illumination_brightness_and_color_all(dev, brightness, color_intensity, red, green, blue );
        printf("Set brighness: %d intensity: %d red: %d green: %d blue: %d\n", brightness, color_intensity, red, green, blue);

        printf("Closing connection ...\n");
        closeIOUSBDeviceInterface(dev);
        printf("All OK\n");

        return 0;
    }
    else
    {
        printf("Unknown command\n");
        return -1;
    }
}