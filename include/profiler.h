#pragma once
#include <iostream>
#include <vector>
#include "scheduler.h"

class Profiler {
public:
    void logTaskState(std::shared_ptr<Task> task) {
        std::string state = "UNKNOWN";
        if(task->state == TaskState::READY) state = "READY";
        else if(task->state == TaskState::RUNNING) state = "RUNNING";
        else if(task->state == TaskState::BLOCKED) state = "BLOCKED";

        std::cout << "[Profiler] Task " << task->id
                  << " State: " << state
                  << " Remaining Ticks: " << task->remainingTicks
		  << std::endl;
    }
};
