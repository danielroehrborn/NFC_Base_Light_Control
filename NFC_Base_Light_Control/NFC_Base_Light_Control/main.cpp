#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <Windows.h>
#include <math.h>
#include "libusb.h"
//#include <unistd.h>
#include "InfinityPortal.h"
#include "SkylandersPortal.h"

using namespace std;

/*
*
*/
int main(int argc, char** argv) {

	srand(time(NULL));

	libusb_device** devices;
	libusb_context* context;
	struct libusb_device_handle* tryDeviceHandler;

	libusb_init(&context);
	int devicesCount = libusb_get_device_list(context, &devices);

	struct libusb_device_descriptor descriptor;
	libusb_device_handle* deviceHandler = NULL;

	int retVal = 0;
	int skylanderPortalIds[0xff];
	int infinityPortalIds[0xff];
	int skylanderPortalCount = 0;
	int infinityPortalCount = 0;

	for (int i = 0; i < devicesCount; i++) {

		retVal = libusb_open(devices[i], &tryDeviceHandler);

		if (retVal < 0) {
			continue;
		}


		unsigned char* data = NULL;
		/*	libusb_device_handle *dev_handle,
			uint8_t request_type,
			uint8_t bRequest,
			uint16_t wValue,
			uint16_t wIndex,
			unsigned char *data,
			uint16_t wLength,
			unsigned int timeout);*/
		retVal = libusb_control_transfer(deviceHandler,
			LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_IN,
			0x09,
			(2 << 8) | 'C',
			0,
			(unsigned char *)data, 32,
			50);



		int len;
		retVal = libusb_bulk_transfer(deviceHandler, 0x81, data, 32, &len, 100);



		libusb_get_device_descriptor(devices[i], &descriptor);

		if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x0129) {

			printf("Found infinity portal at %d\n", i);

			infinityPortalIds[infinityPortalCount] = i;
			infinityPortalCount++;

		}
		else if (descriptor.idVendor == 0x1430 && descriptor.idProduct == 0x150) {

			printf("Found skylander portal at %d\n", i);

			skylanderPortalIds[skylanderPortalCount] = i;
			skylanderPortalCount++;
		}
	}

	if (skylanderPortalCount == 0 && infinityPortalCount == 0) {
		printf("Please plug in either a Portal of Power or an Infinity Base\n");
		return -1;
	}

	InfinityPortal infinityPortals[5/*infinityPortalCount*/];
	SkylandersPortal skylanderPortals[5/*skylanderPortalCount*/];

	int j;

	for (j = 0; j < infinityPortalCount; j++) {
		infinityPortals[j] = InfinityPortal(infinityPortalIds[j]);
	}

	for (j = 0; j < skylanderPortalCount; j++) {
		skylanderPortals[j] = SkylandersPortal(skylanderPortalIds[j]);
	}

	printf("Starting light show\n");

	while (true) {

		for (j = 0; j < max(skylanderPortalCount, infinityPortalCount); j++) {

			if (j < skylanderPortalCount) {
				// printf("Doing %d\n",j);
				skylanderPortals[j].setColour(std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				// skylanderPortals[j].setLeftColour(random()%0x100,random()%0x100,random()%0x100);
				// skylanderPortals[j].setRightColour(random()%0x100,random()%0x100,random()%0x100);
				// skylanderPortals[j].flashTrapLight();
				// skylanderPortals[j].writeMaskerMind();
				return 0;
			}

			if (j < infinityPortalCount) {
				for (int k = 0; k < 3; k++) {
					infinityPortals[j].setColour(k + 1, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				}
			}
		}
		Sleep(100);
		//usleep(100000);
	}


	printf("Done!\n");
	return 0;
}
