#include <sstream>
#include "Block.h"

Block::Block(int year, const std::string& address, int apartments, int occupied)
    : Building(year, address), totalAparments(apartments), occupiedApartments(occupied) {}

bool Block::mustBeRestored() const {
    if (2025 - constructionYear > 40)
        if (static_cast<double>(occupiedApartments) / totalAparments > 0.8)
            return true;
    return false;
}

bool Block::canBeDemolished() const {
    if (static_cast<double>(occupiedApartments) / totalAparments < 0.05)
        return true;
    return false;
}

std::string Block::toString() const {
    std::ostringstream oss;
    oss << "Block: " << address << ", Year: " << constructionYear
        << ", Apartments: " << totalAparments
        << ", Occupied: " << occupiedApartments;
    return oss.str();
}