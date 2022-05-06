#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<regex>
#include<iostream>
using namespace std;

int main()
{
    string line;
    fstream files("input.asm");
    ofstream outt;
    outt.open("symbolsandvariables.asm");

    smatch n;
    regex r1("@[a-zA-Z0-9]+");
    regex reg("\\([a-zA-Z]+\\)");
    while(getline(files,line)){

        for( sregex_iterator it(line.begin(), line.end(), r1), it_end; it != it_end; ++it ){
            string temp1= (*it)[0];
            string temp2 = temp1.substr(1);
            if(temp2.find_first_not_of("0123456789")!=string::npos){
                outt << temp1 << "\n";
            }
        }
        for( sregex_iterator it(line.begin(), line.end(), reg), it_end; it != it_end; ++it ){
            string temp = (*it)[0];
            outt << temp.substr(1,temp.length()-2) << "\n";
        }
    }
    files.close();
    outt.close();
    return 0;
}