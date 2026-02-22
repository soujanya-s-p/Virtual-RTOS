#pragma once
#include <functional>
#include <memory>

enum class TaskState {
    READY,
    RUNNING,
    BLOCKED,
    FINISHED
};

struct Task {
    int id;
    int priority;
    int ticks;
    TaskState state;
    std::function<void(std::shared_ptr<Task>)> callback;

    Task(int tid, int prio, int t, std::function<void(std::shared_ptr<Task>)> cb)
        : id(tid), priority(prio), ticks(t), state(TaskState::READY), callback(cb) {}
};
