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

    void search(vector<int>& result, TreeNode* root,int depth){
        if (root == nullptr) return ;

        if (result.size() == depth) {
            result.push_back(root->val);
        }

        search(result, root->right, depth+1);
        search(result, root->left, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> results{};

        search(results,root, 0);
        return results;
    }
};

