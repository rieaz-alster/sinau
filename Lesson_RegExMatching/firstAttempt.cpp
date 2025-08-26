/* First Attempt Solution*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_ARRAY 10

bool isMatch(string s, string p);
void simplify(string* p);

int main()
{
    //Read input from text
    string line;

    ifstream inputtext("InputText.txt");
    size_t itLine = 0;

    string s, p;

    size_t pos;
    string sElement;

    bool answer;    //type depend on problem
    bool result;

    while(getline(inputtext, line))
    {
        if(line.length() > 0 && line.at(0) == ';')
            continue;

        if(line.length() == 0 && itLine == 0)
            continue;

        switch (itLine)
        {
        case 0:         //first string, target
            s = line;
            itLine++;
            break;

        case 1:         //second string, regex
            p = line;
            itLine++;
            break;

        case 2:         //answer

            answer = line.compare("true") == 0;

            itLine++;
            break;


        case 3:         //blank, should do main function here
            result = answer == isMatch(s,p);
            if(result)
                printf("true\n");
            else
                printf("false\n");
            
            itLine = 0;
            s.clear();
            p.clear();
            break;
        
        default:
            break;
        }
    }
}

bool isMatch(string s, string p)
{
    simplify(&p);
    bool answer;
    if(s.compare(p) == 0)               //the easiest, just compare
        return true;

    string matchedStr;
    string testStr;

    matchedStr.clear();
    testStr.clear();

    size_t findResult;
    char lastValidAsk = 0;

    for(int i = 0; i < p.size(); i++)   //manual parsing
    {
        //Check for asterix first
        if(i < p.size() - 1 &&          
            p[i+1] == '*')
        {
            char preceded;
            if(p[i] == '.')
            {
                //if '.' preceded '*', it should have boundary or at the end of pattern
                char boundary = i < p.size() - 2 ? p[i+2] : 0 ;

                do
                {
                    if(s.size() > matchedStr.size())
                        matchedStr += s[matchedStr.size()];

                }
                while(s[matchedStr.size()] != boundary &&
                      matchedStr.size() < s.size());


            }
            else
            {
                //  fixed before asterisk, only have repetition. Eg "a*"
                preceded = p[i];                  

                testStr = matchedStr;
                do
                {
                    findResult = s.find(testStr);

                    if(findResult != string::npos)
                    {
                        lastValidAsk = testStr[testStr.size()-1];
                        matchedStr = testStr;
                        testStr += preceded;
                    }
                } while (findResult != string::npos);
                
            }

            i++;
        }    
        else if(p[i] == '.')
        {
            //wildcard
            if(matchedStr.size() >= s.size())
                return false;

            matchedStr += s[matchedStr.size()];
        }
        else
        {
            //fixed
            if(lastValidAsk != p[i])
            {
                if(matchedStr.size() >= s.size())
                    return false;
                
                matchedStr += p[i];
            }            
        }
    }

    return (s.compare(matchedStr) == 0);
}

void simplify(string* p)
{
    string temp = (*p);
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == '*' && 
           temp[i-1] == '.' &&
           i < temp.size() - 2 && temp[i+2] == '*')
        {
            temp.erase(i+1, i+2);
        }

        else if(i > 0 && i < temp.size() - 1 &&
                temp[i] == '*' &&
                temp[i-1] == temp[i+1])
        {
            temp.erase(i+1);
        }

        else if(temp[i] == '*' && temp[i+1] == '*')
        {
            temp.erase(i);
        }
    }

    if(temp.compare(*p) != 0)
    {
        simplify(&temp);
    }
    (*p) = temp;
}

