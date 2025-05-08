//
// Created by mures on 5/7/2025.
//

#include "Building.h"

std::string Building::toString() const{

  return "Building{" +
         std::to_string(constructionYear) + ", " +
         address + "}";
}
Building::Building(int constructionYear, const std::string &address) : constructionYear(constructionYear), address(address) {}