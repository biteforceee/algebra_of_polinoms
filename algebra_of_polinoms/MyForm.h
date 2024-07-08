#include "Polynomial.h"
#include <msclr\marshal_cppstd.h>
#include <regex>
#include <cctype>
#pragma once

namespace algebraofpolinoms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;


	Polynomial A;
	Polynomial B;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textA;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textB;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textResult;
	private: System::Windows::Forms::Button^ buttonSum;
	private: System::Windows::Forms::Button^ buttonSubtraction;
	private: System::Windows::Forms::Button^ buttonMultiplyK;
	private: System::Windows::Forms::Button^ buttonMultiply;






	private: System::Windows::Forms::TextBox^ textK;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textMaxDegree;
	private: System::Windows::Forms::TextBox^ textCount;
	private: System::Windows::Forms::Label^ labelA;
	private: System::Windows::Forms::Label^ labelB;








	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Label^ labelCount;

	private: System::Windows::Forms::Label^ labelK;
	private: System::Windows::Forms::Label^ labelDegree;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textA = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textB = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textResult = (gcnew System::Windows::Forms::TextBox());
			this->buttonSum = (gcnew System::Windows::Forms::Button());
			this->buttonSubtraction = (gcnew System::Windows::Forms::Button());
			this->buttonMultiplyK = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->textK = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textMaxDegree = (gcnew System::Windows::Forms::TextBox());
			this->textCount = (gcnew System::Windows::Forms::TextBox());
			this->labelA = (gcnew System::Windows::Forms::Label());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->labelCount = (gcnew System::Windows::Forms::Label());
			this->labelK = (gcnew System::Windows::Forms::Label());
			this->labelDegree = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textA
			// 
			this->textA->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textA->ForeColor = System::Drawing::SystemColors::MenuText;
			this->textA->Location = System::Drawing::Point(83, 105);
			this->textA->Margin = System::Windows::Forms::Padding(4);
			this->textA->Name = L"textA";
			this->textA->Size = System::Drawing::Size(612, 53);
			this->textA->TabIndex = 0;
			this->textA->MouseLeave += gcnew System::EventHandler(this, &MyForm::textA_MouseLeave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(17, 108);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"A:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 205);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 46);
			this->label2->TabIndex = 3;
			this->label2->Text = L"B:";
			// 
			// textB
			// 
			this->textB->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textB->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textB->Location = System::Drawing::Point(83, 202);
			this->textB->Margin = System::Windows::Forms::Padding(4);
			this->textB->Name = L"textB";
			this->textB->Size = System::Drawing::Size(612, 53);
			this->textB->TabIndex = 2;
			this->textB->MouseLeave += gcnew System::EventHandler(this, &MyForm::textB_MouseLeave_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(17, 367);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 46);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Res";
			// 
			// textResult
			// 
			this->textResult->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textResult->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textResult->Location = System::Drawing::Point(127, 364);
			this->textResult->Margin = System::Windows::Forms::Padding(4);
			this->textResult->Name = L"textResult";
			this->textResult->ReadOnly = true;
			this->textResult->Size = System::Drawing::Size(815, 53);
			this->textResult->TabIndex = 4;
			// 
			// buttonSum
			// 
			this->buttonSum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSum->Location = System::Drawing::Point(13, 294);
			this->buttonSum->Margin = System::Windows::Forms::Padding(4);
			this->buttonSum->Name = L"buttonSum";
			this->buttonSum->Size = System::Drawing::Size(94, 69);
			this->buttonSum->TabIndex = 6;
			this->buttonSum->Text = L"+";
			this->buttonSum->UseVisualStyleBackColor = true;
			this->buttonSum->Click += gcnew System::EventHandler(this, &MyForm::buttonSum_Click);
			// 
			// buttonSubtraction
			// 
			this->buttonSubtraction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSubtraction->Location = System::Drawing::Point(127, 294);
			this->buttonSubtraction->Margin = System::Windows::Forms::Padding(4);
			this->buttonSubtraction->Name = L"buttonSubtraction";
			this->buttonSubtraction->Size = System::Drawing::Size(94, 69);
			this->buttonSubtraction->TabIndex = 7;
			this->buttonSubtraction->Text = L"-";
			this->buttonSubtraction->UseVisualStyleBackColor = true;
			this->buttonSubtraction->Click += gcnew System::EventHandler(this, &MyForm::buttonSubtraction_Click);
			// 
			// buttonMultiplyK
			// 
			this->buttonMultiplyK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMultiplyK->Location = System::Drawing::Point(229, 294);
			this->buttonMultiplyK->Margin = System::Windows::Forms::Padding(4);
			this->buttonMultiplyK->Name = L"buttonMultiplyK";
			this->buttonMultiplyK->Size = System::Drawing::Size(94, 69);
			this->buttonMultiplyK->TabIndex = 8;
			this->buttonMultiplyK->Text = L"*k";
			this->buttonMultiplyK->UseVisualStyleBackColor = true;
			this->buttonMultiplyK->Click += gcnew System::EventHandler(this, &MyForm::buttonMultiplyK_Click);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMultiply->Location = System::Drawing::Point(424, 294);
			this->buttonMultiply->Margin = System::Windows::Forms::Padding(4);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(90, 69);
			this->buttonMultiply->TabIndex = 9;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = true;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &MyForm::buttonMultiply_Click);
			// 
			// textK
			// 
			this->textK->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textK->Location = System::Drawing::Point(331, 302);
			this->textK->Margin = System::Windows::Forms::Padding(4);
			this->textK->Name = L"textK";
			this->textK->Size = System::Drawing::Size(85, 53);
			this->textK->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Control;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(13, 21);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 46);
			this->label4->TabIndex = 11;
			this->label4->Text = L"maxSt";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Control;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(314, 21);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 46);
			this->label5->TabIndex = 12;
			this->label5->Text = L"N";
			// 
			// textMaxDegree
			// 
			this->textMaxDegree->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textMaxDegree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textMaxDegree->Location = System::Drawing::Point(169, 18);
			this->textMaxDegree->Margin = System::Windows::Forms::Padding(4);
			this->textMaxDegree->Name = L"textMaxDegree";
			this->textMaxDegree->Size = System::Drawing::Size(121, 53);
			this->textMaxDegree->TabIndex = 13;
			// 
			// textCount
			// 
			this->textCount->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textCount->Location = System::Drawing::Point(371, 18);
			this->textCount->Margin = System::Windows::Forms::Padding(4);
			this->textCount->Name = L"textCount";
			this->textCount->Size = System::Drawing::Size(121, 53);
			this->textCount->TabIndex = 14;
			// 
			// labelA
			// 
			this->labelA->AutoSize = true;
			this->labelA->BackColor = System::Drawing::SystemColors::Control;
			this->labelA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelA->Location = System::Drawing::Point(77, 167);
			this->labelA->Name = L"labelA";
			this->labelA->Size = System::Drawing::Size(159, 31);
			this->labelA->TabIndex = 15;
			this->labelA->Text = L"A добавлен";
			this->labelA->Visible = false;
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->BackColor = System::Drawing::SystemColors::Control;
			this->labelB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelB->Location = System::Drawing::Point(77, 259);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(159, 31);
			this->labelB->TabIndex = 16;
			this->labelB->Text = L"В добавлен";
			this->labelB->Visible = false;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(703, 105);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(4);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(239, 150);
			this->buttonAdd->TabIndex = 18;
			this->buttonAdd->Text = L"Считать значения";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// labelCount
			// 
			this->labelCount->AutoSize = true;
			this->labelCount->BackColor = System::Drawing::SystemColors::Control;
			this->labelCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelCount->Location = System::Drawing::Point(970, 165);
			this->labelCount->Name = L"labelCount";
			this->labelCount->Size = System::Drawing::Size(149, 25);
			this->labelCount->TabIndex = 19;
			this->labelCount->Text = L"Reading error!";
			this->labelCount->Visible = false;
			// 
			// labelK
			// 
			this->labelK->AutoSize = true;
			this->labelK->BackColor = System::Drawing::SystemColors::Control;
			this->labelK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelK->Location = System::Drawing::Point(340, 496);
			this->labelK->Name = L"labelK";
			this->labelK->Size = System::Drawing::Size(149, 25);
			this->labelK->TabIndex = 20;
			this->labelK->Text = L"Reading error!";
			this->labelK->Visible = false;
			// 
			// labelDegree
			// 
			this->labelDegree->AutoSize = true;
			this->labelDegree->BackColor = System::Drawing::SystemColors::Control;
			this->labelDegree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDegree->Location = System::Drawing::Point(970, 79);
			this->labelDegree->Name = L"labelDegree";
			this->labelDegree->Size = System::Drawing::Size(149, 25);
			this->labelDegree->TabIndex = 21;
			this->labelDegree->Text = L"Reading error!";
			this->labelDegree->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(955, 571);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->labelB);
			this->Controls->Add(this->labelA);
			this->Controls->Add(this->textCount);
			this->Controls->Add(this->textMaxDegree);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textK);
			this->Controls->Add(this->buttonMultiply);
			this->Controls->Add(this->buttonMultiplyK);
			this->Controls->Add(this->buttonSubtraction);
			this->Controls->Add(this->buttonSum);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textResult);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textB);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textA);
			this->ForeColor = System::Drawing::Color::Black;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool is_num(String^ s) {
			int  i = 0;
			int l;
			if (i == 0 && s[i] == '-') { i = 1; }
			if (s->Length > i) {
				l = 0;
				for (int i = 0; i < s->Length; i++) {
					if (s[i] == ',') {
						if (l == 1) { return false; }
						l = 1;
					}
					else {
						if (!Char::IsNumber(s[i])) {
							return false;
						}
					}

				}
			}
			return true;
		}

		void removeSpaces(std::string& str) {
			str.erase(remove(str.begin(), str.end(), ' '), str.end());
		}

	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		labelA->Visible = FALSE;
		labelB->Visible = FALSE;
		labelCount->Visible = FALSE;
		labelDegree->Visible = FALSE;
		//labelResult->Visible = FALSE;
		string stringMaxDegree = msclr::interop::marshal_as<std::string>(textMaxDegree->Text);
		string stringCount = msclr::interop::marshal_as<std::string>(textCount->Text);
		if (!stringMaxDegree.empty() && is_num(textMaxDegree->Text)) {
			if (!stringCount.empty() && is_num(textCount->Text)) {
				string stringA = msclr::interop::marshal_as<std::string>(textA->Text);
				removeSpaces(stringA);
				string stringB = msclr::interop::marshal_as<std::string>(textB->Text);
				removeSpaces(stringB);
				if (!stringA.empty()) {
					if (!stringB.empty()) {
						int maxDegree = stoi(stringMaxDegree);
						int count = stoi(stringCount);
						A = Polynomial(stringA, maxDegree, count);
						if (A.getStringPolynomial().find("") == -1) {
							labelA->Text = "А добавлен";
							labelA->Visible = TRUE;
						}
						B = Polynomial(stringB, maxDegree, count);
						if (B.getStringPolynomial().find("") == -1) {
							labelB->Text = "B добавлен";
							labelB->Visible = TRUE;
						}
						textA->Text = marshal_as<String^>(A.getStringPolynomial());
						textB->Text = marshal_as<String^>(B.getStringPolynomial());
					}
					else {
						labelB->Visible = TRUE;
						labelB->Text = "введите полиномы";
					}
				}
			}
		}
	}

	private: System::Void buttonSum_Click(System::Object^ sender, System::EventArgs^ e) {
		Polynomial C = A + B;
		textResult->Text = marshal_as<String^>(C.getStringPolynomial());
	}

	private: System::Void buttonSubtraction_Click(System::Object^ sender, System::EventArgs^ e) {
		Polynomial C = A - B;
		textResult->Text = marshal_as<String^>(C.getStringPolynomial());
	}

	private: System::Void buttonMultiply_Click(System::Object^ sender, System::EventArgs^ e) {
		textResult->Text = "";
		//labelResult->Visible = FALSE;
		Polynomial C = A * B;
		if (C.getStringPolynomial().find("Exceeded the maximum degree") != -1) {
			//labelResult->Text = "Error: Maximum degree exceeded!";
			//labelResult->Visible = TRUE;
		}
		else {
			textResult->Text = marshal_as<String^>(C.getStringPolynomial());
		}
	}

	private: System::Void buttonMultiplyK_Click(System::Object^ sender, System::EventArgs^ e) {
		labelK->Visible = FALSE;
		string stringK = msclr::interop::marshal_as<std::string>(textK->Text);
		if (!stringK.empty() && is_num(textK->Text)) {
			int k = stoi(stringK);
			Polynomial C = A * k;
			textResult->Text = marshal_as<String^>(C.getStringPolynomial());
		}
		else {
			labelK->Visible = TRUE;
		}
	}


	private: System::Void textB_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		labelB->Visible = FALSE;
		string stringMaxDegree = msclr::interop::marshal_as<std::string>(textMaxDegree->Text);
		string stringCount = msclr::interop::marshal_as<std::string>(textCount->Text);
		if (!stringMaxDegree.empty() && is_num(textMaxDegree->Text)) {
			if (!stringCount.empty() && is_num(textCount->Text)) {
				string stringB = msclr::interop::marshal_as<std::string>(textB->Text);
				removeSpaces(stringB);
				if (!stringB.empty()) {
					int maxDegree = stoi(stringMaxDegree);
					int count = stoi(stringCount);
					B = Polynomial(stringB, maxDegree, count);
					if (B.getStringPolynomial().find("") == -1) {
						labelB->Text = "B добаввлен";
						labelB->Visible = TRUE;
					}
					textB->Text = marshal_as<String^>(B.getStringPolynomial());
				}
				else {
					labelB->Visible = TRUE;
					labelB->Text = "Reading error!";
				}

			}
		}
	}
	private: System::Void textA_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		labelA->Visible = FALSE;
		string stringMaxDegree = msclr::interop::marshal_as<std::string>(textMaxDegree->Text);
		string stringCount = msclr::interop::marshal_as<std::string>(textCount->Text);
		if (!stringMaxDegree.empty() && is_num(textMaxDegree->Text)) {
			if (!stringCount.empty() && is_num(textCount->Text)) {
				string stringA = msclr::interop::marshal_as<std::string>(textA->Text);
				removeSpaces(stringA);
				if (!stringA.empty()) {
					int maxDegree = stoi(stringMaxDegree);
					int count = stoi(stringCount);
					A = Polynomial(stringA, maxDegree, count);
					if (A.getStringPolynomial().find("") == -1) {
						labelA->Text = "А добавлен";
						labelA->Visible = TRUE;
					}
					textA->Text = marshal_as<String^>(A.getStringPolynomial());
				}
				else {
					labelA->Visible = TRUE;
					labelA->Text = "Reading error!";
				}
			}
		}
	}
	private: System::Void textB_MouseLeave_1(System::Object^ sender, System::EventArgs^ e) {
		//labelA->Visible = FALSE;
		labelB->Visible = FALSE;
		labelCount->Visible = FALSE;
		labelDegree->Visible = FALSE;
		//labelResult->Visible = FALSE;
		string stringMaxDegree = msclr::interop::marshal_as<std::string>(textMaxDegree->Text);
		string stringCount = msclr::interop::marshal_as<std::string>(textCount->Text);
		if (!stringMaxDegree.empty() && is_num(textMaxDegree->Text)) {
			if (!stringCount.empty() && is_num(textCount->Text)) {
				/*string stringA = msclr::interop::marshal_as<std::string>(textA->Text);
				removeSpaces(stringA);*/
				string stringB = msclr::interop::marshal_as<std::string>(textB->Text);
				removeSpaces(stringB);
				if (!stringB.empty()) {
					if (!stringB.empty()) {
						int maxDegree = stoi(stringMaxDegree);
						int count = stoi(stringCount);
						/*A = Polynomial(stringA, maxDegree, count);
						if (A.getStringPolynomial().find("") == -1) {
							labelA->Text = "А добавлен";
							labelA->Visible = TRUE;
						}*/
						B = Polynomial(stringB, maxDegree, count);
						if (B.getStringPolynomial().find("") == -1) {
							labelB->Text = "B добавлен";
							labelB->Visible = TRUE;
						}
						//textA->Text = marshal_as<String^>(A.getStringPolynomial());
						textB->Text = marshal_as<String^>(B.getStringPolynomial());
					}
					else {
						labelB->Visible = TRUE;
						labelB->Text = "введите полиномы";
					}
				}
			}
		}
	}
	};
}
