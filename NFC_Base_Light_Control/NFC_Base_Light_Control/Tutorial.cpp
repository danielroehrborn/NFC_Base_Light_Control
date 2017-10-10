#include <iostream>
#include <libusb.h>
using namespace std;

void printdev(libusb_device *dev); //prototype of the function

int tutorial() {
	libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices
	libusb_device_handle *dev_handle = NULL;
	libusb_context *ctx = NULL; //a libusb session
	int r; //for return values
	ssize_t cnt; //holding number of devices in list
	r = libusb_init(&ctx); //initialize a library session
	if (r < 0) {
		cout << "Init Error " << r << endl; //there was an error
		return 1;
	}
	libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation
	cnt = libusb_get_device_list(ctx, &devs); //get the list of devices
	if (cnt < 0) {
		cout << "Get Device Error" << endl; //there was an error
	}
	cout << endl << "##################" << endl << cnt << " Devices in list." << endl << "##################" << endl << endl; //print total number of usb devices
	ssize_t i; //for iterating through the list
	for (i = 0; i < cnt; i++) {
		cout << "Device " << i << " descriptors:" << endl;
		printdev(devs[i]); //print specs of this device
		cout << endl << "-----------------------------" << endl << endl << endl;
	}
	libusb_free_device_list(devs, 1); //free the list, unref the devices in it
	libusb_exit(ctx); //close the session
	return 0;
}

void printDT(libusb_descriptor_type dt) {
	printf("Descriptor type: ");
	switch (dt) {
	case LIBUSB_DT_DEVICE: printf("LIBUSB_DT_DEVICE \n"); break;
	case LIBUSB_DT_CONFIG: printf("LIBUSB_DT_CONFIG \n"); break;
	case LIBUSB_DT_STRING: printf("LIBUSB_DT_STRING \n"); break;
	case LIBUSB_DT_INTERFACE: printf("LIBUSB_DT_INTERFACE \n"); break;
	case LIBUSB_DT_ENDPOINT: printf("LIBUSB_DT_ENDPOINT \n"); break;
	case LIBUSB_DT_BOS: printf("LIBUSB_DT_BOS \n"); break;
	case LIBUSB_DT_DEVICE_CAPABILITY: printf("LIBUSB_DT_DEVICE_CAPABILITY \n"); break;
	case LIBUSB_DT_HID: printf("LIBUSB_DT_HID \n"); break;
	case LIBUSB_DT_REPORT: printf("LIBUSB_DT_REPORT \n"); break;
	case LIBUSB_DT_PHYSICAL: printf("LIBUSB_DT_PHYSICAL \n"); break;
	case LIBUSB_DT_HUB: printf("LIBUSB_DT_HUB \n"); break;
	case LIBUSB_DT_SUPERSPEED_HUB: printf("LIBUSB_DT_SUPERSPEED_HUB \n"); break;
	case LIBUSB_DT_SS_ENDPOINT_COMPANION: printf("LIBUSB_DT_SS_ENDPOINT_COMPANION \n"); break;
	default: printf("unknown descriptor type \n");
	}
}

void printDC(libusb_class_code cc) {
	printf("Device class: ");
	switch (cc) {
	case LIBUSB_CLASS_PER_INTERFACE: printf("LIBUSB_CLASS_PER_INTERFACE \n"); break;
	case LIBUSB_CLASS_AUDIO: printf("LIBUSB_CLASS_AUDIO \n"); break;
	case LIBUSB_CLASS_COMM: printf("LIBUSB_CLASS_COMM \n"); break;
	case LIBUSB_CLASS_HID: printf("LIBUSB_CLASS_HID \n"); break;
	case LIBUSB_CLASS_PHYSICAL: printf("LIBUSB_CLASS_PER_INTERFACE \n"); break;
	case LIBUSB_CLASS_PRINTER: printf("LIBUSB_CLASS_PRINTER \n"); break;
	case LIBUSB_CLASS_IMAGE: printf("LIBUSB_CLASS_IMAGE \n"); break;
	case LIBUSB_CLASS_MASS_STORAGE: printf("LIBUSB_CLASS_MASS_STORAGE \n"); break;
	case LIBUSB_CLASS_HUB: printf("LIBUSB_CLASS_HUB \n"); break;
	case LIBUSB_CLASS_DATA: printf("LIBUSB_CLASS_DATA \n"); break;
	case LIBUSB_CLASS_SMART_CARD: printf("LIBUSB_CLASS_SMART_CARD \n"); break;
	case LIBUSB_CLASS_CONTENT_SECURITY: printf("LIBUSB_CLASS_CONTENT_SECURITY \n"); break;
	case LIBUSB_CLASS_VIDEO: printf("LIBUSB_CLASS_VIDEO \n"); break;
	case LIBUSB_CLASS_PERSONAL_HEALTHCARE: printf("LIBUSB_CLASS_PERSONAL_HEALTHCARE \n"); break;
	case LIBUSB_CLASS_DIAGNOSTIC_DEVICE: printf("LIBUSB_CLASS_DIAGNOSTIC_DEVICE \n"); break;
	case LIBUSB_CLASS_WIRELESS: printf("LIBUSB_CLASS_WIRELESS \n"); break;
	case LIBUSB_CLASS_APPLICATION: printf("LIBUSB_CLASS_APPLICATION \n"); break;
	case LIBUSB_CLASS_VENDOR_SPEC: printf("LIBUSB_CLASS_VENDOR_SPEC \n"); break;
	default: printf("unknown device class \n");
	}
}

