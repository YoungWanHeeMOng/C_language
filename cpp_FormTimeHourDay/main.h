#pragma once

namespace cppFormTimeHourDay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void viewDate();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ lbYear;
	private:
	protected:

	private: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ lbMonth;
	private:
	public: System::Windows::Forms::Label^ lbDay;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	public: System::Windows::Forms::Label^ lbHour;
	private:

	private: System::Windows::Forms::Label^ label10;
	public: System::Windows::Forms::Label^ lbMinute;
	private:

	private:

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ lbSecond;

	private:
	public: System::Windows::Forms::Label^ lbMiliSecond;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::StatusStrip^ status;
	private: System::Windows::Forms::ToolStripStatusLabel^ shour;
	private: System::Windows::Forms::ToolStripStatusLabel^ sminute;
	private: System::Windows::Forms::ToolStripStatusLabel^ ssecond;
	private: System::Windows::Forms::ToolStripStatusLabel^ smilsecond;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::ComponentModel::IContainer^ components;
	public:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbYear = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbMonth = (gcnew System::Windows::Forms::Label());
			this->lbDay = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbHour = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lbMinute = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lbSecond = (gcnew System::Windows::Forms::Label());
			this->lbMiliSecond = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->status = (gcnew System::Windows::Forms::StatusStrip());
			this->shour = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->sminute = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->ssecond = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->smilsecond = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->status->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"날자 :";
			// 
			// lbYear
			// 
			this->lbYear->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbYear->Location = System::Drawing::Point(79, 26);
			this->lbYear->Name = L"lbYear";
			this->lbYear->Size = System::Drawing::Size(54, 22);
			this->lbYear->TabIndex = 1;
			this->lbYear->Text = L"1999";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(130, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"년";
			// 
			// lbMonth
			// 
			this->lbMonth->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbMonth->Location = System::Drawing::Point(168, 26);
			this->lbMonth->Name = L"lbMonth";
			this->lbMonth->Size = System::Drawing::Size(36, 22);
			this->lbMonth->TabIndex = 3;
			this->lbMonth->Text = L"01";
			// 
			// lbDay
			// 
			this->lbDay->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbDay->Location = System::Drawing::Point(223, 26);
			this->lbDay->Name = L"lbDay";
			this->lbDay->Size = System::Drawing::Size(36, 22);
			this->lbDay->TabIndex = 5;
			this->lbDay->Text = L"01";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(194, 26);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 22);
			this->label6->TabIndex = 4;
			this->label6->Text = L"월";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(250, 26);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 22);
			this->label7->TabIndex = 6;
			this->label7->Text = L"일";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(314, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 22);
			this->label8->TabIndex = 8;
			this->label8->Text = L"시";
			// 
			// lbHour
			// 
			this->lbHour->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbHour->Location = System::Drawing::Point(288, 26);
			this->lbHour->Name = L"lbHour";
			this->lbHour->Size = System::Drawing::Size(36, 22);
			this->lbHour->TabIndex = 7;
			this->lbHour->Text = L"01";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label10->Location = System::Drawing::Point(370, 26);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 22);
			this->label10->TabIndex = 10;
			this->label10->Text = L"분";
			// 
			// lbMinute
			// 
			this->lbMinute->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbMinute->Location = System::Drawing::Point(343, 26);
			this->lbMinute->Name = L"lbMinute";
			this->lbMinute->Size = System::Drawing::Size(36, 22);
			this->lbMinute->TabIndex = 9;
			this->lbMinute->Text = L"01";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label12->Location = System::Drawing::Point(426, 26);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(32, 22);
			this->label12->TabIndex = 12;
			this->label12->Text = L"초";
			// 
			// lbSecond
			// 
			this->lbSecond->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbSecond->Location = System::Drawing::Point(398, 26);
			this->lbSecond->Name = L"lbSecond";
			this->lbSecond->Size = System::Drawing::Size(36, 22);
			this->lbSecond->TabIndex = 11;
			this->lbSecond->Text = L"01";
			// 
			// lbMiliSecond
			// 
			this->lbMiliSecond->Font = (gcnew System::Drawing::Font(L"Gulim", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->lbMiliSecond->Location = System::Drawing::Point(453, 26);
			this->lbMiliSecond->Name = L"lbMiliSecond";
			this->lbMiliSecond->Size = System::Drawing::Size(45, 22);
			this->lbMiliSecond->TabIndex = 13;
			this->lbMiliSecond->Text = L"01";
			this->lbMiliSecond->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &main::Timer1_Tick);
			// 
			// status
			// 
			this->status->AutoSize = false;
			this->status->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 16));
			this->status->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripStatusLabel1,
					this->shour, this->sminute, this->ssecond, this->smilsecond
			});
			this->status->Location = System::Drawing::Point(0, 74);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(727, 36);
			this->status->TabIndex = 14;
			this->status->Text = L"statusStrip1";
			// 
			// shour
			// 
			this->shour->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->shour->BorderStyle = System::Windows::Forms::Border3DStyle::SunkenOuter;
			this->shour->Name = L"shour";
			this->shour->Size = System::Drawing::Size(37, 31);
			this->shour->Text = L"00";
			// 
			// sminute
			// 
			this->sminute->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->sminute->BorderStyle = System::Windows::Forms::Border3DStyle::SunkenOuter;
			this->sminute->Name = L"sminute";
			this->sminute->Size = System::Drawing::Size(37, 31);
			this->sminute->Text = L"00";
			// 
			// ssecond
			// 
			this->ssecond->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ssecond->BorderStyle = System::Windows::Forms::Border3DStyle::SunkenOuter;
			this->ssecond->Name = L"ssecond";
			this->ssecond->Size = System::Drawing::Size(37, 31);
			this->ssecond->Text = L"00";
			// 
			// smilsecond
			// 
			this->smilsecond->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->smilsecond->BorderStyle = System::Windows::Forms::Border3DStyle::SunkenOuter;
			this->smilsecond->Name = L"smilsecond";
			this->smilsecond->Size = System::Drawing::Size(49, 31);
			this->smilsecond->Text = L"000";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->AutoSize = false;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(550, 31);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 110);
			this->Controls->Add(this->status);
			this->Controls->Add(this->lbMiliSecond);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->lbSecond);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->lbMinute);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->lbHour);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->lbDay);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->lbMonth);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lbYear);
			this->Controls->Add(this->label1);
			this->Name = L"main";
			this->Text = L"날자 시간 표시";
			this->Load += gcnew System::EventHandler(this, &main::Main_Load);
			this->status->ResumeLayout(false);
			this->status->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
		
	}

private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e);
};
}
