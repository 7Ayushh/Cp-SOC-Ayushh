#include <iostream>
#include <vector>

// Definition for a binary tree node
// The left subtree of a node contains only nodes with keys/val lesser than the node’s key/val.
// The right subtree of a node contains only nodes with keys greater than the node’s key.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        int rootVal = root->val;
        int pVal = p->val;
        int qVal = q->val;

        // we have no idea about the index of sequence
        // coincidentally they gave us a BST sorted sequence
        if(pVal<rootVal && qVal<rootVal) return lowestCommonAncestor(root->left,p,q);
        else if(qVal>rootVal && pVal>rootVal) return lowestCommonAncestor(root->right,p,q);
        else return root; // rootval if equal or lies bw them - then ofc diff side of branches
    }
};

// Function to build a BST from a vector of numbers
TreeNode* buildBST(const std::vector<int>& nums) {
    TreeNode* root = nullptr;
    Solution solution;

    for (int num : nums) {
        if (root == nullptr) {
            root = new TreeNode(num);
        } else {
            TreeNode* curr = root;
            while (true) {
                if (num < curr->val) {
                    if (curr->left == nullptr) {
                        curr->left = new TreeNode(num);
                        break;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if (curr->right == nullptr) {
                        curr->right = new TreeNode(num);
                        break;
                    } else {
                        curr = curr->right;
                    }
                }
            }
        }
    }

    return root;
}

int main() {
    // Input sequence of numbers
    std::vector<int> nums = {6, 2, 8, 0, 4, 7, 9, 3, 5};

    // Build the binary search tree
    TreeNode* root = buildBST(nums);

    // Create solution object
    Solution solution;

    // Find the lowest common ancestor of two given values
    int pVal = 2;
    int qVal = 8;
    TreeNode* p = new TreeNode(pVal);
    TreeNode* q = new TreeNode(qVal);
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    // Print the value of the lowest common ancestor
    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    // Clean up memory
    delete p;
    delete q;
    // Remember to delete the binary search tree nodes if necessary

    return 0;
}
