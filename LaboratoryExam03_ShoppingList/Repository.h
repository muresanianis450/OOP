//
// Created by mures on 5/27/2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <sstream>
#include <fstream>
#include "Item.h"

class Repository {
private:
    std::vector<Item> items;
public:
    Repository() {this->loadFromFile();};
    void loadFromFile();
    std::vector<Item> getItems();

};



#endif //REPOSITORY_H
