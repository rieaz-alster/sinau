/* Embedded Solution*/
/*

Disabled under embedded platform

#include <iostream>  
#include <fstream>
#include <string>

*/
#include "lib/log.h"

#include <cstring>

#include "test_case.h"

constexpr int MAX_CHAR = 1000;

void longestPalindrome(char* s, int sLen, char* answer, int* ansLen);
int strCompare(char* str1, int str1Len, char* str2, int str2Len);
   
int main() {
    //Read input from text
    char line[MAX_CHAR];
    int lineLen = 0;

    char s[MAX_CHAR], p[MAX_CHAR];
    int sLen, pLen;

    char answer[MAX_CHAR];    //type depend on problem
    int ansLen = 0;
    bool result;

    int testCaseIt = 0;
    int lineIt = 0;
    while(test_case[testCaseIt] != '\0')
    {
        char curChar = test_case[testCaseIt++];
        if(curChar != '\n' && curChar != '\0')
        {
            line[lineLen++] = curChar;
        }
        else
        {

            if(lineLen > 0 && line[0] == ';')
                continue;

            if(lineLen == 0 && lineIt == 0)
                continue;

            switch (lineIt)
            {
            case 0:         //first string, input
                strncpy(s, line, lineLen);
                sLen = lineLen; lineLen = 0;
                lineIt++;
                break;

            case 1:         //second string, expected answer
                strncpy(p, line, lineLen);
                pLen = lineLen; lineLen = 0;
                lineIt++;
                break;

            case 2:         //blank, should do main function here
                longestPalindrome(s, sLen, answer, &ansLen);
                result = strCompare(p,pLen, answer, ansLen) == 0;

                log(result ? "PASS\n" : "FAIL\n");
                
                lineIt = 0;
                lineLen = 0;
                sLen = 0;
                pLen = 0;
                break;
            
            default:
                break;
            }
        }
    }

    return 0;
}

void longestPalindrome(char* s, int sLen, char* answer, int* ansLen)
{
    char result[MAX_CHAR] = "";
    int resLen = 0;
    for(int i = 0; i < sLen; i++)
    {
        for(int j = 1; j <= (sLen - i); j++)
        {
            //substring
            char specimen[sLen];
            int specLen = 0;
            for(int k = i; k < i+j;)
            {
                specimen[specLen++] = s[k++];
            }

            bool testResult = true;
            for(int k = 0; k < specLen; k++)
            {
                if(specimen[k] != specimen[specLen - 1 - k])
                {
                    testResult = false;
                    break;
                }
            }
            if(testResult && specLen > resLen)
            {
                strncpy(result, specimen, specLen);
                resLen = specLen;
            }
        }
    }

    strncpy(answer, result, resLen);
    (*ansLen) = resLen;
}


int strCompare(char* str1, int str1Len, char* str2, int str2Len)
{
    int itLimit = str1Len < str2Len ? str1Len : str2Len;
    int result;

    for(int i = 0; i < itLimit; i++)
    {
        if(str1[i] != str2[i])
            return str1[i] > str2[i] ? 1 : -1;
    }

    if(str1Len != str2Len)
        return str1Len > str2Len ? 1 : -1;

    return 0;
}
