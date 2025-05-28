/* FOR SHOWCASING C++11 AND MORE*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string text = "this is a test this is only a test";

    unordered_map<string, int> result;      //https://en.cppreference.com/w/cpp/container/unordered_map/; C++11

    auto pos = string::npos;                //auto is c++11 feature
    auto textLen = text.length();

    do
    {
        pos = text.find(' ');
        auto substr = text.substr(0, pos);

        auto it = result.find(substr); 
        if(it == result.end())
        {
            result.emplace(substr, 1);      //emplace is c++11
        }
        else
        {
            it->second++;
        }

        text = text.substr(pos+1, textLen);
        textLen = text.length();
    }
    while(pos != string::npos);

    // for(const pair<string, int>& res : result)   //C++11
    // {
    //     cout << res.first << ": " << res.second << endl;
    // }

    for(const auto& [word, count] : result)         //structural binding; C++17
    {
        cout << word << ": " << count << endl;
    }
    
    return 0;
}