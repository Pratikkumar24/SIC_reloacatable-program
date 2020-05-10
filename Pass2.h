#include "symtab.h"
#include <fstream>
#include <sstream>
ofstream fout("objectcode.txt");
ofstream bout("output.txt");
map<string, string> bit;
map<string, string>::iterator biti;
int addcount = 0;
long int binaryToDecimal(long int n)
{
    long int num = n;
    long int dec_value = 0;

    long int base = 1;

    long int temp = num;
    while (temp)
    {
        long int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}
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
                string k = optab(word);
                if (ss >> word)
                {
                    size_t found = word.find(',');
                    if (found != string::npos)
                    {
                        word = word.substr(0, found);
                        index = 1;
                    }
                    entrypoint(k, convertinttohex(giveaddress(word)), index);
                }
            }
        }
        else
        {

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
                entrypoint(k, convertinttohex(giveaddress(word)), index);
            }
        }
    }
}
void initial(string word, int l)
{
    bout << "H";
    int counter = 0;
    for (int i = 0; (i < word[i] && i < 6); i++)
    {

        if (word[i] != ' ')
        {
            bout << word[i];
            counter++;
        }
        else
        {
            break;
        }
    }
    if (counter < 6)
    {
        for (int i = 0; i < (6 - counter); i++)
        {
            bout << " ";
        }
    }
    if (starting_location == 0)
    {
        string len = convertinttohex(l - starting_location);
        bout << "00000000" << len;
    }
    else
    {
        string len = convertinttohex(l - starting_location);
        transform(len.begin(), len.end(), len.begin(), ::toupper);

        bout << "00" << convertinttohex(starting_location) << "00" << len;
    }
    bout << endl;
}
void final(string word)
{
    if (starting_location == 0)
    {
        bout << "E000000";
    }
    else
    {
        bout << "E0" << convertinttohex(starting_location);
    }
}
void bitmasking(string text, string hexa, int location)
{
    if (location == loctr)
    {
        location -= 3;
    }

    int k = text.length();
    k /= 2;
    location = location - (k - 3);

    string length = convertinttohex(k);
    int l = hexa.length();
    l = 12 - l;
    while (l--)
    {
        hexa += '0';
    }
    stringstream geek(hexa);
    long int x = 0;
    geek >> x;
    hexa = convertinttohex(binaryToDecimal(x));
    transform(hexa.begin(), hexa.end(), hexa.begin(), ::toupper);
    transform(length.begin(), length.end(), length.begin(), ::toupper);
    if (length.length() < 2)
    {
        string s = "00";
        s[1] = length[0];
        bout << "T00" << convertinttohex(location) << s << hexa << text << endl;
    }
    else
    {
        bout << "T00" << convertinttohex(location) << length << hexa << text << endl;
    }
}
