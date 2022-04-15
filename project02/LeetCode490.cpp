/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    vector<int> res;

    void checkNull(Node* root) {
        if (root == nullptr) {
            return;
        } else {
            for (auto& ch : root->children) {
                checkNull(ch);
            }
            res.push_back(root->val);
        }
    }

    vector<int> postorder(Node* root) {
        checkNull(root);
        return res;
    }
};