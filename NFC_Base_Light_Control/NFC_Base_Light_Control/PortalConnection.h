#pragma once
#include "libusb.h"
class PortalConnection {
	libusb_device_handle* deviceHandle;
public:
	PortalConnection();
	libusb_error connect(libusb_device* device, int interfaceNum = 0);
	libusb_error openDevice(libusb_device* device);
	libusb_error claimOpenedDevice(int interfaceNum = 0);
	libusb_error transceiveData(unsigned char *data, unsigned char endpoint = 0x01, int length = 32, int* actualLen = NULL, unsigned int timeout = 100);
	~PortalConnection();
};