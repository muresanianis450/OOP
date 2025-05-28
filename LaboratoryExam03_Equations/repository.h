#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include "domain.h"
#include <string>

class Repository {
private:
    std::vector<Equation> equations;

public:
    Repository(){loadData();};
    ~Repository() = default;

    void loadData() {
        std::ifstream fin("eq.txt");
        std::string line;
        std::string astr, bstr, cstr;

        while (std::getline(fin,line)) {
            std::istringstream iss(line);

            std::getline(iss,astr,',');
            std::getline(iss,bstr,',');
            std::getline(iss,cstr,',');
        equations.emplace_back(
            Equation(std::stod(astr),std::stod(bstr),std::stod(cstr)));
        }

    }

    void updateEquation(int index, Equation equation) {
        if (index < 0 || index >= equations.size()) {
            return;
        }
        equations[index] = equation;
    }
    std::vector<Equation> getEquations() const {return equations;};
};