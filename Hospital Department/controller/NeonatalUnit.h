#ifndef NEONATALUNIT_H
#define NEONATALUNIT_H
#include "HospitalDepartment.h"


class NeonatalUnit : public HospitalDepartment {
public:

    double averageGrade;
    NeonatalUnit(std::string hospitalName, int numberOfDoctors, double averageGrade) :
          HospitalDepartment{ hospitalName, numberOfDoctors }, averageGrade{ averageGrade }{};
    bool isEfficient() const override;
    std::string getHospitalName() const ;
    std::string toString() override;
};



#endif //NEONATALUNIT_H

