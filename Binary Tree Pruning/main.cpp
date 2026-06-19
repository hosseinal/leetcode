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

    bool prune(TreeNode* root) {
        if(!root) return false;

        if(!root->left && !root->right && root->val == 0){
            return true;
        }
        bool lp = prune(root->left);
        if(lp) root->left=nullptr;

        bool rp = prune(root->right);
        if(rp) root->right = nullptr;

        if(!root->left && !root->right && root->val == 0){
            return true;
        }

        return false;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        prune(root);
        if(!root->left && !root->right && root->val == 0){
            return nullptr;
        }
        return root;
    }
};
