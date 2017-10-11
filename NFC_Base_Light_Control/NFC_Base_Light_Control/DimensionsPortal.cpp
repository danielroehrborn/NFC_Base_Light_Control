#include "DimensionsPortal.h"

const unsigned char DimensionsPortal::numFunctions = 5;
const char* DimensionsPortal::functionNames[5] = {
	"activate","setColour","flashColour","fadeColour","getTagId"
};

DimensionsPortal::DimensionsPortal(int deviceId) {

	// printf("Device id: %d\n",deviceId);
	deviceHandler = connect(deviceId);

	int retVal = 0;

	if (libusb_kernel_driver_active(deviceHandler, 0) == 1) {
		retVal = libusb_detach_kernel_driver(deviceHandler, 0);
		if (retVal < 0) {
			libusb_close(deviceHandler);
		}
	}

	retVal = libusb_claim_interface(deviceHandler, 0);

	if (retVal != 0) {
		printf("Error code: %d\n", retVal);
		printf("Error name: %s\n", libusb_error_name(retVal));
		exit(1);
	}

	activate();
}

DimensionsPortal::DimensionsPortal() {

}

libusb_device_handle* DimensionsPortal::connect(int deviceId) {

	libusb_device** devices;
	libusb_context* context;
	struct libusb_device_handle* tryDeviceHandler;

	libusb_init(&context);
	int devicesCount = libusb_get_device_list(context, &devices);

	int error;

	struct libusb_device_descriptor descriptor;

	int retVal = libusb_open(devices[deviceId], &tryDeviceHandler);

	libusb_get_device_descriptor(devices[deviceId], &descriptor);

	if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x0241) {

		return tryDeviceHandler;
	}
}

void DimensionsPortal::getTagId() {

	// ff 03 b4 26 00 dc 02 06 ff 00 00 ca 36 f1 2c 70 00 00 00 00 36 e7 3c 90 00 00 00 00 00 00 00 00
	unsigned char* packet = new unsigned char[32];

	packet[0] = 0xff;
	packet[1] = 0x03;
	packet[2] = 0xb4;
	packet[3] = 0x26;
	packet[4] = 0x00;
	packet[5] = 0xdc;
	packet[6] = 0x02;
	packet[7] = 0x06;
	packet[8] = 0xff;
	packet[9] = 0x00;
	packet[10] = 0x00;
	packet[11] = 0xca;
	packet[12] = 0x36;
	packet[13] = 0xf1;
	packet[14] = 0x2c;
	packet[15] = 0x70;
	packet[16] = 0x00;
	packet[17] = 0x00;
	packet[18] = 0x00;
	packet[19] = 0x00;
	packet[20] = 0x36;
	packet[21] = 0xe7;
	packet[22] = 0x3c;
	packet[23] = 0x90;
	packet[25] = 0x00;
	packet[26] = 0x00;
	packet[27] = 0x00;
	packet[28] = 0x00;
	packet[29] = 0x00;
	packet[30] = 0x00;
	packet[31] = 0x00;

	sendPacket(packet);
}

void DimensionsPortal::sendPacket(unsigned char* packet) {

	int len;
	int retVal = -1;

	receivePackets();

	while (retVal < 0) {
		retVal = libusb_bulk_transfer(deviceHandler, 0x01, packet, 32, &len, 100);
		receivePackets();
	}

	// if(retVal != 0) {
	// 	printf("Error code: %d\n",retVal);
	// 	printf("Error name: %s\n",libusb_error_name(retVal));
	// 	exit(1);
	// }

}

void DimensionsPortal::processReceivedPacket(unsigned char* packet) {

	if (packet[0x00] == 0xab) {
		// printf("Something was placed somewhere!\n");

		// printf("Received: ");

		// for(int i = 0 ; i < 32 ; i++) {
		// 	printf("%x ",packet[i]);
		// }
		// printf("\n");

		char platformSetting = packet[2];
		char placedRemoved = packet[5];

		if (placedRemoved == 0x00) {
			printf("Tag placed on platform: %d\n", platformSetting);
		}
		else {
			printf("Tag removed from platform: %d\n", platformSetting);
		}

		getTagId();

	}
	else if (packet[0x00] == 0xaa && packet[0x01] == 0x09) {
		printf("Got tag info\n");

		// make print tag info!!!
		for (int i = 10; i > 2; i--) {
			printf("%x ", packet[i]);
		}
		printf("\n");
	}

}

int DimensionsPortal::receivePackets() {

	int packetsReceived = 0;
	int retVal = 0;
	int len = 0;
	unsigned char* packet = new unsigned char[32];

	while (retVal == 0) {

		retVal = libusb_bulk_transfer(deviceHandler, 0x81, packet, 32, &len, 10);
		if (retVal == 0) {
			processReceivedPacket(packet);
			packetsReceived += 1;
		}
	}

	return packetsReceived;
}

