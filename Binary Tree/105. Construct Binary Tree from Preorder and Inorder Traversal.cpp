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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, inorder, inorder_map, preIndex, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, map<int, int>& inorder_map,
                    int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) 
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorder_map[rootVal];

        root->left = build(preorder, inorder, inorder_map, preIndex, inStart, rootIndex - 1);
        root->right = build(preorder, inorder, inorder_map, preIndex, rootIndex + 1, inEnd);

        return root;
    }
};