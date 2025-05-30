/* FOR SHOWCASING C++11 AND MORE*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{

    /*Hardcoded input*/
    string text = "this is a test this is only a test";

    /*Variable Initialization*/
    unordered_map<string, int> result;      //Instead of map, we use unordered_map. https://en.cppreference.com/w/cpp/container/unordered_map/. Since C++11

    auto pos = string::npos;                //Since pos type (and more below) can be deducted, we use auto. //https://en.cppreference.com/w/cpp/language/auto.html. Since C++11

    do
    {
        /*Create substring by delimiter (' ')*/
        pos = text.find(' ');
        auto substr = text.substr(0, pos);          //Auto

        /*Search if substring is exist within map*/
        auto it = result.find(substr);              //Auto
        if(it == result.end())
        {
            /*If substring doesn't exist, add new pair*/
            result.emplace(substr, 1);      //We use emplace to replace insert. https://en.cppreference.com/w/cpp/container/unordered_map/emplace. Since C++11
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
    //Since C++11, we can use range-based loop
    //https://en.cppreference.com/w/cpp/language/range-for.html
    for(const pair<string, int>& res : result)
    {
        cout << res.first << ": " << res.second << endl;
    }

    //C++17 onward can use structural binding
    //https://cppreference.com/w/cpp/language/structured_binding.html
    for(const auto& [word, count] : result)
    {
        cout << word << ": " << count << endl;
    }
    
    return 0;
}