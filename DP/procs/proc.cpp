#include "proc.h"

Proc::Proc(const TASK_TYPE &type, void (*callback_fn)(Proc &))
    : state(0)
    , accepted_type(type)
    , callback_fn(callback_fn)
{

}

Proc::~Proc()
{

}

bool Proc::acceptsTask(const Task &task)
{
    return accepted_type == task.type;
}

bool Proc::isFree()
{
    return !isBusy();
}

bool Proc::isBusy()
{
    return state;
}

int Proc::getNumber()
{
    return accepted_type + 1;
}

void Proc::execute(const Task &task)
{
    state = 1;
    std::cout << "[PROC " << getNumber() << "]Running task" << std::endl;
    std::thread t(&Proc::executor, this, task);
    t.detach();
}

void Proc::executor(const Task &task)
{
    task.fn();
    state = 0;
    std::cout << "[PROC " << getNumber() << "]Ready" << std::endl;
    callback_fn(*this);
}
