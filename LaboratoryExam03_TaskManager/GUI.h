//
// Created by mures on 5/27/2025.
//

#ifndef GUI_H
#define GUI_H
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include "Service.h"
#include <QPushButton>
class GUI : public QWidget{

private:
    Service service;
    QListWidget *listWithTasks;
    QListWidget *listWithTasksWithGivenPriority;
    QLabel *labelForPriority;
    QLineEdit *priorityOfTask;
    QLineEdit *resultOfPrioritiesOfTasks;
    QPushButton *computeResultButton;
    QLabel *resultOfPriority;
public:
    GUI(QWidget *parent = Q_NULLPTR);
    void populateListWithTasks();

public slots:
    void computeDuration();

};



#endif //GUI_H
