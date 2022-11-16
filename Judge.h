#ifndef JUDGE_H
#define JUDGE_H
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
class Output{
    string fatherPath;
    string equalfilePath;
    string inequalfilePath;
    string  filePath = "/home/cjh/input";

public:
    vector<string> codefiles;
    Output(){};
    Output(string path,string outfilePath);
    bool cmpOutFiles(string fileA,string fileB);
    void judge();
};
#endif
