/*
 * Warning: code is not htread-safe
 *
 * Problem: There are 3 CPUs, each accepts only 1 type of tasks.
 * Tasks are pushed to queue. If corresponding CPU is busy, task is pushed to stack instead.
 * Stack has higher pop priority than queue.
 *
 * Emulate task processing by CPUs.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <stdlib.h>
#include <thread>
#include <chrono>

#include "task.h"
#include "proc.h"

static std::vector<Proc *> procs;
static std::queue<Task *> task_queue;
static std::stack<Task *> task_stack;

void sleep_task()
{
    int time_to_sleep = std::rand() % 5 + 1;
    std::cout << "[ TASK ]Sleeping " << time_to_sleep << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(time_to_sleep));
}

bool try_to_assign(Task &task)
{
    for (auto &p : procs) {
        if (p->acceptsTask(task) && p->isFree()) {
            p->execute(task);
            return true;
        }
    }

    return false;
}

void check_procs() {
    while (!task_stack.empty() && try_to_assign(*task_stack.top())) {
        task_stack.pop();
    }

    while (!task_queue.empty() && try_to_assign(*task_queue.front())) {
        task_queue.pop();
    }

    if (!task_queue.empty()) {
        task_stack.push(task_queue.front());
        task_queue.pop();
    }

   std::cout << "[ROUTER]Stack: " << task_stack.size() << " Queue: "
             << task_queue.size() << " Procs: [" << procs[0]->isFree()
             << " " << procs[1]->isFree() << " " << procs[2]->isFree()
             << "]" << std::endl;
}

void proc_ready(Proc &p)
{
    check_procs();
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (auto &i : {TASK_TYPE::ONE, TASK_TYPE::TWO, TASK_TYPE::THREE}) {
        procs.push_back(new Proc(i, proc_ready));
    }

    int task_type_to_insert;
    Task *task;

    while (true) {
        std::cout << "[SCRIPT]Enter task typer to insert (1-3): ";
        std::cin >> task_type_to_insert;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();

            std::cout << "[SCRIPT]Bad input" << std::endl;
            continue;
        }

        if (task_type_to_insert > 3 || task_type_to_insert < 1) {
            continue;
        }

        task = new Task();
        task->fn = &sleep_task;

        switch (task_type_to_insert) {
        case 1:
            task->type = TASK_TYPE::ONE;
            break;
        case 2:
            task->type = TASK_TYPE::TWO;
            break;
        case 3:
            task->type = TASK_TYPE::THREE;
            break;
        default:
            std::cout << "[SCRIPT]Invalid task type" << std::endl;
            continue;
        }

        task_queue.push(task);
        check_procs();
    }
}
