
#include "main.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	cppFormTimeHourDay::main main;
	Application::Run(% main);

}