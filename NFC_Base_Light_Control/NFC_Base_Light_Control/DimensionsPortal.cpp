#include "DimensionsPortal.h"
#include <iostream>

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

void setChecksum(unsigned char* packet) {
	int checksum = 0;
	for (int l = 0; l < packet[1] + 2; l++) {
		checksum += packet[l];
	}
	checksum = checksum & 0xFF;
	packet[packet[1] + 2] = checksum;
}

void DimensionsPortal::sendPacket(unsigned char* packet) {
	setChecksum(packet);

	int len;
	int retVal = -1;

	//receivePackets();

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
	unsigned char packet[32];

	while (retVal == 0) {

		retVal = libusb_bulk_transfer(deviceHandler, 0x81, packet, 32, &len, 10);
		if (retVal == 0) {
			/*printf("\nReceived:\n");
			for (int i = 0; i < 32; ++i) {
				if (i % 8 == 0) printf("\n");
				printf("%X ");
			}*/
			processReceivedPacket(packet);
			packetsReceived += 1;
		}
	}

	return packetsReceived;
}

void DimensionsPortal::test() {
	unsigned char packet[32] = {
		//55,len, cmd, msgcnt...checksum
		0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};

	int checksum = 0;
	for (int l = 0; l < packet[1] + 2; l++) {
		checksum += packet[l];
	}
	checksum = checksum & 0xFF;
	packet[packet[1] + 3] = checksum;


	sendPacket(packet);
}



