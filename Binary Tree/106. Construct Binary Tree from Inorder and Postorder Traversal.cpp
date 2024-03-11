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
    int inIndex, postIndex;

    TreeNode* ConstructTree(vector<int>& inorder, vector<int>& postorder) {

        if (inIndex < 0 || postIndex < 0)
            return nullptr;

        cout<<postIndex<<" "<<postorder[postIndex]<<" "<<inorder[inIndex]<<endl;
        TreeNode* root=new TreeNode(postorder[postIndex]);

        postIndex--;
        if(root->val!=inorder[inIndex]){
            root->right=ConstructTree(inorder,postorder);
        }
        
        inIndex--;
        if( root->right->val!=inorder[inIndex]){
            root->left=ConstructTree(inorder,postorder);
        }

        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inIndex = inorder.size()-1;
        postIndex = postorder.size()-1;
        return ConstructTree(inorder, postorder);
    }
    
};