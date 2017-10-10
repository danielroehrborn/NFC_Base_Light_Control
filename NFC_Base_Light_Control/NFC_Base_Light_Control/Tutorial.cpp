#include <iostream>
#include <libusb.h>
using namespace std;
int vendorid;

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
	cout << "cin << VendorID: ";
	cin >> hex >> vendorid;
	for (i = 0; i < cnt; i++) {
		if (vendorid == -1 || (vendorid >= 0 && vendorid < 100 && vendorid == i) || vendorid > 100) {
			cout << "Device " << i << " descriptors:" << endl;
			printdev(devs[i]); //print specs of this device
			cout << endl << "-------------------------------------------------" << endl << endl << endl;
			getchar();
		}
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
		printf("Read Device descriptor: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
		return;
	}
	if (vendorid != -1 && vendorid > 100 && desc.idVendor != vendorid) {
		printf("VendorID: %X\n", desc.idVendor);
		return;
	}
	printf("Descriptor length: %d\n", desc.bLength);
	printDT((libusb_descriptor_type)desc.bDescriptorType);
	printf("USB spec: %X.%X\n", desc.bcdUSB >> 8, (desc.bcdUSB >> 4) & 0xf);
	printDC((libusb_class_code)desc.bDeviceClass);
	cout << "DeviceSubClass: " << (int)desc.bDeviceSubClass << endl;
	printf("Device protocol: %d\n", desc.bDeviceProtocol);
	printf("MaxPacketSize Endpoint0: %d\n", desc.bMaxPacketSize0);
	printf("VendorID: %X\n", desc.idVendor);
	printf("ProductID: %X\n", desc.idProduct);
	cout << "Device release num: " << ((desc.bcdDevice >> 12) & 0xf) << "." << ((desc.bcdDevice >> 8) & 0xf)
		<< "." << ((desc.bcdDevice >> 4) & 0xf) << "." << (desc.bcdDevice & 0xf) << endl;
	cout << "Number of possible configurations: " << (int)desc.bNumConfigurations << endl;

	libusb_device_handle* handle;
	ret = (libusb_error)libusb_open(dev, &handle);
	if (ret != LIBUSB_SUCCESS) {
		printf("Open device: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}
	else {
		if (desc.iManufacturer != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, &data[0], 256);
			if (ret > 0)
				printf("Manufacturer: %s \n", data);
			else
				printf("Read Manufacturer: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
		}
		else
			cout << "no Manufacturer string" << endl;

		if (desc.iProduct != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iProduct, data, 256);
			if (ret > 0)
				printf("Product: %s \n", data);
			else
				printf("Read Product string: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
		}
		else
			cout << "no Product string" << endl;

		if (desc.iSerialNumber != 0) {
			ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, desc.iSerialNumber, data, 256);
			if (ret > 0)
				printf("SerialNum: %s \n", data);
			else
				printf("Read SerialNum: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
		}
		else
			cout << "no SerialNum string" << endl;

		libusb_close(handle);
	}

	libusb_config_descriptor *config;
	for (int l = 0; l < desc.bNumConfigurations; ++l) {
		ret = (libusb_error)libusb_get_config_descriptor(dev, l, &config);
		if (ret != LIBUSB_SUCCESS) {
			printf("Read configuration descriptor[%d]: %s\n\t%s\n", l, libusb_error_name(ret), libusb_strerror(ret));
		}
		else {
			cout << endl << "Configuration[" << l << "]:" << endl;
			cout << "Descriptor length: " << config->bLength << endl;
			printDT((libusb_descriptor_type)config->bDescriptorType);
			cout << "Total length: " << config->wTotalLength << endl;
			cout << "Configuration identifier: " << config->bConfigurationValue << endl;

			ret = (libusb_error)libusb_open(dev, &handle); //read iConfiguration
			if (ret != LIBUSB_SUCCESS) {
				printf("Open device: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
			}
			else {
				if (config->iConfiguration != 0) {
					ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, config->iConfiguration, &data[0], 256);
					if (ret > 0)
						printf("Configuration: %s \n", data);
					else
						printf("Read Configuration: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
				}
				else
					cout << "no Configuration string" << endl;
				libusb_close(handle);
			}

			printf("Configuration characteristics: %d\n", config->bmAttributes);
			cout << "PowerConsumption: " << config->MaxPower << " -> HighSpeed:" << config->MaxPower * 2 << "mA, SuperSpeed:" << config->MaxPower * 8 << "mA" << endl;
			if (config->extra_length > 0) cout << "Detected extra descriptors length: " << config->extra_length << endl;
			printf("Num interfaces: %d\n", config->bNumInterfaces);
			for (int i = 0; i < (int)config->bNumInterfaces; i++) {
				cout << endl << "Configuration[" << l << "] --> Interface[" << i << "]:" << endl;
				printf("Num alternate settings: %d\n", config->interface[i].num_altsetting);
				for (int j = 0; j < config->interface[i].num_altsetting; ++j) {
					cout << "Configuration[" << l << "] --> Interface[" << i << "] --> Setting[" << j << "]:" << endl;
					printf("Descriptor length: %d\n", config->interface[i].altsetting[j].bLength);
					printDT((libusb_descriptor_type)config->interface[i].altsetting[j].bDescriptorType);
					printf("Interface number: %d\n", config->interface[i].altsetting[j].bInterfaceNumber);
					printf("Alternate setting value: %d\n", config->interface[i].altsetting[j].bAlternateSetting);
					printDC((libusb_class_code)config->interface[i].altsetting[j].bInterfaceClass);
					printf("Interface SubClass: %d\n", config->interface[i].altsetting[j].bInterfaceSubClass);
					printf("Interface protocol: %d\n", config->interface[i].altsetting[j].bInterfaceProtocol);
					if (config->interface[i].altsetting[j].extra_length > 0) cout << "Detected extra descriptors length: " << config->interface[i].altsetting[j].extra_length << endl;

					ret = (libusb_error)libusb_open(dev, &handle); //read iInterface
					if (ret != LIBUSB_SUCCESS) {
						printf("Open device: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
					}
					else {
						if (config->interface[i].altsetting[j].iInterface != 0) {
							ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, config->interface[i].altsetting[j].iInterface, &data[0], 256);
							if (ret > 0)
								printf("Interface: %s \n", data);
							else
								printf("Read Interface: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
						}
						else
							cout << "no Interface string" << endl;
						libusb_close(handle);
					}

					printf("Num endpoints: %d\n", config->interface[i].altsetting[j].bNumEndpoints);
					for (int k = 0; k < config->interface[i].altsetting[j].bNumEndpoints; ++k) {
						cout << endl << "Configuration[" << l << "] --> Interface[" << i << "] --> Setting[" << j << "] --> Endpoint[" << k << "]:" << endl;
						printf("Descriptor length: %d\n", config->interface[i].altsetting[j].endpoint[k].bLength);
						printDT((libusb_descriptor_type)config->interface[i].altsetting[j].endpoint[k].bDescriptorType);
						printf("EndpointAddress: %d\n", config->interface[i].altsetting[j].endpoint[k].bEndpointAddress);
						printf("EndpointNumber: %d\n", (config->interface[i].altsetting[j].endpoint[k].bEndpointAddress & 0xf));
						if (config->interface[i].altsetting[j].endpoint[k].bEndpointAddress >> 7 & 0x1)
							cout << "EndpointDirection: LIBUSB_ENDPOINT_IN (device - to - host)" << endl;
						else
							cout << "EndpointDirection: LIBUSB_ENDPOINT_OUT (host - to - device)" << endl;
						printf("Attributes: %d\n", config->interface[i].altsetting[j].endpoint[k].bmAttributes);
						cout << "Transfer type: ";
						switch (config->interface[i].altsetting[j].endpoint[k].bmAttributes & 0x3) {
						case 0: cout << "LIBUSB_TRANSFER_TYPE_CONTROL (Control endpoint)" << endl; break;
						case 1: cout << "LIBUSB_TRANSFER_TYPE_ISOCHRONOUS (Isochronous endpoint)" << endl; break;
						case 2: cout << "LIBUSB_TRANSFER_TYPE_BULK (Bulk endpoint)" << endl; break;
						case 3: cout << "LIBUSB_TRANSFER_TYPE_INTERRUPT (Interrupt endpoint)" << endl; break;
						case 4: cout << "LIBUSB_TRANSFER_TYPE_BULK_STREAM (Stream endpoint)" << endl;
						}
						cout << "Sync type: ";
						switch (config->interface[i].altsetting[j].endpoint[k].bmAttributes >> 2 & 0x3) {
						case 0: cout << "LIBUSB_ISO_SYNC_TYPE_NONE (No synchronization)" << endl; break;
						case 1: cout << "LIBUSB_ISO_SYNC_TYPE_ASYNC (Asynchronous)" << endl; break;
						case 2: cout << "LIBUSB_ISO_SYNC_TYPE_ADAPTIVE (Adaptive)" << endl; break;
						case 3: cout << "LIBUSB_ISO_SYNC_TYPE_SYNC (Synchronous)" << endl;
						}
						cout << "Usage type: ";
						switch (config->interface[i].altsetting[j].endpoint[k].bmAttributes >> 4 & 0x3) {
						case 0: cout << "LIBUSB_ISO_USAGE_TYPE_DATA (Data endpoint)" << endl; break;
						case 1: cout << "LIBUSB_ISO_USAGE_TYPE_FEEDBACK (Feedback endpoint)" << endl; break;
						case 2: cout << "LIBUSB_ISO_USAGE_TYPE_IMPLICIT (Implicit feedback Data endpoint)" << endl; break;
						default: cout << "unknown usage type" << endl;
						}
						printf("Max packet size: %d\n", config->interface[i].altsetting[j].endpoint[k].wMaxPacketSize);
						printf("Data transfer polling interval: %d\n", config->interface[i].altsetting[j].endpoint[k].bInterval);
						printf("Sync feedback rate (only audio devices): %d\n", config->interface[i].altsetting[j].endpoint[k].bRefresh);
						printf("Sync endpoint addr (only audio devices): %d\n", config->interface[i].altsetting[j].endpoint[k].bSynchAddress);
						if (config->interface[i].altsetting[j].endpoint[k].extra_length > 0) cout << "Detected extra descriptors length: " << config->interface[i].altsetting[j].endpoint[k].extra_length << endl;
					}

				}
			}
			/*cout << "Interfaces: " << (int)config->bNumInterfaces << endl;
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
			}*/
			libusb_free_config_descriptor(config);
		}
	}
}