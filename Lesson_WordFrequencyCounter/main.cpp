#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
    string text;
    if(argc <= 1)
    {
        //If there is no parameter, hardcode the input
        text = "this is a test this is only a test";
    }

    unordered_map<string, int> result;      //https://en.cppreference.com/w/cpp/container/unordered_map/; C++11

    auto pos = string::npos;
    auto textLen = text.length();

    do
    {
        pos = text.find(' ');
        auto substr = text.substr(0, pos);

        auto it = result.find(substr); 
        if(it == result.end())
        {
            result.emplace(substr, 1);
        }
        else
        {
            it->second++;
        }

        text = text.substr(pos+1, textLen);
        textLen = text.length();
    }
    while(pos != string::npos);

    for(const pair<string, int>& res : result)   //
    {
        cout << res.first << ": " << res.second << endl;
    }
    
    return 0;
}