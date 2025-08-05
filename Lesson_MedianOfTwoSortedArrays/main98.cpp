/* FOR SHOWCASING C++98 SOLUTION*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1;         // Initialization a la 98
    nums1.push_back(1);
    nums1.push_back(3);

    vector<int> nums2;
    nums2.push_back(2);

    cout << findMedianSortedArrays(nums1, nums2) << endl;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> combined;

    //combine both vector
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();

    while(it1 != nums1.end() || it2 != nums2.end())
    {
        if( it2 == nums2.end() || (*it1) <= (*it2))
        {
            combined.push_back((*it1));
            it1++;
        }
        else
        {
            combined.push_back((*it2));
            it2++;
        }
    }

    //DEBUG:
    for(vector<int>::iterator it = combined.begin(); it!=combined.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    //find median
    int medianPos = static_cast<int>(floor(combined.size() + 0.5f)/2);
    double median;
    if(combined.size() % 2 == 0)    //even size
    {
        median = (combined[medianPos] + combined[medianPos+1]) / 2;
    }
    else
    {
        median = combined[medianPos];
    }
    return median;
}