void printdev(libusb_device *dev) {
	libusb_device_descriptor desc;
	unsigned char data[256];
	libusb_error ret = (libusb_error)libusb_get_device_descriptor(dev, &desc);
	if (ret != LIBUSB_SUCCESS) {
		cout << "failed to get device descriptor: " << libusb_error_name(ret) << endl << libusb_strerror(ret) << endl;
		return;
	}
	cout << "Descriptor length: " << desc.bLength << endl;
	printDT((libusb_descriptor_type)desc.bDescriptorType);
	printf("USB spec: %X.%X\n", desc.bcdUSB >> 8, (desc.bcdUSB >> 4) & 0xf);
	cout << "USB spec: " << desc.bcdUSB << endl;
	printDC((libusb_class_code)desc.bDeviceClass);
	cout << "DeviceSubClass: " << (int)desc.bDeviceSubClass << endl;
	cout << "Device protocol: " << desc.bDeviceProtocol << endl;
	cout << "MaxPacketSize: " << desc.bMaxPacketSize0 << endl;
	cout << "ProductID: " << desc.idProduct << endl;
	cout << "VendorID: " << desc.idVendor << endl;
	cout << "Device release num: " << desc.bcdDevice << endl;


	libusb_device_handle* handle;
	ret = (libusb_error)libusb_open(dev, &handle);
	if (ret != LIBUSB_SUCCESS) {
		cout << "failed to open device: " << libusb_error_name(ret) << endl << libusb_strerror(ret) << endl;
	}
	else {
		if (desc.iManufacturer != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, &data[0], 256);
			if (ret > 0)
				printf("Manufacturer: %s \n", data);
			else
				cout << "failed to read manufacturer string: " << libusb_error_name(ret) << endl << libusb_strerror(ret) << endl;
		}
		else
			cout << "no Manufacturer string" << endl;

		if (desc.iProduct != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iProduct, data, 256);
			if (ret > 0)
				printf("Product: %s \n", data);
			else
				cout << "failed to read product string: " << libusb_error_name(ret) << endl << libusb_strerror(ret) << endl;
		}
		else
			cout << "no Product string" << endl;

		if (desc.iSerialNumber != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iSerialNumber, data, 256);
			if (ret > 0)
				printf("SerialNum: %s \n", data);
			else
				cout << "failed to read SerialNum string: " << libusb_error_name(ret) << endl << libusb_strerror(ret) << endl;
		}
		else
			cout << "no SerialNum string" << endl;

		cout << "Number of possible configurations: " << (int)desc.bNumConfigurations << endl;

		libusb_close(handle);
	}

	libusb_config_descriptor *config;
	ret = (libusb_error)libusb_get_config_descriptor(dev, 0, &config);
	if (ret < 0) {
		cout << "failed to get configuration descriptor" << endl;
		return;
	}
	cout << "Interfaces: " << (int)config->bNumInterfaces << endl;
	const libusb_interface *inter;
	const libusb_interface_descriptor *interdesc;
	const libusb_endpoint_descriptor *epdesc;
	for (int i = 0; i < (int)config->bNumInterfaces; i++) {
		inter = &config->interface[i];
		cout << "Number of alternate settings: " << inter->num_altsetting << endl;
		for (int j = 0; j < inter->num_altsetting; j++) {
			interdesc = &inter->altsetting[j];
			cout << "Interface Number: " << (int)interdesc->bInterfaceNumber << endl;
			cout << "Number of endpoints: " << (int)interdesc->bNumEndpoints << endl;
			for (int k = 0; k < (int)interdesc->bNumEndpoints; k++) {
				epdesc = &interdesc->endpoint[k];
				cout << "Descriptor Type: " << (int)epdesc->bDescriptorType << endl;
				cout << "EP Address: " << (int)epdesc->bEndpointAddress << endl;
			}
		}
	}
	libusb_free_config_descriptor(config);
}