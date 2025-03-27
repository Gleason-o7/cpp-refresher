#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "taskList.h"

class Program
{
private:
    TaskList list;

public:
    void welcome();
    void menuLoop();
    void displayMenu();
    void addTask();
    void printTaskList();
    void markTaskFinished();
    void removeFromList();
    void loadFromCSV();
    void saveToCSV();
    void clear();
};

#endif