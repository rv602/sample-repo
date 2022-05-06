#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<regex>
#include<iostream>
using namespace std;

int main(){
    string str;
    string line;
    fstream  files("input.asm");
    ofstream outp;
    outp.open("_no_whitespace.asm");
    ofstream file1;
    file1.open("rv.txt");

    while (getline(files,str)){
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
        int commentPos = str.find("//");
        if(commentPos!=string::npos){
        for(int i = 0; i<str.length();i++){

            if(str[i]=='/'){
                str.erase(i);
            }
        }
        }
        file1<< str <<endl;
    }
    ifstream fin("rv.txt");
    while(getline(fin,line)){
        while(line.length()==0){
            getline(fin,line);

        }
        outp<< line<<endl;
    }
    files.close();
    file1.close();
    outp.close();
    remove("rv.txt");
    return 0;
}