#include "task.h"

// Constructors
Task::Task() : name(""), priority(0), description(""), status(UNFINISHED) {}

Task::Task(const std::string &name, int priority, const std::string &description, Status status)
    : name(name), priority(priority), description(description), status(status) {}

Task::Task(const Task &taskToCopy) : name(taskToCopy.name),
                                     priority(taskToCopy.priority),
                                     description(taskToCopy.description),
                                     status(taskToCopy.status)
{
}

Task &Task::operator=(const Task &taskToCopy)
{
    if (this != &taskToCopy)
    {
        name = taskToCopy.name;
        priority = taskToCopy.priority;
        description = taskToCopy.description;
        status = taskToCopy.status;
    }
    return *this;
}

// Getter functions
std::string Task::getName() const
{
    return name;
}

int Task::getPriority() const
{
    return priority;
}

std::string Task::getDescription() const
{
    return description;
}

Task::Status Task::getStatus() const
{
    return status;
}

// Setter functions
void Task::setName(const std::string &newName)
{
    name = newName;
}

void Task::setPriority(int newPriority)
{
    priority = newPriority;
}

void Task::setDescription(const std::string &newDescription)
{
    description = newDescription;
}

void Task::setStatus(Status newStatus)
{
    status = newStatus;
}