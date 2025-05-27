//
// Created by mures on 5/27/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <iostream>


class Item {
private:
    std::string category,name;
    int quantity;
public:
    Item(std::string category, std::string name, int quantity):
    category{category}, name{name}, quantity{quantity} {};
    std::string getCategory() const {
        return category;
    }
    std::string getName() const {
        return name;
    }
    int getQuantity() const {
        return quantity;
    }
    inline bool operator < (const Item &other) const {
        if (this->category == other.getCategory()) {
            return this->name < other.name;
        }
        return this->category < other.category;
    }
    std::string toString()const {
        return "Category: " + this->category + ", Name: "+ this->name + ", Quantity: " + std::to_string(this->quantity);

    }

};



#endif //ITEM_H
