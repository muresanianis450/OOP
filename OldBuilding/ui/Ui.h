//
// Created by mures on 5/7/2025.
//

#ifndef UI_H
#define UI_H
#include "../controller/Controller.h"

#include "../domain/Block.h"
#include "../domain/Houses.h"
#include <ostream>
#include <iostream>
#include <vector>
#include <string>


class Ui {
protected:
    Controller controller;
    public:
      void addBuilding();
      void showAllBuildings();
      void SaveRestoredToFile();
      void SaveDemolishedToFile();

};



#endif //UI_H
