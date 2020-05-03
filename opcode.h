#include <bits/stdc++.h>
using namespace std;
map<string, string> mp = {
    {"a", "hello"}};
string optab(string a)
{
    map<string, string>::iterator it;
    it = mp.find(a);
    if (it == mp.end())
    {
        return "0";
    }
    else
    {

        return it->second;
    }
}