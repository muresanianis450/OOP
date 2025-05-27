//
// Created by mures on 5/27/2025.
//

#include "Service.h"

std::vector<Item> Service::getAllItems(){
    std::vector<Item> items = repository.getItems();
    std::sort(items.begin(), items.end(), functionOfComparison);
    return items;

}

std::vector<Item> Service::getItemsByCategory(std::string category) {

    std::vector<Item> items = repository.getItems();
    std::vector<Item> filteredItems;
    for ( auto item : items) {
        if (item.getCategory() == category) {
            filteredItems.push_back(item);

        }
    }
    std::sort(filteredItems.begin(),filteredItems.end(), functionOfComparison);
    return filteredItems;

}


std::vector<Item> Service::getItemsThatContainString(std::string str) {
std::vector<Item> items = repository.getItems();
    std::vector<Item> filteredItems;
    for ( auto item : items) {
        if (item.getCategory().find(str) != std::string::npos || item.getName().find(str) != std::string::npos) {
            filteredItems.push_back(item);
        }

    }
    return filteredItems;
}

