//
// Created by mures on 5/27/2025.
//

#ifndef REPO_H
#define REPO_H

#include "Task.h"
#include <vector>
#include <fstream>
#include <sstream>

class Repo {
private:
    std::vector<Task> tasks;

public:
    Repo() {this->populateRepo();};
    void populateRepo();
        std::vector<Task> getAllTasks() {
            return this->tasks;
        }

};



#endif //REPO_H
