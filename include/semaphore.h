#pragma once
#include <queue>
#include <memory>
#include "scheduler.h"

class Semaphore {
private:
    int count;
    std::queue<std::shared_ptr<Task>> blockedQueue;

public:
    Semaphore(int init) : count(init) {}

    void wait(std::shared_ptr<Task> task) {
        if (count > 0) {
            count--;
        } else {
            task->state = TaskState::BLOCKED;
            blockedQueue.push(task);
        }
    }

    void signal() {
        count++;
        if (!blockedQueue.empty()) {
            auto task = blockedQueue.front();
            blockedQueue.pop();
            task->state = TaskState::READY;
        }
    }
};
