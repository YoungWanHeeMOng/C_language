#include "EHProcess.h"

EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob), cjob(cjob)
{
    this->pname=pname;
}
void EHProcess::IdleToReady()
{
    cout << pname << "총 작업량: " << tjob << " CPU 점유시 작업량: " << cjob << endl;
    ntjob=tjob;
}

#include <Windows.h>
int EHProcess::Running()
{
    cout << pname << " CPU 점유"<<endl;
    ncjob=cjob;
    for (; ntjob && ncjob; ntjob--, ncjob--)
    {
        Sleep(300);
        cout << ntjob << " ";
    }
    cout << endl;

    return ntjob;
}
void EHProcess::EndingProgram()
{
    cout << pname << " 종료"<<endl;
}
