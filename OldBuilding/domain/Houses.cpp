#include "Houses.h"
#include <sstream>

bool Houses::mustBeRestored() const {
    return (2025 - constructionYear > 100);
}

bool Houses::canBeDemolished() const {
    return !isHistorical;
}

std::string Houses::toString() const {
    std::ostringstream oss;
    oss << "House: " << address << ", Year: " << constructionYear
        << ", Type: " << type
        << ", Historical: " << (isHistorical ? "Yes" : "No");
    return oss.str();
}
Houses::Houses(int year, const std::string &address, const std::string &type, bool isHistorical)
    : Building(year, address), type(type), isHistorical(isHistorical) {}