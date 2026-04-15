// Largest Rectangle in Histogram
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea =0;
        for( int i =0; i<=n; i++){
            int h = ( i== n? 0:heights[i]);
            while(!st.empty() && h<heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int right =i;
                int left = st.empty()?-1:st.top();
                int width = right -left -1;
                maxarea = max( maxarea, height*width);
            }
            st.push(i);
        }
        return maxarea;
    }
};