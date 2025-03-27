#include <iostream>
#include "taskList.h"
#include "task.h"

int main()
{
    // Test default constructor
    TaskList taskList1;
    std::cout << "TaskList1 created with default constructor.\n";
    taskList1.printTaskList();

    // Test adding tasks
    Task task1("Task 1", 5, "Complete the assignment");
    Task task2("Task 2", 3, "Prepare for the meeting");
    Task task3("Task 3", 4, "Code this assignment");

    TaskList taskList2;
    taskList2.addToList(task1);
    taskList2.addToList(task2);
    taskList2.addToList(task3);
    std::cout << "TaskList2 created with added tasks.\n";
    taskList2.printTaskList();

    // Test copy constructor
    TaskList taskList3 = taskList2;
    std::cout << "TaskList3 created using the copy constructor.\n";
    taskList3.printTaskList();

    // Test assignment operator
    TaskList taskList4;
    taskList4 = taskList2;
    std::cout << "TaskList4 created using the assignment operator.\n";
    taskList4.printTaskList();

    // Test removing a task by position
    std::cout << "\nRemoving task at position 2 from TaskList2...\n";
    taskList2.removeFromList(2, "");
    taskList2.printTaskList();

    // Test removing a task by name
    std::cout << "\nRemoving 'Task 1' from TaskList2...\n";
    taskList2.removeFromList(-1, "Task 1");
    taskList2.printTaskList();

    // Test removing a non-existent task
    std::cout << "\nAttempting to remove 'Task X' (non-existent task)...\n";
    taskList2.removeFromList(-1, "Task X");

    // Test marking a task as finished by position
    std::cout << "\nMarking task at position 1 as finished in TaskList2...\n";
    taskList2.markTaskFinished(1, "");
    taskList2.printTaskList();

    // Test marking a task as finished by name
    std::cout << "\nMarking 'Task 3' as finished in TaskList2...\n";
    taskList2.markTaskFinished(-1, "Task 3");
    taskList2.printTaskList();

    // Test marking a non-existent task as finished
    std::cout << "\nAttempting to mark 'Task X' as finished (non-existent task)...\n";
    taskList2.markTaskFinished(-1, "Task X");

    // Test isEmpty() function
    std::cout << "\nChecking if TaskList1 is empty: " << (taskList1.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Checking if TaskList2 is empty: " << (taskList2.isEmpty() ? "Yes" : "No") << "\n";

    // Test clearing the list and checking if empty
    std::cout << "\nRemoving all tasks from TaskList2...\n";
    taskList2.removeFromList(1, ""); // Remove last remaining task
    std::cout << "Checking if TaskList2 is empty: " << (taskList2.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
