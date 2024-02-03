#include "roccat_driver.h"
#include "device.h"

illumination_payload ilp = {
    .b0 = 0x06, .b1 = 0x7e, .b2 = 0x00, .b3 = 0x06, .b4 = 0x04, .b5 = 0x02, .b6 = 0x08, .b7 = 0x00, .b8 = 0x10, .b9 = 0x00, .b10 = 0x18, .b11 = 0x00, .b12 = 0x20, .b13 = 0x00, .b14 = 0x40, .b15 = 0x00, 
    .b16 = 0x08, .b17 = 0x00, .b18 = 0x10, .b19 = 0x00, .b20 = 0x18, .b21 = 0x00, .b22 = 0x20, .b23 = 0x00, .b24 = 0x40, .b25 = 0x00, .b26 = 0x03, .b27 = 0x00, .b28 = 0x00, .b29 = 0x08, .b30 = 0xff, .b31 = 0x07, 
    .b32 = 0x00, .b33 = 0x01, .b34 = 0x05, .b35 = 0x00, .b36 = 0x1d, .b37 = 0x13, .b38 = 0xff, .b39 = 0x00, .b40 = 0xff, .b41 = 0x59, .b42 = 0xff, .b43 = 0x00, .b44 = 0x00, .b45 = 0xff, .b46 = 0xfd, .b47 = 0xfd, 
    .b48 = 0x00, .b49 = 0x00, .b50 = 0xff, .b51 = 0xf4, .b52 = 0x64, .b53 = 0x00, .b54 = 0x00, .b55 = 0xff, .b56 = 0xf4, .b57 = 0x00, .b58 = 0x00, .b59 = 0x00, .b60 = 0xff, .b65 = 0x00, .b70 = 0x00, .b75 = 0x00,
    .b80 = 0x00, .b85 = 0x00, .b90 = 0x00, .b95 = 0x00, 
    .b100 = 0x00, .b105 = 0x00, .b110 = 0x00, .b115 = 0x00, .b116 = 0x01, .b117 = 0x01, .b118 = 0x00, .b119 = 0x00, .b120 = 0x00, .b121 = 0x00, .b122 = 0x00, .b123 = 0x00, .b124 = 0x0e, .b125 = 0x28};


IOReturn send_control_msg(IOUSBDeviceInterface **dev, void const *data)
{
    IOUSBDevRequest request;

    request.bRequest = USBHID_SET_REPORT_REQ;
    request.bmRequestType = USBHID_SET_REPORT_REQ_TYPE;
    request.wValue = USBHID_SET_REPORT_REQ_VAL;
    request.wIndex = USBHID_SET_REPORT_REQ_INDEX;
    request.wLength = USBHID_SET_REPORT_REQ_LEN;
    request.pData = (void *)data;

    return (*dev)->DeviceRequest(dev, &request);
}

// void set_illumination_brightness_to_max(IOUSBDeviceInterface **usb_dev)
// {
//     illumination_control_payload.b35=0xff;
//     send_control_msg(usb_dev, &illumination_control_payload);
// }

// void set_illumination_brightness_to_zero(IOUSBDeviceInterface **usb_dev)
// {
//     illumination_control_payload.b35=0x00;
//     send_control_msg(usb_dev, &illumination_control_payload);
// }

// void set_illumination_brightness_to_level(IOUSBDeviceInterface **usb_dev, int level)
// {
//     illumination_control_payload.b35=(unsigned int)level;
//     send_control_msg(usb_dev, &illumination_control_payload);
// }

