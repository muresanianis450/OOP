
#include "Controller.h"
#include <string>
#include <algorithm>
#include <fstream>
void Controller::addDepartment(HospitalDepartment* department) {
    this->departments.push_back(department);
}

std::vector<HospitalDepartment*> Controller::getDepartments() const{
    return this->departments;
}

std::vector<HospitalDepartment*> Controller::getEfficientDepartments() {
    std::vector<HospitalDepartment*> efficientDepartments;

    for ( auto department : this->departments) {
        if (department->isEfficient()) {
            efficientDepartments.push_back(department);
        }
    }
    return efficientDepartments;

}
void Controller::writeToFile(std::string fileName) {
    std::sort(this->departments.begin(), this->departments.end(), [](HospitalDepartment* a, HospitalDepartment* b) {
        return a->getHospitalName() < b->getHospitalName();
    });
    std::ofstream fin(fileName);
    for (auto department : this->departments) {
        fin << department->toString() + "Efficiency: " + (department->isEfficient() ? "Yes" : "No") + "\n"+"\n____________________\n";
    }
}
