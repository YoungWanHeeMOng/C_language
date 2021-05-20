#pragma once

#include <iostream>
#include <string>

using namespace std;

class EHProcess
{
    string pname;   // process 이름
    const int tjob; //전체작업량
    const int cjob; // CPU 점유 시 수행 가능 최대 작업량
    int ntjob;
    int ncjob;

    public:
        EHProcess(string pname, int tjob, int cjob);
        void IdleToReady();
        int Running();
        void EndingProgram();
};

