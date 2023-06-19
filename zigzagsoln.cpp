#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<TreeNode*> currentLevel{root};
        int level = 0;
        
        while (!currentLevel.empty()) {
            vector<TreeNode*> nextLevel;
            vector<int> values;

            for (TreeNode* node : currentLevel) {
                values.push_back(node->val);
                if (node->left != nullptr) {
                    nextLevel.push_back(node->left);
                }
                if (node->right != nullptr) {
                    nextLevel.push_back(node->right);
                }
            }

            if (level % 2 != 0) {
                reverse(values.begin(), values.end());
            }

            res.push_back(values);
            currentLevel = nextLevel;
            level++;
        }

        return res;
    }
};

int main() {
    // Test case
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Display the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the memory
    // ...

    return 0;
}
