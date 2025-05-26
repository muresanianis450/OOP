#pragma once
#include <vector>
#include <algorithm>

class Observer;

class Subject {
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;

    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};
