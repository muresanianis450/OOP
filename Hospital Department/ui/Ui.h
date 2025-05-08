#ifndef UI_H
#define UI_H

#include "../domain/Controller.h"
#include <iostream>
#include <string>

class UI {
private:
    Controller& controller;

    void addDepartment();
    void showAllDepartments();
    void showEfficientDepartments();
    void saveToFile();

public:
    UI(Controller& controller) : controller(controller) {}
    void start();
};

#endif // UI_H