
/*
    this code implements a todo list.
    usesr can:
    " view the list
    " add a task
    " delete a task
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void showTasks(const std::vector<std::string> &tasks)
{
    std::cout << "To-Do List:" << std::endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> tasks;
    std::string task;
    char choice;
    std::vector<std::string>::iterator id;

    // Load existing tasks from file
    std::ifstream inputFile("tasks.txt");
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        std::cout << "\n [Menu]" << std::endl;
        std::cout << "A - Add a task" << std::endl;
        std::cout << "V - View tasks" << std::endl;
        std::cout << "D - Delete a task" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'A':
        case 'a':
            std::cout << "Enter a task to add: ";
            std::cin.ignore(); // Clears the input buffer
            getline(std::cin, task);
            tasks.push_back(task);
            break;
        case 'D':
        case 'd':

            std::cout << "Enter a task to delete: ";

            std::cin.ignore();
            getline(std::cin, task);
            id = std::find(tasks.begin(), tasks.end(), task);
            if (id != tasks.end())
            {
                tasks.erase(id);
            }
            else
            {
                std::cout << "the inputed task is not found in the records, return to the main menu. " << std::endl;
            }
            break;

        case 'V':
        case 'v':
            showTasks(tasks);
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    // Save tasks to file
    std::ofstream outputFile("tasks.txt");
    if (!outputFile)
    {
        std::cerr << "Error: could not open the file for writing." << std::endl;
    }

    for (const auto &t : tasks)
    {
        outputFile << t << std::endl;
    }
    outputFile.close();

    return 0;
}

