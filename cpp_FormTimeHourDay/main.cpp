#include "main.h"

#include <Windows.h>
#include <stdio.h>
#include <thread>
#include <iostream>

using namespace std;

//void WINAPI GetLocalTime(
//    _Out_ LPSYSTEMTIME lpSystemTime
//);
int i = 0;
void cppFormTimeHourDay::main::viewDate()
{
    cppFormTimeHourDay::main fmain;

    SYSTEMTIME st;
    char surrentTime[84] = "";
   /* int i=0;*/
//while (true)
//    {
        GetLocalTime(&st);
         lbYear->Text= st.wYear.ToString("0000");
         lbMonth->Text= st.wMonth.ToString("00");
         lbDay->Text= st.wDay.ToString("00");
         lbHour->Text= st.wHour.ToString("00");
         lbMinute->Text= st.wMinute.ToString("00");
         lbSecond->Text= st.wSecond.ToString("00");
         lbMiliSecond->Text= st.wMilliseconds.ToString("000");

         shour->Text= st.wHour.ToString("00");
         sminute->Text = st.wMinute.ToString("00");
         ssecond->Text = st.wSecond.ToString("00");
         smilsecond->Text = st.wMilliseconds.ToString("000");

         sprintf_s(surrentTime, "%.2d / %.2d / %.4d %.2d:%.2d:%.2d %.3d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
         //std::this_thread::sleep_for(std::chrono::microseconds(1));
         std::cout << i++ << " : Current PC Time : " << surrentTime << std::endl;
      
   /* }*/


}

System::Void cppFormTimeHourDay::main::Timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
  viewDate();
 
}


