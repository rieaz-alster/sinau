/* FOR SHOWCASING C++11 SOLUTION*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm> //for sort

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1;          
    nums1 = {1,2};                  //Initializer list

    vector<int> nums2;
    nums2 = {3};

    cout << findMedianSortedArrays(nums1, nums2) << endl;



    nums1.clear(); nums2.clear();

    nums1 = {1,2};
    nums2 = {3,4};
    
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> combined;

    //combine both vector
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();

    for(int n : nums1) combined.push_back(n);               //range based loop
    for(int n : nums2) combined.push_back(n);

    //sort
    sort(combined.begin(), combined.end());    

    //find median
    size_t size = combined.size();
    if (size % 2 == 0)
    {
        return (combined[size / 2 - 1] + combined[size / 2]) / 2.0;
    }
    else
    {
        return combined[size / 2];
    }
}