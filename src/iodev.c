#include "iodev.h"

IOUSBDeviceInterface **getIOUSBDeviceInterface(UInt16 vId, UInt16 pdId)
{
    CFMutableDictionaryRef matchingDict;
	matchingDict = IOServiceMatching(kIOUSBDeviceClassName);
	if (matchingDict == NULL)
	{
		return NULL;
	}

    io_iterator_t iter;
	kern_return_t kReturn =
		IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDict, &iter);
	if (kReturn != kIOReturnSuccess)
	{
		return NULL;
	}

    io_service_t usbDevice;
    while ((usbDevice = IOIteratorNext(iter)))
    {
        IOCFPlugInInterface **plugInInterface = NULL;
		SInt32 score;

		kReturn = IOCreatePlugInInterfaceForService(
			usbDevice, kIOUSBDeviceUserClientTypeID, kIOCFPlugInInterfaceID, &plugInInterface, &score);

		IOObjectRelease(usbDevice);
		if ((kReturn != kIOReturnSuccess) || plugInInterface == NULL)
		{
			continue;
		}

        IOUSBDeviceInterface **dev = NULL;
		HRESULT hResult = (*plugInInterface)->QueryInterface(plugInInterface, CFUUIDGetUUIDBytes(kIOUSBDeviceInterfaceID), (LPVOID *)&dev);

        (*plugInInterface)->Release(plugInInterface);
		if (hResult || !dev)
		{
			continue;
		}
        
        kern_return_t kr;
        UInt16 vendorId, productId;

        kr = (*dev)->GetDeviceVendor(dev, &vendorId);
        kr = (*dev)->GetDeviceProduct(dev, &productId);

        if (vendorId != vId)
        {
            (*dev)->Release(dev);
			continue;
        }

        if (productId != pdId)
        {
            (*dev)->Release(dev);
			continue;
        }

        kReturn = (*dev)->USBDeviceOpen(dev);
		if (kReturn != kIOReturnSuccess)
		{
			printf("Unable to open USB device: %08x\n", kReturn);
			(*dev)->Release(dev);
			continue;
		}

		IOObjectRelease(iter);
		return dev;
    }

    IOObjectRelease(iter);
    return NULL;
}

void closeIOUSBDeviceInterface(IOUSBDeviceInterface **dev)
{
    kern_return_t kr;
	kr = (*dev)->USBDeviceClose(dev);
	kr = (*dev)->Release(dev);
}