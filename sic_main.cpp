#include "opcode.h"
#include <fstream>
#include <sstream>
using namespace std;
long int loctr = 0;
// map<string, int> mpopcode;
string get_object_code(string ch)
{
    ifstream fin("lineofcodes.txt");
    string word;
    while (fin >> word)
    {
        if (word == "START")
        {
            fin >> word;
            stringstream stringtoint(word);

            stringtoint >> loctr;
            cout << "\n Location pointer:" << loctr;
        }
        else
        {

            cout << "\n this the word:" << word;
            cout << "\n opcode of this word is:" << optab(word) << endl;
        }
    }
    return ch;
}
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
    cout << "\n\n Number of lines:" << count;
    return 0;
}