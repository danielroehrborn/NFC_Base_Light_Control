#include "UIForm.h"
#include "libusb.h"
#include "PortalConnection.h"
#include "InfinityPortal.h"
#include "DimensionsPortal.h"

using namespace UIProject;
libusb_context* usbcontext;
libusb_device** usbdevices;
PortalConnection* connection = new PortalConnection;

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	libusb_error ret = (libusb_error)libusb_init(&usbcontext);
	if (ret != LIBUSB_SUCCESS) {
		textBox33->AppendText("libusb init failed\r\n");
	}
	colorPlatformComboBox->SelectedIndex = 0;
	comboBox2->SelectedIndex = 0;
	textBox33->AppendText("Scan for devices, then choose one device to connect. Activation needed once after connected to a USB port.");
}
bool closing = false;
System::Void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (closing) return;
	closing = true;
	delete connection;
	libusb_exit(usbcontext);
	Application::Exit();
}

class DeviceInfo {
public:
	unsigned char deviceNum;
	libusb_device_descriptor descriptor;
};
System::Void UIProject::MyForm::ScanDevicesButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	comboBox1->Items->Clear();
	libusb_free_device_list(usbdevices, 1);
	int devicesCount = libusb_get_device_list(usbcontext, &usbdevices);
	libusb_device_descriptor descriptor;

	for (int i = 0; i < devicesCount; i++) {
		libusb_get_device_descriptor(usbdevices[i], &descriptor);
		if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x241) {
			comboBox1->Items->Add(String::Concat(i, ". venID: ", descriptor.idVendor.ToString("X"), " devID: ", descriptor.idProduct.ToString("X"), " LegoDimensionsPortal"));
		}
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x129) {
			comboBox1->Items->Add(String::Concat(i, ". venID: ", descriptor.idVendor.ToString("X"), " devID: ", descriptor.idProduct.ToString("X"), " DisneyInfinityBase"));
		}
		else if (descriptor.idVendor == 0x1430 && descriptor.idProduct == 0x150) {
			comboBox1->Items->Add(String::Concat(i, ". venID: ", descriptor.idVendor.ToString("X"), " devID: ", descriptor.idProduct.ToString("X"), " SkylandersPortal"));
		}
		else {
			comboBox1->Items->Add(String::Concat(i, ". venID: ", descriptor.idVendor.ToString("X"), " devID: ", descriptor.idProduct.ToString("X")));
		}
	}
	comboBox1->SelectedIndex = 0;
}

System::Void UIProject::MyForm::comboBox1_SelectionChangeCommitted(System::Object ^ sender, System::EventArgs ^ e)
{
	checkBox4->Checked = false;
	checkBox5->Checked = false;
	int interfaceNum = int::Parse(sendInterfaceTextBox->Text);
	//libusb_error ret = connection.connect(usbdevices[comboBox1->SelectedIndex], interfaceNum);
	libusb_error ret = connection->openDevice(usbdevices[comboBox1->SelectedIndex]);
	if (ret != LIBUSB_SUCCESS) {
		String^ errorName = gcnew String(libusb_error_name(ret));
		String^ errorText = gcnew String(libusb_strerror(ret));
		textBox33->AppendText("\r\nlibusb open device failed: " + errorName + " " + errorText);
		//printf("LegoDimensionsPortal Connect: %s\n\t%s\n", libusb_error_name(ret), libusb_strerror(ret));
	}
	else {
		libusb_error ret = connection->claimOpenedDevice(interfaceNum);
		if (ret != LIBUSB_SUCCESS) {
			String^ errorName = gcnew String(libusb_error_name(ret));
			String^ errorText = gcnew String(libusb_strerror(ret));
			textBox33->AppendText("\r\nlibusb claim device failed: " + errorName + " " + errorText);
		}
		else {
			textBox33->AppendText("\r\nDevice " + comboBox1->SelectedIndex + " interface " + interfaceNum + " connected");
			return;
		}
	}
	textBox33->AppendText("\r\nDevice " + comboBox1->SelectedIndex + " interface " + interfaceNum + " connection failed");
}
DimensionsPortalInterface* ld1data = new DimensionsPortalInput;
libusb_error ret;
System::Void UIProject::MyForm::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nActivation message");
	unsigned char* messageData = ld1data->activate();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::hScrollBar2_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	RedLabel->BackColor = System::Drawing::Color::FromArgb(hScrollBar2->Value, 0, 0);
	FullColorLabel->BackColor = System::Drawing::Color::FromArgb(hScrollBar2->Value, hScrollBar3->Value, hScrollBar4->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox1->Text = String::Concat(hScrollBar2->Value);
	textBox11->Text = String::Concat(hScrollBar2->Value);
	textBox36->Text = String::Concat(hScrollBar2->Value);
	if (checkBox4->Checked) button5->PerformClick();
	else if (checkBox5->Checked) button13->PerformClick();
}

System::Void UIProject::MyForm::hScrollBar3_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	GreenLabel->BackColor = System::Drawing::Color::FromArgb(0, hScrollBar3->Value, 0);
	FullColorLabel->BackColor = System::Drawing::Color::FromArgb(hScrollBar2->Value, hScrollBar3->Value, hScrollBar4->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox2->Text = String::Concat(hScrollBar3->Value);
	textBox10->Text = String::Concat(hScrollBar3->Value);
	textBox35->Text = String::Concat(hScrollBar3->Value);
	if (checkBox4->Checked) button5->PerformClick();
	else if (checkBox5->Checked) button13->PerformClick();
}

System::Void UIProject::MyForm::hScrollBar4_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	BlueLabel->BackColor = System::Drawing::Color::FromArgb(0, 0, hScrollBar4->Value);
	FullColorLabel->BackColor = System::Drawing::Color::FromArgb(hScrollBar2->Value, hScrollBar3->Value, hScrollBar4->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox3->Text = String::Concat(hScrollBar4->Value);
	textBox9->Text = String::Concat(hScrollBar4->Value);
	textBox34->Text = String::Concat(hScrollBar4->Value);
	if (checkBox4->Checked) button5->PerformClick();
	else if (checkBox5->Checked) button13->PerformClick();
}

