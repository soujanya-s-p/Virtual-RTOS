
#pragma once
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <functional>

enum class TaskState { READY, RUNNING, BLOCKED };

// Task struct
struct Task {
    int id;
    int priority;
    int remainingTicks;
    TaskState state;
    std::function<void(std::shared_ptr<Task>)> taskFunc;

    Task(int i, int p, int ticks, std::function<void(std::shared_ptr<Task>)> f)
        : id(i), priority(p), remainingTicks(ticks), state(TaskState::READY), taskFunc(f) {}
};

// Scheduler class
class Scheduler {
private:
    std::vector<std::shared_ptr<Task>> readyQueue;

public:
    void addTask(int id, int priority, int ticks, std::function<void(std::shared_ptr<Task>)> f);
    void addReadyTask(std::shared_ptr<Task> task);
    void run();
};
