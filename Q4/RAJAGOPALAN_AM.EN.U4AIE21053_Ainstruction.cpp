#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<regex>
#include<iostream>
#include <map>
using namespace std;

string decToBinary(int x)
{
    int binaryNum[32];
    string binary;
 
    int i = 0;
    while (x > 0) {
        binaryNum[i] = x % 2;
        x = x / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        binary += to_string(binaryNum[j]);
    return binary;
}

string addZeros(string str){
    int n = str.length();
    int req = 15-n;
    while(req>0){
        str = "0" + str;
        req--;
    }
    return str;
}

int main()
{
    map<string,string> preDef;
    preDef["R0"]="0";
    preDef["R1"]="1";
    preDef["R2"]="2";
    preDef["R3"]="3";
    preDef["R4"]="4";
    preDef["R5"]="5";
    preDef["R6"]="6";
    preDef["R7"]="7";
    preDef["R8"]="8";
    preDef["R9"]="9";
    preDef["R10"]="10";
    preDef["R11"]="11";
    preDef["R12"]="12";
    preDef["R13"]="13";
    preDef["R14"]="14";
    preDef["R15"]="15";
    
    string line;
    fstream files("input.asm");
    ofstream outt;
    outt.open("outt.hack");
    while(getline(files,line)){
        if(line[1]=='R'){
            string sub = line.substr(1);
            string num1 = preDef[sub];
            string temp3 = decToBinary(stoi(num1));
            string temp4 = addZeros(temp3);
            string final1 = "0" + temp4;
            outt<<final1<<endl;
        }
        else{
            string num = line.substr(1);
            string temp1 = decToBinary(stoi(num));
            string temp2 = addZeros(temp1);
            string final = "0" + temp2;
            outt<<final<<endl;
        }
    }
    files.close();
    outt.close();
    return 0;
}
