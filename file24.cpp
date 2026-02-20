// FLOOD FILL
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        if( originalColor == color)return image;
        function <void(int,int)> dfs= [&](int r, int c){
            if( r<0 || c<0 || r>=m || c>=n) return;
            if( image[r][c] != originalColor) return;
            image[r][c]= color;
            dfs(r+1,c);
            dfs(r-1,c);
            dfs(r, c+1);
            dfs(r, c-1);
        };
        dfs( sr,sc);
        return image;
    }
};