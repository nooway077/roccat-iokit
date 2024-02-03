#include <stdio.h>

#include <IOKit/IOKitLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>

typedef struct {
    IOUSBDeviceInterface **usbDevice;
    UInt16 productId;
    int internalDeviceId;
} IODevice;

IOUSBDeviceInterface **getIOUSBDeviceInterface(UInt16 vId, UInt16 pdId);
void closeIOUSBDeviceInterface(IOUSBDeviceInterface **dev);