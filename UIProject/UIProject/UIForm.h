#pragma once
#include <Windows.h>
namespace UIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:









	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  ScanDevicesButton;
	private: System::Windows::Forms::TextBox^  sendInterfaceTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  ColorLabel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  colorPlatformComboBox;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::HScrollBar^  hScrollBar3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::HScrollBar^  hScrollBar4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  FullColorLabel;
	private: System::Windows::Forms::Label^  RedLabel;
	private: System::Windows::Forms::Label^  GreenLabel;
	private: System::Windows::Forms::Label^  BlueLabel;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  messageTextBox;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::TextBox^  textBox29;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::TextBox^  textBox31;
	private: System::Windows::Forms::TextBox^  textBox32;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::HScrollBar^  hScrollBar5;
	private: System::Windows::Forms::Label^  label59;
	private: System::Windows::Forms::HScrollBar^  hScrollBar6;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::Label^  label63;
	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::Label^  label65;
	private: System::Windows::Forms::HScrollBar^  hScrollBar7;
	private: System::Windows::Forms::Label^  label66;
	private: System::Windows::Forms::HScrollBar^  hScrollBar8;
	private: System::Windows::Forms::Label^  label67;
	private: System::Windows::Forms::HScrollBar^  hScrollBar9;




	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;









	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::Label^  label68;
	private: System::Windows::Forms::TextBox^  textBox33;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel14;
	private: System::Windows::Forms::Label^  label78;
	private: System::Windows::Forms::Label^  label79;
	private: System::Windows::Forms::Label^  label80;
	private: System::Windows::Forms::Label^  label81;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::TextBox^  textBox39;
	private: System::Windows::Forms::TextBox^  textBox40;
	private: System::Windows::Forms::TextBox^  textBox41;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::Label^  label70;
	private: System::Windows::Forms::Label^  label71;
	private: System::Windows::Forms::Label^  label72;
	private: System::Windows::Forms::Label^  label73;
	private: System::Windows::Forms::Label^  label74;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::TextBox^  textBox34;
	private: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label69;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;
	private: System::Windows::Forms::Label^  label75;
	private: System::Windows::Forms::Label^  label76;
	private: System::Windows::Forms::Label^  label77;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::TextBox^  textBox38;
	private: System::Windows::Forms::Label^  label82;

	private: System::Windows::Forms::Label^  label83;
	private: System::Windows::Forms::Label^  label84;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel15;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel16;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Label^  label85;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel17;
	private: System::Windows::Forms::Label^  label90;
	private: System::Windows::Forms::TextBox^  textBox42;
	private: System::Windows::Forms::TextBox^  textBox44;
	private: System::Windows::Forms::Label^  label89;
	private: System::Windows::Forms::Label^  label87;
	private: System::Windows::Forms::Label^  label88;
	private: System::Windows::Forms::Label^  label86;
	private: System::Windows::Forms::TextBox^  textBox43;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel20;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel19;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel18;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel21;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel22;
	private: System::Windows::Forms::CheckBox^  checkBox4;

	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::Label^  label91;
	private: System::Windows::Forms::Label^  label92;
	private: System::Windows::Forms::Label^  label93;
	private: System::Windows::Forms::Label^  label94;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel25;
	private: System::Windows::Forms::Label^  label97;
	private: System::Windows::Forms::Label^  label95;
	private: System::Windows::Forms::Label^  label96;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel26;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel24;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel23;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel27;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TreeView^  treeView1;













	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Press \"Read descriptors\" to read available descriptors of all connected USB devic"
				L"es"));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->ScanDevicesButton = (gcnew System::Windows::Forms::Button());
			this->sendInterfaceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->ColorLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->colorPlatformComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar4 = (gcnew System::Windows::Forms::HScrollBar());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->FullColorLabel = (gcnew System::Windows::Forms::Label());
			this->RedLabel = (gcnew System::Windows::Forms::Label());
			this->GreenLabel = (gcnew System::Windows::Forms::Label());
			this->BlueLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar5 = (gcnew System::Windows::Forms::HScrollBar());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar6 = (gcnew System::Windows::Forms::HScrollBar());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar7 = (gcnew System::Windows::Forms::HScrollBar());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar8 = (gcnew System::Windows::Forms::HScrollBar());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar9 = (gcnew System::Windows::Forms::HScrollBar());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel21 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel17 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel20 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox44 = (gcnew System::Windows::Forms::TextBox());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel19 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox43 = (gcnew System::Windows::Forms::TextBox());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel18 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel22 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel25 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel27 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel16 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel14 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel15 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel26 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel24 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel23 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->tableLayoutPanel21->SuspendLayout();
			this->tableLayoutPanel17->SuspendLayout();
			this->tableLayoutPanel20->SuspendLayout();
			this->tableLayoutPanel19->SuspendLayout();
			this->tableLayoutPanel18->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel22->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel25->SuspendLayout();
			this->tableLayoutPanel27->SuspendLayout();
			this->tableLayoutPanel16->SuspendLayout();
			this->tableLayoutPanel14->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tableLayoutPanel15->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->tableLayoutPanel26->SuspendLayout();
			this->tableLayoutPanel24->SuspendLayout();
			this->tableLayoutPanel23->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->DropDownWidth = 250;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(404, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectionChangeCommitted);
			// 
			// ScanDevicesButton
			// 
			this->ScanDevicesButton->Location = System::Drawing::Point(40, 3);
			this->ScanDevicesButton->Name = L"ScanDevicesButton";
			this->ScanDevicesButton->Size = System::Drawing::Size(70, 22);
			this->ScanDevicesButton->TabIndex = 8;
			this->ScanDevicesButton->Text = L"Scan USB Devices";
			this->ScanDevicesButton->UseVisualStyleBackColor = true;
			this->ScanDevicesButton->Click += gcnew System::EventHandler(this, &MyForm::ScanDevicesButton_Click);
			// 
			// sendInterfaceTextBox
			// 
			this->sendInterfaceTextBox->Location = System::Drawing::Point(273, 3);
			this->sendInterfaceTextBox->Name = L"sendInterfaceTextBox";
			this->sendInterfaceTextBox->Size = System::Drawing::Size(26, 20);
			this->sendInterfaceTextBox->TabIndex = 9;
			this->sendInterfaceTextBox->Text = L"0";
			this->sendInterfaceTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Message size";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(3, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Activate";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// ColorLabel
			// 
			this->ColorLabel->AutoSize = true;
			this->ColorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ColorLabel->Location = System::Drawing::Point(3, 0);
			this->ColorLabel->Name = L"ColorLabel";
			this->ColorLabel->Size = System::Drawing::Size(36, 13);
			this->ColorLabel->TabIndex = 12;
			this->ColorLabel->Text = L"Color";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(45, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Platform";
			// 
			// colorPlatformComboBox
			// 
			this->colorPlatformComboBox->FormattingEnabled = true;
			this->colorPlatformComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"all", L"center", L"left", L"right" });
			this->colorPlatformComboBox->Location = System::Drawing::Point(45, 39);
			this->colorPlatformComboBox->Name = L"colorPlatformComboBox";
			this->colorPlatformComboBox->Size = System::Drawing::Size(69, 21);
			this->colorPlatformComboBox->TabIndex = 15;
			this->colorPlatformComboBox->Text = L"Choose";
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(49, 20);
			this->hScrollBar2->Maximum = 255;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(147, 21);
			this->hScrollBar2->SmallChange = 10;
			this->hScrollBar2->TabIndex = 16;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar2_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Red   ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Green";
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(49, 43);
			this->hScrollBar3->Maximum = 255;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(147, 21);
			this->hScrollBar3->SmallChange = 10;
			this->hScrollBar3->TabIndex = 18;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar3_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Blue   ";
			// 
			// hScrollBar4
			// 
			this->hScrollBar4->Location = System::Drawing::Point(49, 66);
			this->hScrollBar4->Maximum = 255;
			this->hScrollBar4->Name = L"hScrollBar4";
			this->hScrollBar4->Size = System::Drawing::Size(147, 21);
			this->hScrollBar4->SmallChange = 10;
			this->hScrollBar4->TabIndex = 20;
			this->hScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar4_Scroll);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(243, 39);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(32, 23);
			this->button5->TabIndex = 22;
			this->button5->Text = L">>";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// FullColorLabel
			// 
			this->FullColorLabel->BackColor = System::Drawing::Color::Black;
			this->FullColorLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->FullColorLabel->Location = System::Drawing::Point(52, 0);
			this->FullColorLabel->Name = L"FullColorLabel";
			this->FullColorLabel->Size = System::Drawing::Size(144, 20);
			this->FullColorLabel->TabIndex = 23;
			// 
			// RedLabel
			// 
			this->RedLabel->BackColor = System::Drawing::Color::Black;
			this->RedLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->RedLabel->Location = System::Drawing::Point(202, 20);
			this->RedLabel->Name = L"RedLabel";
			this->RedLabel->Size = System::Drawing::Size(27, 23);
			this->RedLabel->TabIndex = 24;
			// 
			// GreenLabel
			// 
			this->GreenLabel->BackColor = System::Drawing::Color::Black;
			this->GreenLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->GreenLabel->Location = System::Drawing::Point(202, 43);
			this->GreenLabel->Name = L"GreenLabel";
			this->GreenLabel->Size = System::Drawing::Size(27, 23);
			this->GreenLabel->TabIndex = 25;
			// 
			// BlueLabel
			// 
			this->BlueLabel->BackColor = System::Drawing::Color::Black;
			this->BlueLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->BlueLabel->Location = System::Drawing::Point(202, 66);
			this->BlueLabel->Name = L"BlueLabel";
			this->BlueLabel->Size = System::Drawing::Size(27, 23);
			this->BlueLabel->TabIndex = 26;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(3, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Color1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(120, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(34, 20);
			this->textBox1->TabIndex = 28;
			this->textBox1->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(205, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(28, 13);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Blue";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(163, 13);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 13);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Green";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(120, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(27, 13);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Red";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(120, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 13);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Color1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(163, 39);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(32, 20);
			this->textBox2->TabIndex = 33;
			this->textBox2->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(205, 39);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(32, 20);
			this->textBox3->TabIndex = 34;
			this->textBox3->Text = L"0";
			// 
			// messageTextBox
			// 
			this->messageTextBox->Location = System::Drawing::Point(3, 16);
			this->messageTextBox->Name = L"messageTextBox";
			this->messageTextBox->Size = System::Drawing::Size(677, 20);
			this->messageTextBox->TabIndex = 35;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(50, 13);
			this->label11->TabIndex = 36;
			this->label11->Text = L"Message";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(3, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(49, 23);
			this->button6->TabIndex = 37;
			this->button6->Text = L"Send";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(3, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(35, 13);
			this->label12->TabIndex = 38;
			this->label12->Text = L"Fade";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(44, 16);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(34, 20);
			this->textBox4->TabIndex = 39;
			this->textBox4->Text = L"20";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(99, 16);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(34, 20);
			this->textBox5->TabIndex = 40;
			this->textBox5->Text = L"2";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(44, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 13);
			this->label13->TabIndex = 41;
			this->label13->Text = L"FadeLen";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(99, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(63, 13);
			this->label14->TabIndex = 42;
			this->label14->Text = L"Num Pulses";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(3, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(37, 13);
			this->label15->TabIndex = 43;
			this->label15->Text = L"Flash";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(46, 16);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(34, 20);
			this->textBox6->TabIndex = 44;
			this->textBox6->Text = L"1";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(91, 16);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(34, 20);
			this->textBox7->TabIndex = 45;
			this->textBox7->Text = L"2";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(136, 16);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(34, 20);
			this->textBox8->TabIndex = 46;
			this->textBox8->Text = L"4";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(46, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 13);
			this->label16->TabIndex = 47;
			this->label16->Text = L"OnLen";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(91, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(39, 13);
			this->label17->TabIndex = 48;
			this->label17->Text = L"OffLen";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(136, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(63, 13);
			this->label18->TabIndex = 49;
			this->label18->Text = L"Num Pulses";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(3, 49);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(70, 13);
			this->label19->TabIndex = 50;
			this->label19->Text = L"ColorGroup";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(3, 88);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(69, 13);
			this->label20->TabIndex = 51;
			this->label20->Text = L"FadeGroup";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(3, 127);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(71, 13);
			this->label21->TabIndex = 52;
			this->label21->Text = L"FlashGroup";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(168, 16);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(32, 23);
			this->button7->TabIndex = 53;
			this->button7->Text = L">>";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(205, 16);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(32, 23);
			this->button8->TabIndex = 54;
			this->button8->Text = L">>";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(80, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(44, 13);
			this->label22->TabIndex = 55;
			this->label22->Text = L"Center";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(3, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(29, 13);
			this->label23->TabIndex = 56;
			this->label23->Text = L"Left";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(3, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(37, 13);
			this->label24->TabIndex = 57;
			this->label24->Text = L"Right";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(135, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->checkBox1->Size = System::Drawing::Size(59, 17);
			this->checkBox1->TabIndex = 58;
			this->checkBox1->Text = L"Enable";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(204, 52);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(32, 20);
			this->textBox9->TabIndex = 64;
			this->textBox9->Text = L"0";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(135, 52);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(32, 20);
			this->textBox10->TabIndex = 63;
			this->textBox10->Text = L"0";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(204, 36);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(28, 13);
			this->label25->TabIndex = 62;
			this->label25->Text = L"Blue";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(135, 36);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(36, 13);
			this->label26->TabIndex = 61;
			this->label26->Text = L"Green";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(80, 36);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(27, 13);
			this->label27->TabIndex = 60;
			this->label27->Text = L"Red";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(80, 52);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(34, 20);
			this->textBox11->TabIndex = 59;
			this->textBox11->Text = L"0";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(80, 23);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(37, 13);
			this->label28->TabIndex = 65;
			this->label28->Text = L"Color1";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(3, 23);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(37, 13);
			this->label29->TabIndex = 72;
			this->label29->Text = L"Color2";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(127, 52);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(32, 20);
			this->textBox12->TabIndex = 71;
			this->textBox12->Text = L"0";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(58, 52);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(32, 20);
			this->textBox13->TabIndex = 70;
			this->textBox13->Text = L"0";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(127, 36);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(28, 13);
			this->label30->TabIndex = 69;
			this->label30->Text = L"Blue";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(58, 36);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(36, 13);
			this->label31->TabIndex = 68;
			this->label31->Text = L"Green";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(3, 36);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(27, 13);
			this->label32->TabIndex = 67;
			this->label32->Text = L"Red";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(3, 52);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(34, 20);
			this->textBox14->TabIndex = 66;
			this->textBox14->Text = L"0";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(3, 23);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(37, 13);
			this->label33->TabIndex = 79;
			this->label33->Text = L"Color3";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(127, 52);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(32, 20);
			this->textBox15->TabIndex = 78;
			this->textBox15->Text = L"0";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(58, 52);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(32, 20);
			this->textBox16->TabIndex = 77;
			this->textBox16->Text = L"0";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(127, 36);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(28, 13);
			this->label34->TabIndex = 76;
			this->label34->Text = L"Blue";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(58, 36);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(36, 13);
			this->label35->TabIndex = 75;
			this->label35->Text = L"Green";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(3, 36);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(27, 13);
			this->label36->TabIndex = 74;
			this->label36->Text = L"Red";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(3, 52);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(34, 20);
			this->textBox17->TabIndex = 73;
			this->textBox17->Text = L"0";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(58, 3);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->checkBox2->Size = System::Drawing::Size(59, 17);
			this->checkBox2->TabIndex = 80;
			this->checkBox2->Text = L"Enable";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(58, 3);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->checkBox3->Size = System::Drawing::Size(59, 17);
			this->checkBox3->TabIndex = 81;
			this->checkBox3->Text = L"Enable";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(80, 91);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(34, 20);
			this->textBox18->TabIndex = 82;
			this->textBox18->Text = L"20";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(135, 91);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(34, 20);
			this->textBox19->TabIndex = 83;
			this->textBox19->Text = L"2";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(80, 75);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(49, 13);
			this->label37->TabIndex = 84;
			this->label37->Text = L"FadeLen";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(135, 75);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(63, 13);
			this->label38->TabIndex = 85;
			this->label38->Text = L"Num Pulses";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(58, 75);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(63, 13);
			this->label39->TabIndex = 89;
			this->label39->Text = L"Num Pulses";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(3, 75);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(49, 13);
			this->label40->TabIndex = 88;
			this->label40->Text = L"FadeLen";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(58, 91);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(34, 20);
			this->textBox20->TabIndex = 87;
			this->textBox20->Text = L"2";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(3, 91);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(34, 20);
			this->textBox21->TabIndex = 86;
			this->textBox21->Text = L"20";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(58, 78);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(63, 13);
			this->label41->TabIndex = 93;
			this->label41->Text = L"Num Pulses";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(3, 78);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(49, 13);
			this->label42->TabIndex = 92;
			this->label42->Text = L"FadeLen";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(58, 94);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(34, 20);
			this->textBox22->TabIndex = 91;
			this->textBox22->Text = L"2";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(3, 94);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(34, 20);
			this->textBox23->TabIndex = 90;
			this->textBox23->Text = L"20";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(196, 52);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(32, 23);
			this->button9->TabIndex = 94;
			this->button9->Text = L">>";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(196, 94);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(32, 23);
			this->button10->TabIndex = 95;
			this->button10->Text = L">>";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(204, 114);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(63, 13);
			this->label43->TabIndex = 101;
			this->label43->Text = L"Num Pulses";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(135, 114);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(39, 13);
			this->label44->TabIndex = 100;
			this->label44->Text = L"OffLen";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(80, 114);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(39, 13);
			this->label45->TabIndex = 99;
			this->label45->Text = L"OnLen";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(204, 130);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(34, 20);
			this->textBox24->TabIndex = 98;
			this->textBox24->Text = L"4";
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(135, 130);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(34, 20);
			this->textBox25->TabIndex = 97;
			this->textBox25->Text = L"2";
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(80, 130);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(34, 20);
			this->textBox26->TabIndex = 96;
			this->textBox26->Text = L"1";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(127, 114);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(63, 13);
			this->label46->TabIndex = 107;
			this->label46->Text = L"Num Pulses";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(58, 114);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(39, 13);
			this->label47->TabIndex = 106;
			this->label47->Text = L"OffLen";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(3, 114);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(39, 13);
			this->label48->TabIndex = 105;
			this->label48->Text = L"OnLen";
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(127, 130);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(34, 20);
			this->textBox27->TabIndex = 104;
			this->textBox27->Text = L"4";
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(58, 130);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(34, 20);
			this->textBox28->TabIndex = 103;
			this->textBox28->Text = L"2";
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(3, 130);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(34, 20);
			this->textBox29->TabIndex = 102;
			this->textBox29->Text = L"1";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(127, 120);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(63, 13);
			this->label49->TabIndex = 113;
			this->label49->Text = L"Num Pulses";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(58, 120);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(39, 13);
			this->label50->TabIndex = 112;
			this->label50->Text = L"OffLen";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(3, 120);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(39, 13);
			this->label51->TabIndex = 111;
			this->label51->Text = L"OnLen";
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(127, 136);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(34, 20);
			this->textBox30->TabIndex = 110;
			this->textBox30->Text = L"4";
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(58, 136);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(34, 20);
			this->textBox31->TabIndex = 109;
			this->textBox31->Text = L"2";
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(3, 136);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(34, 20);
			this->textBox32->TabIndex = 108;
			this->textBox32->Text = L"1";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(196, 136);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(32, 23);
			this->button11->TabIndex = 114;
			this->button11->Text = L">>";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(3, 0);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(43, 13);
			this->label52->TabIndex = 125;
			this->label52->Text = L"Color2";
			// 
			// label53
			// 
			this->label53->BackColor = System::Drawing::Color::Black;
			this->label53->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label53->Location = System::Drawing::Point(202, 66);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(27, 23);
			this->label53->TabIndex = 124;
			// 
			// label54
			// 
			this->label54->BackColor = System::Drawing::Color::Black;
			this->label54->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label54->Location = System::Drawing::Point(202, 43);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(27, 23);
			this->label54->TabIndex = 123;
			// 
			// label55
			// 
			this->label55->BackColor = System::Drawing::Color::Black;
			this->label55->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label55->Location = System::Drawing::Point(202, 20);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(27, 23);
			this->label55->TabIndex = 122;
			// 
			// label56
			// 
			this->label56->BackColor = System::Drawing::Color::Black;
			this->label56->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label56->Location = System::Drawing::Point(52, 0);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(144, 20);
			this->label56->TabIndex = 121;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(3, 66);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(34, 13);
			this->label57->TabIndex = 120;
			this->label57->Text = L"Blue  ";
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(49, 66);
			this->hScrollBar1->Maximum = 255;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(147, 21);
			this->hScrollBar1->SmallChange = 10;
			this->hScrollBar1->TabIndex = 119;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll_1);
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(3, 43);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(36, 13);
			this->label58->TabIndex = 118;
			this->label58->Text = L"Green";
			// 
			// hScrollBar5
			// 
			this->hScrollBar5->Location = System::Drawing::Point(49, 43);
			this->hScrollBar5->Maximum = 255;
			this->hScrollBar5->Name = L"hScrollBar5";
			this->hScrollBar5->Size = System::Drawing::Size(147, 21);
			this->hScrollBar5->SmallChange = 10;
			this->hScrollBar5->TabIndex = 117;
			this->hScrollBar5->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar5_Scroll);
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(3, 20);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(36, 13);
			this->label59->TabIndex = 116;
			this->label59->Text = L"Red   ";
			// 
			// hScrollBar6
			// 
			this->hScrollBar6->Location = System::Drawing::Point(49, 20);
			this->hScrollBar6->Maximum = 255;
			this->hScrollBar6->Name = L"hScrollBar6";
			this->hScrollBar6->Size = System::Drawing::Size(147, 21);
			this->hScrollBar6->SmallChange = 10;
			this->hScrollBar6->TabIndex = 115;
			this->hScrollBar6->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar6_Scroll);
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label60->Location = System::Drawing::Point(3, 0);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(43, 13);
			this->label60->TabIndex = 136;
			this->label60->Text = L"Color3";
			// 
			// label61
			// 
			this->label61->BackColor = System::Drawing::Color::Black;
			this->label61->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label61->Location = System::Drawing::Point(202, 66);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(27, 23);
			this->label61->TabIndex = 135;
			// 
			// label62
			// 
			this->label62->BackColor = System::Drawing::Color::Black;
			this->label62->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label62->Location = System::Drawing::Point(202, 43);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(27, 23);
			this->label62->TabIndex = 134;
			// 
			// label63
			// 
			this->label63->BackColor = System::Drawing::Color::Black;
			this->label63->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label63->Location = System::Drawing::Point(202, 20);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(27, 23);
			this->label63->TabIndex = 133;
			// 
			// label64
			// 
			this->label64->BackColor = System::Drawing::Color::Black;
			this->label64->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label64->Location = System::Drawing::Point(52, 0);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(144, 20);
			this->label64->TabIndex = 132;
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(3, 66);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(34, 13);
			this->label65->TabIndex = 131;
			this->label65->Text = L"Blue  ";
			// 
			// hScrollBar7
			// 
			this->hScrollBar7->Location = System::Drawing::Point(49, 66);
			this->hScrollBar7->Maximum = 255;
			this->hScrollBar7->Name = L"hScrollBar7";
			this->hScrollBar7->Size = System::Drawing::Size(147, 21);
			this->hScrollBar7->SmallChange = 10;
			this->hScrollBar7->TabIndex = 130;
			this->hScrollBar7->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar7_Scroll);
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(3, 43);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(36, 13);
			this->label66->TabIndex = 129;
			this->label66->Text = L"Green";
			// 
			// hScrollBar8
			// 
			this->hScrollBar8->Location = System::Drawing::Point(49, 43);
			this->hScrollBar8->Maximum = 255;
			this->hScrollBar8->Name = L"hScrollBar8";
			this->hScrollBar8->Size = System::Drawing::Size(147, 21);
			this->hScrollBar8->SmallChange = 10;
			this->hScrollBar8->TabIndex = 128;
			this->hScrollBar8->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar8_Scroll);
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(3, 20);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(36, 13);
			this->label67->TabIndex = 127;
			this->label67->Text = L"Red   ";
			// 
			// hScrollBar9
			// 
			this->hScrollBar9->Location = System::Drawing::Point(49, 20);
			this->hScrollBar9->Maximum = 255;
			this->hScrollBar9->Name = L"hScrollBar9";
			this->hScrollBar9->Size = System::Drawing::Size(147, 21);
			this->hScrollBar9->SmallChange = 10;
			this->hScrollBar9->TabIndex = 126;
			this->hScrollBar9->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar9_Scroll);
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->AutoSize = true;
			this->tableLayoutPanel5->ColumnCount = 7;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel5->Controls->Add(this->ColorLabel, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label10, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->label9, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->label8, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->label7, 4, 1);
			this->tableLayoutPanel5->Controls->Add(this->button5, 5, 2);
			this->tableLayoutPanel5->Controls->Add(this->textBox3, 4, 2);
			this->tableLayoutPanel5->Controls->Add(this->textBox2, 3, 2);
			this->tableLayoutPanel5->Controls->Add(this->textBox1, 2, 2);
			this->tableLayoutPanel5->Controls->Add(this->colorPlatformComboBox, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->label2, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->label91, 5, 0);
			this->tableLayoutPanel5->Controls->Add(this->checkBox4, 5, 1);
			this->tableLayoutPanel5->Location = System::Drawing::Point(92, 4);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel5->Size = System::Drawing::Size(293, 65);
			this->tableLayoutPanel5->TabIndex = 144;
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Location = System::Drawing::Point(243, 0);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(32, 13);
			this->label91->TabIndex = 157;
			this->label91->Text = L"Send";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(243, 16);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox4->Size = System::Drawing::Size(47, 17);
			this->checkBox4->TabIndex = 0;
			this->checkBox4->Text = L"auto";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->AutoSize = true;
			this->tableLayoutPanel6->ColumnCount = 4;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel6->Controls->Add(this->label92, 3, 0);
			this->tableLayoutPanel6->Controls->Add(this->label12, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->label13, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->label14, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->button7, 3, 1);
			this->tableLayoutPanel6->Controls->Add(this->textBox5, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->textBox4, 1, 1);
			this->tableLayoutPanel6->Location = System::Drawing::Point(392, 4);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel6->Size = System::Drawing::Size(203, 42);
			this->tableLayoutPanel6->TabIndex = 145;
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Location = System::Drawing::Point(168, 0);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(32, 13);
			this->label92->TabIndex = 158;
			this->label92->Text = L"Send";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->AutoSize = true;
			this->tableLayoutPanel7->ColumnCount = 5;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel7->Controls->Add(this->label93, 4, 0);
			this->tableLayoutPanel7->Controls->Add(this->label15, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->label16, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->label17, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->label18, 3, 0);
			this->tableLayoutPanel7->Controls->Add(this->button8, 4, 1);
			this->tableLayoutPanel7->Controls->Add(this->textBox8, 3, 1);
			this->tableLayoutPanel7->Controls->Add(this->textBox7, 2, 1);
			this->tableLayoutPanel7->Controls->Add(this->textBox6, 1, 1);
			this->tableLayoutPanel7->Location = System::Drawing::Point(602, 4);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel7->Size = System::Drawing::Size(240, 42);
			this->tableLayoutPanel7->TabIndex = 146;
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Location = System::Drawing::Point(205, 0);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(32, 13);
			this->label93->TabIndex = 159;
			this->label93->Text = L"Send";
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->AutoSize = true;
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel11->Controls->Add(this->tableLayoutPanel21, 1, 1);
			this->tableLayoutPanel11->Controls->Add(this->tableLayoutPanel17, 1, 2);
			this->tableLayoutPanel11->Controls->Add(this->label11, 0, 0);
			this->tableLayoutPanel11->Controls->Add(this->messageTextBox, 0, 1);
			this->tableLayoutPanel11->Controls->Add(this->textBox33, 0, 2);
			this->tableLayoutPanel11->Location = System::Drawing::Point(21, 424);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 3;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel11->Size = System::Drawing::Size(808, 206);
			this->tableLayoutPanel11->TabIndex = 150;
			// 
			// tableLayoutPanel21
			// 
			this->tableLayoutPanel21->AutoSize = true;
			this->tableLayoutPanel21->ColumnCount = 2;
			this->tableLayoutPanel21->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel21->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel21->Controls->Add(this->button17, 1, 0);
			this->tableLayoutPanel21->Controls->Add(this->button6, 0, 0);
			this->tableLayoutPanel21->Location = System::Drawing::Point(686, 16);
			this->tableLayoutPanel21->Name = L"tableLayoutPanel21";
			this->tableLayoutPanel21->RowCount = 1;
			this->tableLayoutPanel21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel21->Size = System::Drawing::Size(119, 29);
			this->tableLayoutPanel21->TabIndex = 167;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(58, 3);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(58, 23);
			this->button17->TabIndex = 166;
			this->button17->Text = L"Receive";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// tableLayoutPanel17
			// 
			this->tableLayoutPanel17->AutoSize = true;
			this->tableLayoutPanel17->ColumnCount = 1;
			this->tableLayoutPanel17->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel17->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel17->Controls->Add(this->tableLayoutPanel20, 0, 10);
			this->tableLayoutPanel17->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel17->Controls->Add(this->tableLayoutPanel19, 0, 8);
			this->tableLayoutPanel17->Controls->Add(this->label87, 0, 9);
			this->tableLayoutPanel17->Controls->Add(this->label86, 0, 7);
			this->tableLayoutPanel17->Controls->Add(this->tableLayoutPanel18, 0, 6);
			this->tableLayoutPanel17->Location = System::Drawing::Point(686, 51);
			this->tableLayoutPanel17->Name = L"tableLayoutPanel17";
			this->tableLayoutPanel17->RowCount = 11;
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel17->Size = System::Drawing::Size(98, 135);
			this->tableLayoutPanel17->TabIndex = 165;
			// 
			// tableLayoutPanel20
			// 
			this->tableLayoutPanel20->AutoSize = true;
			this->tableLayoutPanel20->ColumnCount = 2;
			this->tableLayoutPanel20->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel20->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel20->Controls->Add(this->textBox44, 0, 0);
			this->tableLayoutPanel20->Controls->Add(this->label90, 1, 0);
			this->tableLayoutPanel20->Location = System::Drawing::Point(3, 106);
			this->tableLayoutPanel20->Name = L"tableLayoutPanel20";
			this->tableLayoutPanel20->RowCount = 1;
			this->tableLayoutPanel20->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel20->Size = System::Drawing::Size(62, 26);
			this->tableLayoutPanel20->TabIndex = 159;
			// 
			// textBox44
			// 
			this->textBox44->Location = System::Drawing::Point(3, 3);
			this->textBox44->Name = L"textBox44";
			this->textBox44->Size = System::Drawing::Size(26, 20);
			this->textBox44->TabIndex = 161;
			this->textBox44->Text = L"81";
			this->textBox44->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Location = System::Drawing::Point(35, 0);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(24, 13);
			this->label90->TabIndex = 164;
			this->label90->Text = L"hex";
			// 
			// tableLayoutPanel19
			// 
			this->tableLayoutPanel19->AutoSize = true;
			this->tableLayoutPanel19->ColumnCount = 2;
			this->tableLayoutPanel19->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel19->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel19->Controls->Add(this->textBox43, 0, 0);
			this->tableLayoutPanel19->Controls->Add(this->label89, 1, 0);
			this->tableLayoutPanel19->Location = System::Drawing::Point(3, 61);
			this->tableLayoutPanel19->Name = L"tableLayoutPanel19";
			this->tableLayoutPanel19->RowCount = 1;
			this->tableLayoutPanel19->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel19->Size = System::Drawing::Size(62, 26);
			this->tableLayoutPanel19->TabIndex = 158;
			// 
			// textBox43
			// 
			this->textBox43->Location = System::Drawing::Point(3, 3);
			this->textBox43->Name = L"textBox43";
			this->textBox43->Size = System::Drawing::Size(26, 20);
			this->textBox43->TabIndex = 159;
			this->textBox43->Text = L"01";
			this->textBox43->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Location = System::Drawing::Point(35, 0);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(24, 13);
			this->label89->TabIndex = 163;
			this->label89->Text = L"hex";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(3, 90);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(92, 13);
			this->label87->TabIndex = 160;
			this->label87->Text = L"Receive Endpoint";
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(3, 45);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(77, 13);
			this->label86->TabIndex = 158;
			this->label86->Text = L"Send Endpoint";
			// 
			// tableLayoutPanel18
			// 
			this->tableLayoutPanel18->AutoSize = true;
			this->tableLayoutPanel18->ColumnCount = 2;
			this->tableLayoutPanel18->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel18->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel18->Controls->Add(this->textBox42, 0, 0);
			this->tableLayoutPanel18->Controls->Add(this->label88, 1, 0);
			this->tableLayoutPanel18->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel18->Name = L"tableLayoutPanel18";
			this->tableLayoutPanel18->RowCount = 1;
			this->tableLayoutPanel18->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel18->Size = System::Drawing::Size(65, 26);
			this->tableLayoutPanel18->TabIndex = 157;
			// 
			// textBox42
			// 
			this->textBox42->Location = System::Drawing::Point(3, 3);
			this->textBox42->Name = L"textBox42";
			this->textBox42->Size = System::Drawing::Size(26, 20);
			this->textBox42->TabIndex = 157;
			this->textBox42->Text = L"32";
			this->textBox42->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Location = System::Drawing::Point(35, 0);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(27, 13);
			this->label88->TabIndex = 162;
			this->label88->Text = L"byte";
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(3, 51);
			this->textBox33->Multiline = true;
			this->textBox33->Name = L"textBox33";
			this->textBox33->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox33->Size = System::Drawing::Size(677, 152);
			this->textBox33->TabIndex = 38;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(4, 41);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(867, 284);
			this->tabControl1->TabIndex = 151;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage1->Controls->Add(this->tableLayoutPanel4);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(859, 258);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"LegoDimensions";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->AutoSize = true;
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel22, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel8, 0, 6);
			this->tableLayoutPanel4->Location = System::Drawing::Point(6, 6);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 7;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->Size = System::Drawing::Size(846, 253);
			this->tableLayoutPanel4->TabIndex = 152;
			// 
			// tableLayoutPanel22
			// 
			this->tableLayoutPanel22->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel22->ColumnCount = 4;
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel22->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->tableLayoutPanel22->Controls->Add(this->tableLayoutPanel7, 3, 0);
			this->tableLayoutPanel22->Controls->Add(this->tableLayoutPanel5, 1, 0);
			this->tableLayoutPanel22->Controls->Add(this->tableLayoutPanel6, 2, 0);
			this->tableLayoutPanel22->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel22->Name = L"tableLayoutPanel22";
			this->tableLayoutPanel22->RowCount = 1;
			this->tableLayoutPanel22->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel22->Size = System::Drawing::Size(840, 73);
			this->tableLayoutPanel22->TabIndex = 157;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button4, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(81, 58);
			this->tableLayoutPanel1->TabIndex = 159;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 158;
			this->button1->Text = L"Demo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->AutoSize = true;
			this->tableLayoutPanel8->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel8->ColumnCount = 3;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel8->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->tableLayoutPanel9, 2, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 82);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel8->Size = System::Drawing::Size(716, 168);
			this->tableLayoutPanel8->TabIndex = 155;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoSize = true;
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Controls->Add(this->label94, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label28, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label21, 0, 7);
			this->tableLayoutPanel2->Controls->Add(this->label27, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->label19, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->label20, 0, 5);
			this->tableLayoutPanel2->Controls->Add(this->label25, 3, 2);
			this->tableLayoutPanel2->Controls->Add(this->label45, 1, 6);
			this->tableLayoutPanel2->Controls->Add(this->textBox24, 3, 7);
			this->tableLayoutPanel2->Controls->Add(this->textBox25, 2, 7);
			this->tableLayoutPanel2->Controls->Add(this->textBox26, 1, 7);
			this->tableLayoutPanel2->Controls->Add(this->label26, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox11, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBox10, 2, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBox9, 3, 3);
			this->tableLayoutPanel2->Controls->Add(this->label37, 1, 4);
			this->tableLayoutPanel2->Controls->Add(this->label38, 2, 4);
			this->tableLayoutPanel2->Controls->Add(this->textBox18, 1, 5);
			this->tableLayoutPanel2->Controls->Add(this->textBox19, 2, 5);
			this->tableLayoutPanel2->Controls->Add(this->label44, 2, 6);
			this->tableLayoutPanel2->Controls->Add(this->label43, 3, 6);
			this->tableLayoutPanel2->Controls->Add(this->label22, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->checkBox1, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 8;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(270, 153);
			this->tableLayoutPanel2->TabIndex = 152;
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label94->Location = System::Drawing::Point(3, 0);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(57, 13);
			this->label94->TabIndex = 158;
			this->label94->Text = L"Platform:";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->AutoSize = true;
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel3->Controls->Add(this->label29, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label32, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->label31, 2, 2);
			this->tableLayoutPanel3->Controls->Add(this->textBox27, 3, 7);
			this->tableLayoutPanel3->Controls->Add(this->textBox28, 2, 7);
			this->tableLayoutPanel3->Controls->Add(this->textBox29, 1, 7);
			this->tableLayoutPanel3->Controls->Add(this->label30, 3, 2);
			this->tableLayoutPanel3->Controls->Add(this->textBox20, 2, 5);
			this->tableLayoutPanel3->Controls->Add(this->textBox14, 1, 3);
			this->tableLayoutPanel3->Controls->Add(this->textBox13, 2, 3);
			this->tableLayoutPanel3->Controls->Add(this->textBox12, 3, 3);
			this->tableLayoutPanel3->Controls->Add(this->textBox21, 1, 5);
			this->tableLayoutPanel3->Controls->Add(this->label40, 1, 4);
			this->tableLayoutPanel3->Controls->Add(this->label39, 2, 4);
			this->tableLayoutPanel3->Controls->Add(this->label48, 1, 6);
			this->tableLayoutPanel3->Controls->Add(this->label46, 3, 6);
			this->tableLayoutPanel3->Controls->Add(this->label47, 2, 6);
			this->tableLayoutPanel3->Controls->Add(this->label23, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->checkBox2, 2, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(281, 4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 8;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->Size = System::Drawing::Size(193, 153);
			this->tableLayoutPanel3->TabIndex = 153;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 5;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				44)));
			this->tableLayoutPanel9->Controls->Add(this->label68, 4, 1);
			this->tableLayoutPanel9->Controls->Add(this->button11, 4, 7);
			this->tableLayoutPanel9->Controls->Add(this->textBox15, 3, 3);
			this->tableLayoutPanel9->Controls->Add(this->button10, 4, 5);
			this->tableLayoutPanel9->Controls->Add(this->textBox22, 2, 5);
			this->tableLayoutPanel9->Controls->Add(this->label33, 1, 1);
			this->tableLayoutPanel9->Controls->Add(this->button9, 4, 3);
			this->tableLayoutPanel9->Controls->Add(this->textBox30, 3, 7);
			this->tableLayoutPanel9->Controls->Add(this->textBox31, 2, 7);
			this->tableLayoutPanel9->Controls->Add(this->textBox32, 1, 7);
			this->tableLayoutPanel9->Controls->Add(this->label49, 3, 6);
			this->tableLayoutPanel9->Controls->Add(this->textBox23, 1, 5);
			this->tableLayoutPanel9->Controls->Add(this->label36, 1, 2);
			this->tableLayoutPanel9->Controls->Add(this->label50, 2, 6);
			this->tableLayoutPanel9->Controls->Add(this->label41, 2, 4);
			this->tableLayoutPanel9->Controls->Add(this->label42, 1, 4);
			this->tableLayoutPanel9->Controls->Add(this->label51, 1, 6);
			this->tableLayoutPanel9->Controls->Add(this->label35, 2, 2);
			this->tableLayoutPanel9->Controls->Add(this->label34, 3, 2);
			this->tableLayoutPanel9->Controls->Add(this->textBox17, 1, 3);
			this->tableLayoutPanel9->Controls->Add(this->textBox16, 2, 3);
			this->tableLayoutPanel9->Controls->Add(this->label24, 1, 0);
			this->tableLayoutPanel9->Controls->Add(this->checkBox3, 2, 0);
			this->tableLayoutPanel9->Location = System::Drawing::Point(481, 4);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 8;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel9->Size = System::Drawing::Size(231, 160);
			this->tableLayoutPanel9->TabIndex = 154;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(196, 23);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(32, 13);
			this->label68->TabIndex = 152;
			this->label68->Text = L"Send";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tableLayoutPanel25);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(859, 258);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Disney Infinity";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel25
			// 
			this->tableLayoutPanel25->AutoSize = true;
			this->tableLayoutPanel25->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel25->ColumnCount = 1;
			this->tableLayoutPanel25->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel25->Controls->Add(this->tableLayoutPanel27, 0, 0);
			this->tableLayoutPanel25->Controls->Add(this->tableLayoutPanel16, 0, 4);
			this->tableLayoutPanel25->Controls->Add(this->tableLayoutPanel14, 0, 3);
			this->tableLayoutPanel25->Controls->Add(this->tableLayoutPanel13, 0, 2);
			this->tableLayoutPanel25->Controls->Add(this->tableLayoutPanel12, 0, 1);
			this->tableLayoutPanel25->Location = System::Drawing::Point(6, 6);
			this->tableLayoutPanel25->Name = L"tableLayoutPanel25";
			this->tableLayoutPanel25->RowCount = 5;
			this->tableLayoutPanel25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel25->Size = System::Drawing::Size(301, 243);
			this->tableLayoutPanel25->TabIndex = 157;
			// 
			// tableLayoutPanel27
			// 
			this->tableLayoutPanel27->AutoSize = true;
			this->tableLayoutPanel27->ColumnCount = 2;
			this->tableLayoutPanel27->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel27->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel27->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel27->Controls->Add(this->button12, 0, 0);
			this->tableLayoutPanel27->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel27->Name = L"tableLayoutPanel27";
			this->tableLayoutPanel27->RowCount = 1;
			this->tableLayoutPanel27->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel27->Size = System::Drawing::Size(162, 29);
			this->tableLayoutPanel27->TabIndex = 159;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(84, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 158;
			this->button2->Text = L"Demo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(3, 3);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 12;
			this->button12->Text = L"Activate";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// tableLayoutPanel16
			// 
			this->tableLayoutPanel16->AutoSize = true;
			this->tableLayoutPanel16->ColumnCount = 2;
			this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel16->Controls->Add(this->button16, 0, 0);
			this->tableLayoutPanel16->Controls->Add(this->label85, 0, 0);
			this->tableLayoutPanel16->Location = System::Drawing::Point(4, 210);
			this->tableLayoutPanel16->Name = L"tableLayoutPanel16";
			this->tableLayoutPanel16->RowCount = 1;
			this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel16->Size = System::Drawing::Size(106, 29);
			this->tableLayoutPanel16->TabIndex = 157;
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(71, 3);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(32, 23);
			this->button16->TabIndex = 55;
			this->button16->Text = L">>";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label85->Location = System::Drawing::Point(3, 0);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(62, 13);
			this->label85->TabIndex = 44;
			this->label85->Text = L"GetTagID";
			// 
			// tableLayoutPanel14
			// 
			this->tableLayoutPanel14->AutoSize = true;
			this->tableLayoutPanel14->ColumnCount = 5;
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel14->Controls->Add(this->label97, 4, 0);
			this->tableLayoutPanel14->Controls->Add(this->label78, 0, 0);
			this->tableLayoutPanel14->Controls->Add(this->label79, 1, 0);
			this->tableLayoutPanel14->Controls->Add(this->label80, 2, 0);
			this->tableLayoutPanel14->Controls->Add(this->label81, 3, 0);
			this->tableLayoutPanel14->Controls->Add(this->button15, 4, 1);
			this->tableLayoutPanel14->Controls->Add(this->textBox39, 3, 1);
			this->tableLayoutPanel14->Controls->Add(this->textBox40, 2, 1);
			this->tableLayoutPanel14->Controls->Add(this->textBox41, 1, 1);
			this->tableLayoutPanel14->Location = System::Drawing::Point(4, 161);
			this->tableLayoutPanel14->Name = L"tableLayoutPanel14";
			this->tableLayoutPanel14->RowCount = 2;
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel14->Size = System::Drawing::Size(240, 42);
			this->tableLayoutPanel14->TabIndex = 147;
			// 
			// label97
			// 
			this->label97->AutoSize = true;
			this->label97->Location = System::Drawing::Point(205, 0);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(32, 13);
			this->label97->TabIndex = 159;
			this->label97->Text = L"Send";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label78->Location = System::Drawing::Point(3, 0);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(37, 13);
			this->label78->TabIndex = 43;
			this->label78->Text = L"Flash";
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(46, 0);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(39, 13);
			this->label79->TabIndex = 47;
			this->label79->Text = L"OnLen";
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(91, 0);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(39, 13);
			this->label80->TabIndex = 48;
			this->label80->Text = L"OffLen";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Location = System::Drawing::Point(136, 0);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(63, 13);
			this->label81->TabIndex = 49;
			this->label81->Text = L"Num Pulses";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(205, 16);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(32, 23);
			this->button15->TabIndex = 54;
			this->button15->Text = L">>";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// textBox39
			// 
			this->textBox39->Location = System::Drawing::Point(136, 16);
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(34, 20);
			this->textBox39->TabIndex = 46;
			this->textBox39->Text = L"4";
			// 
			// textBox40
			// 
			this->textBox40->Location = System::Drawing::Point(91, 16);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(34, 20);
			this->textBox40->TabIndex = 45;
			this->textBox40->Text = L"2";
			// 
			// textBox41
			// 
			this->textBox41->Location = System::Drawing::Point(46, 16);
			this->textBox41->Name = L"textBox41";
			this->textBox41->Size = System::Drawing::Size(34, 20);
			this->textBox41->TabIndex = 44;
			this->textBox41->Text = L"1";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->AutoSize = true;
			this->tableLayoutPanel13->ColumnCount = 4;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel13->Controls->Add(this->label95, 3, 0);
			this->tableLayoutPanel13->Controls->Add(this->label75, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->label76, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->label77, 2, 0);
			this->tableLayoutPanel13->Controls->Add(this->button14, 3, 1);
			this->tableLayoutPanel13->Controls->Add(this->textBox37, 2, 1);
			this->tableLayoutPanel13->Controls->Add(this->textBox38, 1, 1);
			this->tableLayoutPanel13->Location = System::Drawing::Point(4, 112);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 2;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel13->Size = System::Drawing::Size(203, 42);
			this->tableLayoutPanel13->TabIndex = 146;
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->Location = System::Drawing::Point(168, 0);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(32, 13);
			this->label95->TabIndex = 159;
			this->label95->Text = L"Send";
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label75->Location = System::Drawing::Point(3, 0);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(35, 13);
			this->label75->TabIndex = 38;
			this->label75->Text = L"Fade";
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(44, 0);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(49, 13);
			this->label76->TabIndex = 41;
			this->label76->Text = L"FadeLen";
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(99, 0);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(63, 13);
			this->label77->TabIndex = 42;
			this->label77->Text = L"Num Pulses";
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(168, 16);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(32, 23);
			this->button14->TabIndex = 53;
			this->button14->Text = L">>";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// textBox37
			// 
			this->textBox37->Location = System::Drawing::Point(99, 16);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(34, 20);
			this->textBox37->TabIndex = 40;
			this->textBox37->Text = L"2";
			// 
			// textBox38
			// 
			this->textBox38->Location = System::Drawing::Point(44, 16);
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(34, 20);
			this->textBox38->TabIndex = 39;
			this->textBox38->Text = L"20";
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->AutoSize = true;
			this->tableLayoutPanel12->ColumnCount = 7;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel12->Controls->Add(this->label96, 5, 0);
			this->tableLayoutPanel12->Controls->Add(this->label71, 2, 0);
			this->tableLayoutPanel12->Controls->Add(this->label72, 2, 1);
			this->tableLayoutPanel12->Controls->Add(this->label73, 3, 1);
			this->tableLayoutPanel12->Controls->Add(this->label74, 4, 1);
			this->tableLayoutPanel12->Controls->Add(this->button13, 5, 2);
			this->tableLayoutPanel12->Controls->Add(this->textBox34, 4, 2);
			this->tableLayoutPanel12->Controls->Add(this->textBox35, 3, 2);
			this->tableLayoutPanel12->Controls->Add(this->textBox36, 2, 2);
			this->tableLayoutPanel12->Controls->Add(this->comboBox2, 1, 2);
			this->tableLayoutPanel12->Controls->Add(this->label69, 0, 0);
			this->tableLayoutPanel12->Controls->Add(this->label70, 1, 1);
			this->tableLayoutPanel12->Controls->Add(this->checkBox5, 5, 1);
			this->tableLayoutPanel12->Location = System::Drawing::Point(4, 40);
			this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
			this->tableLayoutPanel12->RowCount = 3;
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel12->Size = System::Drawing::Size(293, 65);
			this->tableLayoutPanel12->TabIndex = 145;
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Location = System::Drawing::Point(243, 0);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(32, 13);
			this->label96->TabIndex = 158;
			this->label96->Text = L"Send";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(120, 0);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(37, 13);
			this->label71->TabIndex = 32;
			this->label71->Text = L"Color1";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(120, 13);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(27, 13);
			this->label72->TabIndex = 29;
			this->label72->Text = L"Red";
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(163, 13);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(36, 13);
			this->label73->TabIndex = 30;
			this->label73->Text = L"Green";
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(205, 13);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(28, 13);
			this->label74->TabIndex = 31;
			this->label74->Text = L"Blue";
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(243, 39);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(32, 23);
			this->button13->TabIndex = 22;
			this->button13->Text = L">>";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// textBox34
			// 
			this->textBox34->Location = System::Drawing::Point(205, 39);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(32, 20);
			this->textBox34->TabIndex = 34;
			this->textBox34->Text = L"0";
			// 
			// textBox35
			// 
			this->textBox35->Location = System::Drawing::Point(163, 39);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(32, 20);
			this->textBox35->TabIndex = 33;
			this->textBox35->Text = L"0";
			// 
			// textBox36
			// 
			this->textBox36->Location = System::Drawing::Point(120, 39);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(34, 20);
			this->textBox36->TabIndex = 28;
			this->textBox36->Text = L"0";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"all", L"center", L"left", L"right" });
			this->comboBox2->Location = System::Drawing::Point(45, 39);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(69, 21);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->Text = L"Choose";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(3, 0);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(36, 13);
			this->label69->TabIndex = 12;
			this->label69->Text = L"Color";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(45, 13);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(45, 13);
			this->label70->TabIndex = 14;
			this->label70->Text = L"Platform";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(243, 16);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox5->Size = System::Drawing::Size(47, 17);
			this->checkBox5->TabIndex = 157;
			this->checkBox5->Text = L"auto";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->treeView1);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(859, 258);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"USB Descriptors";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Read descriptors";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(131, 6);
			this->treeView1->Name = L"treeView1";
			treeNode1->Name = L"Knoten0";
			treeNode1->Text = L"Press \"Read descriptors\" to read available descriptors of all connected USB devic"
				L"es";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->treeView1->Size = System::Drawing::Size(702, 246);
			this->treeView1->TabIndex = 0;
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label82->Location = System::Drawing::Point(116, 0);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(151, 13);
			this->label82->TabIndex = 152;
			this->label82->Text = L"then connect to interface";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label83->Location = System::Drawing::Point(305, 0);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(93, 13);
			this->label83->TabIndex = 154;
			this->label83->Text = L"of USB device:";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label84->Location = System::Drawing::Point(3, 0);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(31, 13);
			this->label84->TabIndex = 155;
			this->label84->Text = L"First";
			// 
			// tableLayoutPanel15
			// 
			this->tableLayoutPanel15->AutoSize = true;
			this->tableLayoutPanel15->ColumnCount = 9;
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel15->Controls->Add(this->label84, 0, 0);
			this->tableLayoutPanel15->Controls->Add(this->ScanDevicesButton, 1, 0);
			this->tableLayoutPanel15->Controls->Add(this->label82, 2, 0);
			this->tableLayoutPanel15->Controls->Add(this->comboBox1, 8, 0);
			this->tableLayoutPanel15->Controls->Add(this->label83, 7, 0);
			this->tableLayoutPanel15->Controls->Add(this->sendInterfaceTextBox, 6, 0);
			this->tableLayoutPanel15->Location = System::Drawing::Point(148, 12);
			this->tableLayoutPanel15->Name = L"tableLayoutPanel15";
			this->tableLayoutPanel15->RowCount = 1;
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel15->Size = System::Drawing::Size(499, 28);
			this->tableLayoutPanel15->TabIndex = 156;
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->AutoSize = true;
			this->tableLayoutPanel10->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->tableLayoutPanel10->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel10->ColumnCount = 3;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel10->Controls->Add(this->tableLayoutPanel26, 2, 0);
			this->tableLayoutPanel10->Controls->Add(this->tableLayoutPanel24, 1, 0);
			this->tableLayoutPanel10->Controls->Add(this->tableLayoutPanel23, 0, 0);
			this->tableLayoutPanel10->Location = System::Drawing::Point(66, 327);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 1;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel10->Size = System::Drawing::Size(713, 98);
			this->tableLayoutPanel10->TabIndex = 157;
			// 
			// tableLayoutPanel26
			// 
			this->tableLayoutPanel26->ColumnCount = 3;
			this->tableLayoutPanel26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel26->Controls->Add(this->label61, 2, 3);
			this->tableLayoutPanel26->Controls->Add(this->label60, 0, 0);
			this->tableLayoutPanel26->Controls->Add(this->label62, 2, 2);
			this->tableLayoutPanel26->Controls->Add(this->hScrollBar7, 1, 3);
			this->tableLayoutPanel26->Controls->Add(this->label63, 2, 1);
			this->tableLayoutPanel26->Controls->Add(this->label64, 1, 0);
			this->tableLayoutPanel26->Controls->Add(this->label65, 0, 3);
			this->tableLayoutPanel26->Controls->Add(this->hScrollBar8, 1, 2);
			this->tableLayoutPanel26->Controls->Add(this->label67, 0, 1);
			this->tableLayoutPanel26->Controls->Add(this->label66, 0, 2);
			this->tableLayoutPanel26->Controls->Add(this->hScrollBar9, 1, 1);
			this->tableLayoutPanel26->Location = System::Drawing::Point(482, 4);
			this->tableLayoutPanel26->Name = L"tableLayoutPanel26";
			this->tableLayoutPanel26->RowCount = 4;
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel26->Size = System::Drawing::Size(227, 87);
			this->tableLayoutPanel26->TabIndex = 158;
			// 
			// tableLayoutPanel24
			// 
			this->tableLayoutPanel24->AutoSize = true;
			this->tableLayoutPanel24->ColumnCount = 3;
			this->tableLayoutPanel24->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel24->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel24->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel24->Controls->Add(this->label52, 0, 0);
			this->tableLayoutPanel24->Controls->Add(this->label53, 2, 3);
			this->tableLayoutPanel24->Controls->Add(this->label56, 1, 0);
			this->tableLayoutPanel24->Controls->Add(this->label59, 0, 1);
			this->tableLayoutPanel24->Controls->Add(this->label58, 0, 2);
			this->tableLayoutPanel24->Controls->Add(this->hScrollBar1, 1, 3);
			this->tableLayoutPanel24->Controls->Add(this->label57, 0, 3);
			this->tableLayoutPanel24->Controls->Add(this->hScrollBar6, 1, 1);
			this->tableLayoutPanel24->Controls->Add(this->hScrollBar5, 1, 2);
			this->tableLayoutPanel24->Controls->Add(this->label54, 2, 2);
			this->tableLayoutPanel24->Controls->Add(this->label55, 2, 1);
			this->tableLayoutPanel24->Location = System::Drawing::Point(243, 4);
			this->tableLayoutPanel24->Name = L"tableLayoutPanel24";
			this->tableLayoutPanel24->RowCount = 4;
			this->tableLayoutPanel24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel24->Size = System::Drawing::Size(232, 89);
			this->tableLayoutPanel24->TabIndex = 158;
			// 
			// tableLayoutPanel23
			// 
			this->tableLayoutPanel23->AutoSize = true;
			this->tableLayoutPanel23->ColumnCount = 3;
			this->tableLayoutPanel23->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel23->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel23->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel23->Controls->Add(this->label6, 0, 0);
			this->tableLayoutPanel23->Controls->Add(this->FullColorLabel, 1, 0);
			this->tableLayoutPanel23->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel23->Controls->Add(this->BlueLabel, 2, 3);
			this->tableLayoutPanel23->Controls->Add(this->hScrollBar2, 1, 1);
			this->tableLayoutPanel23->Controls->Add(this->RedLabel, 2, 1);
			this->tableLayoutPanel23->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel23->Controls->Add(this->hScrollBar3, 1, 2);
			this->tableLayoutPanel23->Controls->Add(this->hScrollBar4, 1, 3);
			this->tableLayoutPanel23->Controls->Add(this->GreenLabel, 2, 2);
			this->tableLayoutPanel23->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel23->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel23->Name = L"tableLayoutPanel23";
			this->tableLayoutPanel23->RowCount = 4;
			this->tableLayoutPanel23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel23->Size = System::Drawing::Size(232, 89);
			this->tableLayoutPanel23->TabIndex = 158;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(875, 634);
			this->Controls->Add(this->tableLayoutPanel10);
			this->Controls->Add(this->tableLayoutPanel15);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->tableLayoutPanel11);
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->Text = L"NFC-Base Color Changer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel11->PerformLayout();
			this->tableLayoutPanel21->ResumeLayout(false);
			this->tableLayoutPanel17->ResumeLayout(false);
			this->tableLayoutPanel17->PerformLayout();
			this->tableLayoutPanel20->ResumeLayout(false);
			this->tableLayoutPanel20->PerformLayout();
			this->tableLayoutPanel19->ResumeLayout(false);
			this->tableLayoutPanel19->PerformLayout();
			this->tableLayoutPanel18->ResumeLayout(false);
			this->tableLayoutPanel18->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel22->ResumeLayout(false);
			this->tableLayoutPanel22->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tableLayoutPanel25->ResumeLayout(false);
			this->tableLayoutPanel25->PerformLayout();
			this->tableLayoutPanel27->ResumeLayout(false);
			this->tableLayoutPanel16->ResumeLayout(false);
			this->tableLayoutPanel16->PerformLayout();
			this->tableLayoutPanel14->ResumeLayout(false);
			this->tableLayoutPanel14->PerformLayout();
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->tableLayoutPanel12->ResumeLayout(false);
			this->tableLayoutPanel12->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tableLayoutPanel15->ResumeLayout(false);
			this->tableLayoutPanel15->PerformLayout();
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->tableLayoutPanel26->ResumeLayout(false);
			this->tableLayoutPanel26->PerformLayout();
			this->tableLayoutPanel24->ResumeLayout(false);
			this->tableLayoutPanel24->PerformLayout();
			this->tableLayoutPanel23->ResumeLayout(false);
			this->tableLayoutPanel23->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void ScanDevicesButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox1_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hScrollBar2_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar3_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar4_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hScrollBar6_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar5_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar1_Scroll_1(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar9_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar8_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void hScrollBar7_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e);
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	};
}