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
#include "PortalConnection.h"

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

class DimensionsPortalInterface {
public:
	virtual unsigned char* activate() = 0;
	virtual unsigned char* color(Platform p, RGB rgbVal) = 0;
	virtual unsigned char* flash(Platform p, Flash flashVal) = 0;
	virtual unsigned char* fade(Platform p, Fade fadeVal) = 0;
	virtual unsigned char* colorGroup(Color center, Color left, Color right) = 0;
	virtual unsigned char* flashGroup(Flash center, Flash left, Flash right) = 0;
	virtual unsigned char* fadeGroup(Fade center, Fade left, Fade right) = 0;
};

class DimensionsPortalInput : public DimensionsPortalInterface {
public:
	unsigned char data[32] = { 0 };
	unsigned char* activate();
	unsigned char* color(Platform p, RGB rgbVal);
	unsigned char* flash(Platform p, Flash flashVal);
	unsigned char* fade(Platform p, Fade fadeVal);
	unsigned char* colorGroup(Color center, Color left, Color right);
	unsigned char* flashGroup(Flash center, Flash left, Flash right);
	unsigned char* fadeGroup(Fade center, Fade left, Fade right);
};

class DimensionsPortalCommandLineControl : public DimensionsPortalInterface {
	DimensionsPortalInput impl;
public:
	void printMenu(PortalConnection* pc);
	unsigned char* activate();
	unsigned char* color(Platform p, RGB rgbVal);
	unsigned char* flash(Platform p, Flash flashVal);
	unsigned char* fade(Platform p, Fade fadeVal);
	unsigned char* colorGroup(Color center, Color left, Color right);
	unsigned char* flashGroup(Flash center, Flash left, Flash right);
	unsigned char* fadeGroup(Fade center, Fade left, Fade right);
};