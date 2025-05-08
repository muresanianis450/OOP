#ifndef BLOCK_H
#define BLOCK_H

#include "Building.h"
#include <string>

class Block : public Building {
private:
  int totalAparments;
  int occupiedApartments;

public:
  Block(int year, const std::string& address, int apartments, int occupied);
  ~Block() override = default;
  bool mustBeRestored() const override;
  bool canBeDemolished() const override;
  std::string toString() const override;
};

#endif // BLOCK_H
