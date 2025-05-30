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

    do
    {
        /*Create substring by delimiter (' ')*/
        pos = text.find(' ');
        string substr = text.substr(0, pos);

        /*Search if substring is exist within map*/
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

        text = text.substr(pos+1);
    }
    while(pos != string::npos);

    /*Print result*/
    for(map<string, int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
    return 0;
}