void DimensionsPortal::color(Platform p, RGB rgbVal) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x06; //command length
	packet[2] = 0xc0; //command
	packet[3] = 0x02;
	packet[4] = p; //platform
	packet[5] = rgbVal.r; // r
	packet[6] = rgbVal.g; // g
	packet[7] = rgbVal.b; // b
	sendPacket(packet);
}
void DimensionsPortal::flash(Platform p, Flash flashVal) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x09; //command length
	packet[2] = 0xc3; //command
	packet[3] = 0x1f;
	packet[4] = p; //platform
	packet[5] = flashVal.onLen; //light on length
	packet[6] = flashVal.offLen; //light off length
	packet[7] = flashVal.pulseCnt; //number of pulses
	packet[8] = flashVal.rgb.r; // r
	packet[9] = flashVal.rgb.g; // g
	packet[10] = flashVal.rgb.b; // b
	sendPacket(packet);
}
void DimensionsPortal::fade(Platform p, Fade fadeVal) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x08; //command length
	packet[2] = 0xc2; //command
	packet[3] = 0x0f;
	packet[4] = p; //platform
	packet[5] = fadeVal.fadeLen; //fading duration
	packet[6] = fadeVal.pulseCnt; //number of pulses
	packet[7] = fadeVal.rgb.r; // r
	packet[8] = fadeVal.rgb.g; // g
	packet[9] = fadeVal.rgb.b; // b
	sendPacket(packet);
}
void DimensionsPortal::colorGroup(Color center, Color left, Color right) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x0e; //command length
	packet[2] = 0xc8; //command
	packet[3] = 0x06;
	//center platform
	packet[4] = center.enable; //enable
	packet[5] = center.rgb.r;
	packet[6] = center.rgb.g;
	packet[7] = center.rgb.b;
	//left platform
	packet[8] = left.enable; //enable
	packet[9] = left.rgb.r;
	packet[10] = left.rgb.g;
	packet[11] = left.rgb.b;
	//right platform
	packet[12] = right.enable; //enable
	packet[13] = right.rgb.r;
	packet[14] = right.rgb.g;
	packet[15] = right.rgb.b;
	sendPacket(packet);
}
void DimensionsPortal::flashGroup(Flash center, Flash left, Flash right) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x17; //command length
	packet[2] = 0xc7; //command
	packet[3] = 0x3e;
	//center platform
	packet[4] = center.enable;
	packet[5] = center.onLen;
	packet[6] = center.offLen;
	packet[7] = center.pulseCnt;
	packet[8] = center.rgb.r;
	packet[9] = center.rgb.g;
	packet[10] = center.rgb.b;
	//left platform
	packet[11] = left.enable;
	packet[12] = left.onLen;
	packet[13] = left.offLen;
	packet[14] = left.pulseCnt;
	packet[15] = left.rgb.r;
	packet[16] = left.rgb.g;
	packet[17] = left.rgb.b;
	//right platform
	packet[18] = right.enable;
	packet[19] = right.onLen;
	packet[20] = right.offLen;
	packet[21] = right.pulseCnt;
	packet[22] = right.rgb.r;
	packet[23] = right.rgb.g;
	packet[24] = right.rgb.b;
	sendPacket(packet);
}
void DimensionsPortal::fadeGroup(Fade center, Fade left, Fade right) {
	unsigned char packet[32];
	packet[0] = 0x55; //start
	packet[1] = 0x14; //command length
	packet[2] = 0xc6; //command
	packet[3] = 0x26;
	//center platform
	packet[4] = center.enable;
	packet[5] = center.fadeLen;
	packet[6] = center.pulseCnt;
	packet[7] = center.rgb.r;
	packet[8] = center.rgb.g;
	packet[9] = center.rgb.b;
	//left platform
	packet[10] = left.enable;
	packet[11] = left.fadeLen;
	packet[12] = left.pulseCnt;
	packet[13] = left.rgb.r;
	packet[14] = left.rgb.g;
	packet[15] = left.rgb.b;
	//right platform
	packet[16] = right.enable;
	packet[17] = right.fadeLen;
	packet[18] = right.pulseCnt;
	packet[19] = right.rgb.r;
	packet[20] = right.rgb.g;
	packet[21] = right.rgb.b;
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
/*
void DimensionsPortal::color(char platform, char r, char g, char b) {

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

void DimensionsPortal::flash(char platform, char r, char g, char b) {
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

void DimensionsPortal::fade(char platform, char r, char g, char b) {
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
*/

void DimensionsPortalInput::clearBuffer() {
	for (unsigned char i = 0; i < 32; ++i) data[i] = 0;
}
unsigned char* DimensionsPortalInput::activate() {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x0f; //length
	data[2] = 0xb0; //command
	data[3] = 0x01; 
	data[4] = 0x28; //'('
	data[5] = 0x63; //'c'
	data[6] = 0x29; //')'
	data[7] = 0x20; //' '
	data[8] = 0x4c; //'L'
	data[9] = 0x45; //'E'
	data[10] = 0x47;//'G'
	data[11] = 0x4f;//'O'
	data[12] = 0x20;//' '
	data[13] = 0x32;//'2'
	data[14] = 0x30;//'0'
	data[15] = 0x31;//'1'
	data[16] = 0x34;//'4'
	data[17] = 0xf7;//checksum
	return data;
}
unsigned char* DimensionsPortalInput::color(Platform p, RGB rgbVal) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x06; //command length
	data[2] = 0xc0; //command
	data[3] = 0x02;
	data[4] = p; //platform
	data[5] = rgbVal.r; // r
	data[6] = rgbVal.g; // g
	data[7] = rgbVal.b; // b
	setChecksum(data);
	return data;
}
unsigned char* DimensionsPortalInput::flash(Platform p, Flash flashVal) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x09; //command length
	data[2] = 0xc3; //command
	data[3] = 0x1f;
	data[4] = p; //platform
	data[5] = flashVal.onLen; //light on length
	data[6] = flashVal.offLen; //light off length
	data[7] = flashVal.pulseCnt; //number of pulses
	data[8] = flashVal.rgb.r; // r
	data[9] = flashVal.rgb.g; // g
	data[10] = flashVal.rgb.b; // b
	setChecksum(data);
	return data;
}
unsigned char* DimensionsPortalInput::fade(Platform p, Fade fadeVal) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x08; //command length
	data[2] = 0xc2; //command
	data[3] = 0x0f;
	data[4] = p; //platform
	data[5] = fadeVal.fadeLen; //fading duration
	data[6] = fadeVal.pulseCnt; //number of pulses
	data[7] = fadeVal.rgb.r; // r
	data[8] = fadeVal.rgb.g; // g
	data[9] = fadeVal.rgb.b; // b
	setChecksum(data);
	return data;
}
unsigned char* DimensionsPortalInput::colorGroup(Color center, Color left, Color right) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x0e; //command length
	data[2] = 0xc8; //command
	data[3] = 0x06;
	//center platform
	data[4] = center.enable; //enable
	data[5] = center.rgb.r;
	data[6] = center.rgb.g;
	data[7] = center.rgb.b;
	//left platform
	data[8] = left.enable; //enable
	data[9] = left.rgb.r;
	data[10] = left.rgb.g;
	data[11] = left.rgb.b;
	//right platform
	data[12] = right.enable; //enable
	data[13] = right.rgb.r;
	data[14] = right.rgb.g;
	data[15] = right.rgb.b;
	setChecksum(data);
	return data;
}
unsigned char* DimensionsPortalInput::flashGroup(Flash center, Flash left, Flash right) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x17; //command length
	data[2] = 0xc7; //command
	data[3] = 0x3e;
	//center platform
	data[4] = center.enable;
	data[5] = center.onLen;
	data[6] = center.offLen;
	data[7] = center.pulseCnt;
	data[8] = center.rgb.r;
	data[9] = center.rgb.g;
	data[10] = center.rgb.b;
	//left platform
	data[11] = left.enable;
	data[12] = left.onLen;
	data[13] = left.offLen;
	data[14] = left.pulseCnt;
	data[15] = left.rgb.r;
	data[16] = left.rgb.g;
	data[17] = left.rgb.b;
	//right platform
	data[18] = right.enable;
	data[19] = right.onLen;
	data[20] = right.offLen;
	data[21] = right.pulseCnt;
	data[22] = right.rgb.r;
	data[23] = right.rgb.g;
	data[24] = right.rgb.b;
	setChecksum(data);
	return data;
}
unsigned char* DimensionsPortalInput::fadeGroup(Fade center, Fade left, Fade right) {
	clearBuffer();
	data[0] = 0x55; //start
	data[1] = 0x14; //command length
	data[2] = 0xc6; //command
	data[3] = 0x26;
	//center platform
	data[4] = center.enable;
	data[5] = center.fadeLen;
	data[6] = center.pulseCnt;
	data[7] = center.rgb.r;
	data[8] = center.rgb.g;
	data[9] = center.rgb.b;
	//left platform
	data[10] = left.enable;
	data[11] = left.fadeLen;
	data[12] = left.pulseCnt;
	data[13] = left.rgb.r;
	data[14] = left.rgb.g;
	data[15] = left.rgb.b;
	//right platform
	data[16] = right.enable;
	data[17] = right.fadeLen;
	data[18] = right.pulseCnt;
	data[19] = right.rgb.r;
	data[20] = right.rgb.g;
	data[21] = right.rgb.b;
	setChecksum(data);
	return data;
}

