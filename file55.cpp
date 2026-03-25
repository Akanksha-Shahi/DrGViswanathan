// Serialize and Deserialize Binary Tree
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string s = to_string(root->val)+ ",";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        stringstream ss(data);
        string s;
        while(getline(ss,s,',')){
            if(!s.empty()) q.push(s);
        }
        return deserializeHelper(q);
    }
private:
    TreeNode* deserializeHelper(queue<string> &q){
        string s = q.front();
        q.pop();
        if(s =="N") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);
        return root;
    }    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
