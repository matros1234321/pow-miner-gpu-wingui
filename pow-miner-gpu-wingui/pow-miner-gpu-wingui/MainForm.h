#pragma once

#include "AboutForm.h"
#include <msclr\marshal_cppstd.h>

#include <windows.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <comdef.h>
#include <io.h>
#include <fcntl.h>

#include "AppSysSubProcess.h"
#include "MinerConfig.h"

#include "DeviceTab.h"

#include "UpdateToolsForm.h"

#include "MapVoid.h"

#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

void stopall_thread(void);

namespace powminergpuwingui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	public: static MainForm^ MainForm_0;

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			MainForm_0 = this;

			DeviceTabsMap = new MapVoid();

			LoadConfig();

			//
			

			

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ToolStripMenuItem^  importSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolsToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  DevicesListBox;
	private: System::Windows::Forms::Button^  SearchCUDADevicesButton;
	private: System::Windows::Forms::Button^  UseDeviceButton;
	private: System::Windows::Forms::Button^  SearchOpenCLDevicesButton;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;

	public: System::Windows::Forms::TabControl^  DevicesTabControl;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  StartAllButton;
	private: System::Windows::Forms::Button^  StopAllButton;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->DevicesListBox = (gcnew System::Windows::Forms::ListBox());
			this->SearchCUDADevicesButton = (gcnew System::Windows::Forms::Button());
			this->UseDeviceButton = (gcnew System::Windows::Forms::Button());
			this->SearchOpenCLDevicesButton = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->StartAllButton = (gcnew System::Windows::Forms::Button());
			this->StopAllButton = (gcnew System::Windows::Forms::Button());
			this->DevicesTabControl = (gcnew System::Windows::Forms::TabControl());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1292, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->importSettingsToolStripMenuItem,
					this->exportSettingsToolStripMenuItem, this->updateToolsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importSettingsToolStripMenuItem
			// 
			this->importSettingsToolStripMenuItem->Name = L"importSettingsToolStripMenuItem";
			this->importSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->importSettingsToolStripMenuItem->Text = L"Import settings";
			this->importSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::importSettingsToolStripMenuItem_Click);
			// 
			// exportSettingsToolStripMenuItem
			// 
			this->exportSettingsToolStripMenuItem->Name = L"exportSettingsToolStripMenuItem";
			this->exportSettingsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->exportSettingsToolStripMenuItem->Text = L"Export settings";
			this->exportSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exportSettingsToolStripMenuItem_Click);
			// 
			// updateToolsToolStripMenuItem
			// 
			this->updateToolsToolStripMenuItem->Name = L"updateToolsToolStripMenuItem";
			this->updateToolsToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->updateToolsToolStripMenuItem->Text = L"Update tools";
			this->updateToolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::updateToolsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitCallback);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::AboutCallback);
			// 
			// DevicesListBox
			// 
			this->DevicesListBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->DevicesListBox->FormattingEnabled = true;
			this->DevicesListBox->HorizontalScrollbar = true;
			this->DevicesListBox->Location = System::Drawing::Point(3, 61);
			this->DevicesListBox->MaximumSize = System::Drawing::Size(156, 350);
			this->DevicesListBox->MinimumSize = System::Drawing::Size(156, 350);
			this->DevicesListBox->Name = L"DevicesListBox";
			this->DevicesListBox->Size = System::Drawing::Size(156, 342);
			this->DevicesListBox->TabIndex = 3;
			// 
			// SearchCUDADevicesButton
			// 
			this->SearchCUDADevicesButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchCUDADevicesButton->Location = System::Drawing::Point(3, 3);
			this->SearchCUDADevicesButton->Name = L"SearchCUDADevicesButton";
			this->SearchCUDADevicesButton->Size = System::Drawing::Size(156, 23);
			this->SearchCUDADevicesButton->TabIndex = 1;
			this->SearchCUDADevicesButton->Text = L"Search CUDA devices";
			this->SearchCUDADevicesButton->UseVisualStyleBackColor = true;
			this->SearchCUDADevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchCUDADevicesButton_Click);
			// 
			// UseDeviceButton
			// 
			this->UseDeviceButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->UseDeviceButton->Location = System::Drawing::Point(3, 417);
			this->UseDeviceButton->Name = L"UseDeviceButton";
			this->UseDeviceButton->Size = System::Drawing::Size(156, 23);
			this->UseDeviceButton->TabIndex = 4;
			this->UseDeviceButton->Text = L"Use device";
			this->UseDeviceButton->UseVisualStyleBackColor = true;
			this->UseDeviceButton->Click += gcnew System::EventHandler(this, &MainForm::UseDeviceButton_Click);
			// 
			// SearchOpenCLDevicesButton
			// 
			this->SearchOpenCLDevicesButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchOpenCLDevicesButton->Location = System::Drawing::Point(3, 32);
			this->SearchOpenCLDevicesButton->Name = L"SearchOpenCLDevicesButton";
			this->SearchOpenCLDevicesButton->Size = System::Drawing::Size(156, 23);
			this->SearchOpenCLDevicesButton->TabIndex = 2;
			this->SearchOpenCLDevicesButton->Text = L"Search OpenCL devices";
			this->SearchOpenCLDevicesButton->UseVisualStyleBackColor = true;
			this->SearchOpenCLDevicesButton->Click += gcnew System::EventHandler(this, &MainForm::SearchOpenCLDevicesButton_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->SearchCUDADevicesButton);
			this->flowLayoutPanel1->Controls->Add(this->SearchOpenCLDevicesButton);
			this->flowLayoutPanel1->Controls->Add(this->DevicesListBox);
			this->flowLayoutPanel1->Controls->Add(this->UseDeviceButton);
			this->flowLayoutPanel1->Controls->Add(this->StartAllButton);
			this->flowLayoutPanel1->Controls->Add(this->StopAllButton);
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 24);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(164, 498);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// StartAllButton
			// 
			this->StartAllButton->Location = System::Drawing::Point(3, 446);
			this->StartAllButton->Name = L"StartAllButton";
			this->StartAllButton->Size = System::Drawing::Size(156, 23);
			this->StartAllButton->TabIndex = 5;
			this->StartAllButton->Text = L"Start all";
			this->StartAllButton->UseVisualStyleBackColor = true;
			this->StartAllButton->Click += gcnew System::EventHandler(this, &MainForm::StartAllButton_Click);
			// 
			// StopAllButton
			// 
			this->StopAllButton->Location = System::Drawing::Point(3, 475);
			this->StopAllButton->Name = L"StopAllButton";
			this->StopAllButton->Size = System::Drawing::Size(156, 23);
			this->StopAllButton->TabIndex = 6;
			this->StopAllButton->Text = L"Stop all";
			this->StopAllButton->UseVisualStyleBackColor = true;
			this->StopAllButton->Click += gcnew System::EventHandler(this, &MainForm::StopAllButton_Click);
			// 
			// DevicesTabControl
			// 
			this->DevicesTabControl->Location = System::Drawing::Point(170, 24);
			this->DevicesTabControl->Name = L"DevicesTabControl";
			this->DevicesTabControl->SelectedIndex = 0;
			this->DevicesTabControl->Size = System::Drawing::Size(1118, 498);
			this->DevicesTabControl->TabIndex = 4;
			this->DevicesTabControl->Tag = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1292, 525);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->DevicesTabControl);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1308, 564);
			this->MinimumSize = System::Drawing::Size(1308, 564);
			this->Name = L"MainForm";
			this->Text = L"pow-miner-gpu-wingui";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitCallback(System::Object^  sender, System::EventArgs^  e) {
	
	StopAll();
	SaveConfig(false);

	this->Close();
}

