#ifndef VEGETABLES_VEGETABLE_H
#define VEGETABLES_VEGETABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Vegetable
{
private:
    string family, name;
    vector<string> parts; // Changed from string to vector<string>

public:
    Vegetable(string family = "", string name = "", vector<string> parts = {})
        : family{family}, name{name}, parts{parts} {}

    string getFamily() const { return this->family; }
    string getName() const { return this->name; }

    string getParts() const {
        stringstream ss;
        for (size_t i = 0; i < parts.size(); ++i) {
            ss << parts[i];
            if (i < parts.size() - 1) {
                ss << ",";
            }
        }
        return ss.str();
    }

    inline bool operator<(const Vegetable &other) const {
        return this->name < other.getName();
    }
};

#endif // VEGETABLES_VEGETABLE_H