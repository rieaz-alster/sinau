/*Optimized C++98 Solution*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_ARRAY 10

bool isMatch(string s, string p);

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
    // Function to check if string 's' matches the pattern 'p'.
    // https://algo.monster/liteproblems/10

    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: empty string matches with empty pattern
    dp[0][0] = true;

    // Fill the dp table
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If the pattern character is '*', it can either eliminate the character and its predecessor
            // or if the string is not empty and the character matches, include it
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }

            // If the current characters match (or the pattern has '.'), then the result
            // is determined by the previous states of both the string and pattern
            else if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    // Return the result at the bottom-right corner of the dp table
    return dp[m][n];
}

