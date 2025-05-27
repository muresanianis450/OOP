#include "repository.h"
#include <sstream>

void Repository::loadRepo()
{
    ifstream file("vegetables.txt");
    string line, family, name, part;
    const char del = '|';
    while (getline(file, line))
    {
        istringstream iss(line);
        getline(iss, family, del);
        getline(iss, name, del);
        getline(iss, part, del);


        vector<string> parts;
        stringstream partStream(part);
        string item;
        while (getline(partStream, item, ',')) {
            parts.push_back(item);
        }

        this->vegetables.push_back(Vegetable(family, name, parts));
    }
}