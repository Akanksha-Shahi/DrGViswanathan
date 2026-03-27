// MINIMUM WINDOW SUBSTRING
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        unordered_map<char, int> need, window;
        for(char c:t) need[c]++;
        int have =0;
        int required = need.size();
        int left=0;
        int minLen= INT_MAX;
        int start =0;
        for( int right=0; right<s.size(); right++){
            char c =s[right];
            window[c]++;
            if(need.count(c) && window[c] == need[c]) have++;
            while(have == required){
                if(right-left+1< minLen){
                    minLen =right-left+1;
                    start = left;
                }
                char leftChar =s[left];
                window[leftChar]--;
                if(need.count(leftChar) && window[leftChar]< need[leftChar]) have--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};