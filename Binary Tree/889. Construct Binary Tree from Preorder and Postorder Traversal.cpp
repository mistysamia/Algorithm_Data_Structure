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
    int preIndex = 0, postIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(preorder[preIndex++]);

        if(root->val!=postorder[postIndex]){
            root->left=constructFromPrePost(preorder,postorder);
            cout<<root->val<<"  L  "<<root->left->val<<endl;
        }
        if(root->val!=postorder[postIndex]){
            root->right=constructFromPrePost(preorder,postorder);
            cout<<root->val<<"  R  "<<root->right->val<<endl;
        }
        postIndex++;
        return root;
    }
};