System::Void UIProject::MyForm::button5_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nSet color r:" + textBox1->Text + " g:" + textBox2->Text + " b:" + textBox3->Text);
	unsigned char r = int::Parse(textBox1->Text);
	unsigned char g = int::Parse(textBox2->Text);
	unsigned char b = int::Parse(textBox3->Text);
	unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { r, g, b });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

unsigned char bytearray[256];
System::Void UIProject::MyForm::button6_Click(System::Object ^ sender, System::EventArgs ^ e)
{

	int messageLength = int::Parse(textBox42->Text);
	char* stringarray2 = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(textBox43->Text).ToPointer();
	char* stringarray3 = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(textBox44->Text).ToPointer();
	int sendEndpoint = strtol(stringarray2, NULL, 16);
	int receiveEndpoint = strtol(stringarray3, NULL, 16);

	char* stringarray = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(messageTextBox->Text).ToPointer();
	char highStringChar, lowStringChar;
	for (int i = 0; i < messageLength; i++) {
		if (stringarray[i * 2] == NULL || stringarray[i * 2 + 1] == NULL) {
			textBox33->AppendText("\r\nCannot send: Message must have " + messageLength + " bytes");
			return;
		}
		highStringChar = stringarray[i * 2];
		lowStringChar = stringarray[i * 2 + 1];
		bytearray[i] = strtol((const char*)&highStringChar, NULL, 16) << 4 | strtol((const char*)&lowStringChar, NULL, 16);
	}
	ret = connection->transceiveData(bytearray, sendEndpoint, messageLength);
	if (ret != LIBUSB_SUCCESS) {
		String^ errorName = gcnew String(libusb_error_name(ret));
		String^ errorText = gcnew String(libusb_strerror(ret));
		textBox33->AppendText("\r\nlibusb bulk transfer failed: " + errorName + " " + errorText);
	}
	else {
		bool responseReceived = false;
		int receivedLength = 0;
		do {
			ret = connection->transceiveData(bytearray, receiveEndpoint, messageLength, &receivedLength);
			if (ret == LIBUSB_SUCCESS) {
				responseReceived = true;
				String^ receiveStr = gcnew String("");
				for (int i = 0; i < receivedLength && i < 256; ++i) {
					receiveStr += bytearray[i].ToString("X2");
				}
				textBox33->AppendText("\r\nReceived " + receivedLength + " bytes: " + receiveStr);
			}
			else if (!responseReceived) {
				textBox33->AppendText("\r\nNo response received");
			}
		} while (ret == LIBUSB_SUCCESS);

	}
}

System::Void UIProject::MyForm::hScrollBar6_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label55->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, 0, 0);
	label56->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, hScrollBar5->Value, hScrollBar1->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox14->Text = String::Concat(hScrollBar6->Value);
}

System::Void UIProject::MyForm::hScrollBar5_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label54->BackColor = System::Drawing::Color::FromArgb(0, hScrollBar5->Value, 0);
	label56->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, hScrollBar5->Value, hScrollBar1->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox13->Text = String::Concat(hScrollBar5->Value);
}

System::Void UIProject::MyForm::hScrollBar1_Scroll_1(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label53->BackColor = System::Drawing::Color::FromArgb(0, 0, hScrollBar1->Value);
	label56->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, hScrollBar5->Value, hScrollBar1->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox12->Text = String::Concat(hScrollBar1->Value);
}

System::Void UIProject::MyForm::hScrollBar9_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label63->BackColor = System::Drawing::Color::FromArgb(hScrollBar9->Value, 0, 0);
	label64->BackColor = System::Drawing::Color::FromArgb(hScrollBar9->Value, hScrollBar8->Value, hScrollBar7->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox17->Text = String::Concat(hScrollBar9->Value);
}

System::Void UIProject::MyForm::hScrollBar8_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label62->BackColor = System::Drawing::Color::FromArgb(0, hScrollBar8->Value, 0);
	label64->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, hScrollBar8->Value, hScrollBar7->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox16->Text = String::Concat(hScrollBar8->Value);
}

System::Void UIProject::MyForm::hScrollBar7_Scroll(System::Object ^ sender, System::Windows::Forms::ScrollEventArgs ^ e)
{
	label61->BackColor = System::Drawing::Color::FromArgb(0, 0, hScrollBar7->Value);
	label64->BackColor = System::Drawing::Color::FromArgb(hScrollBar6->Value, hScrollBar8->Value, hScrollBar7->Value);
	//ret = connection.sendData(ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value }));
	textBox15->Text = String::Concat(hScrollBar7->Value);
}

