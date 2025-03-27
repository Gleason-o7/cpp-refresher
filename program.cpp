#include <fstream>
#include <iomanip>
#include <iostream>
#include "program.h"

void Program::welcome()
{
    std::cout << "Welcome to your task manager.\n";
}

void Program::menuLoop()
{
    char input;
    do
    {
        displayMenu();
        std::cout << "\t>> ";
        std::cin >> input;
        system("clear");
        switch (toupper(input))
        {
        case 'D':
            printTaskList();
            break;
        case 'A':
            addTask();
            break;
        case 'R':
            removeFromList();
            break;
        case 'F':
            printTaskList();
            markTaskFinished();
            break;
        case 'L':
            std::cout << "L";
            break;
        case 'Q':
            std::cout << "Q";
            return;
        default:
            std::cout << "Invalid option\n";
        }
    } while (true);
}

void Program::displayMenu()
{
    std::cout << "\nPick an option from the menu below:\n";
    std::cout << "(D) Display list of tasks\n";
    std::cout << "(A) Add a task\n";
    std::cout << "(R) Remove a task\n";
    std::cout << "(F) Mark a task finished\n";
    std::cout << "(L) Mark a list of tasks finished\n";
    std::cout << "(Q) Quit program\n";
}

void Program::printTaskList()
{
    list.printTaskList();
}

void Program::removeFromList()
{
    if (list.isEmpty())
    {
        std::cout << "No tasks available";
        return;
    }

    std::string input;
    printTaskList();
    std::cout << "Enter the task name or number to remove: \n\t>> ";
    std::cin.ignore();
    std::getline(std::cin, input);

    // Check if the input is a positive integer
    bool isInt = true;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            isInt = false;
            break;
        }
    }

    if (isInt)
    {
        int pos = std::stoi(input);
        if (pos <= 0)
        {
            std::cout << "Invalid position.\n";
            return;
        }
        list.removeFromList(pos, "");
    }
    else
    {
        list.removeFromList(-1, input);
    }
}

void Program::markTaskFinished()
{
    if (list.isEmpty())
    {
        std::cout << "No tasks available";
        return;
    }

    std::string input;
    std::cout << "Enter the task name or number to mark as finished: \n\t>> ";
    std::cin.ignore();
    std::getline(std::cin, input);

    // Check if the input is a positive integer
    bool isInt = true;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            isInt = false;
            break;
        }
    }

    if (isInt)
    {
        int pos = std::stoi(input);
        if (pos <= 0)
        {
            std::cout << "Invalid position.\n";
            return;
        }
        list.markTaskFinished(pos, "");
    }
    else
    {
        list.markTaskFinished(-1, input);
    }
}

void Program::addTask()
{

    std::string tempName;
    std::cout << "\nWhat will the name of the task be?\n\t>> ";
    std::cin >> tempName;

    int tempPriority;
    std::cout << "What will the priority of the task?\n\t (More important tasks get a lower priority)\n\t>> ";
    std::cin >> tempPriority;

    std::string tempDescription;
    std::cout << "What will the task description be?\n\t>> ";
    std::cin >> tempDescription;

    Task newTask(tempName, tempPriority, tempDescription);
    list.addToList(newTask);
}
