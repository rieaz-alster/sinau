/* FOR SHOWCASING EMBEDDED SOLUTION WHILE COMPLIANT WITH C++11*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

constexpr size_t MAX_ARRAY = 128;

double findMedianSortedArrays(int* nums1, size_t m, int* nums2, size_t n);
void insertionSort(int* array, size_t arrLen);

int main()
{
    //Read input from text
    string line;

    ifstream inputtext("InputText.txt");
    size_t itLine = 0;

    int num1[MAX_ARRAY];    size_t num1It = 0;
    int num2[MAX_ARRAY];    size_t num2It = 0;

    size_t pos;
    string sElement;
    float answer;

    while(getline(inputtext, line))
    {
        if(line.length() > 0 && line.at(0) == ';')
            continue;

        if(line.length() == 0 && itLine == 0)
            continue;

        float median;

        switch (itLine)
        {
        case 0:         //first array
            
            do
            {
                pos = line.find(',');
                sElement = line.substr(0,pos);

                num1[num1It] = atoi(sElement.c_str());
                num1It++;

                line = line.substr(pos+1);
            }
            while(pos != string::npos);
            
            itLine++;
            break;

        case 1:         //second array
        
            do
            {
                pos = line.find(',');
                sElement = line.substr(0,pos);

                num2[num2It] = atoi(sElement.c_str());
                num2It++;

                line = line.substr(pos+1);
            }
            while(pos != string::npos);

            itLine++;
            break;

        case 2:         //answer

            answer = atof(line.c_str());

            itLine++;
            break;

        case 3:         //blank, should do main function here

            median = findMedianSortedArrays(num1, num1It, num2, num2It);
            if(answer == median)
                printf("true\n");
            else
                printf("false\n");

            itLine = 0;
            num1It = 0;
            num2It = 0;
            answer = 0;
            break;

        
        default:
            break;
        }
    }
}


double findMedianSortedArrays(int* nums1, size_t m, int* nums2, size_t n)
{
    int combined[m+n];
    size_t comLen = 0;
    size_t insertIdx = 0;

    //combine both array
    for(int i = 0; i < m; i++)
        combined[comLen++] = nums1[i];
    for(int i = 0; i < n; i++)
        combined[comLen++] = nums2[i];

    //do sort (insertion)
    insertionSort(combined, comLen);

    //find median
    auto size = m+n;
    if (size % 2 == 0)
    {
        return (combined[size / 2 - 1] + combined[size / 2]) / 2.0;
    }
    else
    {
        return combined[size / 2];
    }
}

void insertionSort(int* arr, size_t arrLen)
{
    for(int i = 0; i < arrLen; i++)
    {
        auto key = arr[i];
        auto j = i;
        while(j > 0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}