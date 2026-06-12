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
    int goodNodes(TreeNode* root) {
        return search(root,root->val);
    }

    int search(TreeNode* node, int maximum){
        if(node == nullptr){
            return 0;
        }


        int result = 0;
        if (node->val >= maximum){
            result = 1;
            maximum = node->val;
        }
        // left
        result += search(node->left,maximum);
        // right
        result += search(node->right, maximum);

        return result;
    }
};

