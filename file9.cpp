// MAXIMUM SUBARRAY
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = nums[0];
        int maxSum = nums[0];
        for( int i =1; i<n; i++){
            curSum = max(nums[i], curSum +nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};