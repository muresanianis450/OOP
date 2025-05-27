//
// Created by mures on 5/27/2025.
//

#include "GUI.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include "Task.h"
GUI::GUI(QWidget *parent): QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    this->listWithTasks = new QListWidget;
    this->labelForPriority = new QLabel("Enter Priority");
    this->priorityOfTask = new QLineEdit;
    this->resultOfPriority = new QLabel("Total Duration");
    this->computeResultButton = new QPushButton("Show Duration");
    this->resultOfPrioritiesOfTasks = new QLineEdit;
    this->listWithTasksWithGivenPriority = new QListWidget;

    mainLayout->addWidget(this->listWithTasks);
    mainLayout->addWidget(this->labelForPriority);
    mainLayout->addWidget(this->priorityOfTask);
    mainLayout->addWidget(this->computeResultButton);
    mainLayout->addWidget(this->resultOfPriority);
    mainLayout->addWidget(this->resultOfPrioritiesOfTasks);
    mainLayout->addWidget(this->listWithTasksWithGivenPriority);

    this->setLayout(mainLayout);
    this->populateListWithTasks();
    QObject::connect(computeResultButton, &QPushButton::clicked, this, &GUI::computeDuration);
    QObject::connect(priorityOfTask, &QLineEdit::returnPressed, this, &GUI::computeDuration);


}

void GUI::populateListWithTasks() {
    this->listWithTasks->clear();
    for (auto task : this->service.getAllTasks()) {
        this->listWithTasks->addItem(QString::fromStdString(task.toString()));

    }

}

void GUI::computeDuration() {
    int priority = this->priorityOfTask->text().toInt(), duration = 0;

    std::vector<Task> tasksWithGivenPriority = this->service.getTasksWithGivenPriority(priority);
    this->listWithTasksWithGivenPriority->clear();
    for ( auto task: tasksWithGivenPriority) {
        this->listWithTasksWithGivenPriority->addItem(QString::fromStdString(task.toString()));
        duration += task.getEstimateDuration();
    }
    if (duration == 0 )
        this->resultOfPrioritiesOfTasks->setText(QString::fromStdString("No tasks with this priority"));
    else
        this->resultOfPrioritiesOfTasks->setText(QString::number(duration));

}



