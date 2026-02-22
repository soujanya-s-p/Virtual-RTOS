#include <iostream>
#include <memory>
#include "task.h"

class SystemProfiler {
public:
    void trackTaskState(std::shared_ptr<Task> task) {
        std::cout << "Task " << task->id << " state: " << static_cast<int>(task->state) << "\n";
    }

    void report() {
        std::cout << "System Profiler reporting...\n";
    }
};
