#include "taskList.h"
#include <iostream>

TaskList::TaskList() : size(0), head(nullptr), tail(nullptr) {};

TaskList::TaskList(const TaskList &listToCopy) : size(listToCopy.size)
{
    // Initialize the head with null if list is empty
    if (listToCopy.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Initialize the head if list is not empty
    head = new Node;
    head->data = listToCopy.head->data;
    head->next = nullptr;
    tail = head;

    Node *currPtr = head;
    Node *copyPtr = listToCopy.head->next;

    while (copyPtr != nullptr)
    {
        currPtr->next = new Node;
        currPtr = currPtr->next;
        currPtr->data = copyPtr->data;
        copyPtr = copyPtr->next;
    }

    tail = currPtr;
};

TaskList &TaskList::operator=(const TaskList &listToCopy)
{
    if (this != &listToCopy)
    {
        // Free old list
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        // Copy listToCopy
        size = listToCopy.size;

        if (listToCopy.head == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return *this;
        }

        // Copy first node
        head = new Node;
        head->data = listToCopy.head->data;
        head->next = nullptr;
        tail = head;

        Node *currPtr = head;
        Node *copyPtr = listToCopy.head->next;

        while (copyPtr != nullptr)
        {
            currPtr->next = new Node;
            currPtr = currPtr->next;
            currPtr->data = copyPtr->data;
            copyPtr = copyPtr->next;
        }
        tail = currPtr;
    }
    return *this;
};

// Destructor
TaskList::~TaskList()
{
    Node *curr = head;

    while (curr != nullptr)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

int TaskList::addToList(const Task &task)
{
    Node *newTail = new Node;
    newTail->data = task;
    newTail->next = nullptr;

    if (tail == nullptr)
    {
        head = newTail;
        tail = newTail;
    }
    else
    {

        tail->next = newTail;
        tail = newTail;
    }
    // If list was empty, update tail

    return ++size;
}

int TaskList::removeFromList(const std::string &taskName)
{
    // Special case: list is empty
    if (head == nullptr)
    {
        return 1;
    }

    Node *curr = head;
    Node *prev = nullptr;

    // Special case: head is to be removed
    if (head->data.getName() == taskName)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr)
            tail = nullptr;

        return 0;
    }

    while (curr != nullptr && curr->data.getName() != taskName)
    {
        prev = curr;
        curr = curr->next;
    }

    // Node not found
    if (curr == nullptr)
    {
        return 1;
    }

    // Remove the node
    prev->next = curr->next;

    // Special case: node is tail
    if (curr == tail)
        tail = prev;

    delete curr;
    size--;
    return 0;
}

void TaskList::printTaskList() const
{
    Node *curr = head;

    if (curr == nullptr)
    {
        std::cout << "The task list is empty." << std::endl;
        return;
    }

    std::cout << "Task List:" << std::endl;
    while (curr != nullptr)
    {
        std::cout << "- " << curr->data.getName() << " (Priority: "
                  << curr->data.getPriority() << ", Duration: "
                  //                  << curr->data.getTimeframe() << ") - "
                  << curr->data.getDescription() << " [Status: "
                  << (curr->data.getStatus() == Task::FINISHED ? "Finished" : "Unfinished")
                  << "]" << std::endl;
        curr = curr->next;
    }
}