private: System::Void AboutCallback(System::Object^  sender, System::EventArgs^  e) {
	// this->Hide();
	powminergpuwingui::AboutForm AboutFormObject;
	AboutFormObject.ShowDialog();
	// this->Show();
}

private: System::Void SearchOpenCLDevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-opencl.exe\"", "2>&1", AppSysSubProcess::ExePath(), true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {

		System::String^ Line = gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str());

		if (Line->StartsWith("[ OpenCL: platform #"))
			DevicesListBox->Items->Add(Line);
		
	}

	DevicesListBox->EndUpdate();

}

private: System::Void SearchCUDADevicesButton_Click(System::Object^  sender, System::EventArgs^  e) {

	AppSysSubProcess AppSysSubProcess_0;

	AppSysSubProcess_0.Run("\"" + AppSysSubProcess::ExePath() + "\\tools\\minertools\\pow-miner-cuda.exe\"", "2>&1", AppSysSubProcess::ExePath(), true);

	DevicesListBox->BeginUpdate();

	DevicesListBox->Items->Clear();

	for (int i = 0; i < AppSysSubProcess_0.stdoutData.size(); i++) {
				
		System::String^ Line = gcnew String(AppSysSubProcess_0.stdoutData.at(i).c_str());

		if (Line->StartsWith("[ GPU #"))
			DevicesListBox->Items->Add(Line);

	}

	DevicesListBox->EndUpdate();

}

