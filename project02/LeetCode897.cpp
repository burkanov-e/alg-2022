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
    TreeNode* head = new TreeNode(0);
    TreeNode* temp = head;

    void rec(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        rec(root->left);
        head->right = new TreeNode(root->val);
        head = head->right;
        rec(root->right);

        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        rec(root);
        return temp->right;
    }
};