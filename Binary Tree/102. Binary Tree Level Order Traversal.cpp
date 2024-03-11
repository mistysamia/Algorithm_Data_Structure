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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<vector<TreeNode*>> deq(2002);
        vector<vector<int>> ans;

        if (!root) return ans;

        int level = 0;
        deq[level].push_back(root);

        while (!deq[level].empty()) {
            ans.resize(level+1);
            for (int i = 0; i < deq[level].size(); i++) {
                int data = deq[level][i]->val;
                ans[level].push_back(data);

                if (deq[level][i]->left != NULL)
                    deq[level + 1].push_back(deq[level][i]->left);
                if (deq[level][i]->right != NULL)
                    deq[level + 1].push_back(deq[level][i]->right);
            }
            level++;
        }
        
        return ans; 
    }
};