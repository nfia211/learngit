#include "createOJinput.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

void getFiles(string path, vector<string>& filenames)
{
	DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0){
            filenames.push_back(path + "/" + ptr->d_name);
    	}
    }
    closedir(pDir);
}

char RandChar(){

    int s = rand() % 2;
    char c;
    if(s == 1)
        c= 'A' + rand() % ('Z' - 'A' + 1);
    else
        c= 'a' + rand() % ('z' - 'a' + 1);
    return c;
}

int RandInt(int min,int max){
    
    int n = min + rand() % (max - min + 1);
    return n;
}

string RandString(int min,int max){
    int len=RandInt(min,max);
    string str="";
    for(int i=0;i<len;++i){
        str+=RandChar();
    }
    return str;
}
InputFile::InputFile(string path){
    fatherPath = path;
    stdinPath = path+"/stdin_format.txt";
    inputFilePath = path +"/input" + ".txt";
    this->getInputTypes();
}
void InputFile::getInputTypes(){//char -1 int -2 string -3
    ifstream ifs(stdinPath);
    vector<string> temp;
    string str;
    while(ifs>>str){
        temp.push_back(str);
    }
    ifs.close();

    for(int i=0;i<temp.size();++i){
        if(temp[i] == "char"){
            types.push_back(-1);
        }
        else{
            stringstream ss(temp[i]);
            string tmp;
            if(getline(ss, tmp, '(')){
                if(tmp=="int"){
                    types.push_back(-2);
                    getline(ss, tmp, ',');
                    types.push_back(atoi(tmp.c_str()));
                    getline(ss, tmp, ')');
                    types.push_back(atoi(tmp.c_str()));
                }
                if(tmp=="string"){
                    types.push_back(-3);
                    getline(ss, tmp, ',');
                    types.push_back(atoi(tmp.c_str()));
                    getline(ss, tmp, ')');
                    types.push_back(atoi(tmp.c_str()));
                }
            }
        }
    }
}
  
string InputFile::makeInFiles(){
	srand((unsigned)time(NULL));
    ofstream ofs;
    ofs.open(inputFilePath,ios::out);
    //cout<<inputFilePath<<endl;
    int i=0;
    //cout<<types.size()<<endl;
    while(i<types.size()){
        if(types[i] == -1){
            ofs<<RandChar();
            ++i;
        }
        if(types[i] == -2){
            int p=RandInt(types[i+1],types[i+2]);
            ofs<<p;
            //cout<<p;
            i+=3;
        }
        if(types[i] == -3){
            string p=RandString(types[i+1],types[i+2]);
            ofs<<p;
            i+=3;
        }

        if(i!=types.size())
            ofs<<" ";
    }
    ofs.close();
    return inputFilePath;
}

