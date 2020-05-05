#include "symtab.h"
#include <fstream>
#include <sstream>
using namespace std;

string convertinttohex(int p)
{
    stringstream ss;
    ss << hex << p;
    string res = ss.str();
    return res;
}
int giveaddress(string ch)
{
    it = mpopcode.find(ch);
    if (it == mpopcode.end())
    {
        return 0;
    }
    else
    {
        return it->second;
    }
}
void pass2(string ch)
{
    stringstream ss(ch);
    string word;
    ofstream fout("objectcode.txt");
    while (ss >> word)
    {
        if ((isoptab(word) == 0))
        {
            if (word == "END")
            {
                if (ss >> word)
                {
                    continue;
                }
            }

            ss >> word;

            if (word == "START")
                break;
            else if (word == "BYTE")
            {
                string ch;
                int k = 0;
                ss >> word;
                if (word[0] == 'C')
                {
                    int end = 0;
                    for (int i = 2; word[i]; i++)
                    {
                        if (word[i] == '\'')
                        {
                            break;
                        }
                        end++;
                    }

                    ch = word.substr(2, end);
                    stringstream ss;
                    for (int i = 0; i < ch.size(); ++i)
                        ss << std::hex << (int)ch[i];
                    string mystr = ss.str();
                    cout << "\n The nemonic of " << word << ":" << mystr;
                }

                else
                {
                    int end = 0;
                    for (int i = 2; word[i]; i++)
                    {
                        if (word[i] == '\'')
                        {
                            break;
                        }
                        end++;
                    }

                    ch = word.substr(2, end);
                    cout << "\n The nemonic of " << word << ":" << ch;
                }
            }
            else
            {
                if (word == "WORD" || word == "RESW" || word == "RESB")
                {
                    if (ss >> word)
                    {
                        continue;
                    }
                }

                size_t found = word.find(',');
                if (found != string::npos)
                {
                    word = word.substr(0, found);
                }
                cout << "\n1 The nemonic value of " << word << " is:" << optab(word);

                if (ss >> word)
                {
                    size_t found = word.find(',');
                    if (found != string::npos)
                    {
                        word = word.substr(0, found);
                    }
                    cout << "\n 1The address of " << word << ": " << convertinttohex(giveaddress(word));
                }
            }
        }
        else
        {

            cout << "\n2 The nemonic value of " << word << " is:" << optab(word);

            if (ss >> word)
            {
                size_t found = word.find(',');
                if (found != string::npos)
                {
                    word = word.substr(0, found);
                }
                cout << "\n2 The address of " << word << ": " << convertinttohex(giveaddress(word));
            }
        }
    }
    cout << endl;
}

int main()
{

    ifstream fin("lineofcodes.txt");
    ofstream fout("objectcode.txt");

    string lineofcode, value;
    char c;
    while (!fin.eof())
    {

        getline(fin, lineofcode);
        string value = get_object_code(lineofcode);
    }
    fin.close();

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
    cout << "\n The symbol table:" << endl;

    cout << "\n Length of the program:" << loctr;
    fins.close();
    return 0;
}