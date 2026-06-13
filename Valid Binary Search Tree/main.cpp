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

    bool checkValidation(TreeNode* root, int lower_limit, int upper_limit){

        if (root == nullptr) return true;

        if (root->val <= lower_limit || root->val >= upper_limit){
            return false;
        }

        return checkValidation(root->left, lower_limit, root->val) && checkValidation(root->right,root->val,upper_limit );

    }
    
    bool isValidBST(TreeNode* root) {
        return checkValidation(root, -1001,1001 );
    
    }
};

