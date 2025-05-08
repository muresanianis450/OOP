
#include "Surgery.h"

std::string Surgery::toString() {
    return "Type: Surgery\n" + HospitalDepartment::toString() + "Number of pacients: " + std::to_string(this->numberOfPacients) + "\n";
}
bool Surgery::isEfficient() const  {
    double ratio = (double) this->numberOfPacients / this->numberOfDoctors;
    return ratio >=2;
}
std::string Surgery::getHospitalName() const {
    return this->hospitalName;
}