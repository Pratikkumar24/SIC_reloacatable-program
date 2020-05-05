#include "Pass2.h"
using namespace std;

int main()
{

    ifstream fin("lineofcodes.txt");

    string lineofcode, value;
    char c;
    while (!fin.eof())
    {

        getline(fin, lineofcode);
        string value = get_object_code(lineofcode);
    }
    fin.close();
    cout << endl;
    cout << "\n The symbol table:" << endl;
    ifstream fins("lineofcodes.txt");
    cout << endl;
    cout << "\n\n NEMONIC    -    OPCODE" << endl;
    for (it = mpopcode.begin(); it != mpopcode.end(); it++)
    {
        cout << it->first << " => \t" << it->second << endl;
    }

    while (!fins.eof())
    {
        getline(fins, lineofcode);
        pass2(lineofcode);
    }

    cout << "\n Length of the program:" << convertinttohex(loctr);
    fins.close();
    return 0;
}