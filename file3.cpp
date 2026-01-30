// TOP K FREQUENT ELEMENTS
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for( int x: nums)freq[x]++;
        priority_queue<pair<int, int>> pq;
        for( auto &it: freq){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while( k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};