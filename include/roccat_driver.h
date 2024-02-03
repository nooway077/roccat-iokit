#ifndef ROCCAT_DRIVER_H_
#define ROCCAT_DRIVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <IOKit/IOKitLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>
#include "device.h"

IOReturn send_control_msg(IOUSBDeviceInterface **dev, void const *data);

void set_illumination_brightness_to_max(IOUSBDeviceInterface **usb_dev);
void set_illumination_brightness_to_zero(IOUSBDeviceInterface **usb_dev);
void set_illumination_brightness_to_level(IOUSBDeviceInterface **usb_dev, int level);

void set_illumination_color(IOUSBDeviceInterface **usb_dev, int location, int intensity, unsigned char red, unsigned char green, unsigned char blue);
void set_illumination_brightness_and_color_all(IOUSBDeviceInterface **usb_dev, int brightness_level, int color_intensity, unsigned char red, unsigned char green, unsigned char blue);

#endif