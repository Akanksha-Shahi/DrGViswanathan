// Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int left = 0, maxLen =0;
        for( int right =0; right<s.size(); right++){
            if(lastSeen[s[right]]>= left){
                left = lastSeen[s[right]]+1;
            }
            lastSeen[s[right]]= right;
            maxLen= max(maxLen, right-left+1);
        }
        return maxLen;
    }
};