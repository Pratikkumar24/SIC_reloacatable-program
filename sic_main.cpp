#include "Pass2.h"
using namespace std;

int main()
{

    //Pass 1..creation of symtab
    ifstream fin("lineofcodes.txt");
    string lineofcode, value;
    char c;
    while (!fin.eof())
    {

        getline(fin, lineofcode);
        string value = get_object_code(lineofcode);
    }
    fin.close();
    //end

    //Pass2:
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
    //pass2:bitmasking
    ifstream in("lineofcodes.txt");
    while (!in.eof())
    {
        getline(in, lineofcode);
        }
    in.close();
    return 0;
}