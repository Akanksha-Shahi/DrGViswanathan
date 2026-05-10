// Perfect Rectangle
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area= 0;
        int minX= INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;
        set<pair<int, int>> st;
        for( auto &r: rectangles){
            int x1 = r[0]; 
            int y1 = r[1]; 
            int x2= r[2]; 
            int y2 = r[3];
            area+= 1LL *(x2-x1) *( y2-y1);
            minX= min(minX, x1);
            minY = min(minY, y1);
            maxX= max(maxX, x2);
            maxY = max(maxY, y2);
            vector<pair<int, int>> corners={
                {x1,y1},{x1, y2},{x2,y1},{x2,y2}
            };
            for(auto &c:corners){
                if(st.count(c)) st.erase(c);
                else st.insert(c);
            }
        }
        if(st.size()!=4) return false;
        if(!st.count({minX, minY})|| !st.count({minX, maxY}) || !st.count({maxX, minY}) || !st.count({maxX, maxY})) return false;
        long long expected = 1LL *(maxX-minX) *(maxY-minY);
        return area == expected;
    }
};