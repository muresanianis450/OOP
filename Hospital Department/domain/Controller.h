#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "HospitalDepartment.h"
#include "NeonatalUnit.h"
#include "Surgery.h"



class Controller {
private:
    std::vector<HospitalDepartment*> departments;
public:
    Controller() {
        HospitalDepartment *neonatalUnit1 = new NeonatalUnit("Cluj-Napoca",11,3);
        HospitalDepartment *neonatalUnit2 = new NeonatalUnit("Baia-Mare",21,1000000);

        HospitalDepartment *surgery1 = new Surgery("Dej", 10000000, 1);
        HospitalDepartment *surgery2 = new Surgery("Oradea", 41, 500);

        departments.push_back(neonatalUnit1);
        departments.push_back(neonatalUnit2);
        departments.push_back(surgery1);
        departments.push_back(surgery2);
    }
    ~Controller() {
        for (auto department: departments) {
            delete department;
        }
    }
    void addDepartment(HospitalDepartment* department);
    std::vector<HospitalDepartment*> getDepartments() const;
    std::vector<HospitalDepartment*> getEfficientDepartments();
    void writeToFile(std::string fileName);
};


#endif //CONTROLLER_H


