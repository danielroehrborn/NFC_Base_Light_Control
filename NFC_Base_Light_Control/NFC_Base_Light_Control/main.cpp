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
#include "PortalConnection.h"

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
	libusb_init(&context);
	libusb_device** devices;
	int devicesCount = libusb_get_device_list(context, &devices);
	struct libusb_device_descriptor descriptor;
	libusb_device_handle* deviceHandler = NULL;
	for (int i = 0; i < devicesCount; i++) {
		libusb_get_device_descriptor(devices[i], &descriptor);
		if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x241) {
			printf("Found Lego Dimensions portal at %d\n", i);
			PortalConnection ld1;
			libusb_error ret = ld1.connect(devices[i]);
			if (ret != LIBUSB_SUCCESS) {
				printf("LegoDimensionsPortal Connect: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
			}
			else {
				DimensionsPortalInterface* ld1data = new DimensionsPortalInput;
				ret = ld1.transceiveData(ld1data->activate());
				if (ret != LIBUSB_SUCCESS) {
					printf("LegoDimensionsPortal Activate: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				char repeat = 2;
				do {
					ret = ld1.transceiveData(ld1data->fade(Platform::center, { 0,10,1,{ 0,0,0 } }));
					Sleep(250);
					ret = ld1.transceiveData(ld1data->fade(Platform::left, { 0,10,1,{ 0,0,0 } }));
					Sleep(250);
					ret = ld1.transceiveData(ld1data->fade(Platform::right, { 0,10,1,{ 0,0,0 } }));
					Sleep(500);
					ret = ld1.transceiveData(ld1data->fade(Platform::center, { 0,10,1,{ 20,0,0 } }));
					Sleep(250);
					ret = ld1.transceiveData(ld1data->fade(Platform::left, { 0,10,1,{ 0,20,0 } }));
					Sleep(250);
					ret = ld1.transceiveData(ld1data->fade(Platform::right, { 0,10,1,{ 0,0,20 } }));
					Sleep(500);
				} while (repeat--);
				ret = ld1.transceiveData(ld1data->fade(all, { 0,50,0xff,{ 0,0,0 } }));
				delete ld1data;
				DimensionsPortalCommandLineControl cmd;
				cmd.printMenu(&ld1);
			}
		}
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x0129) {
			PortalConnection di1;
			libusb_error ret = di1.connect(devices[i]);
			if (ret != LIBUSB_SUCCESS) {
				printf("DisneyInfinity Connect: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
			}
			else {
				InfinityBaseInput di1data;
				//activate
				printf("Send Activate\n");
				ret = di1.transceiveData(di1data.activate());
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity Activate: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//color all
				printf("Send ColorAll\n");
				ret = di1.transceiveData(di1data.color(InfinityBaseInput::Platform::all, { 10,10,10 }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity ColorAll: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//color center
				printf("Send ColorCenter\n");
				ret = di1.transceiveData(di1data.color(InfinityBaseInput::Platform::center, { 10,0,0 }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity ColorCenter: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//color left
				printf("Send ColorLeft\n");
				ret = di1.transceiveData(di1data.color(InfinityBaseInput::Platform::left, { 0,10,0 }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity ColorLeft: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//color right
				printf("Send ColorRight\n");
				ret = di1.transceiveData(di1data.color(InfinityBaseInput::Platform::right, { 0,0,10 }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity ColorRight: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//fade all
				printf("Send FadeAll\n");
				ret = di1.transceiveData(di1data.fade(InfinityBaseInput::Platform::all, { 20,2, {0,0,0} }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FadeAll: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//fade center
				printf("Send FadeCenter\n");
				ret = di1.transceiveData(di1data.fade(InfinityBaseInput::Platform::center, { 20,2,{ 0,0,0 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FadeCenter: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//fade left
				printf("Send FadeLeft\n");
				ret = di1.transceiveData(di1data.fade(InfinityBaseInput::Platform::left, { 20,2,{ 0,0,0 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FadeLeft: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//fade right
				printf("Send FadeRight\n");
				ret = di1.transceiveData(di1data.fade(InfinityBaseInput::Platform::right, { 20,2,{ 0,0,0 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FadeRight: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//flash all
				printf("Send FlashAll\n");
				ret = di1.transceiveData(di1data.flash(InfinityBaseInput::Platform::all, { 1,2,4,{ 10,10,10 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FlashAll: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//flash center
				printf("Send FlashCenter\n");
				ret = di1.transceiveData(di1data.flash(InfinityBaseInput::Platform::center, { 1,2,4,{ 10,10,10 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FlashCenter: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//flash left
				printf("Send FlashLeft\n");
				ret = di1.transceiveData(di1data.flash(InfinityBaseInput::Platform::left, { 1,2,4,{ 10,10,10 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FlashLeft: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				//flash right
				printf("Send FlashRight\n");
				ret = di1.transceiveData(di1data.flash(InfinityBaseInput::Platform::right, { 1,2,4,{ 10,10,10 } }));
				if (ret != LIBUSB_SUCCESS) {
					printf("DisneyInfinity FlashRight: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				do {
					ret = di1.transceiveData(di1data.data, 0x81);
					if (ret == LIBUSB_SUCCESS) {
						printf("ReceivedData:\n");
						for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]);
					}
				} while (ret == 0);
				Sleep(1000);

				while (1) {
					int cnt = 0;
					//send get tagID
					printf("Send getTagID\n");
					ret = di1.transceiveData(di1data.getTagId());
					if (ret != LIBUSB_SUCCESS) {
						printf("DisneyInfinity GetTagID: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
					}
					do {
						ret = di1.transceiveData(di1data.data, 0x81, 32, 1000);
						if (ret == LIBUSB_SUCCESS) {
							//printf("ReceivedData:\n");
							if (++cnt % 10 == 0) {
								printf("Send getTagID\n");
								ret = di1.transceiveData(di1data.getTagId());
								if (ret != LIBUSB_SUCCESS) {
									printf("DisneyInfinity GetTagID: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
								}
							}
							if (di1data.data[0] == 0xAA) {
								for (int i = 0; i < 32; ++i)printf("0x%X ", di1data.data[i]); printf("\n");
							}
							if (di1data.data[0] == 0xAB)printf("2: %X  3: %X  4: %X  5: %X\n", di1data.data[2], di1data.data[3], di1data.data[4], di1data.data[5]);
						}
						else Sleep(500);
					} while (1);// (ret == 0);
					Sleep(2000);
				}
			}
		}
	}
	libusb_exit(context);
	return 0;
}

int mainy(int argc, char** argv) {
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
			infinityPortals[j].fadeColour(0, 8, 1, 0, 0, 0);
			infinityPortals[j].fadeColour(1, 10, 1, 20, 0, 0);
			infinityPortals[j].fadeColour(2, 10, 1, 0, 20, 0);
			infinityPortals[j].fadeColour(3, 10, 1, 0, 0, 20);
			for (int k = 0; k < 3; k++) {
				//infinityPortals[j].setColour(k + 1, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				/*infinityPortals[j].fadeColour(0, 8, 1, 0, 0, 0);
				infinityPortals[j].flashColour(0, 1, 2, 4, 2, 2, 2);
				infinityPortals[j].flashColour(0, 1, 3, 4, 2, 2, 2);
				infinityPortals[j].fadeColour(0, 8, 1, 0, 0, 0);
				infinityPortals[j].fadeColour(1, 10, 1, 10, 0, 0);
				infinityPortals[j].fadeColour(2, 10, 1, 0, 10, 0);
				infinityPortals[j].fadeColour(3, 10, 1, 0, 0, 10);
				infinityPortals[j].setColour(k + 1, 10, 10, 10);
				infinityPortals[j].fadeColour(0, 8, 1, 0, 0, 0);
				infinityPortals[j].getTagId();*/
			}
		}

		if (j < dimensionsPortalCount) {
			dimensionsPortals[j].color(center, { 10,0,0 });
			dimensionsPortals[j].fade(Platform::left, { 0,10,1,{0,10,0} });
			dimensionsPortals[j].flash(Platform::right, { 0,2,2,5,{0,0,10} });
			dimensionsPortals[j].colorGroup({ 1,{1,5,5} }, { 0,{1,1,1} }, { 1,{5,5,5} });
			dimensionsPortals[j].fadeGroup({ 0,10,1,{10,0,10} }, { 1,10,1,{ 10,0,10 } }, { 1,10,1,{ 10,10,0 } });
			dimensionsPortals[j].flashGroup({ 1,1,1,4,{2,0,0} }, { 1,1,1,4,{ 2,0,0 } }, { 0,1,1,4,{ 2,0,0 } });
			dimensionsPortals[j].fade(center, { 0,10,1,{ 0,0,0 } });
			Sleep(200);
			dimensionsPortals[j].fade(Platform::left, { 0,10,1,{ 0,0,0 } });
			Sleep(200);
			dimensionsPortals[j].fade(Platform::right, { 0,10,1,{ 0,0,0 } });
			Sleep(500);
			dimensionsPortals[j].fade(Platform::center, { 0,10,1,{ 10,0,0 } });
			Sleep(200);
			dimensionsPortals[j].fade(Platform::left, { 0,10,1,{ 0,10,0 } });
			Sleep(200);
			dimensionsPortals[j].fade(Platform::right, { 0,10,1,{ 0,0,10 } });
			dimensionsPortals[j].fade(all, { 0,50,0xff,{ 0,0,0 } });
			for (int k = 0; k < 3; k++) {
				//dimensionsPortals[j].setColour(k + 1, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100, std::rand()/*random()*/ % 0x100);
				//dimensionsPortals[j].setColour(k + 1, 1, 1, 1);
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
