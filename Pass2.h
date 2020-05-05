#include "symtab.h"
#include <fstream>
#include <sstream>
ofstream fout("objectcode.txt");

void entrypoint(string a, string b, int i)
{
    if (i == 0)
    {
        fout << a << b << endl;
    }
    else
    {
        char k = b[0];
        switch (k)
        {
        case '0':
            b[0] = '8';
            break;
        case '1':
            b[0] = '9';
            break;
        case '2':
            b[0] = 'A';
            break;
        case '3':
            b[0] = 'B';
            break;
        case '4':
            b[0] = 'C';
            break;
        case '5':
            b[0] = 'D';
            break;
        case '6':
            b[0] = 'E';
            break;
        case '7':
            b[0] = 'F';
            break;
        default:
            b[0] = '0';
        }
        fout << a << b << endl;
    }
}
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
    int index = 0;
    stringstream ss(ch);
    string word;
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
                    entrypoint(mystr, "", index);
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
                    entrypoint(ch, "", index);
                }
            }
            else
            {
                if (word == "WORD" || word == "RESW" || word == "RESB")
                {
                    if (word == "WORD")
                    {
                        ss >> word;
                        stringstream i(word);
                        int x = 0;
                        i >> x;
                        int count = 0;
                        string a = "000000", b = convertinttohex(x);
                        for (int i = 0; b[i]; i++)
                        {
                            count++;
                        }
                        a = a.substr(0, 6 - count);
                        cout << "\n\t\t\t\t\t\t\t size of x:" << sizeof(convertinttohex(x));
                        entrypoint(a, b, index);
                    }
                    if (ss >> word)
                    {
                        continue;
                    }
                }

                size_t found = word.find(',');
                if (found != string::npos)
                {
                    word = word.substr(0, found);
                    index = 1;
                }
                cout << "\n1 The nemonic value of " << word << " is:" << optab(word);
                string k = optab(word);
                if (ss >> word)
                {
                    size_t found = word.find(',');
                    if (found != string::npos)
                    {
                        word = word.substr(0, found);
                        index = 1;
                    }
                    cout << "\n 1The address of " << word << ": " << convertinttohex(giveaddress(word));
                    entrypoint(k, convertinttohex(giveaddress(word)), index);
                }
            }
        }
        else
        {

            cout << "\n2 The nemonic value of " << word << " is:" << optab(word);
            string k = optab(word);
            if (word == "RSUB")
            {
                entrypoint(k, "0000", index);
            }
            if (ss >> word)
            {
                size_t found = word.find(',');
                if (found != string::npos)
                {
                    word = word.substr(0, found);
                    index = 1;
                }
                cout << "\n2 The address of " << word << ": " << convertinttohex(giveaddress(word));
                entrypoint(k, convertinttohex(giveaddress(word)), index);
            }
        }
    }
    cout << endl;
}
