#include "Myform.h"


using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	algebraofpolinoms::MyForm form;
	Application::Run(% form);
}