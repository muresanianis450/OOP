#pragma once

#include "repository.h"

class Service {

private:
    Repository repository;

public:
    Service(){};
    ~Service(){};

    std::vector<Equation> getEquations() const {
        return repository.getEquations();
    };
    void updateEquation(int index, Equation equation) {
        repository.updateEquation(index, equation);
    }
};