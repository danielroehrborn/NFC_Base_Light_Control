#include <stdio.h>
#include "PortalConnection.h";
PortalConnection::PortalConnection() {
	deviceHandle = NULL;
}
libusb_error PortalConnection::connect(libusb_device* device, int interfaceNum) {
	/*if (deviceHandle != NULL) {
	libusb_close(deviceHandle);
	deviceHandle = NULL;
	}
	//get device handle
	libusb_error ret = (libusb_error)libusb_open(device, &deviceHandle);
	if (ret != LIBUSB_SUCCESS) {
	printf("Open device: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}
	//detach kernel from device
	if (libusb_kernel_driver_active(deviceHandle, 0) == 1) {
	ret = (libusb_error)libusb_detach_kernel_driver(deviceHandle, 0);
	if (ret != LIBUSB_SUCCESS) {
	printf("Detach kernel driver: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}
	}
	//claim device interface0
	ret = (libusb_error)libusb_claim_interface(deviceHandle, interfaceNum);
	if (ret != LIBUSB_SUCCESS) {
	printf("Claim interface%d: %s\n\t%s\n", interfaceNum, libusb_error_name(ret), libusb_strerror(ret));
	}*/
	libusb_error ret = openDevice(device);
	if (ret == LIBUSB_SUCCESS)
		ret = claimOpenedDevice(interfaceNum);
	return ret;
}
libusb_error PortalConnection::openDevice(libusb_device * device)
{
	if (deviceHandle != NULL) {
		libusb_close(deviceHandle);
		deviceHandle = NULL;
	}
	//get device handle
	libusb_error ret = (libusb_error)libusb_open(device, &deviceHandle);
	if (ret != LIBUSB_SUCCESS) {
		printf("Open device: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}
	return ret;
}
libusb_error PortalConnection::claimOpenedDevice(int interfaceNum)
{
	libusb_error ret;
	//detach kernel from device
	if (libusb_kernel_driver_active(deviceHandle, 0) == 1) {
		ret = (libusb_error)libusb_detach_kernel_driver(deviceHandle, 0);
		if (ret != LIBUSB_SUCCESS) {
			printf("Detach kernel driver: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
		}
	}
	//claim device interface0
	ret = (libusb_error)libusb_claim_interface(deviceHandle, interfaceNum);
	if (ret != LIBUSB_SUCCESS) {
		printf("Claim interface%d: %s\n\t%s\n", interfaceNum, libusb_error_name(ret), libusb_strerror(ret));
	}
	return ret;
}
libusb_error PortalConnection::transceiveData(unsigned char *data, unsigned char endpoint, int length, unsigned int timeout) {
	int actual_length = 0;
	libusb_error ret = (libusb_error)libusb_bulk_transfer(deviceHandle, endpoint, data, length, &actual_length, timeout);
	/*if (ret == LIBUSB_SUCCESS) {
		printf("Transmitted : %d bytes \n", actual_length);
	}
	else {
		printf("Transfer: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}*/
	return ret;
}
PortalConnection::~PortalConnection() {
	libusb_close(deviceHandle);
}