System::Void UIProject::MyForm::button7_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nFade color to r:" + textBox1->Text + " g:" + textBox2->Text + " b:" + textBox3->Text);
	unsigned char r = int::Parse(textBox1->Text);
	unsigned char g = int::Parse(textBox2->Text);
	unsigned char b = int::Parse(textBox3->Text);
	unsigned char fadeLen = int::Parse(textBox4->Text);
	unsigned char numPulses = int::Parse(textBox5->Text);
	unsigned char* messageData = ld1data->fade((Platform)colorPlatformComboBox->SelectedIndex, { 0, fadeLen, numPulses, {r, g, b} });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button8_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nFlash color to r:" + textBox1->Text + " g:" + textBox2->Text + " b:" + textBox3->Text);
	unsigned char r = int::Parse(textBox1->Text);
	unsigned char g = int::Parse(textBox2->Text);
	unsigned char b = int::Parse(textBox3->Text);
	unsigned char onLen = int::Parse(textBox6->Text);
	unsigned char offLen = int::Parse(textBox7->Text);
	unsigned char numPulses = int::Parse(textBox8->Text);
	unsigned char* messageData = ld1data->flash((Platform)colorPlatformComboBox->SelectedIndex, { 0, onLen, offLen, numPulses,{ r, g, b } });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button9_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nSet group color r1:" + textBox11->Text + " g1:" + textBox10->Text + " b1:" + textBox9->Text +
		"r2:" + textBox14->Text + " g2:" + textBox13->Text + " b2:" + textBox2->Text +
		"r3:" + textBox17->Text + " g3:" + textBox16->Text + " b3:" + textBox5->Text);
	unsigned char r1 = int::Parse(textBox11->Text);
	unsigned char g1 = int::Parse(textBox10->Text);
	unsigned char b1 = int::Parse(textBox9->Text);
	unsigned char r2 = int::Parse(textBox14->Text);
	unsigned char g2 = int::Parse(textBox13->Text);
	unsigned char b2 = int::Parse(textBox12->Text);
	unsigned char r3 = int::Parse(textBox17->Text);
	unsigned char g3 = int::Parse(textBox16->Text);
	unsigned char b3 = int::Parse(textBox15->Text);
	unsigned char onLen = int::Parse(textBox6->Text);
	unsigned char offLen = int::Parse(textBox7->Text);
	unsigned char numPulses = int::Parse(textBox8->Text);
	unsigned char* messageData = ld1data->colorGroup({ checkBox1->Checked, { r1, g1, b1 } }, { checkBox2->Checked, { r2, g2, b2 } }, { checkBox3->Checked, { r3, g3, b3 } });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button10_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nFade group color to r1:" + textBox11->Text + " g1:" + textBox10->Text + " b1:" + textBox9->Text +
		"r2:" + textBox14->Text + " g2:" + textBox13->Text + " b2:" + textBox2->Text +
		"r3:" + textBox17->Text + " g3:" + textBox16->Text + " b3:" + textBox5->Text);
	unsigned char r1 = int::Parse(textBox11->Text);
	unsigned char g1 = int::Parse(textBox10->Text);
	unsigned char b1 = int::Parse(textBox9->Text);
	unsigned char r2 = int::Parse(textBox14->Text);
	unsigned char g2 = int::Parse(textBox13->Text);
	unsigned char b2 = int::Parse(textBox12->Text);
	unsigned char r3 = int::Parse(textBox17->Text);
	unsigned char g3 = int::Parse(textBox16->Text);
	unsigned char b3 = int::Parse(textBox15->Text);
	unsigned char fadeLen1 = int::Parse(textBox18->Text);
	unsigned char numPulses1 = int::Parse(textBox19->Text);
	unsigned char fadeLen2 = int::Parse(textBox21->Text);
	unsigned char numPulses2 = int::Parse(textBox20->Text);
	unsigned char fadeLen3 = int::Parse(textBox23->Text);
	unsigned char numPulses3 = int::Parse(textBox22->Text);
	unsigned char* messageData = ld1data->fadeGroup({ checkBox1->Checked,fadeLen1,numPulses1,{ r1, g1, b1 } }, { checkBox2->Checked,fadeLen2,numPulses2,{ r2, g2, b2 } }, { checkBox3->Checked,fadeLen3,numPulses3,{ r3, g3, b3 } });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button11_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\Flash group color to r1:" + textBox11->Text + " g1:" + textBox10->Text + " b1:" + textBox9->Text +
		"r2:" + textBox14->Text + " g2:" + textBox13->Text + " b2:" + textBox2->Text +
		"r3:" + textBox17->Text + " g3:" + textBox16->Text + " b3:" + textBox5->Text);
	unsigned char r1 = int::Parse(textBox11->Text);
	unsigned char g1 = int::Parse(textBox10->Text);
	unsigned char b1 = int::Parse(textBox9->Text);
	unsigned char r2 = int::Parse(textBox14->Text);
	unsigned char g2 = int::Parse(textBox13->Text);
	unsigned char b2 = int::Parse(textBox12->Text);
	unsigned char r3 = int::Parse(textBox17->Text);
	unsigned char g3 = int::Parse(textBox16->Text);
	unsigned char b3 = int::Parse(textBox15->Text);
	unsigned char onLen1 = int::Parse(textBox26->Text);
	unsigned char offLen1 = int::Parse(textBox25->Text);
	unsigned char numPulses1 = int::Parse(textBox24->Text);
	unsigned char onLen2 = int::Parse(textBox29->Text);
	unsigned char offLen2 = int::Parse(textBox28->Text);
	unsigned char numPulses2 = int::Parse(textBox27->Text);
	unsigned char onLen3 = int::Parse(textBox32->Text);
	unsigned char offLen3 = int::Parse(textBox31->Text);
	unsigned char numPulses3 = int::Parse(textBox30->Text);
	unsigned char* messageData = ld1data->flashGroup({ checkBox1->Checked,onLen1,offLen1,numPulses1,{ r1, g1, b1 } }, { checkBox2->Checked,onLen2,offLen2,numPulses2,{ r2, g2, b2 } }, { checkBox3->Checked,onLen3,offLen3,numPulses3,{ r3, g3, b3 } });

	//unsigned char* messageData = ld1data->color((Platform)colorPlatformComboBox->SelectedIndex, { (unsigned char)hScrollBar2->Value, (unsigned char)hScrollBar3->Value, (unsigned char)hScrollBar4->Value });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button17_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int messageLength = int::Parse(textBox42->Text);
	char* stringarray = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(textBox44->Text).ToPointer();
	int receiveEndpoint = strtol(stringarray, NULL, 16);
	bool responseReceived = false;
	int receivedLength = 0;
	do {
		ret = connection->transceiveData(bytearray, receiveEndpoint, messageLength, &receivedLength);
		if (ret == LIBUSB_SUCCESS) {
			responseReceived = true;
			String^ receiveStr = gcnew String("");
			for (int i = 0; i < receivedLength && i < 256; ++i) {
				receiveStr += bytearray[i].ToString("X2");
			}
			textBox33->AppendText("\r\nReceived: " + receiveStr);
		}
		else if (!responseReceived) {
			textBox33->AppendText("\r\nNothing received");
		}
	} while (ret == LIBUSB_SUCCESS);
}

InfinityBaseInput di1data;
System::Void UIProject::MyForm::button12_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nActivation message");
	unsigned char* messageData = di1data.activate();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
	/*
	//test animation
	char repeat = 2;
	do {
		messageData = di1data.fade(InfinityBaseInput::Platform::center, { 10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = di1data.fade(InfinityBaseInput::Platform::left, { 10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = di1data.fade(InfinityBaseInput::Platform::right, { 10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(500);
		messageData = di1data.fade(InfinityBaseInput::Platform::center, { 10,1,{ 20,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = di1data.fade(InfinityBaseInput::Platform::left, { 10,1,{ 0,20,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = di1data.fade(InfinityBaseInput::Platform::right, { 10,1,{ 0,0,20 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(500);
	} while (repeat--);
	messageData = di1data.fade(InfinityBaseInput::Platform::all, { 50,0xff,{ 0,0,0 } });
	boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();*/
}

