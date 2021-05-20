#pragma once

#include <iostream>
#include <string>

using namespace std;

class EHProcess
{
    string pname;   // process �̸�
    const int tjob; //��ü�۾���
    const int cjob; // CPU ���� �� ���� ���� �ִ� �۾���
    int ntjob;
    int ncjob;

    public:
        EHProcess(string pname, int tjob, int cjob);
        void IdleToReady();
        int Running();
        void EndingProgram();
};

