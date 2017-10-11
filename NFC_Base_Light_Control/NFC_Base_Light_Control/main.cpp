#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>
#include "libusb.h"
//#include <unistd.h>
#include "InfinityPortal.h"
#include "SkylandersPortal.h"
#include "DimensionsPortal.h"

using namespace std;
extern int tutorial();

const char* sBases[4] = { "SkylandersPortal","DisneyInfinityBase","LegoDimensionsBase","Unknown" };
class DeviceInfo {
public:
	enum DeviceType {
		SkylandersPortal,
		DisneyInfinityBase,
		LegoDimensionsBase,
		Unknown
	};
	const unsigned char deviceID;
	const DeviceType type;
};
vector<DeviceInfo> vDevices;
libusb_context* context;
void scanDevices() {
	vDevices.clear();
	libusb_device** devices;
	int devicesCount = libusb_get_device_list(context, &devices);
	libusb_device_descriptor descriptor;
	for (unsigned char i = 0; i < devicesCount; i++) {
		libusb_get_device_descriptor(devices[i], &descriptor);
		if (descriptor.idVendor == 0x1430 && descriptor.idProduct == 0x150)
			vDevices.push_back({ i,DeviceInfo::DeviceType::SkylandersPortal });
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x0129)
			vDevices.push_back({ i,DeviceInfo::DeviceType::DisneyInfinityBase });
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x241)
			vDevices.push_back({ i,DeviceInfo::DeviceType::LegoDimensionsBase });
		else
			vDevices.push_back({ i,DeviceInfo::DeviceType::Unknown });
	}

	//libusb_close(handle);
}

int mainx(int argc, char** argv) {
	libusb_init(&context);
	scanDevices();
	printf("Devices list:\n");
	for (std::vector<DeviceInfo>::iterator it = vDevices.begin(); it != vDevices.end(); ++it) {
		printf("Device %d %s\n", it->deviceID, sBases[it->type]);
	}
	cout << "Auswahl: ";
	int input;
	cin >> input;
	if (vDevices[input].deviceID == Unknown) cout << "error" << endl;
	switch (vDevices[input].deviceID) {
	case DeviceInfo::DeviceType::SkylandersPortal:
		cout << "SkylandersPortal" << endl; break;
	case DeviceInfo::DeviceType::DisneyInfinityBase:
		cout << "DisneyInfinityBase" << endl;
		for (int i = 0; i < InfinityPortal::numFunctions; ++i) {
			printf("%d: %s\n", i, InfinityPortal::functionNames[i]);
		}
		cout << "Auswahl: ";
		cin >> input;
		switch (input) {
		case 0://activate
			break;
		case 1://setColour
			break;
		case 2://flashColour
			break;
		case 3://fadeColour
			break;
		case 4://getTagId
			break;
		default:
			cout << "Unknown" << endl;
		}
		break;
	case DeviceInfo::DeviceType::LegoDimensionsBase:
		cout << "LegoDimensionsBase" << endl;
		for (int i = 0; i < DimensionsPortal::numFunctions; ++i) {
			printf("%d: %s\n", i, DimensionsPortal::functionNames[i]);
		}
		break;
	default:
		cout << "Unbekanntes ausgewählt" << endl;
	}
	libusb_exit(context);
	return 0;
}

int main(int argc, char** argv) {
	//tutorial();
	//return 0;	
	libusb_init(&context);

	srand(time(NULL));
	libusb_device** devices;
	struct libusb_device_handle* tryDeviceHandler;
	int devicesCount = libusb_get_device_list(context, &devices);

	struct libusb_device_descriptor descriptor;
	libusb_device_handle* deviceHandler = NULL;

	int retVal = 0;
	int skylanderPortalIds[0xff];
	int infinityPortalIds[0xff];
	int dimensionsPortalIds[0xff];
	int skylanderPortalCount = 0;
	int infinityPortalCount = 0;
	int dimensionsPortalCount = 0;

	for (int i = 0; i < devicesCount; i++) {

		retVal = libusb_open(devices[i], &tryDeviceHandler);

		if (retVal < 0) {
			continue;
		}


		libusb_get_device_descriptor(devices[i], &descriptor);

		printf("Device %d: VendorID: %X, ProductID: %X\n", i, descriptor.idVendor, descriptor.idProduct);

		if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x0129) {

			printf("Found infinity portal at %d\n", i);

			infinityPortalIds[infinityPortalCount] = i;
			infinityPortalCount++;

		}
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x241) {

			printf("Found Lego Dimensions portal at %d\n", i);

			dimensionsPortalIds[dimensionsPortalCount] = i;
			dimensionsPortalCount++;
		}
		else if (descriptor.idVendor == 0x1430 && descriptor.idProduct == 0x150) {

			printf("Found skylander portal at %d\n", i);

			skylanderPortalIds[skylanderPortalCount] = i;
			skylanderPortalCount++;
		}
	}

	if (skylanderPortalCount == 0 && infinityPortalCount == 0 && dimensionsPortalCount == 0) {
		printf("Please plug in either a Portal of Power, an Infinity Base or an Lego Dimensions Base\n");
		return -1;
	}

	InfinityPortal infinityPortals[5/*infinityPortalCount*/];
	SkylandersPortal skylanderPortals[5/*skylanderPortalCount*/];
	DimensionsPortal dimensionsPortals[5];

	int j;

	for (j = 0; j < infinityPortalCount; j++) {
		infinityPortals[j] = InfinityPortal(infinityPortalIds[j]);
	}

	for (j = 0; j < skylanderPortalCount; j++) {
		skylanderPortals[j] = SkylandersPortal(skylanderPortalIds[j]);
	}
	for (j = 0; j < dimensionsPortalCount; j++) {
		dimensionsPortals[j] = DimensionsPortal(dimensionsPortalIds[j]);
	}

	printf("Starting light show\n");

	//while (true) {

	for (j = 0; j < max(dimensionsPortalCount, max(skylanderPortalCount, infinityPortalCount)); j++) {

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
				//infinityPortals[j].setColour(k + 1, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				infinityPortals[j].setColour(k + 1, 10, 10, 10);
			}
		}

		if (j < dimensionsPortalCount) {
			dimensionsPortals[j].fadeColour(1, 20, 0, 0);
			dimensionsPortals[j].fadeColour(2, 0, 20, 0);
			dimensionsPortals[j].fadeColour(3, 0, 0, 20);
			dimensionsPortals[j].flashColour(1, 20, 20, 0);
			dimensionsPortals[j].flashColour(2, 0, 20, 20);
			dimensionsPortals[j].flashColour(3, 20, 0, 20);
			for (int k = 0; k < 3; k++) {
				//dimensionsPortals[j].setColour(k + 1, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				dimensionsPortals[j].setColour(k + 1, 1, 1, 1);
			}
		}
	}
	Sleep(100);
	//usleep(100000);
//}


	libusb_exit(context);
	printf("Done!\n");
	return 0;
}
