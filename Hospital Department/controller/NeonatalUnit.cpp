#include "NeonatalUnit.h"

std::string NeonatalUnit::toString(){
    return "Type: Neonatal Unit\n" + HospitalDepartment::toString() + "Average grade: " + std::to_string(this->averageGrade)
    + "\nNumber of mothers: "  + "\n";
}

bool NeonatalUnit::isEfficient() const  {
    return this->averageGrade > 8.5  ;
}

std::string NeonatalUnit::getHospitalName() const {
    return this->hospitalName;
}