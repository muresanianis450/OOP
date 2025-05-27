//
// Created by mures on 5/27/2025.
//

#ifndef SERVICE_H
#define SERVICE_H

#include "Repo.h"
#include <algorithm>

class Service {
private:
    Repo repo;
public:
    std::vector <Task> getAllTasks();
    std::vector <Task> getTasksWithGivenPriority(int priority);
};



#endif //SERVICE_H
