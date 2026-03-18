// Find all anagrams in String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()< p.size()) return res;
        vector<int> freqp(26,0), freqs(26,0);
        for( char c:p)freqp[c-'a']++;
        int k  = p.size();
        for( int i =0; i<s.size(); i++){
            freqs[s[i]-'a']++;
            if( i>=k) freqs[s[i-k] - 'a']--;
            if( freqs == freqp) res.push_back(i-k+1);
        }
        return res;
    }
};