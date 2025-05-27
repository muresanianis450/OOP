//
// Created by mures on 5/27/2025.
//

#include "Service.h"
std::vector<Task> Service::getAllTasks() {
    return this->repo.getAllTasks();
}
std::vector<Task> Service::getTasksWithGivenPriority(int priority) {
    std::vector<Task> tasksWithGivenPriority;
    for (auto &task : this->repo.getAllTasks()) {
        if (task.getPriority() == priority) {
            tasksWithGivenPriority.push_back(task);
        }
    }
    return tasksWithGivenPriority;
}