#include "EHProcess.h"

EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob), cjob(cjob)
{
    this->pname=pname;
}
void EHProcess::IdleToReady()
{
    cout << pname << "�� �۾���: " << tjob << " CPU ������ �۾���: " << cjob << endl;
    ntjob=tjob;
}

#include <Windows.h>
int EHProcess::Running()
{
    cout << pname << " CPU ����"<<endl;
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
    cout << pname << " ����"<<endl;
}
