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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr || p == nullptr || q == nullptr){
            return nullptr;
        }

        int rv = root->val;
        int pv = p->val;
        int qv= q->val;

        if (rv > pv && rv > qv){
            return lowestCommonAncestor(root->left, p, q);
        }else if (rv < pv && rv < qv){
            return lowestCommonAncestor(root->right, p, q);
        }else {
            return root;
        }
        
    }
};

