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

    int counter = 0;
    int final_val = 0;
    
    void search(TreeNode* root, int k){
        if (root == nullptr) return;
        search(root->left,k);
        counter++;
        if (counter == k){
            final_val = root->val;
            return;
        }else{
            search(root->right,k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        search(root,k);
        return final_val;
    }
};

