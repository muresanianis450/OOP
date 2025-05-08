#include "Ui.h"
#include <iostream>
#include <../domain/Houses.h>
void displayMenu() {
    std::cout << "1. Add new house" << std::endl;
    std::cout << "2. Add new block" << std::endl;
    std::cout << "3. Show all buildings" << std::endl;
    std::cout << "4. Save buildings to files" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void addHouseUI(Controller &controller) {

    int year;
    std::string address;
    int rooms;
    bool isHistorical;

    std::cout << "Enter construction year: ";
    std::cin >> year;
    std::cin.ignore();
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter number of rooms: ";
    std::cin >> rooms;
    std::cout << "Is it a historical building? (1 for yes, 0 for no): ";
    std::cin >> isHistorical;
    std::cin.ignore();
    std::cout << "Enter type of house: ";
    std::string type;
    std::getline(std::cin, type);


try{
    auto house = std::make_shared<Houses>(year, address, type, isHistorical);
    controller.addBuilding(house) ;
    }catch (const std::exception &e) {
        std::cout << "Failed to add house." << std::endl;
    }
}

void addBlockUI(Controller &controller) {
    int year;
    std::string address;
    int apartments;

    std::cout << "Enter construction year: ";
    std::cin >> year;
    std::cin.ignore();
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter number of apartments: ";
    std::cin >> apartments;
    std::cin.ignore();
    std::cout << "Enter number of occupied apartments: ";
    int occupied;
    std::cin >> occupied;
    std::cin.ignore();
    if (occupied > apartments) {
        std::cout << "Occupied apartments cannot exceed total apartments." << std::endl;
        return;
    }

    auto block = std::make_shared<Block>(year, address, apartments, occupied);
    if (controller.addBuilding(block)) {
        std::cout << "Block added successfully!" << std::endl;
    } else {
        std::cout << "Failed to add block." << std::endl;
    }
}

void showAllBuildingsUI(Controller &controller) {
    auto buildings = controller.sortedByYear();
    if (buildings.empty()) {
        std::cout << "No buildings available.\n";
        return;
    }

    for (const auto &b : buildings)
        std::cout << b->toString() << std::endl;
}

void saveBuildingsToFileUI(Controller &controller) {
    std::string restoreFile, demolishFile;
    std::cout << "Enter filename for buildings to be restored: ";
    std::cin >> restoreFile;
    std::cout << "Enter filename for buildings to be demolished: ";
    std::cin >> demolishFile;

    auto toBeRestored = controller.getAllToBeRestored();
    auto toBeDemolished = controller.getAllToBeDemolished();

    controller.writeToFile(restoreFile, toBeRestored);
    controller.writeToFile(demolishFile, toBeDemolished);

    std::cout << "Buildings saved to files successfully!" << std::endl;
}

int main() {
    Controller controller;
    controller.addBuilding(std::make_shared<Houses>(1900, "Main Street 1", "Victorian", true));
    controller.addBuilding(std::make_shared<Houses>(2005, "Elm Street 5", "Modern", false));
    controller.addBuilding(std::make_shared<Houses>(1850, "Oak Avenue 12", "Cottage", true));
    controller.addBuilding(std::make_shared<Houses>(1990, "Pine Road 8", "Bungalow", false));
    controller.addBuilding(std::make_shared<Houses>(2020, "Maple Lane 3", "Townhouse", false));

    controller.addBuilding(std::make_shared<Block>(1980, "Highrise Blvd 10", 50, 45));
    controller.addBuilding(std::make_shared<Block>(1975, "Sunset Drive 22", 30, 25));
    controller.addBuilding(std::make_shared<Block>(2010, "Riverbank Way 7", 100, 90));
    controller.addBuilding(std::make_shared<Block>(1965, "Hilltop Street 15", 20, 18));
    controller.addBuilding(std::make_shared<Block>(2023, "Downtown Square 2", 10, 5));


    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                try {
                    addHouseUI(controller);
                } catch (const std::exception &e) {
                    std::cout << "An error occurred: " << e.what() << std::endl;
                }
            break;
            case 2:
                try {
                    addBlockUI(controller);
                } catch (const std::exception &e) {
                    std::cout << "An error occurred: " << e.what() << std::endl;
                }
            break;
            case 3:
                try {
                    showAllBuildingsUI(controller);
                } catch (const std::exception &e) {
                    std::cout << "An error occurred: " << e.what() << std::endl;
                }
            break;
            case 4:
                try {
                    saveBuildingsToFileUI(controller);
                } catch (const std::exception &e) {
                    std::cout << "An error occurred: " << e.what() << std::endl;
                }
            break;
            case 0:
                std::cout << "Exiting application. Goodbye!" << std::endl;
            break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}