#ifndef SURGERY_H
#define SURGERY_H

#include "HospitalDepartment.h"

class Surgery : public HospitalDepartment {
private:
    int numberOfPacients;
public:
    Surgery(std::string hospitalName, int numberOfDoctors, int numberOfPacients) :
      HospitalDepartment{ hospitalName, numberOfDoctors }, numberOfPacients{ numberOfPacients } {};
    bool isEfficient() const override;
    std::string getHospitalName() const;
    std::string toString() override;
};



#endif //SURGERY_H