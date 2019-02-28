#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <thread>

#include "task.h"

class Proc
{
    bool state; // 0: free; 1: busy

    TASK_TYPE accepted_type;
    void (*callback_fn)(Proc &);
public:
    Proc(const TASK_TYPE &type, void (*callback_fn)(Proc &));

    bool acceptsTask(const Task &task);
    bool isFree();
    bool isBusy();

    int getNumber();

    void execute(const Task &task);
private:
    void executor(const Task &task);
};

#endif // PROC_H
