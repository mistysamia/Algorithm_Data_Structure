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
   int traverseIndx = 0;

    TreeNode* treeForm(vector<int>& preorder, int stop) {
        if (traverseIndx >= preorder.size() || (stop != -1 && preorder[traverseIndx] > stop)) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[traverseIndx++]);

        root->left = treeForm(preorder, root->val);
        root->right = treeForm(preorder, stop);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return treeForm(preorder, -1);
    }
};