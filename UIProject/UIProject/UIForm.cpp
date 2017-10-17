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
	libusb_init(&usbcontext);
	colorPlatformComboBox->SelectedIndex = 0;
	comboBox2->SelectedIndex = 0;
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
	unsigned char* messageData = ld1data->activate();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();

	//test animation
	char repeat = 2;
	do {
		messageData = ld1data->fade(Platform::center, { 0,10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = ld1data->fade(Platform::left, { 0,10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = ld1data->fade(Platform::right, { 0,10,1,{ 0,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(500);
		messageData = ld1data->fade(Platform::center, { 0,10,1,{ 20,0,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = ld1data->fade(Platform::left, { 0,10,1,{ 0,20,0 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(250);
		messageData = ld1data->fade(Platform::right, { 0,10,1,{ 0,0,20 } });
		boxstr = gcnew String("");
		for (int i = 0; i < 32; i++) {
			boxstr += messageData[i].ToString("X2");
		}
		messageTextBox->Text = boxstr;
		button6->PerformClick();

		System::Threading::Thread::Sleep(500);
	} while (repeat--);
	messageData = ld1data->fade(all, { 0,50,0xff,{ 0,0,0 } });
	boxstr = gcnew String("");
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
	unsigned char* messageData = di1data.activate();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();

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
	button6->PerformClick();
}

System::Void UIProject::MyForm::button13_Click(System::Object ^ sender, System::EventArgs ^ e)
{//infinity color
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
	unsigned char* messageData = di1data.getTagId();
	String^ boxstr = gcnew String("");
	for (int i = 0; i < 32; i++) {
		boxstr += messageData[i].ToString("X2");
	}
	messageTextBox->Text = boxstr;
	button6->PerformClick();
}