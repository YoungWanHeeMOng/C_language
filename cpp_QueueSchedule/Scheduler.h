#pragma once
#include <vector>
#include <queue>

using namespace std;
#include "EHProcess.h"

typedef vector<EHProcess *> Memory;
typedef queue<EHProcess *> ReadyQueue;
typedef Memory::iterator miter;

class Scheduler
{
    Memory hard_disk;
    ReadyQueue rq;

    public:
        Scheduler();
        ~Scheduler();
        void Simulation();

    private:
        void Init();
        void Ending();
};

