#include "createOJinput.h"
#include "Execute.h"
#include "Judge.h"

int main(){
     char  filePath[100] = "/home/cjh/input";//自己设置目录  
     vector<string> files;

     getFiles(filePath, files);
  
     char str[30];
     int size = files.size();
     vector<Output> ou;
      for (int i = 0; i < size; i++)
     {
        //cout<<files[i]<<endl;
         string fatherpath=files[i];
         Output ouu(fatherpath,"/home/cjh");
         ou.push_back(ouu);
     }
     for (int i = 0; i < size; i++)
     {
        //cout<<files[i]<<endl;
         string fatherpath=files[i];
         InputFile p(fatherpath);
         vector<string> codefiles;
         getFiles(fatherpath, codefiles);
         for(int i=0;i<20;i++){
            string inputfile = p.makeInFiles();
            execute(fatherpath, codefiles,inputfile);
         }
     
     }
     for(int i=0;i<size;++i){    ou[i].judge();}
 }
