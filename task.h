#ifndef TASK_H_
#define TASK_H_
#include <string>

class Task
{
public:
    enum Status
    {
        UNFINISHED,
        FINISHED
    };

private:
    std::string name;
    int priority;
    // int timeframe;
    std::string description;
    Status status;

public:
    // Constructors
    Task();
    Task(const std::string &name, int priority /*, int timeframe*/, const std::string &description);
    Task(const Task &taskToCopy);
    Task &operator=(const Task &taskToCopy);

    // Destructor not needed

    // Getter functions
    std::string getName() const;
    int getPriority() const;
    // int getTimeframe() const;
    std::string getDescription() const;
    Status getStatus() const;

    // Setter functions
    void setName(const std::string &newName);
    void setPriority(int newPriority);
    // void setTimeframe(int newTimeframe);
    void setDescription(const std::string &newDescription);
    void setStatus(Status newStatus);
};

#endif