void DimensionsPortalCommandLineControl::printMenu(PortalConnection* pc) {
	while (1) {
		int i = 0;
		printf("\n\nMenu\n");
		printf("%d. activate\n", ++i);
		printf("%d. color\n", ++i);
		printf("%d. flash\n", ++i);
		printf("%d. fade\n", ++i);
		printf("%d. colorGroup\n", ++i);
		printf("%d. flashGroup\n", ++i);
		printf("%d. fadeGroup\n", ++i);
		printf("%d. quit\n", ++i);
		printf("Choose: ");
		std::cin >> i;
		std::cout << std::endl;
		switch (i) {
		case 1:
			pc->transceiveData(activate());
			break;
		case 2:
			pc->transceiveData(color(all, { 0,0,0 }));
			break;
		case 3:
			pc->transceiveData(flash(all, { 0,0,0,0,{0,0,0} }));
			break;
		case 4:
			pc->transceiveData(fade(all, { 0,0,0,{0,0,0} }));
			break;
		case 5:
			pc->transceiveData(colorGroup({ 0,{0,0,0} }, { 0,{0,0,0} }, { 0,{0,0,0} }));
			break;
		case 6:
			pc->transceiveData(flashGroup({ 0,0,0,0,{0,0,0} }, { 0,0,0,0,{ 0,0,0 } }, { 0,0,0,0,{ 0,0,0 } }));
			break;
		case 7:
			pc->transceiveData(fadeGroup({ 0,0,0,{0,0,0} }, { 0,0,0,{ 0,0,0 } }, { 0,0,0,{ 0,0,0 } }));
			break;
		case 8:
			return;
		}
	}
}
unsigned char* DimensionsPortalCommandLineControl::activate() {
	printf("Activate\n");
	return impl.activate();
}
unsigned char* DimensionsPortalCommandLineControl::color(Platform p, RGB rgbVal) {
	printf("Color\n");
	printf("Type platform (0:all, 1: center, 2: left, 3: right: ");
	int platform, r, g, b;
	std::cin >> platform;
	std::cout << std::endl;
	printf("Type red (0-255): ");
	std::cin >> r;
	std::cout << std::endl;
	printf("Type green (0-255): ");
	std::cin >> g;
	std::cout << std::endl;
	printf("Type blue(0-255): ");
	std::cin >> b;
	std::cout << std::endl;
	return impl.color((Platform)platform, { (unsigned char)r,(unsigned char)g,(unsigned char)b });
}
unsigned char* DimensionsPortalCommandLineControl::flash(Platform p, Flash flashVal) {
	printf("Flash\n");
	return impl.flash(p, flashVal);
}
unsigned char* DimensionsPortalCommandLineControl::fade(Platform p, Fade fadeVal) {
	printf("Fade\n");
	printf("Type platform (0:all, 1: center, 2: left, 3: right: ");
	int platform, fadeLen, pulseCnt, r, g, b;
	std::cin >> platform;
	printf("Type fade length (0-255): ");
	std::cin >> fadeLen;
	printf("Type pulse count (0-255): ");
	std::cin >> pulseCnt;
	printf("Type red (0-255): ");
	std::cin >> r;
	printf("Type green (0-255): ");
	std::cin >> g;
	printf("Type blue(0-255): ");
	std::cin >> b;
	return impl.fade((Platform)platform, { 1,(unsigned char)fadeLen,(unsigned char)pulseCnt,{ (unsigned char)r,(unsigned char)g,(unsigned char)b} });
}
unsigned char* DimensionsPortalCommandLineControl::colorGroup(Color center, Color left, Color right) {
	printf("ColorGroup\n");
	return impl.colorGroup(center, left, right);
}
unsigned char* DimensionsPortalCommandLineControl::flashGroup(Flash center, Flash left, Flash right) {
	printf("FlashGroup\n");
	return impl.flashGroup(center, left, right);
}
unsigned char* DimensionsPortalCommandLineControl::fadeGroup(Fade center, Fade left, Fade right) {
	printf("FadeGroup\n");
	return impl.fadeGroup(center, left, right);
}