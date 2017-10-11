#pragma once
#ifndef INFINITYPORTAL_H
#define	INFINITYPORTAL_H

#include <stdio.h>
#include "libusb.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

class InfinityPortal {
public:
	static const unsigned char numFunctions;
	static const char* functionNames[5];
	InfinityPortal();
	InfinityPortal(int deviceId);
	virtual ~InfinityPortal();
	libusb_device_handle* deviceHandler;
	void setColour(char platform, char r, char g, char b);
	void flashColour(char platform, unsigned char onLen, unsigned char offLen, unsigned char pulseCnt, char r, char g, char b);
	void fadeColour(char platform, unsigned char pulseLen, unsigned char pulseCnt, char r, char g, char b);
	void activate();
	void getTagId();
private:
	void processReceivedPacket(unsigned char* packet);
	void sendPacket(unsigned char* packet);
	int receivePackets();
	libusb_device_handle* connect(int deviceId);
};

#endif