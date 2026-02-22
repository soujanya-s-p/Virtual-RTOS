#include "scheduler.h"
#include "semaphore.h"
#include <iostream>

int main() {
    Scheduler scheduler;
    Semaphore sem(1); // binary semaphore

    std::cout << "Virtual RTOS Booting..." << std::endl;

    // Task definitions
    scheduler.addTask(1, 1, 5, [&](std::shared_ptr<Task> t){
        std::cout << "Running Task " << t->id << " | Remaining Ticks: " << t->remainingTicks << std::endl;
        std::cout << "Low priority working..." << std::endl;
    });

    scheduler.addTask(2, 3, 5, [&](std::shared_ptr<Task> t){
        std::cout << "Running Task " << t->id << " | Remaining Ticks: " << t->remainingTicks << std::endl;
        std::cout << "High priority working..." << std::endl;
    });

    scheduler.addTask(3, 2, 5, [&](std::shared_ptr<Task> t){
        std::cout << "Running Task " << t->id << " | Remaining Ticks: " << t->remainingTicks << std::endl;
        std::cout << "Medium priority working..." << std::endl;
    });

    scheduler.run();

    return 0;
}
