#pragma once
#include <stdio.h>
#include "libusb.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

class RGB {
public:
	const unsigned char r, g, b;
};
class Color {
public:
	const unsigned char enable;
	const RGB rgb;
};
class Flash {
public:
	const unsigned char enable, onLen, offLen, pulseCnt;
	const RGB rgb;
};
class Fade {
public:
	const unsigned char enable, fadeLen, pulseCnt;
	const RGB rgb;
};
enum Platform {
	all = 0,
	center = 1,
	left = 2,
	right = 3
};
class DimensionsPortal {
public:
	static const unsigned char numFunctions;
	static const char* functionNames[5];
	DimensionsPortal();
	DimensionsPortal(int deviceId);
	virtual ~DimensionsPortal();
	libusb_device_handle* deviceHandler;
	void color(Platform p, RGB rgbVal);
	void flash(Platform p, Flash flashVal);
	void fade(Platform p, Fade fadeVal);
	void colorGroup(Color center, Color left, Color right);
	void flashGroup(Flash center, Flash left, Flash right);
	void fadeGroup(Fade center, Fade left, Fade right);
	void activate();
	void test();
	void processReceivedPacket(unsigned char* packet);
	void sendPacket(unsigned char* packet);
	int receivePackets();
	libusb_device_handle* connect(int deviceId);
};
