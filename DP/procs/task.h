#ifndef TASK_H
#define TASK_H

enum TASK_TYPE
{
    ONE, TWO, THREE
};

struct Task {
    TASK_TYPE type;
    void (*fn)();
};

#endif // TASK_H
