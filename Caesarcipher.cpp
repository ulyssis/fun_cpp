#include "Caesarcipher.h"

Caesarcipher::Caesarcipher()
{
    inputFilePath = "Tasks.txt";
    outputFilePath = "Tasks2.txt",
    key = 3;
}

void Caesarcipher::encryptFile()
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file '" << inputFilePath << "'." << endl;
        return;
    }
    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch + key);
    }
    inputFile.close();
    outputFile.close();
}

void Caesarcipher::decryptFile()
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file '" << inputFilePath << "'." << endl;
        return;
    }
    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch - key);
    }
    inputFile.close();
    outputFile.close();
}

void Caesarcipher::runCaesar()
{
    int choice;

    cout << "\n";
    cout << "1. Encrypt File\n";
    cout << "2. Decrypt File\n";
    cout << "Enter your choice of action: ";
    cin >> choice;

    if (choice == 1)
    {
        encryptFile();
    }

    else if (choice == 2)
    {
        decryptFile();
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}