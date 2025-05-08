#include "Ui.h"
#include "Surgery.h"
#include "NeonatalUnit.h"

void UI::addDepartment() {
    std::string hospitalName;
    int numberOfDoctors;

    std::cout << "Enter hospital name: ";
    std::cin >> hospitalName;
    std::cout << "Enter number of doctors: ";
    std::cin >> numberOfDoctors;

    std::cout << "Enter department type (1 for Surgery, 2 for Neonatal Unit): ";
    int type;
    std::cin >> type;

    if (type == 1) {
        int numberOfPatients;
        std::cout << "Enter number of patients: ";
        std::cin >> numberOfPatients;
        auto* surgery = new Surgery(hospitalName, numberOfDoctors, numberOfPatients);
        this->controller.addDepartment(surgery);
        std::cout << "Surgery department added successfully.\n";
    } else if (type == 2) {
        double averageGrade;
        std::cout << "Enter average grade: ";
        std::cin >> averageGrade;
        auto* neonatalUnit = new NeonatalUnit(hospitalName, numberOfDoctors, averageGrade);
        this->controller.addDepartment(neonatalUnit);
        std::cout << "Neonatal unit added successfully.\n";
    } else {
        std::cout << "Invalid department type.\n";
    }
}

void UI::showAllDepartments() {
    auto departments = this->controller.getDepartments();
    for (const auto& department : departments) {
        std::cout << department->toString() << "\n";
    }
}

void UI::showEfficientDepartments() {
    auto efficientDepartments = this->controller.getEfficientDepartments();
    for (const auto& department : efficientDepartments) {
        std::cout << department->toString() << "\n";
    }
}

void UI::saveToFile() {
    std::string filename;
    std::cout << "Enter the filename to save the departments: ";
    std::cin >> filename;

    this->controller.writeToFile(filename);
    std::cout << "Departments saved to file successfully.\n";
}

void UI::start() {
    while (true) {
        std::cout << "\n1. Add Department\n";
        std::cout << "2. Show All Departments\n";
        std::cout << "3. Show Efficient Departments\n";
        std::cout << "4. Save Departments to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addDepartment();
                break;
            case 2:
                showAllDepartments();
                break;
            case 3:
                showEfficientDepartments();
                break;
            case 4:
                saveToFile();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}