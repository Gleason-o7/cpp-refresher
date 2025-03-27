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
    // Constructors
    TaskList();
    TaskList(const TaskList &listToCopy);
    TaskList &operator=(const TaskList &listToCopy);

    // Destructor
    ~TaskList();

    // Methods
    int addToList(const Task &task);
    int removeFromList(int position, const std::string &taskName);
    int markTaskFinished(int position, const std::string &taskName);
    bool isEmpty();
    int getSize() const;
    void printTaskList() const;
    bool loadFromCSV(const std::string &fileName);
    bool saveToCSV(const std::string &fileName) const;
    void clear();
};

#endif