#include <bits/stdc++.h>
using namespace std;
map<string, string> mp = {
    {"ADD", "18"}, {"ADDF", "58"}, {"AND", "40"}, {"CLEAR", "B4"}, {"COMP", "28"}, {"COMPF", "88"}, {"DIV", "24"}, {"DIVF", "64"}, {"FIX", "C4"}, {"FLOAT", "C0"}, {"HIO", "F4"}, {"J", "3C"}, {"JEQ", "30"}, {"JGT", "34"}, {"JLT", "38"}, {"JSUB", "48"}, {"LDA", "00"}, {"LDB", "68"}, {"LDCH", "50"}, {"LDF", "70"}, {"LDL", "08"}, {"LDS", "6C"}, {"LDT", "74"}, {"LDX", "04"}, {"LPS", "D0"}, {"MUL", "20"}, {"MULF", "60"}, {"NORM", "C8"}, {"OR", "44"}, {"RD", "D8"}, {"RSUB", "4C"}, {"RMO", "AC"}, {"MULR", "98"}, {"DIVR", "9C"}, {"COMPR", "A0"}, {"ADDR", "90"}, {"SHIFTL", "A4"}, {"SHIFTR", "A8"}, {"SIO", "F0"}, {"SSK", "EC"}, {"STA", "OC"}, {"STB", "78"}, {"STCH", "54"}, {"STF", "80"}, {"STI", "D4"}, {"STL", "14"}, {"STS", "7C"}, {"STSW", "E8"}, {"SIT", "84"}, {"STX", "10"}, {"SUB", "1C"}, {"SUBF", "5C"}, {"SUBR", "94"}, {"SVC", "B0"}, {"TD", "E0"}, {"TIO", "F8"}, {"TIX", "2C"}, {"TIXR", "B8"}, {"WD", "DC"}};
string optab(string a)
{
    map<string, string>::iterator it;
    it = mp.find(a);
    if (it == mp.end())
    {
        return "0";
    }
    else
    {

        return it->second;
    }
}