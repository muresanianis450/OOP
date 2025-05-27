//
// Created by mures on 5/27/2025.
//

#include "Repository.h"
#include <string>
void Repository::loadFromFile() {
    std::ifstream file("items.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    std::string const delimiter = "|";
    std::string category, name;
    int quantity;
    while (std::getline(file,line)) {
        std::stringstream ss(line);
        std::getline(ss,category,delimiter[0]);
        std::getline(ss,name,delimiter[0]);
        ss >> quantity;
        if (ss.fail()) {
            throw std::runtime_error("Error reading quantity from file");
        }
        items.emplace_back(category, name, quantity);
    }
    file.close();
}

std::vector<Item> Repository::getItems() {
    return items;
}