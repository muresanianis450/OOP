#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
protected:
  int constructionYear;
  std::string address;

public:
  Building(int constructionYear, const std::string &address);
  virtual ~Building() = default;

  virtual bool mustBeRestored() const = 0;
  virtual bool canBeDemolished() const = 0;
  virtual std::string toString() const = 0;

  std::string getAdress() const {
    return address;
  }

  int getConstructionYear() const {
    return constructionYear;
  }
};

#endif // BUILDING_H
