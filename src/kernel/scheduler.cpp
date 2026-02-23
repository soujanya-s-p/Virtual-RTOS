#include "scheduler.h"
#include "profiler.h"
#include <algorithm>
#include <thread>
#include <chrono>

void Scheduler::addTask(int id, int priority, int ticks, std::function<void(std::shared_ptr<Task>)> f) {   //Creates a new Task.       Adds it to readyQueue
    readyQueue.push_back(std::make_shared<Task>(id, priority, ticks, f));
}

void Scheduler::addReadyTask(std::shared_ptr<Task> task) {   // Adds an existing task back into ready queue.
    readyQueue.push_back(task);
}

void Scheduler::run() {
    Profiler profiler;             //Step 1️⃣: Create Profiler object   Used to log task execution state.

    while (!readyQueue.empty()) {
        // pick highest priority ready task
        auto it = std::max_element(readyQueue.begin(), readyQueue.end(),
            [](std::shared_ptr<Task> a, std::shared_ptr<Task> b) {
                return a->priority < b->priority;
            });

        auto task = *it;
        readyQueue.erase(it);
        task->state = TaskState::RUNNING;

        while (task->remainingTicks > 0) {
            profiler.logTaskState(task);
            task->taskFunc(task);
            task->remainingTicks--;
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // simulate tick
        }

        task->state = TaskState::READY;
        std::cout << "Task " << task->id << " finished." << std::endl;
    }

    std::cout << "No tasks left. Scheduler stopping." << std::endl;
}
