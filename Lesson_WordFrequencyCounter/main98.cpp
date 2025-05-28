/* FOR SHOWCASING C++98 SOLUTION*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    /*Hardcoded input*/
    string text = "this is a test this is only a test";

    map<string, int> result;

    size_t pos = string::npos;
    size_t textLen = text.length();

    do
    {
        /*Create substring by delimiter (' ')*/
        pos = text.find(' ');
        string substr = text.substr(0, pos);

        /*Search if substring is exist withing map*/
        map<string, int>::iterator it = result.find(substr); 
        if(it == result.end())
        {
            /*If substring doesn't exist, add new pair*/
            result.insert(pair<string, int>(substr, 1));
        }
        else
        {
            /*If substring exist, increment its count*/
            it->second++;
        }

        text = text.substr(pos+1, textLen);
        textLen = text.length();
    }
    while(pos != string::npos);

    for(map<string, int>::iterator it = result.begin(); it != result.end(); it++)
    {
        /*Print result*/
        cout << it->first << ": " << it->second << endl;
    }
    
    return 0;
}