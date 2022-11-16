#include "Judge.h"
#include "createOJinput.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
Output::Output(string path,string outfilePath){
    fatherPath=path;
    equalfilePath=outfilePath+"/equal.csv";
    inequalfilePath=outfilePath+"/inequal.csv";
    getFiles(fatherPath, codefiles);
}
bool Output::cmpOutFiles(string fileA,string fileB){
    ifstream op;
    string str1,str2;
    op.open(fileA);
    //cout<<1<<endl;
    while(!op.eof())
        str1+=op.get();
    op.close();
    op.open(fileB);
    while(!op.eof())
        str2+=op.get();
    op.close();
    if(str1==str2)
       return true;
    else
        return false;
}
void Output::judge(){
    int len=codefiles.size();
    
    vector<string> outfileName;
     for(int i=0;i<len;++i){
        stringstream ss(codefiles[i]);
        string tmp;
        getline(ss, tmp, '.');
        outfileName.push_back(tmp+"out.txt");
     }
    
    int l=filePath.size();
    ofstream equalofs,inequalofs;
    equalofs.open(equalfilePath,ios::app);
    inequalofs.open(inequalfilePath,ios::app);

    for(int i=0;i<len;++i){
        for(int j=i+1;j<len;++j){ 
            if(codefiles[i]!=fatherPath+"/stdin_format.txt"&&codefiles[j]!=fatherPath+"/stdin_format.txt")
               {
                 string temp1=codefiles[i],temp2=codefiles[j];
                temp1=temp1.erase(0,l);
                temp2=temp2.erase(0,l);
                //cout<<outfileName[i]<<','<<outfileName[j]<<endl;
                if(cmpOutFiles(outfileName[i],outfileName[j])==true){
                    equalofs<<temp1<<','<<temp2<<endl;
                }
                else{
                    inequalofs<<temp1<<','<<temp2<<endl;
                }
            }
        }
    }
    equalofs.close();
    inequalofs.close();
}