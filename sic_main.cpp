#include "opcode.h"
using namespace std;
int main()
{
    string p = "s";
    p = optab(p);
    if (p == "ERROR")
    {
        cout << "\n Its an error";
    }
    else
    {
        cout << "\n Opcode:" << p;
    }
    return 0;
}