private: powminergpuwingui::DeviceTab ^DeviceTab_0;
private: int tabs_id_cnt = 0;

public: MapVoid *DeviceTabsMap;

private: System::Void UseDeviceButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
	int type = 0;
	int pid	 = 0;
	int did	 = 0;

	if (DevicesListBox->SelectedItem) {
	
		System::String^ dev_sstr = DevicesListBox->GetItemText(DevicesListBox->SelectedItem);
		std::string dev_str = msclr::interop::marshal_as<std::string>(dev_sstr);

		if (dev_sstr->StartsWith("[ OpenCL: platform #")) {
			type = 1;
			if (sscanf(dev_str.c_str(), "[ OpenCL: platform #%d device #%d ", &pid, &did) != 2)
				return;
		} else if (dev_sstr->StartsWith("[ GPU #")) {
			type = 0;
			if (sscanf(dev_str.c_str(), "[ GPU #%d ", &did) != 1)
				return;
		} else {
			return;
		}

		DeviceTab_0 = (gcnew powminergpuwingui::DeviceTab());

		DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;
		DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(this->tabs_id_cnt);
		DeviceTab_0->GetDevTypeComboBox()->SelectedIndex = type;
		DeviceTab_0->GetDevPidTextBox()->Text = gcnew String(std::to_string(pid).c_str());
		DeviceTab_0->GetDevDidTextBox()->Text = gcnew String(std::to_string(did).c_str());
		
		if (type == 0)
			DeviceTab_0->GetTabPage()->Text = gcnew String(("CUDA [" + std::to_string(pid) + ":" + std::to_string(did) + "]").c_str());
		else if (type == 1)
			DeviceTab_0->GetTabPage()->Text = gcnew String(("OCL [" + std::to_string(pid) + ":" + std::to_string(did) + "]").c_str());

		DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

		DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

		DeviceTab_0->GetTabPage()->Show();

		std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);
		
		DeviceTabsMap->add_void(m_key, (void *) (void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));

		tabs_id_cnt += 1;

			
	}

}

private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

public: delegate void DeviceTab_LogsTextBoxAddLine_Delagate(DeviceTab^ DeviceTab, System::String^ line);

public: void DeviceTab_LogsTextBoxAddLine(DeviceTab^ DeviceTab, System::String^ line) {

	if (DeviceTab->GetLogsTextBox()->InvokeRequired)
	{

		DeviceTab_LogsTextBoxAddLine_Delagate ^DLG = gcnew DeviceTab_LogsTextBoxAddLine_Delagate(this, &MainForm::DeviceTab_LogsTextBoxAddLine);

		if (this->IsHandleCreated)
			this->Invoke(DLG, DeviceTab, line);

	}
	else
	{

		// System::String^ dt_line = gcnew String(AppSysSubProcess::GetDateTime().c_str()) + gcnew String(": ") + line;		
		System::String^ dt_line = line;

		if (dt_line->Contains("FOUND")) {
			DeviceTab->GetLogsFoundsTextBox()->Text = dt_line;
			DeviceTab->AppSysSubProcess_0->DataVector.push_back(msclr::interop::marshal_as<std::string>(dt_line));
		}

		if (dt_line->Contains("average speed:")) {
			
			array<wchar_t> ^id = { ':' ,',', '[', ']' };
			array<String^> ^StringArray_TMP = dt_line->Split(id);

			bool found = false;

			for each(String^ temp in StringArray_TMP) {

				if (found == true) {
					DeviceTab->GetHashSpeedTextBox()->Text = temp;
					break;
				}

				if (temp->Contains("average speed"))
					found = true;
				
					

			}
				
		}
						
		DeviceTab->GetLogsTextBox()->AppendText(dt_line);		

		int max_lines_qnt = int::Parse( DeviceTab->GetLogsMaxLinesTextBox()->Text );

		System::String^ Text = gcnew System::String("");
		
		Text->Copy(DeviceTab->GetLogsMaxLinesTextBox()->Text);
		
		array <String^>^ string_array_temp = DeviceTab->GetLogsTextBox()->Text->Split('\n');

		int lines_qnt = string_array_temp->Length;
		
		// OutputDebugStringA((std::string("max_lines_qnt: ") + std::to_string(max_lines_qnt) + std::string("\n\r")).c_str());
		// OutputDebugStringA((std::string("lines_qnt: ") + std::to_string(lines_qnt) + std::string("\n\r")).c_str());
	
		if (lines_qnt > max_lines_qnt) {

			DeviceTab->GetLogsTextBox()->Text = "";

			// TODO make normal rotation
			/*
			if (string_array_temp->Length == lines_qnt) {

				DeviceTab->GetLogsTextBox()->Text = "";

				for (int i = (lines_qnt - max_lines_qnt); i < (lines_qnt); i++) {

					DeviceTab->GetLogsTextBox()->AppendText(string_array_temp[i]);
					DeviceTab->GetLogsTextBox()->AppendText("\n");

				}

			}
			*/

		}
		
	}

}


