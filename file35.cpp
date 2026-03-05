// Construct Binary Tree with Preorder and inorder traversal
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex =0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for( int i =0; i<inorder.size(); i++) mp[inorder[i]]=i;
        return build( preorder, 0, inorder.size()-1);
    }
    TreeNode* build( vector<int> & preorder, int left, int right){
        if( left> right ) return NULL;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode( rootVal);
        int index = mp[rootVal];
        root->left = build( preorder, left, index-1);
        root->right = build( preorder, index+1, right);
        return root;
    }
};