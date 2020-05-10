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
    ifstream fins("lineofcodes.txt");

    while (!fins.eof())
    {
        getline(fins, lineofcode);
        pass2(lineofcode);
    }

    fins.close();

    //pass2:bitmasking(continue)

    ifstream filin("lineofcodes.txt");
    ifstream sc("objectcode.txt");
    string source, opcodes, hexa, text, init;
    int occurence = 0;    //if the resw/resb occurs then need to break the chain
    int incr = 0;         //index for the bitmask
    int counter = 0;      //if the text is <=10 then action is taking accordingly
    getline(filin, init); //sending the first record
    initial(init, loctr); //sending the first location

    // storing the starting location in the variable location
    int location = starting_location;

    //Making of address
    int index = -1;
    int even = 0;

    while (filin >> opcodes)
    {
        if (isoptab(opcodes) || opcodes == "WORD" || opcodes == "RESW" || opcodes == "RESB" || opcodes == "BYTE")
        { //already a array of address has been made
            // hence to get that particular address of
            //the opcode the index is been incremented
            index++;
        }
        if (occurence == 1 && isoptab(opcodes))
        { //if the word/byte/RESW/RESB occurs
            //or the opcode occurs
            string s;
            for (int i = 0; i < incr; i++)
            {
                s += hexa[i];
            }
            s += "00";
            if (even == 1)
            {
                bitmasking(text, s, l[index - 1]);
                even = 0;
            }
            else
            {
                bitmasking(text, s, l[index]);
                even = 1;
            }
            hexa.clear();
            incr = 0;
            text.clear();
            sc >> source;
            if (opcodes == "RSUB" || opcodes == "WORD" || opcodes == "BYTE")
            {
                hexa[incr++] = '0';
                //adding the bitmask
            }
            else
            {
                hexa[incr++] = '1';
                //adding the bitmask
            }
            text += source;
            occurence = 0;
            counter = 1;
        }
        else if (isoptab(opcodes))
        {
            sc >> source;

            text += source;
            if (opcodes == "RSUB")
            {
                hexa[incr++] = '0';
                //adding the bitmask
            }
            else
            {
                hexa[incr++] = '1';
                //adding the bitmask
            }
            counter++;
        }
        else if (opcodes == "WORD" || opcodes == "BYTE")
        {

            sc >> source;
            text += source;
            counter++;
            occurence = 1;
            hexa[incr++] = '0';
        }

        if (counter >= 10)
        {
            string s;
            for (int i = 0; i < incr; i++)
            {
                s += hexa[i];
            }
            s += "00";
            if (even == 1)
            {
                bitmasking(text, s, l[index - 1]);
                even = 0;
            }
            else
            {
                bitmasking(text, s, l[index]);
                even = 1;
            }
            hexa.clear();
            incr = 0;
            text.clear();
            counter = 0;
        }
    }

    index++;
    string s;
    for (int i = 0; i < incr; i++)
    {
        s += hexa[i];
    }
    s += "00";
    if (even == 1)
    {
        bitmasking(text, s, l[index - 1]);
        even = 0;
    }
    else
    {
        bitmasking(text, s, l[index]);
        even = 1;
    }

    final("END"); //sending the end record

    return 0;
}
