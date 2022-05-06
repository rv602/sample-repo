#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<regex>
#include<iostream>
#include <map>
using namespace std;

int main(){
    string c_init = "111";
 
    map<string,string> computationTable;
    map<string,string> destinaTable;
    map<string,string> jumpInstTable;

    computationTable["0"] = "0101010";
    computationTable["1"] = "0111111";
    computationTable["-1"] = "0111010";    
    computationTable["D"] = "0001100";
    computationTable["A"] = "0110000";
    computationTable["!D"] = "0001101";
    computationTable["!A"] = "0110001";
    computationTable["-D"] = "0001111";
    computationTable["-A"] = "0110011";
    computationTable["D+1"] = "0011111";
    computationTable["A+1"] = "0110111";
    computationTable["D-1"] = "0001110";
    computationTable["A-1"] = "0110010";
    computationTable["D+A"] = "0000010";
    computationTable["D-A"] = "0010011";
    computationTable["A-D"] = "0000111";
    computationTable["D&A"] = "0000000";
    computationTable["D|A"] = "0010101";
    computationTable["M"] = "1110000";
    computationTable["!M"] = "1110001";
    computationTable["-M"] = "1110011";
    computationTable["M+1"] = "1110111";
    computationTable["M-1"] = "1110010";
    computationTable["D+M"] = "1000010";
    computationTable["D-M"] = "1010011";
    computationTable["M-D"] = "1000111";
    computationTable["D&M"] = "1000000";
    computationTable["D|M"] = "1010101";
    
    destinaTable[""] = "000";
    destinaTable["M"] = "001";
    destinaTable["D"] = "010";
    destinaTable["MD"] = "011";
    destinaTable["A"] = "100";
    destinaTable["AM"] = "101";
    destinaTable["AD"] = "110";
    destinaTable["AMD"] = "111";

    jumpInstTable[""] = "000";
    jumpInstTable["JGT"] = "001";
    jumpInstTable["JEQ"] = "010";
    jumpInstTable["JGE"] = "011";
    jumpInstTable["JLT"] = "100";
    jumpInstTable["JNE"] = "101";
    jumpInstTable["JLE"] = "110";
    jumpInstTable["JMP"] = "111";

    string destination;
    string comp1;
    string comp2;
    string dest;
    string jump;
    string comp_binary;
    string dest_binary;
    string jump_binary;
    
    string instruction;
    ifstream file("input.asm");
    ofstream output;
    output.open("output.hack");

    while(getline(file,instruction)){

    int equalSignPosition = instruction.find("=");
    int semiColonPosition = instruction.find(";");

    if(equalSignPosition!=string::npos){
        destination = instruction.substr(0,equalSignPosition);
        if(semiColonPosition!=string::npos){
            comp1 = instruction.substr(equalSignPosition+1,semiColonPosition - equalSignPosition - 1);
            jump = instruction.substr(semiColonPosition + 1,instruction.length() - semiColonPosition - 1);
        
        }
        else{
            comp1 = instruction.substr(equalSignPosition+1,instruction.length() - equalSignPosition - 1);
        }
    }
    else  {
        comp1 = instruction.substr(0,semiColonPosition);
        jump = instruction.substr(semiColonPosition + 1,instruction.length() - semiColonPosition - 1);
    }
    if (destinaTable.find(destination) != destinaTable.end()) {
        dest_binary = destinaTable[destination];
    }
    if (computationTable.find(comp1) != computationTable.end()) {
        comp_binary = computationTable[comp1];
    }
    if (jumpInstTable.find(dest) != jumpInstTable.end()) {
        jump_binary = jumpInstTable[jump];
    }
    string c_binary = c_init + comp_binary + dest_binary  + jump_binary;
    output<<c_binary<<endl;
    }
    return  0;
}