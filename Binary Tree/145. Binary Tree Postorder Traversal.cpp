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
    void printPostOrder(TreeNode* root, vector<int>& nums){
        if(root==NULL)
            return;
        
        printPostOrder(root->left,nums);
        printPostOrder(root->right,nums);
        nums.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vec;
        printPostOrder(root,vec);
        return vec;
    }
};