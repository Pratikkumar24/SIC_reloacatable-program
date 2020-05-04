#include "symtab.h"
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    ifstream fin("lineofcodes.txt");
    ofstream fout("objectcode.txt");

    string lineofcode, value;
    char c;
    int count = 0;
    while (!fin.eof())
    {

        getline(fin, lineofcode);
        string value = get_object_code(lineofcode);
        fout << value << endl;
        count++;
    }
    cout << "\n The symbol table:" << endl;
    for (it = mpopcode.begin(); it != mpopcode.end(); it++)
    {
        cout << it->first << " => " << it->second << endl;
    }
    cout << "\n Length of the program:" << loctr;
    return 0;
}