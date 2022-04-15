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
    vector<string> v;
    void treePath(TreeNode* root, string ans) {
        if (root->left == NULL && root->right == NULL) {
            ans = ans + to_string(root->val);
            v.push_back(ans);
        } else {
            ans = ans + to_string(root->val) + "->";

            if (root->left) {
                treePath(root->left, ans);
            }
            if (root->right) {
                treePath(root->right, ans);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string ans;
        treePath(root, ans);
        return v;
    }
};