private: System::Void updateToolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	powminergpuwingui::UpdateToolsForm UpdateToolsFormObject;
	UpdateToolsFormObject.ShowDialog();

}

public: std::string MarshalString(String ^ s) {
	using namespace Runtime::InteropServices;
	std::string str;

	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return str;
}

private: System::Void exportSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	this->saveFileDialog1->Filter = "JSON file|*.json";
	this->saveFileDialog1->Title = "Export settings to file";
	this->saveFileDialog1->ShowDialog();

	if (this->saveFileDialog1->FileName != "")
	{
		// System::IO::FileStream^ fs = (System::IO::FileStream^) this->saveFileDialog1->OpenFile();

		marshal_context context;

		std::string file_name_str = MarshalString(this->saveFileDialog1->FileName);
		// std::string file_name_str = AppSysSubProcess::ExePath() + "\\config\\autosave.config.json";

		// OutputDebugStringA(file_name_str.c_str());

		SaveConfig_ToFile(file_name_str);
		
		// fs->Close();

	}

}

private: System::Void importSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
	this->openFileDialog1->Filter = "JSON file|*.json";
	this->openFileDialog1->Title = "Import settings from file";
	this->openFileDialog1->ShowDialog();

	if (this->openFileDialog1->FileName != "")
	{
		// System::IO::FileStream^ fs = (System::IO::FileStream^) this->openFileDialog1->OpenFile();

		marshal_context context;

		std::string file_name_str = MarshalString(this->openFileDialog1->FileName);
		// std::string file_name_str = AppSysSubProcess::ExePath() + "\\config\\autosave.config.json";

		// OutputDebugStringA(file_name_str.c_str());

		if (LoadConfig_FromFile(file_name_str, true) != 0 )
			return;

		SaveConfig(true);

		DeleteAll();

		this->tabs_id_cnt = 0;

		if (LoadConfig_FromFile(file_name_str, false) != 0)
			return;

		// fs->Close();
	}

}
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		
	StopAll();

	SaveConfig(false);

}

private: void LoadConfig() {

	if (AppSysSubProcess::FileExists(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json")) {

		std::vector<std::string> miners_json_strings;

		miners_json_strings = AppSysSubProcess::ReadLinesFromFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json");
			
		MinerConfig^ MinerConfig_tmp;

		MinerConfig_tmp = gcnew MinerConfig();

		for (int i = 0; i < miners_json_strings.size(); i++) {

						
			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) == 0) {

				DeviceTab_0 = (gcnew powminergpuwingui::DeviceTab());

				DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;

				DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(tabs_id_cnt);

				DeviceTab_0->ImportConfig(MinerConfig_tmp);

				DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

				std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);

				DeviceTabsMap->add_void(m_key, (void *)(void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));
				
				tabs_id_cnt = tabs_id_cnt + 1;

				// DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

				// DeviceTab_0->GetTabPage()->Show();


			}


		}
	

	}


}

public: void DeleteAll(void) {

	for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->MinerStop();

		P_DeviceTab_TMP->Delete();

	}

}

public: void StartAll(void) {

	for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->MinerStart();

	}

}

private: System::Void StartAllButton_Click(System::Object^  sender, System::EventArgs^  e) {

	StartAll();

}

