/*
    This is a App for maintaining a todo list. The list is stored in the file "Tasks.txt" in the local folder.

    This code implements a TodoList class and TodoApp class.
    TodoList <- TodoApp (association)

    The objects of both classes are on the stack, because the calsses are small and neither of them persist beyond their current scope.
    Otherwise we need to have them on heap.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class TodoList
{
private:
    vector<string> tasks;

public:
    TodoList(); // initililze tasks from file
    void add(const string &string);
    void remove(const string &string);
    void showTasks() const;
    void updateTasks(); // update file with tasks
};

// constructor
TodoList::TodoList()
{
    string task;
    ifstream inputFile("Tasks.txt");
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();
}

void TodoList::updateTasks()
{
    ofstream outputFile("Tasks.txt");
    if (!outputFile)
    {
        cerr << "Error: could not open the file for writing." << endl;
        return;
    }

    for (const auto &t : tasks)
    {
        outputFile << t << endl;
    }
    outputFile.close();
}
void TodoList::add(const string &string)
{
    tasks.push_back(string);
}

void TodoList::remove(const string &str)
{
    if (tasks.empty())
    {
        cout << "the to-do list is empty" << endl;
    }
    vector<string>::iterator it = find(tasks.begin(), tasks.end(), str);
    if (it != tasks.end())
    {
        tasks.erase(it);
        cout << "task is deleted from the to-do list" << endl;
    }
    else
    {
        cout << "the given task doesn't in the to-do list " << endl;
    }
}

void TodoList::showTasks() const
{
    if (tasks.empty())
    {
        cout << "the to-do list is empty" << endl;
    }
    int index = 0;
    for (auto it = tasks.begin(); it != tasks.end(); it++)
    {
        cout << index++ << ". " << *it << "\n";
    }
    cout << endl;
}

class TodoApp
{
private:
    TodoList todoList;

public:
    void run();
};

void TodoApp::run()
{
    char choice;
    string task;
    do
    {
        cout << "  [MENU]" << endl;
        cout << "A - Add a task" << endl;
        cout << "V - View tasks" << endl;
        cout << "D - Delete a task" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 'A':
        case 'a':
            cout << "Enter a task to add: " << endl;
            getline(cin, task);
            todoList.add(task);
            break;
        case 'V':
        case 'v':
            cout << "The tasks on the to-do list are:\n";
            todoList.showTasks();
            break;
        case 'D':
        case 'd':
            cout << "Enter a task to delete it from the list: ";
            getline(cin, task);
            todoList.remove(task);
            break;
        case 'Q':
        case 'q':
            cout << "Quitting the program." << endl;
            break;
        default:
            cout << "Invalid choice. please try again!" << endl;
        }
    } while (choice != 'Q' && choice != 'q');
    todoList.updateTasks();
}

int main()
{
    TodoApp todoApp;
    todoApp.run();
    return 0;
}