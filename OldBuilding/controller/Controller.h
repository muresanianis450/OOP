#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "../domain/Building.h"

class Controller {
public:
    std::vector<std::shared_ptr<Building>> buildings;

    bool addBuilding(const std::shared_ptr<Building>& building);
    std::vector<std::shared_ptr<Building>> getAllBuildings() const;
    std::vector<std::shared_ptr<Building>> getAllToBeRestored() const;
    std::vector<std::shared_ptr<Building>> getAllToBeDemolished() const;
    std::vector<std::shared_ptr<Building>> sortedByYear() const;
    static void writeToFile(const std::string &filename, const std::vector<std::shared_ptr<Building>> &buildings);
};

#endif // CONTROLLER_H
