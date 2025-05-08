#include "../ui/Ui.h"
#include "../domain/Controller.h"
#include <iostream>

int main() {
    Controller controller;
    UI ui(controller);
    ui.start();

    return 0;
}