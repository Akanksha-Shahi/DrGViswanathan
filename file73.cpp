// Maximum profit in job scheduling
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for( int i =0; i<n; i++){
            jobs[i]={startTime[i],endTime[i], profit[i]};
        }
        sort( jobs.begin(), jobs.end());
        vector<int> dp(n);
        return solve(0, jobs, dp);
    }
    int solve ( int i, vector<vector<int>>&jobs, vector<int> &dp){
        if( i>= jobs.size()) return 0;
        if(dp[i] !=0) return dp[i];
        int notMake = solve(i+1, jobs, dp);
        int next = findNext(i, jobs);
        int take = jobs[i][2]+ solve( next, jobs, dp);
        return dp[i]= max( take, notMake);
    }
    int findNext( int i, vector<vector<int>>&jobs){
        int l = i+1, r= jobs.size()-1;
        int ans = jobs.size();
        while( l<=r){
            int mid = (l+r)/2;
            if( jobs[mid][0] >= jobs[i][1]){
                ans = mid;
                r = mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};