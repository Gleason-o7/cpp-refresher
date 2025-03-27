#include "task.h"
#include <iostream>

int main()
{
    std::cout << "Testing Task Class...\n";

    // Test default constructor
    Task defaultTask;
    std::cout << "Default Task: \n";
    std::cout << "Name: " << defaultTask.getName() << "\n";
    std::cout << "Priority: " << defaultTask.getPriority() << "\n";
    std::cout << "Timeframe: " << defaultTask.getTimeframe() << "\n";
    std::cout << "Description: " << defaultTask.getDescription() << "\n\n";

    // Test parameterized constructor
    Task customTask("Finish Project", 5, 3, "Complete the C++ project by Friday");
    std::cout << "Custom Task: \n";
    std::cout << "Name: " << customTask.getName() << "\n";
    std::cout << "Priority: " << customTask.getPriority() << "\n";
    std::cout << "Timeframe: " << customTask.getTimeframe() << "\n";
    std::cout << "Description: " << customTask.getDescription() << "\n\n";

    // Test copy constructor
    Task copiedTask(customTask);
    std::cout << "Copied Task: \n";
    std::cout << "Name: " << copiedTask.getName() << "\n";
    std::cout << "Priority: " << copiedTask.getPriority() << "\n";
    std::cout << "Timeframe: " << copiedTask.getTimeframe() << "\n";
    std::cout << "Description: " << copiedTask.getDescription() << "\n\n";

    // Test assignment operator
    Task assignedTask;
    assignedTask = customTask;
    std::cout << "Assigned Task: \n";
    std::cout << "Name: " << assignedTask.getName() << "\n";
    std::cout << "Priority: " << assignedTask.getPriority() << "\n";
    std::cout << "Timeframe: " << assignedTask.getTimeframe() << "\n";
    std::cout << "Description: " << assignedTask.getDescription() << "\n\n";

    // Test setters
    assignedTask.setName("Review Code");
    assignedTask.setPriority(4);
    assignedTask.setTimeframe(2);
    assignedTask.setDescription("Go through the code and fix issues");
    std::cout << "Modified Assigned Task: \n";
    std::cout << "Name: " << assignedTask.getName() << "\n";
    std::cout << "Priority: " << assignedTask.getPriority() << "\n";
    std::cout << "Timeframe: " << assignedTask.getTimeframe() << "\n";
    std::cout << "Description: " << assignedTask.getDescription() << "\n";
    return 0;
}