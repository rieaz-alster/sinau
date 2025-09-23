/* First Attempt Solution*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string longestPalindrome(string s);
   
int main() {
        //Read input from text
    string line;

    ifstream inputtext("InputText.txt");
    size_t itLine = 0;

    string s, p;

    size_t pos;
    string sElement;

    string answer;    //type depend on problem
    bool result;

    while(getline(inputtext, line))
    {
        if(line.length() > 0 && line.at(0) == ';')
            continue;

        if(line.length() == 0 && itLine == 0)
            continue;

        switch (itLine)
        {
        case 0:         //first string, input
            s = line;
            itLine++;
            break;

        case 1:         //second string, expected answer
            p = line;
            itLine++;
            break;

        case 2:         //blank, should do main function here
            answer = longestPalindrome(s);
            result = p.compare(answer) == 0;

            printf(result ? "PASS\n" : "FAIL\n");
            
            itLine = 0;
            s.clear();
            p.clear();
            break;
        
        default:
            break;
        }
    }

    return 0;
}

string longestPalindrome(string s)
{
    string result="";
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 1; j <= (s.length() - i); j++)
        {
            string specimen = s.substr(i,j);
            bool testResult = true;
            for(int k = 0; k < specimen.length(); k++)
            {
                if(specimen.at(k) != specimen.at(specimen.length() - 1 - k))
                {
                    testResult = false;
                    break;
                }
            }
            if(testResult && specimen.length() > result.length())
                result = specimen;
        }
    }

    return result;
}
