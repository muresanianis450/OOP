
#ifndef TASK_H
#define TASK_H
#include <string>
class Task {
private:
    std::string description;
    int estimateDuration, priority;
public:
    Task(std::string description, int estimateDuration, int priority)
        : description{description}, estimateDuration{estimateDuration}, priority{priority} {};
    std::string toString(){
        return this->description + " " + std::to_string(this->estimateDuration) + " " + std::to_string(this->priority);
    }
    int getPriority() const { return this->priority;};
    int getEstimateDuration() const {return this->estimateDuration;};
    inline bool operator < (const Task &other) const {
        return this->priority < other.getPriority();
    }

};



#endif //TASK_H
