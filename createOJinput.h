#ifndef CREATEOJINPUT_H
#define CREATEOJINPUT_H
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class InputFile{
    string fatherPath;
    string stdinPath;
    string inputFilePath;
    vector<int> types;
public:
    InputFile(){};
    InputFile(string path);
    string makeInFiles();
    void getInputTypes();
};
void getFiles(string path, vector<string>& filenames);
char RandChar();
int RandInt(int min,int max);
string RandString(int min,int max);
#endif