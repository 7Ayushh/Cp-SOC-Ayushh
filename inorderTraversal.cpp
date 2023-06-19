#include<bits/stdc++.h>
using namespace std;

// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 // inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree). The binary search tree makes use of this traversal to print all nodes in ascending order of value.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { // dtype dekho - it outputs a vector
        if(root==nullptr) return vector<int>();

        vector<int> vec3;
        vector<int> vec2;
        vector<int> vec1;
        //vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
        if(root->left != nullptr) {
            vec1= inorderTraversal(root->left);
            vec3.insert(vec3.end(),vec1.begin(),vec1.end());
        }
        vec3.insert(vec3.end(),root->val);

        if(root->right != nullptr) {
            vec2= inorderTraversal(root->right);
            vec3.insert(vec3.end(),vec2.begin(),vec2.end());
        }
        return vec3;
    }
};