public: void StopAll(void) {

	if (!DeviceTabsMap->map_void.empty()) {
	
		TabPage^ TMP_TabPage = DevicesTabControl->SelectedTab;

		GCHandle h = GCHandle::FromIntPtr(IntPtr((--DeviceTabsMap->map_void.end())->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);
		
		DevicesTabControl->SelectedTab = P_DeviceTab_TMP->GetTabPage();
		// P_DeviceTab_TMP->GetTabPage()->Show();

		for (std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin(); it != DeviceTabsMap->map_void.end(); it++) {
			
			GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
			DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

			// DevicesTabControl->SelectedTab = P_DeviceTab_TMP->GetTabPage();
			// P_DeviceTab_TMP->GetTabPage()->Show();

			// this->Refresh();
			// this->DevicesTabControl->Refresh();
			// P_DeviceTab_TMP->Refresh();

			P_DeviceTab_TMP->MinerStop();
			P_DeviceTab_TMP->TestStop();
			
			// this->Refresh();
			// this->DevicesTabControl->Refresh();
			// P_DeviceTab_TMP->Refresh();

		}

		DevicesTabControl->SelectedTab = TMP_TabPage;
	
	}

}

private: System::Void StopAllButton_Click(System::Object^  sender, System::EventArgs^  e) {

	StopAll();

}

public: void SaveConfig(bool force) {

	std::vector<std::string> vect_string_old;
	std::vector<std::string> vect_string;

	MinerConfig^ MinerConfig_tmp;

	MinerConfig_tmp = gcnew MinerConfig();

	std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin();

	for (; it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->ExportConfig(MinerConfig_tmp);

		vect_string.push_back( MinerConfig_tmp->export_json_string() + "\n" );

	}

	vect_string_old = AppSysSubProcess::ReadLinesFromFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json");

	if ( (vect_string != vect_string_old) || (force == true) ) {

		std::string dt_str = AppSysSubProcess::GetDateTime();
		std::string dest_file_str = AppSysSubProcess::ExePath() + "\\config\\autosave_dumps\\" + "dump_" + "%s" + "_autosave.config.json";
		char dest_file_char[2048] = { "" };

		sprintf(dest_file_char, dest_file_str.c_str(), dt_str.c_str());

		if (CopyFileA(
			(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json").c_str(),
			dest_file_char,
			false
		) == 0)
			printf("error on config dump creation\n");

		AppSysSubProcess::WriteLinesToFile(AppSysSubProcess::ExePath() + "\\config\\autosave.config.json", &vect_string);

	}

}

public: void SaveConfig_ToFile( std::string filename ) {

	std::vector<std::string> vect_string_old;
	std::vector<std::string> vect_string;

	MinerConfig^ MinerConfig_tmp;

	MinerConfig_tmp = gcnew MinerConfig();

	std::map<std::string, void *>::iterator it = DeviceTabsMap->map_void.begin();

	for (; it != DeviceTabsMap->map_void.end(); it++) {

		GCHandle h = GCHandle::FromIntPtr(IntPtr(it->second));
		DeviceTab^ P_DeviceTab_TMP = reinterpret_cast<DeviceTab^>(h.Target);

		P_DeviceTab_TMP->ExportConfig(MinerConfig_tmp);

		vect_string.push_back(MinerConfig_tmp->export_json_string() + "\n");

	}

	AppSysSubProcess::WriteLinesToFile(filename, &vect_string);

}

public: int LoadConfig_FromFile(std::string filename, bool only_test) {

	if (AppSysSubProcess::FileExists(filename)) {

		std::vector<std::string> miners_json_strings;

		miners_json_strings = AppSysSubProcess::ReadLinesFromFile(filename);
		
		MinerConfig^ MinerConfig_tmp;

		MinerConfig_tmp = gcnew MinerConfig();

		if (miners_json_strings.size() <= 0)
			return 1;

		for (int i = 0; i < miners_json_strings.size(); i++) {
			
			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) != 0) {

				return 1;

			}


		}

		if (only_test == true)
			return 0;


		for (int i = 0; i < miners_json_strings.size(); i++) {

			if (MinerConfig_tmp->import_json_string(miners_json_strings.at(i)) == 0) {

				DeviceTab_0 = (gcnew powminergpuwingui::DeviceTab());

				DeviceTab_0->DevicesTabControl_Parent = this->DevicesTabControl;

				DeviceTab_0->GetTabPage()->Name = "miner" + "_" + System::Convert::ToString(tabs_id_cnt);

				DeviceTab_0->ImportConfig(MinerConfig_tmp);

				DevicesTabControl->TabPages->Add(DeviceTab_0->GetTabPage());

				std::string m_key = "miner_" + std::to_string(this->tabs_id_cnt);

				DeviceTabsMap->add_void(m_key, (void *)(void *)GCHandle::ToIntPtr(GCHandle::Alloc(DeviceTab_0)));

				this->tabs_id_cnt++;

				// DevicesTabControl->SelectedTab = DeviceTab_0->GetTabPage();

				// DeviceTab_0->GetTabPage()->Show();




			}


		}

		return 0;


	}
	else {

		return 1;
	}

}


};
}

