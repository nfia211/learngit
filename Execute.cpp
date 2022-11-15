
#include "Execute.h"

#include<cstdlib>
#include<iostream>
#include<string>
#include<string.h>
#include<ctime>
#include<cstdio>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
void execute(string fatherpath, vector<string> files,string inputfile){
	for(int i=0;i<files.size();++i){
        if(files[i]!=fatherpath+"/stdin_format.txt"){        
            string cmd="./execute.sh "+files[i]+" "+inputfile;
            system(cmd.c_str());
        }
	}
}