#pragma once
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

#include "service.h"

class GUI: public QWidget {

private:
    Service service;
    QListWidget *mainItems;
    int selectedIndex;

    QLineEdit *a;
    QLineEdit *b;
    QLineEdit *c;

    QPushButton *updateButton;
    QPushButton *computeSolution;

public:

    GUI(QWidget *parent = Q_NULLPTR);
    ~GUI() override = default;

    void populateItems();

public slots:
    void populateFields();
    void updateEquation();
    void showSolution();
};