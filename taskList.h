#ifndef TASKLIST_H_
#define TASKLIST_H_
#include "task.h"

class TaskList
{
private:
    struct Node
    {
        Task data;
        Node *next;
    };
    int size;
    Node *head;
    Node *tail;

public:
    TaskList();
    TaskList(const TaskList &listToCopy);
    TaskList &operator=(const TaskList &listToCopy);

    ~TaskList();

    // Rest to be implemented
    int addToList(const Task &task);
    int removeFromList(const std::string &taskName);

    // Not to be used, only for verifying results in testList.cpp
    void printTaskList() const;
};

#endif