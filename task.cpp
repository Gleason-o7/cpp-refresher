#include "task.h"

// Constructors
Task::Task() : name(""), priority(0) /*, timeframe(0)*/, description(""), status(UNFINISHED) {}

Task::Task(const std::string &name, int priority /*, int timeframe*/, const std::string &description)
    : name(name), priority(priority) /*, timeframe(timeframe)*/, description(description), status(UNFINISHED) {}

Task::Task(const Task &taskToCopy) : name(taskToCopy.name),
                                     priority(taskToCopy.priority),
                                     /*timeframe(taskToCopy.timeframe),*/
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
        // timeframe = taskToCopy.timeframe;
        description = taskToCopy.description;
        status = taskToCopy.status;
    }
    return *this;
}

std::string Task::getName() const
{
    return name;
}

int Task::getPriority() const
{
    return priority;
}

/*int Task::getTimeframe() const
{
    return timeframe;
}*/

std::string Task::getDescription() const
{
    return description;
}

Task::Status Task::getStatus() const
{
    return status;
}

void Task::setName(const std::string &newName)
{
    name = newName;
}
void Task::setPriority(int newPriority)
{
    priority = newPriority;
}
/*
void Task::setTimeframe(int newTimeframe)
{
    timeframe = newTimeframe;
}*/
void Task::setDescription(const std::string &newDescription)
{
    description = newDescription;
}

void Task::setStatus(Status newStatus)
{
    status = newStatus;
}