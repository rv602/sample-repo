#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<regex>
#include<iostream>
#include <map>
using namespace std;

string Symbol(string line1){
    int bracketOpen = line1.find('(');
    int bracketClose = line1.find(')');
    
    if(line1[0]=='@'){
        return line1.substr(1,line1.length()-1);
    }
    return "";
}

int main()
{
    map<string, int> symbolTable;
    symbolTable["R0"] = 0;
    symbolTable["R1"] = 1;
    symbolTable["R2"] = 2;
    symbolTable["R3"] = 3;
    symbolTable["R4"] = 4;
    symbolTable["R5"] = 5;
    symbolTable["R6"] = 6;
    symbolTable["R7"] = 7;
    symbolTable["R8"] = 8;
    symbolTable["R9"] = 9;
    symbolTable["R10"] = 10;
    symbolTable["R11"] = 11;
    symbolTable["R12"] = 12;
    symbolTable["R13"] = 13;
    symbolTable["R14"] = 14;
    symbolTable["R15"] = 15;
    symbolTable["SCREEN"] = 16384;
    symbolTable["KBD"] = 24576;
    
    string curLine;
    int lineNo = 0;
    ifstream file1("input.asm");
    ofstream out;
    out.open("symboltable.asm");
    int index = 16;
    while(getline(file1,curLine)){
        string sym = Symbol(curLine);
        
        if(symbolTable.find(sym)==symbolTable.end() && sym.length()!=0){
            symbolTable[sym]=index;
            index++;
        }
    }
    int table_size = sizeof(symbolTable);

    map<string, int>::iterator itr;

    for (itr = symbolTable.begin(); itr != symbolTable.end(); ++itr) {
        out << itr->first << '\t' << itr->second
             << '\n';
    }   
}
