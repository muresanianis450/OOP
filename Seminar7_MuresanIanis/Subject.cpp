#include "Subject.h"
#include "Observer.h"

void Subject::registerObserver(Observer* obs) {
    observers.push_back(obs);
}

void Subject::unregisterObserver(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void Subject::notify() {
    for (Observer* obs : observers) {
        if (obs)
            obs->update();
    }
}