void set_illumination_color(IOUSBDeviceInterface **usb_dev, int location, int intensity, unsigned char red, unsigned char green, unsigned char blue)
{
    switch (location)
    {
    case SCROLL_WHEEL_LED:
        ilp.LED_CTRL_SCRLW.i = (unsigned)intensity;
        ilp.LED_CTRL_SCRLW.r = red;
        ilp.LED_CTRL_SCRLW.g = green;
        ilp.LED_CTRL_SCRLW.b = blue;
        break;

    case LEFT_SIDE_TOP_LED:
        ilp.LED_CTRL_LEFT_SIDE_TOP.i = (unsigned)intensity;
        ilp.LED_CTRL_LEFT_SIDE_TOP.r = red;
        ilp.LED_CTRL_LEFT_SIDE_TOP.g = green;
        ilp.LED_CTRL_LEFT_SIDE_TOP.b = blue;
        break;

    case LEFT_SIDE_MIDDLE_UP_LED:
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.i = (unsigned)intensity;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.r = red;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.g = green;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.b = blue;
        break;

     case LEFT_SIDE_MIDDLE_LED:
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE.i = (unsigned)intensity;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE.r = red;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE.g = green;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE.b = blue;
        break;

    case LEFT_SIDE_MIDDLE_DOWN_LED:
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.i = (unsigned)intensity;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.r = red;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.g = green;
        ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.b = blue;
        break;

     case LEFT_SIDE_BOTTOM_LED:
        ilp.LED_CTRL_LEFT_SIDE_BOTTOM.i = (unsigned)intensity;
        ilp.LED_CTRL_LEFT_SIDE_BOTTOM.r = red;
        ilp.LED_CTRL_LEFT_SIDE_BOTTOM.g = green;
        ilp.LED_CTRL_LEFT_SIDE_BOTTOM.b = blue;
        break;

    case RIGHT_SIDE_TOP_LED:
        ilp.LED_CTRL_RIGHT_SIDE_TOP.i = (unsigned)intensity;
        ilp.LED_CTRL_RIGHT_SIDE_TOP.r = red;
        ilp.LED_CTRL_RIGHT_SIDE_TOP.g = green;
        ilp.LED_CTRL_RIGHT_SIDE_TOP.b = blue;
        break;
    
    case RIGHT_SIDE_MIDDLE_UP_LED:
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.i = (unsigned)intensity;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.r = red;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.g = green;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.b = blue;
        break;

    case RIGHT_SIDE_MIDDLE_LED:
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.i = (unsigned)intensity;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.r = red;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.g = green;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.b = blue;
        break;

    case RIGHT_SIDE_MIDDLE_DOWN_LED:
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.i = (unsigned)intensity;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.r = red;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.g = green;
        ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.b = blue;
        break;

    case RIGHT_SIDE_BOTTOM_LED:
        ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.i = (unsigned)intensity;
        ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.r = red;
        ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.g = green;
        ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.b = blue;
        break;
    }     

    ilp.b35 = (unsigned char)0xdff;    // max out the brightness

    send_control_msg(usb_dev, &ilp);
}

void set_illumination_brightness_and_color_all(IOUSBDeviceInterface **usb_dev, int brightness_level, int color_intensity, unsigned char red, unsigned char green, unsigned char blue)
{
    ilp.LED_CTRL_SCRLW.i = (unsigned)color_intensity;
    ilp.LED_CTRL_SCRLW.r = red;
    ilp.LED_CTRL_SCRLW.g = green;
    ilp.LED_CTRL_SCRLW.b = blue;

    ilp.LED_CTRL_LEFT_SIDE_TOP.i = (unsigned)color_intensity;
    ilp.LED_CTRL_LEFT_SIDE_TOP.r = red;
    ilp.LED_CTRL_LEFT_SIDE_TOP.g = green;
    ilp.LED_CTRL_LEFT_SIDE_TOP.b = blue;

    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.i = (unsigned)color_intensity;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.r = red;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.g = green;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.b = blue;

    ilp.LED_CTRL_LEFT_SIDE_MIDDLE.i = (unsigned)color_intensity;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE.r = red;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE.g = green;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE.b = blue;

    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.i = (unsigned)color_intensity;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.r = red;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.g = green;
    ilp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.b = blue;

    ilp.LED_CTRL_LEFT_SIDE_BOTTOM.i = (unsigned)color_intensity;
    ilp.LED_CTRL_LEFT_SIDE_BOTTOM.r = red;
    ilp.LED_CTRL_LEFT_SIDE_BOTTOM.g = green;
    ilp.LED_CTRL_LEFT_SIDE_BOTTOM.b = blue;

    ilp.LED_CTRL_RIGHT_SIDE_TOP.i = (unsigned)color_intensity;
    ilp.LED_CTRL_RIGHT_SIDE_TOP.r = red;
    ilp.LED_CTRL_RIGHT_SIDE_TOP.g = green;
    ilp.LED_CTRL_RIGHT_SIDE_TOP.b = blue;

    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.i = (unsigned)color_intensity;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.r = red;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.g = green;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.b = blue;

    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.i = (unsigned)color_intensity;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.r = red;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.g = green;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE.b = blue;

    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.i = (unsigned)color_intensity;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.r = red;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.g = green;
    ilp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.b = blue;

    ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.i = (unsigned)color_intensity;
    ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.r = red;
    ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.g = green;
    ilp.LED_CTRL_RIGHT_SIDE_BOTTOM.b = blue;

    ilp.b35=(unsigned int)brightness_level;
    send_control_msg(usb_dev, &ilp);
}