#ifndef HOUSES_H
#define HOUSES_H

#include "Building.h"
#include <string>

class Houses : public Building {
private:
    std::string type;
    bool isHistorical;

public:
    Houses(int year, const std::string &address, const std::string &type, bool isHistorical);
    ~Houses() override = default;
    bool mustBeRestored() const override;
    bool canBeDemolished() const override;
    std::string toString() const override;
};

#endif // HOUSES_H
