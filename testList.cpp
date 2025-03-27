#include <iostream>
#include "taskList.h"
#include "task.h"

int main()
{
    // Test default constructor
    TaskList taskList1;
    std::cout << "TaskList1 created with default constructor." << std::endl;
    taskList1.printTaskList();

    // Test parameterized constructor
    Task task1("Task 1", 5 /*, 3*/, "Complete the assignment");
    Task task2("Task 2", 3 /*, 2*/, "Prepare for the meeting");
    Task task3("Task 3", 4 /*, 4*/, "Code this assignment");
    TaskList taskList2;

    taskList2.addToList(task1);
    taskList2.addToList(task2);
    taskList2.addToList(task3);
    std::cout << "TaskList2 created with parameterized constructor and added tasks." << std::endl;
    taskList2.printTaskList();

    // Test copy constructor
    TaskList taskList3 = taskList2; // This uses the copy constructor
    std::cout << "TaskList3 created using the copy constructor." << std::endl;
    taskList3.printTaskList();

    // Test assignment operator
    TaskList taskList4;
    taskList4 = taskList2; // This uses the assignment operator
    taskList4.removeFromList("Task 2");
    std::cout
        << "TaskList4 created using the assignment operator and removing task 2." << std::endl;
    taskList4.printTaskList();

    return 0;
}
