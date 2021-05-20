#include "Scheduler.h"


Scheduler::Scheduler()
{
    Init();
}
Scheduler::~Scheduler()
{
    Ending();
}
void Scheduler::Simulation()
{
    EHProcess *process=0;
    int job=0;
    while (!rq.empty())
    {
        process=rq.front();
        rq.pop();

        job=process->Running();
        if (job)
        {
            rq.push(process);
        }
        else
        {
            process->EndingProgram();
        }
    }
}

void Scheduler::Init()
{
    hard_disk.push_back(new EHProcess("A", 20, 5));
    hard_disk.push_back(new EHProcess("B", 23, 6));
    hard_disk.push_back(new EHProcess("C", 18, 4));
    hard_disk.push_back(new EHProcess("D", 38, 7));

    miter seek= hard_disk.begin();
    miter end = hard_disk.end();
    EHProcess* pro=0;
    for (; seek != end; ++seek)
    {
        pro=*seek;
        rq.push(pro);
        pro->IdleToReady();
    }
}
void Scheduler::Ending()
{
    miter seek=hard_disk.begin();
    miter end = hard_disk.end();
    for (; seek != end; ++seek)
    {
        delete *seek;
    }
}