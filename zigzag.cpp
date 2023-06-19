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

vector<vector<int>> func(TreeNode* root, &lefttoright, vector<vector<int>> &output){
    if(root->val == null) return vector<vector<int>>();

    if(!lefttoright){
        if((root->left != nullptr) && (root->right != nullptr)) {
            output.push_back(root->left.val);
            output.push_back(root->right.val);
        }
        if((root->left != nullptr) && (root->right == nullptr)) output.push_back(root->left.val);
        if((root->left == nullptr) && (root->right != nullptr)) output.push_back(root->right.val); 
    }
    else{
        if((root->left != nullptr) && (root->right != nullptr)){
            output.push_back(root->right.val);
            output.push_back(root->left.val);
        }
        if((root->left != nullptr) && (root->right == nullptr)) output.push_back(root->left.val);
        if((root->left == nullptr) && (root->right != nullptr)) output.push_back(root->right.val);   
    }
    output.push_back(func(root->left,!lefttoright));
    output.push_back(func(root->right,!leftoright));  
    lefttoright = !lefttoright;
    return output;
}
class Solution {
public:

// nullptr value of pointer, while null is value of memory cell
// null itself not a key word
// left, right are pointers and val is memory

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool lefttoright;
        vector<pair<int,int>> output;
        if(root==nullptr) return vector<vector<int>>();
        output.push_back(root->val);
        func(root,lefttoright,output);
    }
};