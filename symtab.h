#include "opcode.h"
#include <math.h>
using namespace std;
int loctr = 0;

map<string, int> mpopcode;
map<string, int>::iterator it;

int conversion(int n)
{
    int temp, hex = 0, temp1;
    int i = 0;
    while (n != 0)
    {
        temp = n % 10;
        hex += (pow(16, i) * temp);
        n /= 10;
        i++;
    }
    return hex;
}
int ispresent(string word)
{

    it = mpopcode.find(word);
    if (it == mpopcode.end())
    {
        return 1;
    }
    else
        return 0;
}
string get_object_code(string ch)
{
    int k;
    string word;
    stringstream iss(ch);

    while (iss >> word)
    {

        if (word == "END")
        {
            cout << "\n ENd of the program";
            return "OKAY";
        }
        else if (word == "START")
        {
            iss >> word;
            stringstream stringtoint(word);

            stringtoint >> loctr;
            loctr = conversion(loctr); //converting into decimal..so that addition becomes easy
            cout << "\n Location pointer:" << loctr;
        }
        else
        {
            if (isoptab(word) == 0) //symbol
            {

                if (ispresent(word) && loctr != 0) //is symbol already present in the symtab?
                {                                  //if NO
                    if (word == "WORD")
                    {
                        loctr += 3;
                        iss >> word;
                    }
                    else if (word == "RESW")
                    {
                        iss >> word;

                        stringstream stringtoint(word);
                        stringtoint >> k;
                        k *= 3;
                        loctr += k;
                    }
                    else if (word == "RESB")
                    {
                        iss >> word;
                        stringstream stringtoint(word);
                        stringtoint >> k;
                        loctr += k;
                    }
                    else if (word == "BYTE") // C'EOF'..find the length of byte..hereit is 3
                    {
                        int counter = 0;
                        iss >> word;
                        if (word[0] == 'C')
                        {
                            for (int i = 0; word[i]; i++)
                            {

                                if (word[i] == '\'')
                                {
                                    int k = i + 1;

                                    while (!(word[k] == '\''))
                                    {
                                        counter++;
                                        k++;
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            counter = 1;
                        }
                        loctr += counter;
                    }
                    else
                    {

                        mpopcode.insert({word, loctr});
                    }
                }
                else if (loctr != 0)
                { //if no
                    cout << "\n ITS an ERROR..ITS ALREADy PRESENT IN THE SYMTAB";
                    cout << "\n\n\t\t TERMINATING";
                    exit(0);
                }
            }
            else if (isoptab(word)) //opcode
            {

                loctr += 3;
                iss >> word;
            }
        }
    }

    return ch;
}
