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

//func type int, pass by reference automatically update ho jayega
void valnode(TreeNode* node, vector<int> &values){
    if(node== nullptr) return;
    else values.push_back(node->val);

    valnode(node->left,values);
    valnode(node->right,values);

    return;
} 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        //traverse the whole tree, put the values in a vector, sort it and return the k-1th value
        valnode(root,values);
        
        sort(values.begin(),values.end());
        return values[k-1];
    }
};