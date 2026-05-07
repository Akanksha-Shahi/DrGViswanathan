// Sort Characters by Frequnecy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for( char c: s){ freq[c]++;}
        vector<pair<char, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](pair<char, int>&a, pair<char, int>&b){
            return a.second> b.second;
        });
        string ans ="";
        for(auto &p:vec){
            ans+= string(p.second, p.first);
        }
        return ans;
    }
};