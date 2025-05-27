//
// Created by mures on 5/27/2025.
//

#ifndef SERVICE_H
#define SERVICE_H


#include "Repository.h"
#include <algorithm>

class Service {

private:
    Repository repository;
public:
    static inline bool functionOfComparison(const Item &a, const Item &b) {
        return a.getQuantity() < b.getQuantity();
    }
    std::vector<Item> getAllItems();
    std::vector<Item> getItemsByCategory(std::string category);
    std::vector<Item> getItemsThatContainString(std::string str);
};




#endif //SERVICE_H
