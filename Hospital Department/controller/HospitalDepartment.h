
#ifndef HOSPITALDEPARTMENT_H
#define HOSPITALDEPARTMENT_H
#include <string>



    class HospitalDepartment {
    protected:
        std::string hospitalName;
        int numberOfDoctors;

    public:
        HospitalDepartment() : hospitalName{ "" }, numberOfDoctors{0} {};
        HospitalDepartment(std::string hospitalName, int numberOfDoctors) : hospitalName{ hospitalName }, numberOfDoctors{ numberOfDoctors } {};
        virtual bool isEfficient() const = 0;
        virtual std::string toString();
        std::string getName(){return this->hospitalName;};
        ~HospitalDepartment();
        std::string getHospitalName() const;

    };


#endif //HOSPITALDEPARTMENT_H