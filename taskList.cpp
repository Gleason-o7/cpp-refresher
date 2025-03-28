#include "taskList.h"
#include <iostream>
#include <sstream> // For stringstream
#include <fstream>
#include <stdexcept>
#include <iomanip>

// Constructors
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

// Methods

// Adds a task to the end of the list
// Returns the new size of the list
// If the list was empty, it updates the tail pointer
// Returns 0 on success, 1 on failure
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

// Removes a task from the list
// If position is greater than 0, it removes by position
// If position is 0 or less, it removes by name
// Returns 0 on success, 1 on failure
int TaskList::removeFromList(int position, const std::string &taskName)
{
    // Special case: list is empty
    if (head == nullptr)
    {
        return 1;
    }

    // Remove by position
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

// Marks a task as finished
// If position is greater than 0, it marks by position
// If position is 0 or less, it marks by name
// Returns 0 on success, 1 on failure
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

// Checks if the list is empty
bool TaskList::isEmpty()
{
    return size == 0;
}

// Returns the size of the list
int TaskList::getSize() const
{
    return size;
}

// prints the task list
void TaskList::printTaskList() const
{
    Node *curr = head;
    int i = 1;
    int maxNameLength = 0;
    int maxDescriptionLength = 0;

    if (curr == nullptr)
    {
        std::cout << "The task list is empty." << std::endl;
        return;
    }

    std::cout << "Task List:" << std::endl;
    std::cout << "| * |>------------------------------<| * |>--------------<| * |>---------------------<| * |" << std::endl;
    std::cout << "| * |" << std::setw(5) << std::right << "No" << ": "
              << std::setw(25) << std::left << "Task Name"
              << "| * | Priority: " << std::setw(4) << "Prio"
              << " | * | Status : " << std::setw(12) << "Status"
              << " | * | "
              << std::endl;
    std::cout << "| * |>------------------------------<| * |>--------------<| * |>---------------------<| * |" << std::endl;
    while (curr != nullptr)
    {
        std::cout << "| * |"
                  << std::setw(5) << std::right << i << ": "
                  << std::setw(25) << std::left << curr->data.getName()
                  << "| * | Priority: " << std::setw(4) << curr->data.getPriority()
                  << " | * | Status : " << std::setw(12) << (curr->data.getStatus() == Task::FINISHED ? " Finished " : " Unfinished ")
                  << " | * | "
                  << std::endl;
        curr = curr->next;
        i++;
    }
    std::cout << "| * |>------------------------------<| * |>--------------<| * |>---------------------<| * |" << std::endl;
}

// Loads tasks from a CSV file
bool TaskList::loadFromCSV(const std::string &fileName)
{
    std::ifstream inFile(fileName);
    if (size > 0)
    {
        std::cout << "List is not empty, would you like to clear it? (y/n)\n";
        std::string input;
        std::cin >> input;
        if (input == "y" || input == "Y")
        {
            clear();
        }
    }
    if (!inFile.is_open())
    {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return false;
    }

    std::string line;
    std::getline(inFile, line); // Skip header line
    if (line.empty())
    {
        std::cerr << "Empty file: " << fileName << std::endl;
        return false;
    }

    // Read each line and parse the task details
    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string name, priorityStr, description, statusStr;
        int priority;
        Task::Status status = Task::UNFINISHED;

        if (std::getline(ss, name, ',') && std::getline(ss, priorityStr, ',') && std::getline(ss, description, ',') && std::getline(ss, statusStr))
        {

            // Convert priority
            try
            {
                priority = std::stoi(priorityStr);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Invalid priority value: " << priorityStr << std::endl;
                return false;
            }

            // Convert status string to enum
            if (statusStr == "FINISHED")
            {
                status = Task::FINISHED;
            }
            else if (statusStr == "UNFINISHED")
            {
                status = Task::UNFINISHED;
            }
            else
            {
                std::cerr << "Invalid status in file: " << statusStr << std::endl;
                return false; // Skip this line
            }

            Task task(name, priority, description, status);
            addToList(task);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << std::endl;
            return false; // Skip this line
        }
    }

    inFile.close();
    return true;
}

bool TaskList::saveToCSV(const std::string &fileName) const
{
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return false;
    }

    outFile << "Task Name,Priority,Description,Status\n"; // Header

    Node *curr = head;
    while (curr != nullptr)
    {
        outFile << curr->data.getName() << ","
                << curr->data.getPriority() << ","
                << curr->data.getDescription() << ","
                << (curr->data.getStatus() == Task::FINISHED ? "FINISHED" : "UNFINISHED") << "\n";
        curr = curr->next;
    }

    outFile.close();
    return true;
}

void TaskList::clear()
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}