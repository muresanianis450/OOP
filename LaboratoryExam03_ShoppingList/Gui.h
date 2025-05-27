//
// Created by mures on 5/27/2025.
//

#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushbutton>
#include <QLabel>
#include "Service.h"


class GUI : public QWidget
{
private:
    Service service;
    QListWidget* listWidgetAllItems;
    QListWidget* listWidgetFilteredItems;
    QLabel *labelForSearchByCategoryOrName;
    QLabel *labelForSearchByCategory;
    QLineEdit* searchByCategoryOrName;
    QLineEdit *searchByCategoryLineEdit;
    QPushButton *searchByCategoryButton;
public:
    GUI(QWidget* parent = Q_NULLPTR);
    void populateListWidgetAllItems();
    public slots:
        void populateListWidgetBasedOnSearch();
    void filterByCategory();
    void printSelectedItem();
};
#endif //SHOPPING_LIST_GUI_H

