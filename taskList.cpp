#include "taskList.h"
#include <iostream>
#include <cctype>  // For isdigit
#include <sstream> // For stringstream

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

int TaskList::removeFromList(int position, const std::string &taskName)
{
    // Special case: list is empty
    if (head == nullptr)
    {
        return 1;
    }

    if (position > 0)
    {
        Node *curr = head;
        Node *prev = nullptr;
        int index = 1;

        while (curr != nullptr)
        {
            if (index == position)
            {
                if (prev == nullptr) // Removing head
                {
                    head = head->next;
                    if (head == nullptr)
                        tail = nullptr;
                }
                else
                {
                    prev->next = curr->next;
                    if (curr == tail)
                        tail = prev;
                }
                delete curr;
                size--;
                std::cout << "Task #" << position << " removed.\n";
                return 0;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        std::cout << "Task number out of range.\n";
        return 1;
    }
    // Remove by name
    else
    {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data.getName() == taskName)
            {
                if (prev == nullptr) // Removing head
                {
                    head = head->next;
                    if (head == nullptr)
                        tail = nullptr;
                }
                else
                {
                    prev->next = curr->next;
                    if (curr == tail)
                        tail = prev;
                }
                delete curr;
                size--;
                std::cout << "Task \"" << taskName << "\" removed.\n";
                return 0;
            }
            prev = curr;
            curr = curr->next;
        }
        std::cout << "Task not found.\n";
        return 1;
    }
}

int TaskList::markTaskFinished(int position, const std::string &taskName)
{
    if (head == nullptr)
    {
        return 1;
    }

    // Find task by position
    if (position > 0)
    {
        Node *curr = head;
        int index = 1;

        while (curr != nullptr)
        {
            if (index == position)
            {
                curr->data.setStatus(Task::FINISHED);
                std::cout << "Task #" << position << " marked as finished.\n";
                return 0;
            }
            curr = curr->next;
            index++;
        }
        std::cout << "Task number out of range.\n";
    }

    // Find task by name
    else
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.getName() == taskName)
            {
                curr->data.setStatus(Task::FINISHED);
                std::cout << "\nTask \"" << taskName << "\" marked as finished.\n";
                return 0;
            }
            curr = curr->next;
        }
        std::cout << "Task not found.\n";
    }
    return 1;
}

bool TaskList::isEmpty()
{
    return size == 0;
}

void TaskList::printTaskList() const
{
    Node *curr = head;
    int i = 1;
    if (curr == nullptr)
    {
        std::cout << "The task list is empty." << std::endl;
        return;
    }

    std::cout << "Task List:" << std::endl;
    while (curr != nullptr)
    {
        std::cout << i << ": " << curr->data.getName() << " (Priority: "
                  << curr->data.getPriority() << ", Duration: "
                  << /*curr->data.getTimeframe() << */ ") - "
                  << curr->data.getDescription() << " [Status: "
                  << (curr->data.getStatus() == Task::FINISHED ? "Finished" : "Unfinished")
                  << "]" << std::endl;
        curr = curr->next;
    }
}