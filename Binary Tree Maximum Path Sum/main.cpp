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
    int m = INT_MIN;

     int maxPathSearch(TreeNode* root){
        if (!root) return 0;

        //max path right
        int max_right = maxPathSearch(root->right);
        //max path left
        int max_left = maxPathSearch(root->left);
        if (max_right + max_left + root->val > m) m = max_right + max_left + root->val;

        return max(0,max(root->val + max_right, root->val+max_left));
     }


    int maxPathSum(TreeNode* root) {
        maxPathSearch(root);

        return m;        

    }
};