System::Void UIProject::MyForm::button13_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nSet color r:" + textBox36->Text + " g:" + textBox35->Text + " b:" + textBox34->Text);
	unsigned char r = int::Parse(textBox36->Text);
	unsigned char g = int::Parse(textBox35->Text);
	unsigned char b = int::Parse(textBox34->Text);
	unsigned char* messageData = di1data.color((InfinityBaseInput::Platform)comboBox2->SelectedIndex, { r, g, b });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button14_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nFade color to r:" + textBox36->Text + " g:" + textBox35->Text + " b:" + textBox34->Text);
	unsigned char r = int::Parse(textBox36->Text);
	unsigned char g = int::Parse(textBox35->Text);
	unsigned char b = int::Parse(textBox34->Text);
	unsigned char fadeLen = int::Parse(textBox38->Text);
	unsigned char numPulses = int::Parse(textBox37->Text);
	unsigned char* messageData = di1data.fade((InfinityBaseInput::Platform)comboBox2->SelectedIndex, { fadeLen, numPulses,{ r, g, b } });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button15_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nFlash color to r:" + textBox36->Text + " g:" + textBox35->Text + " b:" + textBox34->Text);
	unsigned char r = int::Parse(textBox36->Text);
	unsigned char g = int::Parse(textBox35->Text);
	unsigned char b = int::Parse(textBox34->Text);
	unsigned char onLen = int::Parse(textBox41->Text);
	unsigned char offLen = int::Parse(textBox40->Text);
	unsigned char numPulses = int::Parse(textBox39->Text);
	unsigned char* messageData = di1data.flash((InfinityBaseInput::Platform)comboBox2->SelectedIndex, { onLen, offLen, numPulses,{ r, g, b } });
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button16_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox33->AppendText("\r\nRequest tag id");
	unsigned char* messageData = di1data.getTagId();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}

System::Void UIProject::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	unsigned char* messageData;
	String^ boxstr = gcnew String("");
	textBox33->AppendText("\r\nRunning demo animation");
	char repeat = 1;
	do {
		colorPlatformComboBox->SelectedIndex = 1;//platform
		hScrollBar2->Value = 0;//red
		hScrollBar3->Value = 0;//green
		hScrollBar4->Value = 0;//blue
		textBox1->Text = String::Concat("0");//red
		textBox2->Text = String::Concat("0");//green
		textBox3->Text = String::Concat("0");//blue
		textBox4->Text = String::Concat("10");//fadeLen
		textBox5->Text = String::Concat("1");//numPulses
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		colorPlatformComboBox->SelectedIndex = 2;//platform
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		colorPlatformComboBox->SelectedIndex = 3;//platform
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(500);
		colorPlatformComboBox->SelectedIndex = 1;//platform
		textBox1->Text = String::Concat("20");//red
		hScrollBar2->Value = 20;//red
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		colorPlatformComboBox->SelectedIndex = 2;//platform
		hScrollBar2->Value = 0;//red
		hScrollBar3->Value = 20;//green
		textBox1->Text = String::Concat("0");//red
		textBox2->Text = String::Concat("20");//green
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		colorPlatformComboBox->SelectedIndex = 3;//platform
		hScrollBar3->Value = 0;//green
		hScrollBar4->Value = 20;//blue
		textBox2->Text = String::Concat("0");//green
		textBox3->Text = String::Concat("20");//blue
		button7->PerformClick();//fade

		System::Threading::Thread::Sleep(500);
	} while (--repeat);
	colorPlatformComboBox->SelectedIndex = 0;//platform
	hScrollBar4->Value = 0;//blue
	textBox3->Text = String::Concat("0");//blue
	textBox4->Text = String::Concat("40");//fadeLen
	textBox5->Text = String::Concat("255");//numPulses
	button7->PerformClick();//fade
}

System::Void UIProject::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	unsigned char* messageData;
	String^ boxstr = gcnew String("");
	textBox33->AppendText("\r\nRunning demo animation");
	char repeat = 1;
	do {
		comboBox2->SelectedIndex = 1;//platform
		hScrollBar2->Value = 0;//red
		hScrollBar3->Value = 0;//green
		hScrollBar4->Value = 0;//blue
		textBox36->Text = String::Concat("0");//red
		textBox35->Text = String::Concat("0");//green
		textBox34->Text = String::Concat("0");//blue
		textBox38->Text = String::Concat("10");//fadeLen
		textBox37->Text = String::Concat("1");//numPulses
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		comboBox2->SelectedIndex = 2;//platform
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		comboBox2->SelectedIndex = 3;//platform
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(500);
		comboBox2->SelectedIndex = 1;//platform
		textBox36->Text = String::Concat("20");//red
		hScrollBar2->Value = 20;//red
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		comboBox2->SelectedIndex = 2;//platform
		hScrollBar2->Value = 0;//red
		hScrollBar3->Value = 20;//green
		textBox36->Text = String::Concat("0");//red
		textBox35->Text = String::Concat("20");//green
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(250);
		comboBox2->SelectedIndex = 3;//platform
		hScrollBar3->Value = 0;//green
		hScrollBar4->Value = 20;//blue
		textBox35->Text = String::Concat("0");//green
		textBox34->Text = String::Concat("20");//blue
		button14->PerformClick();//fade

		System::Threading::Thread::Sleep(500);
	} while (--repeat);
	comboBox2->SelectedIndex = 0;//platform
	hScrollBar4->Value = 0;//blue
	textBox34->Text = String::Concat("0");//blue
	textBox38->Text = String::Concat("40");//fadeLen
	textBox37->Text = String::Concat("255");//numPulses
	button14->PerformClick();//fade
}

