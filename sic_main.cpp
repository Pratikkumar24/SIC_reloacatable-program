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

    cout << "\n Length of the program:" << convertinttohex(loctr) << endl;
    fins.close();
    //pass2:bitmasking
    ifstream filin("lineofcodes.txt");
    ifstream sc("objectcode.txt");
    string source;
    string opcodes;
    string hexa;
    int occurence = 0;

    string text;
    int counter = 0;
    int flag = 0;
    string init;
    getline(filin, init);
    initial(init, loctr);
    while (filin >> opcodes)
    {
        if (occurence == 1 && isoptab(opcodes))
        {
            cout << "\n\n\tThe TEXT:" << text << endl;
            text.clear();
            sc >> source;
            text += source;
            occurence = 0;
            counter = 1;
        }
        else if (isoptab(opcodes))
        {
            sc >> source;
            text += source;
            counter++;
        }
        else if (opcodes == "WORD" || opcodes == "BYTE")
        {
            sc >> source;
            text += source;
            counter++;
            occurence = 1;
        }

        if (counter >= 10)
        {
            cout << "\n\n\tThe TEXT:" << text << endl;
            text.clear();
            counter = 0;
        }
    }
    cout << "\n\n\t The Text:" << text << endl;
    return 0;
}

//RUK JAAA
