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

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size()==0) return nullptr;
        int val = preorder[0];
        auto r = find(inorder.begin(),inorder.end(),val);
        auto d = distance(inorder.begin(), r);


        vector<int> pl{preorder.begin()+1,preorder.begin()+d+1};
        vector<int> il{inorder.begin(),inorder.begin()+d};

        vector<int> pr{preorder.begin()+d+1, preorder.end()};
        vector<int> ir{inorder.begin()+d+1, inorder.end()};



        TreeNode *head = new TreeNode(preorder[0]);
        head->left = construct(pl,il);
        head->right = construct(pr,ir);

        return head;
    }

    TreeNode* construct2(vector<int>& preorder, vector<int>& inorder, 
                        int preStart, int preEnd, int inStart, int inEnd) {
        
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int val = preorder[preStart];
        TreeNode *head = new TreeNode(val);

        auto r = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, val);
        auto d = distance(inorder.begin() + inStart, r); // Size of left subtree

        head->left = construct2(preorder, inorder, 
                               preStart + 1, preStart + d, 
                               inStart, inStart + d - 1);
                               
        head->right = construct2(preorder, inorder, 
                                preStart + d + 1, preEnd, 
                                inStart + d + 1, inEnd);

        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // return construct(preorder,inorder);
        return construct2(preorder,inorder,0, preorder.size()-1, 0, inorder.size()-1);
;    }
};

