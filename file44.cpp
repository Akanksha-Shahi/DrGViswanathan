// Subarray Sum Equals K
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] =1;
        int sum =0, count =0;
        for( int num : nums){
            sum+=num;
            if(map.count(sum-k)) count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }
    
};