System::Void UIProject::MyForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	treeView1->Nodes->Clear();
	treeView1->BeginUpdate();
	/*treeView1->Nodes->Add("22");
	treeView1->Nodes[0]->Nodes->Add("d");
	treeView1->Nodes->Add("Device " + 5)->Nodes->Add("Read descriptor error");*/


	libusb_error ret;
	libusb_device **devs;
	libusb_device_descriptor descriptor;
	int devicesCount = libusb_get_device_list(usbcontext, &devs);
	if (devicesCount < 0) {
		textBox33->AppendText("\r\nlibusb get device list failed");
		return;
	}
	for (int i = 0; i < devicesCount; i++) {
		ret = (libusb_error)libusb_get_device_descriptor(devs[i], &descriptor);
		if (ret != LIBUSB_SUCCESS) {
			textBox33->AppendText("\r\nRead Device " + i + " descriptor failed");
			treeView1->Nodes->Add("Device " + i)->Nodes->Add("Read descriptor error");
			continue;
		}
		System::Windows::Forms::TreeNode^ curDevice;
		if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x241)
			curDevice = treeView1->Nodes->Add("Device " + i + " venID:" + descriptor.idVendor.ToString("X") + " prodID:" + descriptor.idProduct.ToString("X") + " LegoDimensionsPortal");
		else if (descriptor.idVendor == 0x0e6f && descriptor.idProduct == 0x129)
			curDevice = treeView1->Nodes->Add("Device " + i + " venID:" + descriptor.idVendor.ToString("X") + " prodID:" + descriptor.idProduct.ToString("X") + " DisneyInfinityBase");
		else if (descriptor.idVendor == 0x1430 && descriptor.idProduct == 0x150)
			curDevice = treeView1->Nodes->Add("Device " + i + " venID:" + descriptor.idVendor.ToString("X") + " prodID:" + descriptor.idProduct.ToString("X") + " SkylandersPortal");
		else curDevice = treeView1->Nodes->Add("Device " + i + " venID:" + descriptor.idVendor.ToString("X") + " prodID:" + descriptor.idProduct.ToString("X"));
		curDevice->Nodes->Add("Descriptor length: " + descriptor.bLength);
		switch (descriptor.bDescriptorType) {
		case LIBUSB_DT_DEVICE: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE"); break;
		case LIBUSB_DT_CONFIG: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_CONFIG"); break;
		case LIBUSB_DT_STRING: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_STRING"); break;
		case LIBUSB_DT_INTERFACE: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_INTERFACE"); break;
		case LIBUSB_DT_ENDPOINT: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_ENDPOINT"); break;
		case LIBUSB_DT_BOS: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_BOS"); break;
		case LIBUSB_DT_DEVICE_CAPABILITY: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE_CAPABILITY"); break;
		case LIBUSB_DT_HID: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_HID"); break;
		case LIBUSB_DT_REPORT: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_REPORT"); break;
		case LIBUSB_DT_PHYSICAL: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_PHYSICAL"); break;
		case LIBUSB_DT_HUB: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_HUB"); break;
		case LIBUSB_DT_SUPERSPEED_HUB: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_SUPERSPEED_HUB"); break;
		case LIBUSB_DT_SS_ENDPOINT_COMPANION: treeView1->Nodes[i]->Nodes->Add("Descriptor type: LIBUSB_DT_SS_ENDPOINT_COMPANION"); break;
		default: treeView1->Nodes[i]->Nodes->Add("Descriptor type: unknown Descriptor type"); break;
		}
		curDevice->Nodes->Add("USB spec: " + (descriptor.bcdUSB >> 8) + "." + ((descriptor.bcdUSB >> 4) & 0xf));
		switch (descriptor.bDeviceClass) {
		case LIBUSB_CLASS_PER_INTERFACE: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_PER_INTERFACE"); break;
		case LIBUSB_CLASS_AUDIO: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_AUDIO"); break;
		case LIBUSB_CLASS_COMM: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_COMM"); break;
		case LIBUSB_CLASS_HID: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_HID \n"); break;
		case LIBUSB_CLASS_PHYSICAL: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_PER_INTERFACE"); break;
		case LIBUSB_CLASS_PRINTER: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_PRINTER"); break;
		case LIBUSB_CLASS_IMAGE: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_IMAGE"); break;
		case LIBUSB_CLASS_MASS_STORAGE: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_MASS_STORAGE"); break;
		case LIBUSB_CLASS_HUB: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_HUB"); break;
		case LIBUSB_CLASS_DATA: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_DATA"); break;
		case LIBUSB_CLASS_SMART_CARD: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_SMART_CARD"); break;
		case LIBUSB_CLASS_CONTENT_SECURITY: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_CONTENT_SECURITY"); break;
		case LIBUSB_CLASS_VIDEO: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_VIDEO"); break;
		case LIBUSB_CLASS_PERSONAL_HEALTHCARE: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_PERSONAL_HEALTHCARE"); break;
		case LIBUSB_CLASS_DIAGNOSTIC_DEVICE: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_DIAGNOSTIC_DEVICE"); break;
		case LIBUSB_CLASS_WIRELESS: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_WIRELESS"); break;
		case LIBUSB_CLASS_APPLICATION: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_APPLICATION"); break;
		case LIBUSB_CLASS_VENDOR_SPEC: treeView1->Nodes[i]->Nodes->Add("Device class: LIBUSB_CLASS_VENDOR_SPEC"); break;
		default: treeView1->Nodes[i]->Nodes->Add("Device class: unknown device class");
		}
		curDevice->Nodes->Add("Device subclass: " + descriptor.bDeviceSubClass);
		curDevice->Nodes->Add("Device protocol: " + descriptor.bDeviceProtocol);
		curDevice->Nodes->Add("MaxPacketSize Endpoint0 : " + descriptor.bMaxPacketSize0);
		curDevice->Nodes->Add("VendorID: " + descriptor.idVendor.ToString("X"));
		curDevice->Nodes->Add("ProductID: " + descriptor.idProduct.ToString("X"));
		curDevice->Nodes->Add("Device release num: " + ((descriptor.bcdDevice >> 12) & 0xf) + "." +
			((descriptor.bcdDevice >> 12) & 0xf) + "." + ((descriptor.bcdDevice >> 4) & 0xf) + "." + (descriptor.bcdDevice & 0xf));
		curDevice->Nodes->Add("Number of possible configurations: " + descriptor.bNumConfigurations);
		libusb_device_handle* handle;
		ret = (libusb_error)libusb_open(devs[i], &handle);
		if (ret != LIBUSB_SUCCESS) {
			String^ errorName = gcnew String(libusb_error_name(ret));
			String^ errorText = gcnew String(libusb_strerror(ret));
			//textBox33->AppendText("\r\nlibusb open device failed: " + errorName + " " + errorText);
			treeView1->Nodes[i]->Nodes->Add("Manufacturer: Open device error");
			treeView1->Nodes[i]->Nodes->Add("Product: Open device error");
			treeView1->Nodes[i]->Nodes->Add("SerialNum: Open device error");
		}
		else {
			//Manufacturer string
			unsigned char data[256];
			if (descriptor.iManufacturer != 0) {
				for (int i = 0; i < 256; ++i)data[i] = 0;
				ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, descriptor.iManufacturer, &data[0], 256);
				if (ret > 0) {
					String^ manufacturerText = gcnew String((char*)data);
					treeView1->Nodes[i]->Nodes->Add("Manufacturer: " + manufacturerText);
				}
				else {
					String^ errorName = gcnew String(libusb_error_name(ret));
					String^ errorText = gcnew String(libusb_strerror(ret));
					//textBox33->AppendText("\r\nlibusb read manufacturer text failed: " + errorName + " " + errorText);
					treeView1->Nodes[i]->Nodes->Add("Manufacturer: Read text error");
				}
			}
			else
				treeView1->Nodes[i]->Nodes->Add("Manufacturer: no information");
			//Product string
			if (descriptor.iProduct != 0) {
				for (int i = 0; i < 256; ++i)data[i] = 0;
				ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, descriptor.iProduct, &data[0], 256);
				if (ret > 0) {
					String^ productText = gcnew String((char*)data);
					treeView1->Nodes[i]->Nodes->Add("Product: " + productText);
				}
				else {
					String^ errorName = gcnew String(libusb_error_name(ret));
					String^ errorText = gcnew String(libusb_strerror(ret));
					textBox33->AppendText("\r\nlibusb read product text failed: " + errorName + " " + errorText);
					treeView1->Nodes[i]->Nodes->Add("Product: Read text error");
				}
			}
			else
				treeView1->Nodes[i]->Nodes->Add("Product: no information");
			//Serialnumber string
			if (descriptor.iSerialNumber != 0) {
				for (int i = 0; i < 256; ++i)data[i] = 0;
				ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, descriptor.iSerialNumber, &data[0], 256);
				if (ret > 0) {
					String^ serialnumberText = gcnew String((char*)data);
					treeView1->Nodes[i]->Nodes->Add("Serialnumber: " + serialnumberText);
				}
				else {
					String^ errorName = gcnew String(libusb_error_name(ret));
					String^ errorText = gcnew String(libusb_strerror(ret));
					textBox33->AppendText("\r\nlibusb read product text failed: " + errorName + " " + errorText);
					treeView1->Nodes[i]->Nodes->Add("Serialnumber: Read text error");
				}
			}
			else
				treeView1->Nodes[i]->Nodes->Add("Serialnumber: no information");
			libusb_close(handle);
		}
		libusb_config_descriptor *config;
		//Iterate configurations
		for (int l = 0; l < descriptor.bNumConfigurations; ++l) {
			ret = (libusb_error)libusb_get_config_descriptor(devs[i], l, &config);
			if (ret != LIBUSB_SUCCESS) {
				String^ errorName = gcnew String(libusb_error_name(ret));
				String^ errorText = gcnew String(libusb_strerror(ret));
				//textBox33->AppendText("\r\nlibusb get config descriptor failed: " + errorName + " " + errorText);
				treeView1->Nodes[i]->Nodes->Add("Configuration " + l)->Nodes->Add("Read error");
			}
			else {
				System::Windows::Forms::TreeNode^ curConfig = curDevice->Nodes->Add("Configuration " + l);
				curConfig->Nodes->Add("Descriptor length: " + config->bLength);
				switch (config->bDescriptorType) {
				case LIBUSB_DT_DEVICE: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE"); break;
				case LIBUSB_DT_CONFIG: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_CONFIG"); break;
				case LIBUSB_DT_STRING: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_STRING"); break;
				case LIBUSB_DT_INTERFACE: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_INTERFACE"); break;
				case LIBUSB_DT_ENDPOINT: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_ENDPOINT"); break;
				case LIBUSB_DT_BOS: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_BOS"); break;
				case LIBUSB_DT_DEVICE_CAPABILITY: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE_CAPABILITY"); break;
				case LIBUSB_DT_HID: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_HID"); break;
				case LIBUSB_DT_REPORT: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_REPORT"); break;
				case LIBUSB_DT_PHYSICAL: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_PHYSICAL"); break;
				case LIBUSB_DT_HUB: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_HUB"); break;
				case LIBUSB_DT_SUPERSPEED_HUB: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_SUPERSPEED_HUB"); break;
				case LIBUSB_DT_SS_ENDPOINT_COMPANION: curConfig->Nodes->Add("Descriptor type: LIBUSB_DT_SS_ENDPOINT_COMPANION"); break;
				default: curConfig->Nodes->Add("Descriptor type: unknown Descriptor type"); break;
				}
				curConfig->Nodes->Add("Total length: " + config->wTotalLength);
				curConfig->Nodes->Add("Configuration identifier: " + config->bConfigurationValue);
				libusb_device_handle* handle;
				ret = (libusb_error)libusb_open(devs[i], &handle);
				if (ret != LIBUSB_SUCCESS) {
					String^ errorName = gcnew String(libusb_error_name(ret));
					String^ errorText = gcnew String(libusb_strerror(ret));
					//textBox33->AppendText("\r\nlibusb open device failed: " + errorName + " " + errorText);
					curConfig->Nodes->Add("Configuration string descriptor: Open device error");
				}
				else {
					//Configuration string
					unsigned char data[256];
					if (config->iConfiguration != 0) {
						for (int i = 0; i < 256; ++i)data[i] = 0;
						ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, config->iConfiguration, &data[0], 256);
						if (ret > 0) {
							String^ configurationText = gcnew String((char*)data);
							curConfig->Nodes->Add("Configuration: " + configurationText);
						}
						else {
							String^ errorName = gcnew String(libusb_error_name(ret));
							String^ errorText = gcnew String(libusb_strerror(ret));
							//textBox33->AppendText("\r\nlibusb read configuration text failed: " + errorName + " " + errorText);
							curConfig->Nodes->Add("Configuration: Read text error");
						}
					}
					else
						curConfig->Nodes->Add("Configuration: no information");
					libusb_close(handle);
				}
				curConfig->Nodes->Add("Configuration characteristics: " + config->bmAttributes);
				curConfig->Nodes->Add("PowerConsumption: " + config->MaxPower + " -> HighSpeed:" + (config->MaxPower * 2) +
					"mA, SuperSpeed:" + (config->MaxPower * 8) + "mA");
				if (config->extra_length > 0)treeView1->Nodes[i]->Nodes[l]->Nodes->Add("Detected extra descriptors length: " + config->extra_length);
				curConfig->Nodes->Add("Num interfaces: " + config->bNumInterfaces);
				//Iterate interfaces
				for (int k = 0; k < (int)config->bNumInterfaces; ++k) {
					System::Windows::Forms::TreeNode^ curInterface = curConfig->Nodes->Add("Interface " + k);
					curInterface->Nodes->Add("Num alternate settings: " + config->interface[k].num_altsetting);
					//Iterate settings
					for (int j = 0; j < config->interface[k].num_altsetting; ++j) {
						System::Windows::Forms::TreeNode^ curSetting = curInterface->Nodes->Add("Setting " + j);
						curSetting->Nodes->Add("Descriptor length: " + config->interface[k].altsetting[j].bLength);
						switch ((libusb_descriptor_type)config->interface[k].altsetting[j].bDescriptorType) {
						case LIBUSB_DT_DEVICE: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE"); break;
						case LIBUSB_DT_CONFIG: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_CONFIG"); break;
						case LIBUSB_DT_STRING: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_STRING"); break;
						case LIBUSB_DT_INTERFACE: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_INTERFACE"); break;
						case LIBUSB_DT_ENDPOINT: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_ENDPOINT"); break;
						case LIBUSB_DT_BOS: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_BOS"); break;
						case LIBUSB_DT_DEVICE_CAPABILITY: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE_CAPABILITY"); break;
						case LIBUSB_DT_HID: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_HID"); break;
						case LIBUSB_DT_REPORT: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_REPORT"); break;
						case LIBUSB_DT_PHYSICAL: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_PHYSICAL"); break;
						case LIBUSB_DT_HUB: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_HUB"); break;
						case LIBUSB_DT_SUPERSPEED_HUB: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_SUPERSPEED_HUB"); break;
						case LIBUSB_DT_SS_ENDPOINT_COMPANION: curSetting->Nodes->Add("Descriptor type: LIBUSB_DT_SS_ENDPOINT_COMPANION"); break;
						default: curSetting->Nodes->Add("Descriptor type: unknown Descriptor type"); break;
						}
						curSetting->Nodes->Add("Interface number: " + config->interface[k].altsetting[j].bInterfaceNumber);
						curSetting->Nodes->Add("Alternate setting value: " + config->interface[k].altsetting[j].bAlternateSetting);
						switch ((libusb_class_code)config->interface[k].altsetting[j].bInterfaceClass) {
						case LIBUSB_CLASS_PER_INTERFACE: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_PER_INTERFACE"); break;
						case LIBUSB_CLASS_AUDIO: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_AUDIO"); break;
						case LIBUSB_CLASS_COMM: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_COMM"); break;
						case LIBUSB_CLASS_HID: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_HID \n"); break;
						case LIBUSB_CLASS_PHYSICAL: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_PER_INTERFACE"); break;
						case LIBUSB_CLASS_PRINTER: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_PRINTER"); break;
						case LIBUSB_CLASS_IMAGE: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_IMAGE"); break;
						case LIBUSB_CLASS_MASS_STORAGE: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_MASS_STORAGE"); break;
						case LIBUSB_CLASS_HUB: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_HUB"); break;
						case LIBUSB_CLASS_DATA: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_DATA"); break;
						case LIBUSB_CLASS_SMART_CARD: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_SMART_CARD"); break;
						case LIBUSB_CLASS_CONTENT_SECURITY: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_CONTENT_SECURITY"); break;
						case LIBUSB_CLASS_VIDEO: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_VIDEO"); break;
						case LIBUSB_CLASS_PERSONAL_HEALTHCARE: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_PERSONAL_HEALTHCARE"); break;
						case LIBUSB_CLASS_DIAGNOSTIC_DEVICE: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_DIAGNOSTIC_DEVICE"); break;
						case LIBUSB_CLASS_WIRELESS: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_WIRELESS"); break;
						case LIBUSB_CLASS_APPLICATION: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_APPLICATION"); break;
						case LIBUSB_CLASS_VENDOR_SPEC: curSetting->Nodes->Add("Device class: LIBUSB_CLASS_VENDOR_SPEC"); break;
						default: curSetting->Nodes->Add("Device class: unknown device class");
						}
						curSetting->Nodes->Add("Interface SubClass: " + config->interface[k].altsetting[j].bInterfaceSubClass);
						curSetting->Nodes->Add("Interface protocol: " + config->interface[k].altsetting[j].bInterfaceProtocol);
						if (config->interface[k].altsetting[j].extra_length > 0) curSetting->Nodes->Add("Detected extra descriptors length: " + config->interface[k].altsetting[j].extra_length);
						ret = (libusb_error)libusb_open(devs[i], &handle);
						if (ret != LIBUSB_SUCCESS) {
							String^ errorName = gcnew String(libusb_error_name(ret));
							String^ errorText = gcnew String(libusb_strerror(ret));
							//textBox33->AppendText("\r\nlibusb open device failed: " + errorName + " " + errorText);
							curSetting->Nodes->Add("Interface string descriptor: Open device error");
						}
						else {
							//Interface string
							unsigned char data[256];
							if (config->iConfiguration != 0) {
								for (int i = 0; i < 256; ++i)data[i] = 0;
								ret = (libusb_error)libusb_get_string_descriptor_ascii(handle, config->interface[k].altsetting[j].iInterface, &data[0], 256);
								if (ret > 0) {
									String^ configurationText = gcnew String((char*)data);
									curSetting->Nodes->Add("Interface: " + configurationText);
								}
								else {
									String^ errorName = gcnew String(libusb_error_name(ret));
									String^ errorText = gcnew String(libusb_strerror(ret));
									//textBox33->AppendText("\r\nlibusb read interface text failed: " + errorName + " " + errorText);
									curSetting->Nodes->Add("Interface: Read text error");
								}
							}
							else
								curSetting->Nodes->Add("Interface: no information");
							libusb_close(handle);
						}
						curSetting->Nodes->Add("Num endpoints: " + config->interface[k].altsetting[j].bNumEndpoints);
						//Iterate endpoints
						for (int m = 0; m < config->interface[k].altsetting[j].bNumEndpoints; ++m) {
							System::Windows::Forms::TreeNode^ curEndpoint = curSetting->Nodes->Add("Endpoint " + m);
							curEndpoint->Nodes->Add("Descriptor length: " + config->interface[k].altsetting[j].endpoint[m].bLength);
							switch (config->interface[k].altsetting[j].endpoint[m].bDescriptorType) {
							case LIBUSB_DT_DEVICE: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE"); break;
							case LIBUSB_DT_CONFIG: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_CONFIG"); break;
							case LIBUSB_DT_STRING: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_STRING"); break;
							case LIBUSB_DT_INTERFACE: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_INTERFACE"); break;
							case LIBUSB_DT_ENDPOINT: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_ENDPOINT"); break;
							case LIBUSB_DT_BOS: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_BOS"); break;
							case LIBUSB_DT_DEVICE_CAPABILITY: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_DEVICE_CAPABILITY"); break;
							case LIBUSB_DT_HID: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_HID"); break;
							case LIBUSB_DT_REPORT: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_REPORT"); break;
							case LIBUSB_DT_PHYSICAL: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_PHYSICAL"); break;
							case LIBUSB_DT_HUB: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_HUB"); break;
							case LIBUSB_DT_SUPERSPEED_HUB: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_SUPERSPEED_HUB"); break;
							case LIBUSB_DT_SS_ENDPOINT_COMPANION: curEndpoint->Nodes->Add("Descriptor type: LIBUSB_DT_SS_ENDPOINT_COMPANION"); break;
							default: curEndpoint->Nodes->Add("Descriptor type: unknown Descriptor type"); break;
							}
							curEndpoint->Nodes->Add("EndpointAddress: 0x" + config->interface[k].altsetting[j].endpoint[m].bEndpointAddress.ToString("X2"));
							curEndpoint->Nodes->Add("EndpointNumber: " + (config->interface[k].altsetting[j].endpoint[m].bEndpointAddress & 0xf));
							if (config->interface[k].altsetting[j].endpoint[m].bEndpointAddress >> 7 & 0x1)
								curEndpoint->Nodes->Add("EndpointDirection: LIBUSB_ENDPOINT_IN (device - to - host)");
							else
								curEndpoint->Nodes->Add("EndpointDirection: LIBUSB_ENDPOINT_OUT (host - to - device)");
							curEndpoint->Nodes->Add("Attributes: " + config->interface[k].altsetting[j].endpoint[m].bmAttributes);
							switch (config->interface[k].altsetting[j].endpoint[m].bmAttributes & 0x3) {
							case 0:
								curEndpoint->Nodes->Add("Transfer type: LIBUSB_TRANSFER_TYPE_CONTROL (Control endpoint)"); break;
							case 1:
								curEndpoint->Nodes->Add("Transfer type: LIBUSB_TRANSFER_TYPE_ISOCHRONOUS (Isochronous endpoint)"); break;
							case 2:
								curEndpoint->Nodes->Add("Transfer type: LIBUSB_TRANSFER_TYPE_BULK (Bulk endpoint)"); break;
							case 3:
								curEndpoint->Nodes->Add("Transfer type: LIBUSB_TRANSFER_TYPE_INTERRUPT (Interrupt endpoint)"); break;
							case 4:
								curEndpoint->Nodes->Add("Transfer type: LIBUSB_TRANSFER_TYPE_BULK_STREAM (Stream endpoint)"); break;
							}
							switch (config->interface[k].altsetting[j].endpoint[m].bmAttributes >> 2 & 0x3) {
							case 0:
								curEndpoint->Nodes->Add("Sync type: LIBUSB_ISO_SYNC_TYPE_NONE (No synchronization)"); break;
							case 1:
								curEndpoint->Nodes->Add("Sync type: LIBUSB_ISO_SYNC_TYPE_ASYNC (Asynchronous)"); break;
							case 2:
								curEndpoint->Nodes->Add("Sync type: LIBUSB_ISO_SYNC_TYPE_ADAPTIVE (Adaptive)"); break;
							case 3:
								curEndpoint->Nodes->Add("Sync type: LIBUSB_ISO_SYNC_TYPE_SYNC (Synchronous)"); break;
							}
							switch (config->interface[k].altsetting[j].endpoint[m].bmAttributes >> 4 & 0x3) {
							case 0:
								curEndpoint->Nodes->Add("Usage type: LIBUSB_ISO_USAGE_TYPE_DATA (Data endpoint)"); break;
							case 1:
								curEndpoint->Nodes->Add("Usage type: LIBUSB_ISO_USAGE_TYPE_FEEDBACK (Feedback endpoint)"); break;
							case 2:
								curEndpoint->Nodes->Add("Usage type: LIBUSB_ISO_USAGE_TYPE_IMPLICIT (Implicit feedback Data endpoint)"); break;
							default:
								curEndpoint->Nodes->Add("unknown usage type"); break;
							}
							curEndpoint->Nodes->Add("Max packet size: " + config->interface[k].altsetting[j].endpoint[m].wMaxPacketSize);
							curEndpoint->Nodes->Add("Data transfer polling interval: " + config->interface[k].altsetting[j].endpoint[m].bInterval);
							curEndpoint->Nodes->Add("Sync feedback rate (only audio devices): " + config->interface[k].altsetting[j].endpoint[m].bRefresh);
							curEndpoint->Nodes->Add("Sync endpoint addr (only audio devices): 0x" + config->interface[k].altsetting[j].endpoint[m].bSynchAddress.ToString("X2"));
							if (config->interface[k].altsetting[j].endpoint[m].extra_length > 0)
								curEndpoint->Nodes->Add("Detected extra descriptors length: " + config->interface[k].altsetting[j].endpoint[m].extra_length);
						}

					}
				}
				libusb_free_config_descriptor(config);
			}
		}
	}
	treeView1->EndUpdate();
	libusb_free_device_list(devs, 1);
}