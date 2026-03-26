// Perfect Squares
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<long long>dp(n+1, INT_MAX);;
        dp[0]=0;
        for( int i=0; i<=n; i++){
            for( int j =0; j*j<=i; j++){
                dp[i]= min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};