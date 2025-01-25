#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3(0);
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        if (nums3.size()%2==1){
            return nums3[floor((nums3.size()-1)/2)];
        }
        else{
            return (nums3[floor((nums3.size())/2)-1]+nums3[floor((nums3.size())/2)])/2.0;
        }
        return 0;
    }
};
int main(){ 
    vector<int> ceva = {1, 3, 10};
    vector<int> ceva2 = {2, 4, 100};
    Solution op;
    double sol=op.findMedianSortedArrays(ceva,ceva2);
    cout<<sol<<endl;
    return 0;
}
