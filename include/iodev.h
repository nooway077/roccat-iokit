#include <IOKit/IOKitLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>

typedef struct {
    IOUSBDeviceInterface **usbDevice;
    UInt16 productId;
    int internalDeviceId;
} IODevice;

IOUSBDeviceInterface **getIOUSBDeviceInterface(unsigned char vId, unsigned char pdId);
void closeIOUSBDeviceInterface(IOUSBDeviceInterface **dev);