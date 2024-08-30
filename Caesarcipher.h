// prevent being included for multiple times
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <iostream>
#include <fstream>
using namespace std;

class Caesarcipher
{
private:
    string inputFilePath;
    string outputFilePath;
    int key;

public:
    Caesarcipher();
    void encryptFile();
    void decryptFile();
    void runCaesar();
};

#endif