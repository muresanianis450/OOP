#include "Controller.h"
#include <iostream>
#include <fstream>
#include <algorithm>

bool Controller::addBuilding(const std::shared_ptr<Building>& building) {
    if (!building) return false;

    for (const auto& b : buildings) {
        if (b->getAdress() == building->getAdress()) {
            std::cerr << "Building with this address already exists.\n";
            return false;
        }
    }
    buildings.push_back(building);
    return true;
}

std::vector<std::shared_ptr<Building>> Controller::getAllBuildings() const {
    return buildings;
}

std::vector<std::shared_ptr<Building>> Controller::getAllToBeRestored() const {
    std::vector<std::shared_ptr<Building>> result;
    for (const auto& b : buildings)
        if (b->mustBeRestored())
            result.push_back(b);
    return result;
}

std::vector<std::shared_ptr<Building>> Controller::getAllToBeDemolished() const {
    std::vector<std::shared_ptr<Building>> result;
    for (const auto& b : buildings)
        if (b->canBeDemolished())
            result.push_back(b);
    return result;
}

std::vector<std::shared_ptr<Building>> Controller::sortedByYear() const {
    std::vector<std::shared_ptr<Building>> sorted = buildings;
    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a->getConstructionYear() < b->getConstructionYear();
    });
    return sorted;
}

void Controller::writeToFile(const std::string &filename, const std::vector<std::shared_ptr<Building>> &buildings) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    for (const auto &b : buildings)
        outFile << b->toString() << "\n";

    outFile.close();
}
