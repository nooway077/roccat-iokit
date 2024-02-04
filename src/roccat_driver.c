#include "roccat_driver.h"
#include "device.h"

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

void set_illumination_color(IOUSBDeviceInterface **usb_dev, int location, int intensity, unsigned char red, unsigned char green, unsigned char blue)
{
    switch (location)
    {
    case SCROLL_WHEEL_LED:
        ilcp.LED_CTRL_SCRLW.i = (unsigned)intensity;
        ilcp.LED_CTRL_SCRLW.r = red;
        ilcp.LED_CTRL_SCRLW.g = green;
        ilcp.LED_CTRL_SCRLW.b = blue;
        break;

    case LEFT_SIDE_TOP_LED:
        ilcp.LED_CTRL_LEFT_SIDE_TOP.i = (unsigned)intensity;
        ilcp.LED_CTRL_LEFT_SIDE_TOP.r = red;
        ilcp.LED_CTRL_LEFT_SIDE_TOP.g = green;
        ilcp.LED_CTRL_LEFT_SIDE_TOP.b = blue;
        break;

    case LEFT_SIDE_MIDDLE_UP_LED:
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.i = (unsigned)intensity;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.r = red;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.g = green;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.b = blue;
        break;

     case LEFT_SIDE_MIDDLE_LED:
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.i = (unsigned)intensity;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.r = red;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.g = green;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.b = blue;
        break;

    case LEFT_SIDE_MIDDLE_DOWN_LED:
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.i = (unsigned)intensity;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.r = red;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.g = green;
        ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.b = blue;
        break;

     case LEFT_SIDE_BOTTOM_LED:
        ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.i = (unsigned)intensity;
        ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.r = red;
        ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.g = green;
        ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.b = blue;
        break;

    case RIGHT_SIDE_TOP_LED:
        ilcp.LED_CTRL_RIGHT_SIDE_TOP.i = (unsigned)intensity;
        ilcp.LED_CTRL_RIGHT_SIDE_TOP.r = red;
        ilcp.LED_CTRL_RIGHT_SIDE_TOP.g = green;
        ilcp.LED_CTRL_RIGHT_SIDE_TOP.b = blue;
        break;
    
    case RIGHT_SIDE_MIDDLE_UP_LED:
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.i = (unsigned)intensity;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.r = red;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.g = green;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.b = blue;
        break;

    case RIGHT_SIDE_MIDDLE_LED:
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.i = (unsigned)intensity;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.r = red;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.g = green;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.b = blue;
        break;

    case RIGHT_SIDE_MIDDLE_DOWN_LED:
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.i = (unsigned)intensity;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.r = red;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.g = green;
        ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.b = blue;
        break;

    case RIGHT_SIDE_BOTTOM_LED:
        ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.i = (unsigned)intensity;
        ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.r = red;
        ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.g = green;
        ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.b = blue;
        break;
    }     

    ilcp.b35 = (unsigned char)0xdff;    // max out the brightness

    send_control_msg(usb_dev, &ilcp);
}

void set_illumination_brightness_and_color_all(IOUSBDeviceInterface **usb_dev, int brightness_level, int color_intensity, unsigned char red, unsigned char green, unsigned char blue)
{
    ilcp.LED_CTRL_SCRLW.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_SCRLW.r = red;
    ilcp.LED_CTRL_SCRLW.g = green;
    ilcp.LED_CTRL_SCRLW.b = blue;

    ilcp.LED_CTRL_LEFT_SIDE_TOP.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_LEFT_SIDE_TOP.r = red;
    ilcp.LED_CTRL_LEFT_SIDE_TOP.g = green;
    ilcp.LED_CTRL_LEFT_SIDE_TOP.b = blue;

    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.r = red;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.g = green;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_UP.b = blue;

    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.r = red;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.g = green;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE.b = blue;

    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.r = red;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.g = green;
    ilcp.LED_CTRL_LEFT_SIDE_MIDDLE_DOWN.b = blue; 

    ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.r = red;
    ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.g = green;
    ilcp.LED_CTRL_LEFT_SIDE_BOTTOM.b = blue;

    ilcp.LED_CTRL_RIGHT_SIDE_TOP.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_RIGHT_SIDE_TOP.r = red;
    ilcp.LED_CTRL_RIGHT_SIDE_TOP.g = green;
    ilcp.LED_CTRL_RIGHT_SIDE_TOP.b = blue;

    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.r = red;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.g = green;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_UP.b = blue;

    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.r = red;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.g = green;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE.b = blue;

    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.r = red;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.g = green;
    ilcp.LED_CTRL_RIGHT_SIDE_MIDDLE_DOWN.b = blue;

    ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.i = (unsigned)color_intensity;
    ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.r = red;
    ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.g = green;
    ilcp.LED_CTRL_RIGHT_SIDE_BOTTOM.b = blue;

    ilcp.b35=(unsigned int)brightness_level;
    send_control_msg(usb_dev, &ilcp);
}

UInt16 getVendorId()
{
    return USB_VENDOR_ID;
}

UInt16 getProductId()
{
    return USB_DEVICE_ID;
}