void DimensionsPortal::fadeColour(char platform, char r, char g, char b) {
	unsigned char packet[32];

	packet[0] = 0x55;//start
	packet[1] = 0x14;//len
	packet[2] = 0xc6;//command
	packet[3] = 0x26;//msg count

	//platform 1
	packet[4] = platform == 0 || platform == 1 ? 0x01 : 0; //enable
	packet[5] = 10;//fade time
	packet[6] = 5; //pulse count
	packet[7] = r; //r
	packet[8] = g; //g
	packet[9] = b; //b

	//platform 2
	packet[10] = platform == 0 || platform == 2 ? 0x01 : 0; //enable
	packet[11] = 10;//fade time
	packet[12] = 5; //pulse count
	packet[13] = r; //r
	packet[14] = g; //g
	packet[15] = b; //b

	//platform 3
	packet[16] = platform == 0 || platform == 3 ? 0x01 : 0; //enable
	packet[17] = 10;//fade time
	packet[18] = 5; //pulse count
	packet[19] = r; //r
	packet[20] = g; //g
	packet[21] = b; //b

	int checksum = 0;
	for (int l = 0; l < 22; l++) {
		checksum += packet[l];
	}

	checksum = checksum & 0xFF;

	packet[22] = checksum;
	packet[23] = 0x00;
	packet[24] = 0x00;
	packet[25] = 0x00;
	packet[26] = 0x00;
	packet[27] = 0x00;
	packet[28] = 0x00;
	packet[29] = 0x00;
	packet[30] = 0x00;
	packet[31] = 0x00;

	sendPacket(packet);
}

DimensionsPortal::~DimensionsPortal() {

}

void DimensionsPortal::activate() {
	unsigned char packet[] = {
		0x55,0x0f,0xb0,0x01,0x28,0x63,0x29,0x20,
		0x4c,0x45,0x47,0x4f,0x20,0x32,0x30,0x31,
		0x34,0xf7,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};
	sendPacket(packet);
}

void DimensionsPortal::setColour(char platform, char r, char g, char b) {

	// ff 06 90 41 02 00 00 00 d8 00 00 00 36 f1 2c 70 00 00 00 00 36 e7 3c 90 00 00 00 00 00 00 00 00

	unsigned char* packet = new unsigned char[32];

	packet[0] = 0x55;
	packet[1] = 0x06; // packet length
	packet[2] = 0xc0;
	packet[3] = 0x02;
	packet[4] = platform; // platform
	packet[5] = r; // r
	packet[6] = g; // g
	packet[7] = b; // b
				   // packet[8] = 0xd8;

	int checksum = 0;
	for (int l = 0; l < 8; l++) {
		checksum += packet[l];
	}

	checksum = checksum & 0xFF;

	packet[8] = checksum;
	packet[9] = 0x00;
	packet[10] = 0x00;
	packet[11] = 0x00;
	packet[12] = 0x36;
	packet[13] = 0xf1;
	packet[14] = 0x2c;
	packet[15] = 0x70;
	packet[16] = 0x00;
	packet[17] = 0x00;
	packet[18] = 0x00;
	packet[19] = 0x00;
	packet[20] = 0x36;
	packet[21] = 0xe7;
	packet[22] = 0x3c;
	packet[23] = 0x90;
	packet[24] = 0x00;
	packet[25] = 0x00;
	packet[26] = 0x00;
	packet[27] = 0x00;
	packet[28] = 0x00;
	packet[29] = 0x00;
	packet[30] = 0x00;
	packet[31] = 0x00;

	sendPacket(packet);
}

void DimensionsPortal::flashColour(char platform, char r, char g, char b) {
	unsigned char packet[32];

	packet[0] = 0x55;//start
	packet[1] = 0x17;//len
	packet[2] = 0xc7;//command
	packet[3] = 0x30;//msg count

	//platform 1
	packet[4] = platform == 0 || platform == 1 ? 0x01 : 0; //enable
	packet[5] = 10;//on len
	packet[6] = 5; //off len
	packet[7] = 5; //pulse count
	packet[8] = r; //r
	packet[9] = g; //g
	packet[10] = b; //b

	//platform 2
	packet[11] = platform == 0 || platform == 2 ? 0x01 : 0; //enable
	packet[12] = 10;//on len
	packet[13] = 5; //off len
	packet[14] = 5; //pulse count
	packet[15] = r; //r
	packet[16] = g; //g
	packet[17] = b; //b

	//platform 3
	packet[18] = platform == 0 || platform == 3 ? 0x01 : 0; //enable
	packet[19] = 10;//on len
	packet[20] = 5; //off len
	packet[21] = 5; //pulse count
	packet[22] = r; //r
	packet[23] = g; //g
	packet[24] = b; //b

	int checksum = 0;
	for (int l = 0; l < 25; l++) {
		checksum += packet[l];
	}

	checksum = checksum & 0xFF;

	packet[25] = checksum;
	packet[26] = 0x00;
	packet[27] = 0x00;
	packet[28] = 0x00;
	packet[29] = 0x00;
	packet[30] = 0x00;
	packet[31] = 0x00;

	sendPacket(packet);
}

