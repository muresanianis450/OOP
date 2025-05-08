//
// Created by mures on 5/7/2025.
//

#include "HospitalDepartment.h"




HospitalDepartment::~HospitalDepartment() {};
std::string HospitalDepartment::toString() {
    return "Name: " + this->hospitalName + "\nNumber Of Doctors: " + std::to_string(this->numberOfDoctors) + "\n";
}
std::string HospitalDepartment::getHospitalName() const {
    return this->hospitalName;
}






